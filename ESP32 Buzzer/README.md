# Simple Motion Sensor ESP32 Buzzer with LED indicators

#TODO: final picture

I designed a simple buzzer with a red LED indicators and motion sensor. It is intended to light up RED when a motion is detected, with a buzzing sound.

## Resources

- [ESP32 board by diymore ](https://www.amazon.fr/dp/B0BS6R68H6?psc=1&ref=ppx_yo2ov_dt_b_product_details)
- Active buzzer (the standard cylindrical arduino version will do)
- Red LED x1
- Motion sensor x 1
- 220-ohm resistor x 1
- 1K-ohm resistor x 1
- 2N2222A transistor x 1 (NPN)
- Jumper wires and breadboard

If you plan on soldering the final project:

- [a 3x7 cm PCB](!https://www.amazon.fr/gp/product/B073W78G8J/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- a soldering iron and soldering material

For the 3D printed design:

- strong glue
- [5x3mm magnets x 4](!https://www.amazon.fr/gp/product/B0C9WQYZ27/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- electrical wires
- female to male jumper cables (we will cut the ends to connect to the PCB)

## 3D Printing

#TODO: complete

## Wiring

Wiring the ESP32 to the IR Sensor:

_ESP32 -> IR Sensor_
<br/>
D13 -> OUT
<br/>
GND -> GND
<br/>
VIN -> VCC
<br/>

Wiring the LED and Active buzzer to the ESP32:

![Circuit diagram](images/circuit_diagram.png)
<br/>
The are only 2 GND GPIO pins on the ESP32 board, we therefore have to share one between the LED and the buzzer.

This is the prototype version of the circuit before it was soldered together on a PCB.
![POC breadboard 1](images/breadboard_1.jpg)
![POC breadboard 2](images/breadboard_2.jpg)

**NOTE: you can calibrate the sensitivity of the IR sensor by turning the blue trim-post distance adjuster**

#TODO: add PCB version

## Assembly

#TODO: complete

## Software

The software is quite straightforward, it will:

At setup:

- Initialise the onboard LED
- Initialise the red LED
- Initialise the buzzer pin

On a loop:

- Turn the onboard led on
- Read the IR sensor data
- If there is a proximity (value 0) reading, turn the red LED on and activate the buzzer
- If there is NO proximity (value 1) reading, turn the red LED off and deactivate the buzzer
- Turn the onboard led off
- Wait 1 second

_There are comments in the code to help explain the key elements_

## Future improvements

#TODO: complete

## Useful links

- [ESP32 Buzzer](https://www.youtube.com/watch?v=TcH8Bx9yC7Q)
- [2N222A datasheet](https://components101.com/transistors/2n2222a-pinout-equivalent-datasheet)
- [IR Sensor and ESP32](https://techatronic.com/ir-sensor/)
