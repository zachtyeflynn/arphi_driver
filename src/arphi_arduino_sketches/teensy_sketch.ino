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

  digitalWrite(stepPin, HIGH);
  delayMicroseconds(stepDelay*scale_factor);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(stepDelay*scale_factor);

}

void check_limit_switches() {
  
  for (int i = 0; i < 3; ++i) {
    limitSwitches[i].update();
  }

}

void move_steppers(int dj[3]) {

  check_limit_switches();

  int steps_j[] = {0, 0, 0};

  int direction_correction[] = {1, 1, -1};

  int dir[3];
  
  check_direction(dj, dir);

  for (int i = 0; i < 3; i++) {

    set_direction(DIR_PINS[i], dir[i]);

  }

  for (int i = 0; i < 3; i++) {
    
    dj[i] = abs(dj[i]);

  }

  while (dj[0] - steps_j[0] + dj[1] - steps_j[1] + dj[2] - steps_j[2] > 0) {

    int scale_factor = (dj[0] == 0) + (dj[1] == 0) + (dj[2] == 0);

    if (scale_factor == 0) {
      
      scale_factor = 1;

    }

    for (int i = 0; i < 3; i++) {

      if (dj[i] - steps_j[i] > 0) {

        if (!(direction_correction[i]*dir[i] < 0 && limitSwitches[i].read())) {  

          PWM_steppers(STEP_PINS[i], scale_factor);

        }
        
        steps_j[i]++;

      }

    }

  }

}

void check_direction(int dj[3], int dir[3]) {

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

  if (Serial.available()) {

      String signal = Serial.readStringUntil('\n');
      signal.trim();

      int dj1 = 0, dj2 = 0, dj3 = 0;
      sscanf(signal.c_str(), "%d,%d,%d", &dj1, &dj2, &dj3);

      int dj[] = {dj1, dj2, dj3};

      move_steppers(dj);

  }

}
