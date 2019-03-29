/*
 This code makes a sleeping laptop animation for a 3x3x3 LED cube.
 
 The arduino I'm using doesn't have enough PWM pins on it to just use
 analogWrite() on all the pins so I had to do the PWM stuff manually.
 DOING PWM MANUALLY:
    
    * Each on/off cycle is 10 milliseconds long.
     
    * Start off looping through from 0 to 100 (I used 0 to 100
      so I can directly use that as the on/off time percentage)
    
    * Set the time the leds stay on to `percentage/10`,
      the `/10` is coz we want 10ms cycles
    
    * Then set the time the leds stay off to `(100 - percentage)/10`
      the remainder of the cycle.
    
    * Loop again this time from 100 to 0 doing the same thing.


 I'm using multiplexing to drive all the 27 LEDs this cube uses, so:

 * Each vertical column of LEDs has a common anode.
 * Each horizontal plane of LEDs has a common cathode.

 This way if I connect column 1 to power and plane 1 to ground
 the LED at 1,0,0 turns on(read: top corner)

 I'm using digital pins 2 to 7 and analog pins 0 to 5 since the spacing
 of the holes on my perf board doesn't allow me to use pins 8 to 13.

 Author: cautiouspotato
 git repo: https://github.com/sit-on-cushions-we-must/led_cube
 This code is licensed under the MIT license: https://mit-license.org/
*/

// the planes of LEDs
const int plane1 = 7;
const int plane2 = 6;
const int plane3 = 5;

// the columns of LEDs
const int c1 = 4;
const int c2 = 3;
const int c3 = 2;
const int c4 = A0;
const int c5 = A1;
const int c6 = A2;
const int c7 = A3;
const int c8 = A4;
const int c9 = A5;


void setup() {
    // set everything as an output
    pinMode(plane1, OUTPUT);
    pinMode(plane2, OUTPUT);
    pinMode(plane3, OUTPUT);

    pinMode(c1, OUTPUT);
    pinMode(c2, OUTPUT);
    pinMode(c3, OUTPUT);
    pinMode(c4, OUTPUT);
    pinMode(c5, OUTPUT);
    pinMode(c6, OUTPUT);
    pinMode(c7, OUTPUT);
    pinMode(c8, OUTPUT);
    pinMode(c9, OUTPUT);

    // set the plane pins as 'HIGH' first this stops a weird effect where they
    // all go 'LOW' by default and all the LEDs turn on.
    digitalWrite(plane1, HIGH);
    digitalWrite(plane2, HIGH);
    digitalWrite(plane3, HIGH);
}


void loop() {  
    digitalWrite(plane1, LOW);
    digitalWrite(plane2, LOW);
    digitalWrite(plane3, LOW);

    // go from 0 to 100, turn the leds on for "i/10" milliseconds,
    // and turn the leds off for "(100 - i)/10" milliseconds
    for (int i = 0; i <= 100; i++) {
        digitalWrite(c1, HIGH);
	digitalWrite(c2, HIGH);
        digitalWrite(c3, HIGH);
        digitalWrite(c4, HIGH);
        digitalWrite(c5, HIGH);
        digitalWrite(c6, HIGH);
        digitalWrite(c7, HIGH);
        digitalWrite(c8, HIGH);
        digitalWrite(c9, HIGH);
	
        delay(i/10);
	
	digitalWrite(c1, LOW);
	digitalWrite(c2, LOW);
        digitalWrite(c3, LOW);
        digitalWrite(c4, LOW);
        digitalWrite(c5, LOW);
        digitalWrite(c6, LOW);
        digitalWrite(c7, LOW);
        digitalWrite(c8, LOW);
        digitalWrite(c9, LOW);
	
	delay((100 - i)/10);
    }


    // go from 100 to 0, turn the leds on for "i/10" milliseconds,
    // and turn the leds off for "(100 - i)/10" milliseconds
    for (int j = 100; j >= 0; j--) {
	digitalWrite(c1, HIGH);
	digitalWrite(c2, HIGH);
        digitalWrite(c3, HIGH);
        digitalWrite(c4, HIGH);
        digitalWrite(c5, HIGH);
        digitalWrite(c6, HIGH);
        digitalWrite(c7, HIGH);
        digitalWrite(c8, HIGH);
        digitalWrite(c9, HIGH);
	
	delay(j/10);
		
	digitalWrite(c1, LOW);
	digitalWrite(c2, LOW);
        digitalWrite(c3, LOW);
        digitalWrite(c4, LOW);
        digitalWrite(c5, LOW);
        digitalWrite(c6, LOW);
        digitalWrite(c7, LOW);
        digitalWrite(c8, LOW);
        digitalWrite(c9, LOW);
	
	delay((100 - j)/10);
    }
}
