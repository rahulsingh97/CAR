## motor driver control.ino
uses a IR remote to comunicate with the LM293D drives to move the car `forword`, `backward`, `right`, `left` and `stop`
issue detcted sometimes `FFFFFFFF` is picked up by the IR reciver and everything just stops working and this also stops the code from working if the button is pressed

- [x] Fixed the `FFFFFFFF` thing

## code to remove FFFFFFFF.ino
this code is made to remove the biggest issue that was `random value` caught up by the reciver and also removes `FFFFFFFF` by repeating the last stable value until a known value is found

## car basic controls.ino
here im able to controle the car with a IR remote we can perform acctions like `forword`, `backward`, `right`, `left` without the worry of IR issues

#### Microprocessor
Microprocessor is an IC which has only the CPU inside them i.e. only the processing powers such as Intel's Pentium 1,2,3,4, core 2 duo, i3, i5 etc. ... Microcontroller has a CPU, in addition with a fixed amount of RAM, ROM and other peripherals all embedded on a single chip.

#### motor driver l239d
motor driver l239d - The L293 and L293D devices are quadruple high current half-H drivers. The L293 is designed to provide bidirectional drive currents of up to 1 A at voltages from 4.5 V to 36 V. The L293D is designed to provide bidirectional drive currents of up to 600-mA at voltages from 4.5 V to 36 V. Both devices are designed to drive inductive loads such as relays, solenoids, DC and bipolar stepping motors, as well as other high-current/high-voltage loads in positive supply applications.

#### nodemcu
nodemcu - NodeMCU is an open source LUA based firmware developed for ESP8266 Wi-Fi chip. By exploring functionality with ESP8266 chip, NodeMCU firmware comes with ESP8266 Development board/kit i.e. NodeMCU Development board. Since NodeMCU is open source platform, their hardware design is open for edit/modify/build.

#### ultrasonic sensor
ultrasonic sensor - Ultrasonic ranging module HC - SR04 provides 2cm - 400cm non-contact measurement function, the ranging accuracy can reach to 3mm. The modules include ultrasonic transmitters, receiver and control circuit.

#### arduino nano
arduino nano - The Arduino Nano is a small, complete, and breadboard-friendly board based on the ATmega328 (Arduino Nano 3.x). It has more or less the same functionality of the Arduino Duemilanove, but in a different package. It lacks only a DC power jack, and works with a Mini-B USB cable instead of a standard one.

#### android studio
android studio - Android Studio is the official Integrated Development Environment (IDE) for Android app development, based on IntelliJ IDEA . On top of IntelliJ's powerful code editor and developer tools, Android Studio offers even more features that enhance your productivity when building Android apps,

#### arduino ide
arduino ide - The Arduino Integrated Development Environment (IDE) is a cross-platform application (for Windows, macOS, Linux) that is written in functions from C and C++]. It is used to write and upload programs to Arduino compatible boards, but also, with the help of 3rd party cores, other vendor development boards.

#### hive mqtt server
hive mqtt server - IoT applications can generate a LOT of data. It is critical to select a technology that is designed to move IoT data across networks and cloud platforms. HiveMQ's MQTT broker is designed for cloud native deployments to make optimal use of cloud resources. It's use of MQTT reduces network bandwidth required for moving data. Efficient IoT solutions mean lower total costs of operation.
