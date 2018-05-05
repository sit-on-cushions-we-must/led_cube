# LED cube 

My goal for this was to make a neat LED cube "shield" for an Arduino UNO so it plugs straight into
the Arduino.

The shield plugs into analog pins 0 to 5 and digital pins 2 to 7 on the Arduino, i couldn't use
digital pins 8 to 13 as the spacing of pins on the Arduino and perf board wouldn't match.

# The hardware

You'll need to have moderate soldering skills and about 2 to 3 hours to build this.

**Parts:**

* 27 LEDs, Use diffused LEDs not clear ones, if you use the clear
  ones any the LEDs above them will [look like they] light up with them, ghosting basically.

* Three 2k resistors.

* An Arduino.

* A piece of perf board big enough to fit your cube.

* A strip of 12 male headers, [like this.](https://duckduckgo.com/?q=male+headers&t=ffab&atb=v100-7&iax=images&ia=images&iai=http%3A%2F%2Fktechnics.com%2Fwp-content%2Fuploads%2F2016%2F02%2F1x26_male_pin.jpg)

* Wires.

## Wiring

So the cube has 27 LEDs in a configuration of 9 vertical columns by 3 horizontal planes.
To drive all those LEDs I used multiplexing (like everyone else), so all the LEDs on a 
plane have a common ground pin (cathode), and all the LEDs in a column have a common power pin (anode).
This gives me 3 ground pins and 9 power pins.
To turn on an LED you just give it's column power and pull it's plane to ground.

This picture illustrates the connections of a single vertical "layer?" of the cube:

![LED_connections](https://aaalearn.mystagingwebsite.com/wp-content/uploads/2018/05/led_connections.png)

The lines highlighted in red are the anodes and the ones in blue are the cathodes.

For the whole cube it looks like this:

![cube_connections](https://aaalearn.mystagingwebsite.com/wp-content/uploads/2018/05/cube_side.png)


The Arduino can only deliver about 20 milliamp of power from each pin, that's just enough
to power 3 LEDs, so if you connect all the LEDs on a plane to a common power pin and all the 
LEDs in a column to a common ground pin the Arduino will not be able to light up all the LEDs.

Use these charts to wire the LEDs:

Arduino      |      LED planes
-------------|------------------
Digital pin7 |      plane 1
Digital pin6 |      plane 2
Digital pin5 |      plane 3


Arduino      |      LED columns
-------------|------------------
Digital pin4 |      column 1
Digital pin3 |      column 2
Digital pin2 |      column 3
Analog pin0  |      column 4
Analog pin1  |      column 5
Analog pin2  |      column 6
Analog pin3  |      column 7
Analog pin4  |      column 8
Analog pin5  |      column 9

The LEDs run at 3 volts but the Arduino UNO delivers 5 volts through it's pins, 
so to regulate it to 3 volts connect each LED plane to it's pin with a 2k resistor.

**Diagram:**

![wiring](https://aaalearn.mystagingwebsite.com/wp-content/uploads/2018/05/led_cube_wiring.png)

## Making the shield part:

Solder the male header pins onto the perf board so they plug into the Arduinos analog pins 0 to 5 
and digital 2 to 7:

![headers](https://aaalearn.mystagingwebsite.com/wp-content/uploads/2018/05/sheild_headers.png)

The pins that plug into each other are highlighted with matching colors.

Send the pins of the cube through the holes on the perf board and use wires to connect the 
pins from the cube to the corresponding pins on the headers.

## notes on making animations for the cube

Since I'm using an Arduino all the animations are written in c++ for the Arduino.

The pins driving the cube have to be set to low at the beginning of the program, otherwise 
when the cube is powered on all the LEDs light up, to fix that put the following
code at the end of the `void setup()` function:

```
digitalWrite(plane1, HIGH);
digitalWrite(plane2, HIGH);
digitalWrite(plane3, HIGH);
```

That will make the ground pins for the planes go to the same voltage as the column pins and the
LEDs wont light up right when you power on the board.

## Licensing

All the code and documentation in this repository is licensed under the MIT license which can be found here: https://mit-license.org/

All the pictures for this project are licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.

<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.