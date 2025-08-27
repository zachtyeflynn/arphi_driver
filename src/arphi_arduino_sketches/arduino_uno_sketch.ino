// Pin outputs on arduino nano
const int stepPin1 = 2;
const int dirPin1 = 3;
const int stepPin2 = 4;
const int dirPin2 = 5;
const int stepPin3 = 8;
const int dirPin3 = 9;

unsigned long int stepDelay = 2000;
const int steps_per_rev = 200;
// RPM = (Keyboard Command Refresh Rate (Hz))*(Steps per Key)/(Motor Steps Per Rev)*60
const unsigned int RPM = (30UL * 60UL) / 200;

unsigned long delay_ms_RPM(const int RPM, const int steps_per_rev) {

  return (60UL * 1000000)/(steps_per_rev*2UL*RPM);

}

void move_steppers(int dq1, int dq2, int dq3) {

  int steps_q1 = 0;
  int steps_q2 = 0;
  int steps_q3 = 0;

  set_direction(dirPin1, check_direction(dq1));
  set_direction(dirPin2, check_direction(dq2));
  set_direction(dirPin3, check_direction(dq3));

  dq1 = abs(dq1);
  dq2 = abs(dq2);
  dq3 = abs(dq3);

  while (dq1 - steps_q1 + dq2 - steps_q2 + dq3 - steps_q3 > 0) {

    int scale_factor = (dq1 == 0) + (dq2 == 0) + (dq3 == 0);
    if (scale_factor == 0) scale_factor = 1;

    if (dq1 - steps_q1 > 0) {

      PWM_steppers(stepPin1, scale_factor);

      steps_q1++;

    }

    if (dq2 - steps_q2 > 0) {

      PWM_steppers(stepPin2, scale_factor);

      steps_q2++;

    }

    if (dq3 - steps_q3 > 0) {

      PWM_steppers(stepPin3, scale_factor);

      steps_q3++;

    }

  }

}

void PWM_steppers(const int stepPin, const int scale_factor) {

  digitalWrite(stepPin, HIGH);
  delayMicroseconds(stepDelay*scale_factor);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(stepDelay*scale_factor);

}

int check_direction(int dq) {

  if (dq < 0) {

    return 0;

  }

  else if (dq > 0) {

    return 1;

  }

  return 0;

}

void set_direction(const int dirPin, int direction) {

  if (direction == 0) {

    digitalWrite(dirPin, LOW);

  }

  else if (direction == 1) {
  
    digitalWrite(dirPin, HIGH);

  }

}

void setup() {

  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin3, OUTPUT);
  pinMode(stepPin3, OUTPUT);
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);
  digitalWrite(dirPin3, LOW);

  Serial.begin(9600);

  stepDelay = delay_ms_RPM(RPM, steps_per_rev);

}

void loop() {

  if (Serial.available()) {

      String signal = Serial.readStringUntil('\n');
      signal.trim();

      int dq1 = 0, dq2 = 0, dq3 = 0;
      sscanf(signal.c_str(), "%d,%d,%d", &dq1, &dq2, &dq3);

      move_steppers(dq1, dq2, dq3);

  }

}