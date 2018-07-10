# washboard-metronome
Arduino controlled servos mounted to a washboard to make a beat with adjustable tempo via a potentiometer.

Sometimes in life it's hard to find a washboard player, so I made my own.

## Components
- Arduino UNO w/ USB power connector
- 2x 9g Servos
- 10k Potentiometer
- *Optional* Knob for potentiometer
- 22 gauge wire
- Small wire nuts
- USB Power Bank
- Washboard
- Fork
- Spoon
- Mounting material (Wood, Screws)

## Build
- Mount one servo so that the arm performs a scratching motion
- Attach the spoon to that servo
- Mount one servo so that the arm performs a tapping motion
- Attach the fork to that servo
- Drill hole in convenient place to add tempo knob (potentiometer)
- Attach potentiometer using super glue
- Once potentiometer is set, put knob over potentiometer

## Wire
- Solder three wires onto potentiometer's +5v, ground, and control wires
- Attach three wires on to each servo's +5v, ground, and control wires
- Join the +5v wires of each servo and the potentiometer with a wire nut. 
- Join the ground wires of each servo and the potentiometer with a wire nut. 
- Attach the scratch servo control wire to digital pin 9
- Attach the tap servo control wire to digital pin 7
- Attach the potentiometer control wire to analog pin 0

## Code
- Download and Install the [Arduino IDE](https://www.arduino.cc/en/Main/Software) on to a computer with a USB port
- Clone this repository
- Open the Washboard.ino file
- Connect the Arduino to the computer and upload the code via the Arduino IDE

## Play
Now that the code has been uploaded, all the Arduino needs is a power source (USB power bank), and it will continue to loop the code listed in the loop() function of the Washboard.ino 
