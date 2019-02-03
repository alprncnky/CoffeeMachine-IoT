# CoffeeMachine-IoT
Coffee maker using with Arduino

I made a automatic coffee maker with arduino. Its getting the data from WebService.
Then its running servo motor and selenoid for pouring coffee to heater.
Its start pumping water which looking for the data coming from Webservice (Is it for 1 person or 2 person?)
Finally its turning on the heater.


YOUTUBE VIDEO:
https://www.youtube.com/watch?v=OyULZ6lz3Js

(Once u connecting to the WebService u can send command anywhere u want. I have a project that recognize my voice and I basically say "make me a coffee" then its sended to arduino.)

I use these for my Project
- Arduino Uno
- Esp8266 Wifi Module
- 12V 2A adaptor (for AC to DC)
- 12V Selenoid motor (for vibrate the pod and helping to pouring coffee)
- 5V Servo motor (open the cover for pouring coffee)
- 5V water pump motor
- 1K Ohm Resistors (2X)
- 1N4001 Diode (2X)
- 5V relay to switch heater electricity.
- LM2596 Step-Down Voltage Regulator(2X)  (One for 12V to 9V used Arduino power the other one for 5V pumping motor and relay)

![In a single picture](https://raw.githubusercontent.com/alprncnky/CoffeeMachine-IoT/master/CoffeeMachinepAİNTED.png)

(This project can be done better with a few extra motors or electronics part)
