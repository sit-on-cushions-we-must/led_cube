# LED cube 

My goal for this was to make a neat LED cube "shield" for an Arduino UNO so it plugs straight into
the Arduino 

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
plane have a common ground pin, and all the LEDs in a column have a common power pin.
This gives me 3 ground pins and 9 power pins.
To turn on an LED you just give it's column power and pull it's plane to ground.

This picture illustrates the connections of a single vertical "layer?" of the cube:

![LED_connections](https://aaalearn.mystagingwebsite.com/wp-content/uploads/2018/05/led_connections.png)

The lines highlighted in red are the anodes and the ones in blue are the cathodes.


The Arduino can only deliver about 20 milliamp of power from each pin, that's just enough
to power 3 LEDs, so if you connect all the LEDs on a plane to a common power pin and all the 
LEDs in a column to a common ground pin the Arduino will not be able to light up all the LEDs.