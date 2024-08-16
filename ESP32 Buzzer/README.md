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
- SUNLU PLA

## 3D case and soldering considerations

The buzzer is intended for indoor use, we therefore do not need a waterproof design.
<br/>
However, we needed a design:

- that made the RED led visible.
- that did not obstruct the sound from the buzzer.
- that hid the ESP32 board.
- that left enough space for a long charging cable if necessary.
- that was small enough to be discreet and stick around a door.
- that did not obstruct the IR sensors but hid the connected board.
- where the ESP32 board would be placed upside down in order to have the GPIO pins facing upwards, the PCB board facing downwards (to avoid cabled going in every direction, particularly over the PCB). The length of the cables might be an issue, but we could tidy them up afterwards with cable holders or by shortening them, soldering the ends and covering them with thermal duct.
- with an accessible lid: the calibration of the distance of the IR sensor should be flexible, based on where the final project is placed.
- with a removable lid: using magnets should keep the lid closed if the case ends up being upside down.
- with a modular place for the sensor for flexibility
- with a modular place for the esp32 board rotation for flexibility

This time I decided to use Blender to design the case. Although Fusion 360 is a better tool solution for this kind of low-tolerance build, my experience with that tool wasn't sufficient to get a quick prototype working.

The original sketches are available below.

<img src="images/sketch_1.jpg" height="500" />
<img src="images/sketch_2.jpg" height="500" />
<img src="images/sketch_3.jpg" height="500" />

## 3D Printing instructions

The files to 3D print are available in `.stl` format in the "3d" folder. There are two parts to this print: the main case and the lid.

I printed the case in PLA but it can easily be printed in ABS or PETG too. The below settings apply to PLA (from SUNLU).

The lid should be printed with the holes facing upwards to avoid having to fill them and remove the supports.

Infill: 20%
Print speed: 80mm/s
Support pattern: Gyroid
Support: everywhere, line pattern
Nozzle temperature: 210 degrees Celsius
Bed temperature: 60 degrees Celsius

Removing the supports once the print is completed can be tricky, I recommend you start with the outside-facing supports and move inwards.

The total print time was 8h24m with approximately 82g (Cura slicer indicator) of filament.

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

Below is the soldered PCB version for reference. I did not solder the connections to the ESP32 GPIOs or the IR sensor GPIOs.
![POC breadboard 2](images/pcb_1.jpg)
![POC breadboard 2](images/pcb_2.jpg)

## Assembly

#TODO: complete
#TODO add to thingiverse (with pictures) once print and assembly complete

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

- Rounded edges for the case (the current topology has to be updated, the bevel should have been applied before setting holes in the base structure)

- Improve the overall design of the case, preferable using software like Fusion 360.

## Useful links

- [ESP32 Buzzer](https://www.youtube.com/watch?v=TcH8Bx9yC7Q)
- [2N222A datasheet](https://components101.com/transistors/2n2222a-pinout-equivalent-datasheet)
- [IR Sensor and ESP32](https://techatronic.com/ir-sensor/)
