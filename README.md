:Author: saviour Dagadu
:Email: {senamdagadusaviour@gmail.com}
:Date: 10/08/2023
:Revision: v1.4
:License: Public Domain

Project: {Solar-based Alcohol detector}

----------------------------------------------------Descripon--------------------------------------------------------------

The solar-based alcohol breath detector system described in the provided code operates as a comprehensive tool designed to assess 
the alcohol content in a person's breath and convey the results in a clear and informative manner. This innovative device incorporates 
various components and functionalities to achieve its intended purpose while utilizing solar energy for sustainable operation.

At its core, the system employs an ATmega328P microcontroller to orchestrate the entire process. 
The detection process hinges on the MQ-3 gas sensor, a fundamental element that senses the alcohol content in the exhaled breath. 
This sensor generates an analog voltage signal proportional to the alcohol concentration detected, allowing the microcontroller 
to interpret the magnitude of alcohol presence.

The LCD (Liquid Crystal Display) is a crucial visual interface, where the detected alcohol levels and related information are displayed. 
A LiquidCrystal_I2C library is utilized to interface with the LCD via an I2C communication protocol. 
The display not only conveys real-time alcohol levels but also provides guidance during the system's warm-up period, 
ensuring accurate readings are obtained once the sensor is calibrated.

To ensure reliable and accurate readings, the system incorporates a warm-up phase during which the sensor stabilizes. 
This warm-up duration is indicated on the LCD, reassuring the user that the device is preparing to deliver precise results. 
After the warm-up phase, the microcontroller retrieves the alcohol content from the MQ-3 sensor, processes it, and categorizes 
the user's condition based on preset alcohol level thresholds.

The system employs a set of LED indicators in various colors, each denoting a specific alcohol concentration range. 
Green LEDs signify sobriety, yellow LEDs indicate mild alcohol consumption, and red LEDs signify higher levels of intoxication.
By implementing different blinking rates for the LEDs, the system enhances the visual impact, reflecting the severity of the situation. 
Moreover, a buzzer is incorporated, emitting distinct tones when alcohol levels surpass a certain threshold, providing an auditory warning to the user.

A notable feature of this system is its energy efficiency achieved through solar power. 
By utilizing a solar panel, the system can harvest and store energy from the sun, ensuring prolonged 
and sustainable operation without the need for frequent battery replacements or external power sources.




== Step 1: Installation
Please describe the steps to install this project.

For example:

1. Open this file
2. Edit as you like
3. Release to the World!

== Step 2: Assemble the circuit


Assemble the circuit following the diagram layout.png attached to the sketch

== Step 3: Load the code

Upload the code contained in this sketch on to your board

=== Folder structure

....
 sketch123                => Arduino sketch folder
  ├── sketch123.ino       => main Arduino file
  ├── schematics.png      => (optional) an image of the required schematics
  ├── layout.png          => (optional) an image of the layout
  └── ReadMe.adoc         => this file
....

=== License
This project is released under a {License} License.

=== Contributing
To contribute to this project please contact saviourbot https://id.arduino.cc/saviourbot

=== BOM
Add the bill of the materials you need for this project.

|===
| ID | Part name      | Part number | Quantity
| R1 | 10k Resistor   | 1234-abcd   | 10
| L1 | Red LED        | 2345-asdf   | 5
| A1 | Arduino Zero   | ABX00066    | 1
|===


=== Help
This document is written in the _AsciiDoc_ format, a markup language to describe documents.
If you need help you can search the http://www.methods.co.nz/asciidoc[AsciiDoc homepage]
or consult the http://powerman.name/doc/asciidoc[AsciiDoc cheatsheet]
