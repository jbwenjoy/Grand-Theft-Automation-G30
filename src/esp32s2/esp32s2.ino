/*
    Author:

        @jbwenjoy: Furina de Fontaine
    
    Description: 
    
        This is the main Arduino file for the ESP32-S2 robot.

*/

#include <stdio.h>
#include "esp_log.h"
#include "driver/i2c.h"
#include "sdkconfig.h"

#include "html510.h"

#include "body.h"

#include "behavior.h"

#include "control.h"

// #include "communication.h"

#include "s2_sensors.h"

#include "actions.h"
#include "actions_motor.h"
#include "actions_servo.h"


// actions is a global variable containing: 
// pin definitions, ledc pwm parameters, two motor and two servo objects, 
// and basic actions of specifying motor speeds and servo angles
// This gloabl variable is only for debugging purposes
// In the final version, the actions object should be created in the behavior class
Actions actions = Actions();

// sensors is a global variable containing:
// pin definitions, encoder and vive objects, and sensor readings
Sensors sensors = Sensors();

// behavior is a global variable containing:
// the behavior tree and the action object
Behavior behavior = Behavior();

// communication
// Communication communication = Communication();

void setup() {
    Serial.begin(115200);
}

void loop() {
    // ### Motor Test Code ###
    // should always be commented when not testing
    // should comment all other code when testing
    
    // actions.moveForward(1000);
    // actions.setMotorSpeed(actions.MOTOR_R, 3000);  // right wheel
    // actions.setMotorSpeed(actions.MOTOR_L, 3000);  // left wheel

    sensors.updateEncoder();
    actions.updateActualSpeed(sensors.speed_L, sensors.speed_R);

    // behavior.updateBehaviorClassHTMLVariables(...);
    // behavior.updateBehaviorClassSensorVariables(...);
    // behavior.action.updateHTMLData(...);
    // behavior.action.updateActualSpeed(...);

    // must be called before taking actions that uses PID speed control
    actions.updateActualSpeed(sensors.speed_L, sensors.speed_R);

    actions.turnLeftSamePlace(4000);
    // actions.MOTOR_L.setSpeed(2000);
    // actions.MOTOR_R.setSpeed(-2000);

    Serial.print('\n');
    Serial.print(sensors.speed_L);
    Serial.print('\t');
    Serial.print(sensors.speed_R);
    Serial.print('\t');
    Serial.print(actions.PIDSpeedL);
    Serial.print('\t');
    Serial.print(actions.PIDSpeedR);

    // actions.moveBackward(-2000);
    
    // sensors.updateVive();
    // Serial.print('\n');
    // Serial.print(sensors.vive1_x);
    // Serial.print('\t');
    // Serial.print(sensors.vive1_y);
    // Serial.print('\t');
    // Serial.print(sensors.vive2_x);
    // Serial.print('\t');
    // Serial.print(sensors.vive2_y);

    delay(50);

    // ### Main Code ###
    // should comment all other test code when using

    // website cmd checking and global variables updating
    

    // sensor reading and global variables updating
    sensors.updateEncoder();
    sensors.updateVive();
    // behavior.updateBehaviorClassHTMLVariables(html_state, html_manual_direction, html_if_jaw_open, html_speed, html_turn_rate);
    // behavior.updateBehaviorClassSensorVariables(tof_front, tof_left,
    //                                             sensors.vive_x_mm, sensors.vive_y_mm, sensors.vive_theta, 
    //                                             police_x_mm, police_y_mm, trophy_direction);

    


    // run behavior tree, generate action list

    // 

}
