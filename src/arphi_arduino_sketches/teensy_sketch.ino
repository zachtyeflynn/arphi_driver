#include <Bounce2.h>

///////////////////////////////////////////////////////////////////////////////
// Physical Params
///////////////////////////////////////////////////////////////////////////////

// Step pins on teensy board
const int STEP_PINS[] = {0, 2, 4};
// Dir pins on teensy board
const int DIR_PINS[] = {1, 3, 5};
// Limit switch pins on teensy board
const int LIMIT_PINS[] = {26, 27, 28};
// Limit switch objects
Bounce2::Button limitSwitches[3];

// Constants
const int stepDelay = 100; // microseconds, tune for your motors
const int DEBOUNCE_INTERVAL = 10; // ms
const bool LIMIT_SWITCH_HIGH[3] = {true, true, true}; // adjust if NC/NO wiring differs

///////////////////////////////////////////////////////////////////////////////
// Functions
///////////////////////////////////////////////////////////////////////////////

void PWM_steppers(const int stepPin, const int scale_factor) {

  // Sends a PWM signal to a certain motor
  // Args:
  // stepPin: Pin number associated with the step terminal of motor driver
  // scale_factor: Scaling how fast the motor moves

  digitalWrite(stepPin, HIGH);
  delayMicroseconds(stepDelay*scale_factor);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(stepDelay*scale_factor);

}

void check_limit_switches() {

  // Check the state of the limit switches
  
  for (int i = 0; i < 3; ++i) {
    limitSwitches[i].update();
  }

}

void move_steppers(int dj[3]) {

  // Concurrent function which simultaneously moves all joints at once, if necessary
  // Args:
  // dj[3]: Array containing the number of steps each joint should move

  // Check the state of the limit switches
  check_limit_switches();

  // Number of steps the joints have taken so far
  int steps_j[] = {0, 0, 0};

  // Correct for the joint direction anamoly in joint 3
  int direction_correction[] = {1, 1, -1};

  // Instantiate direction array (storing in which direction every joint should move)
  int dir[3];
  
  // Check which direction the joints should move
  check_direction(dj, dir);

  // Set the direction of the joints
  for (int i = 0; i < 3; i++) {

    set_direction(DIR_PINS[i], dir[i]);

  }

  // Absolute value
  for (int i = 0; i < 3; i++) {
    
    dj[i] = abs(dj[i]);

  }

  // While there are still steps to perform, do:
  while (dj[0] - steps_j[0] + dj[1] - steps_j[1] + dj[2] - steps_j[2] > 0) {

    // Scale factor determines by how much you need to multiply the step velocity depending on how many steppers are moving at once
    int scale_factor = (dj[0] == 0) + (dj[1] == 0) + (dj[2] == 0);
    if (scale_factor == 0) {
      
      scale_factor = 1;

    }

    // Perform all necessary steps for all motors

    for (int i = 0; i < 3; i++) {

      if (dj[i] - steps_j[i] > 0) {

        // If the limit switch is activated, then do not allow any motion in the direction of the limit switch
        if (!(direction_correction[i]*dir[i] < 0 && limitSwitches[i].read())) {  

          PWM_steppers(STEP_PINS[i], scale_factor);

        }
        
        steps_j[i]++;

      }

    }

  }

}

void check_direction(int dj[3], int &dir[3]) {

  // Checks direction of all motors based on increment sign
  // Args:
  // dj[3]: Array containing the number of steps every joint should move
  // dir[3] (passed by reference): Set the directions in the array

  for (int i = 0; i < 3; i++) {

    dir[i] = 0;

    if (dj[i] < 0) {

      dir[i] = -1;

    } else if (dj[i] > 0) {

      dir[i] = 1;

    }

  }
  
}

void set_direction(const int dirPin, int direction) {

  // Sets the direction of rotation of a motor
  // Args:
  // dirPin: Pin number associated with the dir terminal of motor driver
  // direction: either 0 or 1

  if (direction <= 0) {

    digitalWrite(dirPin, LOW);

  } else {

    digitalWrite(dirPin, HIGH);  // forward

  }

}

void setup() {

  // Initialize step, dir and limit pins on teensy board
  for (int i = 0; i < 3; i++) {

    pinMode(STEP_PINS[i], OUTPUT);
    pinMode(DIR_PINS[i], OUTPUT);
    pinMode(LIMIT_PINS[i], INPUT);

  }

  // Set limit switch pins
  for (int i = 0; i < 3; ++i) {
    limitSwitches[i] = Bounce2::Button();
    limitSwitches[i].attach(LIMIT_PINS[i], INPUT);
    limitSwitches[i].interval(DEBOUNCE_INTERVAL);
    limitSwitches[i].setPressedState(LIMIT_SWITCH_HIGH[i]);
  }

  // Start serial communications at baud rate 115200
  Serial.begin(115200);

}

void loop() {

  // If there is a serial command available
  if (Serial.available()) {

      // Parse signal
      String signal = Serial.readStringUntil('\n');
      signal.trim();

      // Extract the stepper commands
      int dj1 = 0, dj2 = 0, dj3 = 0;
      sscanf(signal.c_str(), "%d,%d,%d", &dj1, &dj2, &dj3);

      int dj[] = {dj1, dj2, dj3};

      // Move steppers
      move_steppers(dj);

  }

}
