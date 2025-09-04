// Pin outputs on arduino nano
const int stepPin1 = 2;
const int dirPin1 = 3;
const int stepPin2 = 4;
const int dirPin2 = 5;
const int stepPin3 = 8;
const int dirPin3 = 9;

// Microsecond delay needed for PWM signals (steppers)
unsigned long int stepDelay = 2000;
// How many steps there are per revolution in the pancake steppers
const int steps_per_rev = 200;

void move_steppers(int ds1, int ds2, int ds3) {

  // Concurrent function which simultaneously moves all steppers at once, if necessary
  // Args:
  // ds1: Number of steps stepper 1 needs to be moved (sign indicates direction)
  // ds2: Number of steps stepper 2 needs to be moved (sign indicates direction)
  // ds3: Number of steps stepper 3 needs to be moved (sign indicates direction)

  // Counter to keep track of how many steps each stepper has taken so far
  int steps_s1 = 0;
  int steps_s2 = 0;
  int steps_s3 = 0;

  // Set direction of stepper motors based on sign of ds1/2/3
  set_direction(dirPin1, check_direction(ds1));
  set_direction(dirPin2, check_direction(ds2));
  set_direction(dirPin3, check_direction(ds3));

  // Absolute value
  ds1 = abs(ds1);
  ds2 = abs(ds2);
  ds3 = abs(ds3);

  // While there are still steps to perform, do:
  while (ds1 - steps_s1 + ds2 - steps_s2 + ds3 - steps_s3 > 0) {

    // Scale factor determines by how much you need to multiply the step velocity depending on how many steppers are moving at once
    int scale_factor = (ds1 == 0) + (ds2 == 0) + (ds3 == 0);
    if (scale_factor == 0) scale_factor = 1;

    // Perform all necessary steps for all motors

    // If stepper 1 needs to be moved
    if (ds1 - steps_s1 > 0) {

      PWM_steppers(stepPin1, scale_factor);

      steps_s1++;

    }

    // If stepper 2 needs to be moved
    if (ds2 - steps_s2 > 0) {

      PWM_steppers(stepPin2, scale_factor);

      steps_s2++;

    }

    // If stepper 3 needs to be moved
    if (ds3 - steps_s3 > 0) {

      PWM_steppers(stepPin3, scale_factor);

      steps_s3++;

    }

  }

}

void PWM_steppers(const int stepPin, const int scale_factor) {

  // Sends a PWM signal to a certain motor
  // Args:
  // stepPin: Pin number associated with the step terminal of motor driver
  // scale_factor: Scaling how fast the motor moves

  // Write PWM signal
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(stepDelay*scale_factor);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(stepDelay*scale_factor);

}

int check_direction(int ds) {

  // Checks direction of increment through its sign
  // Args:
  // ds: Number of steps of a motor

  if (ds < 0) {

    return 0;

  }

  else if (ds > 0) {

    return 1;

  }

  return 0;

}

void set_direction(const int dirPin, int direction) {

  // Sets the direction of rotation of a motor
  // Args:
  // dirPin: Pin number associated with the dir terminal of motor driver
  // direction: either 0 or 1

  if (direction == 0) {

    digitalWrite(dirPin, LOW);

  }

  else if (direction == 1) {
  
    digitalWrite(dirPin, HIGH);

  }

}

void setup() {

  // Set the Arduino pins

  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin3, OUTPUT);
  pinMode(stepPin3, OUTPUT);
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);
  digitalWrite(dirPin3, LOW);

  // Start serial communications with computer (baud rate of 9600)
  Serial.begin(9600);

}

void loop() {

  // If there is a serial command available
  if (Serial.available()) {

      // Parse signal
      String signal = Serial.readStringUntil('\n');
      signal.trim();

      // Extract the stepper commands
      int ds1 = 0, ds2 = 0, ds3 = 0;
      sscanf(signal.c_str(), "%d,%d,%d", &ds1, &ds2, &ds3);

      // Move steppers
      move_steppers(ds1, ds2, ds3);

  }

}