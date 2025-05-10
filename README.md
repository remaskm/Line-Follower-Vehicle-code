# Line Follower Robot with Obstacle Avoidance

This Arduino project combines IR sensors and an ultrasonic sensor to create a line-following robot that can also avoid obstacles by stopping when an object is detected. The robot uses motor control to navigate and adjust its path based on sensor readings.

## Features

* **Line Following**: The robot uses six IR sensors (three front, three rear) to detect the line and follow it.
* **Obstacle Detection**: The ultrasonic sensor detects objects within 20 cm and stops the robot if an obstacle is detected.
* **Motor Control**: The robot can move forward, turn left or right, and stop based on sensor input.
* **Speed Control**: The robot adjusts its speed depending on the detected environment, such as turning or moving straight.

## Requirements

* **Hardware**:

  * Arduino Uno (or any compatible Arduino board)
  * 2 DC motors with a motor driver (e.g., L298N)
  * 6 IR sensors (3 front and 3 rear)
  * Ultrasonic sensor (HC-SR04)
  * Jumper wires
  * Power supply for Arduino and motors

* **Software**:

  * Arduino IDE (to upload the code)
  * Arduino libraries for motor control (if necessary, like `AFMotor` for motor shield)

## Setup Instructions

1. **Connect the Motors**: Connect the two motors to the motor driver pins. Use PWM pins for speed control.
2. **Wiring the IR Sensors**: Connect the 6 IR sensors to the appropriate digital pins on your Arduino.
3. **Ultrasonic Sensor**: Wire the ultrasonic sensor to the `trig` and `echo` pins for distance measurements.
4. **Upload Code**: Open the provided code in the Arduino IDE, select the appropriate board and port, and upload it to the Arduino.
5. **Powering Up**: After uploading, power up the robot with an appropriate power source.

## How It Works

1. **Line Following**: The IR sensors detect whether the robot is over the line. Based on the input, the robot adjusts the motors to follow the path.
2. **Obstacle Avoidance**: The ultrasonic sensor continuously checks for obstacles in front of the robot. If an object is detected within 20 cm, the robot will stop.
3. **Turning**: The robot makes turns based on sensor readings from the IR sensors, adjusting its direction accordingly.

## Example Use Case

1. **Forward Movement**: When the line is detected, the robot moves forward with both motors powered.
2. **Turn Right/Left**: When the robot detects a need to change direction (e.g., based on the line path or sensor input), it will rotate the motors in opposite directions.
3. **Obstacle Detection**: If the ultrasonic sensor detects an object within 20 cm, the robot will immediately stop all motors to avoid a collision.

## Example Code Flow

```cpp
// Ultrasonic distance check
if (distance < 20) {
    // Stop the robot when an obstacle is detected
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
} else {
    // Continue line following and obstacle avoidance logic
    // Adjust motor speeds and directions based on IR sensor input
}
```

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

* [Arduino](https://www.arduino.cc/) for their open-source hardware and software.
* [HC-SR04 Ultrasonic Sensor](https://www.electronicwings.com/arduino/hc-sr04-ultrasonic-sensor) for object detection.
* [IR Sensors](https://www.electronicwings.com/arduino/ir-sensor) for line following functionality.

