/*
 This code makes a barrel roll animation for a 3x3x3 LED cube.

 I'm using multiplexing to drive all the 27 LEDs this cube uses, so:

 * Each vertical column of LEDs has a common anode.
 * Each horizontal plane of LEDs has a common cathode.

 This way if I connect column 1 to power and plane 1 to ground 
 the LED at 1,0,0 turns on(read: top corner)

 I'm using digital pins 2 to 7 and analog pins 0 to 5 since the spacing 
 of the holes on my perf board doesn't allow me to use pins 8 to 13.

 this code is not well written, the tilt functions could be 
 made into one function but I'm lazy, so...

  Author: cautiouspotato
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


/*////////////////////////////////////////////////////////////////////////////
 these functions animate the "diagonal" spin, really 
 this is impossible to explain just run it and see what it does.

 to get the desired effect, we rapidly turn on the horizontal rows of
 columns one after the other, and rapidly pull the planes to ground one after
 the other super fast and your brain thinks that they are
 on at the same time: persistence of vision.
*//////////////////////////////////////////////////////////////////////////////

// tilts the plane of lit LEDs to the left
void spinLeft() {

	// this needs to stay animated for about 100 milliseconds
	// so we loop it a bunch of times
	for (int i = 0; i < 10; ++i) {
		/*
		 pull the first plane to ground and 
		 turn on the first horizontal row of columns
		*/
		digitalWrite(plane1, LOW);
		digitalWrite(c1, HIGH);
		digitalWrite(c2, HIGH);
		digitalWrite(c3, HIGH);
		delay(3);
		// turn off the first plane and row of columns.
		digitalWrite(plane1, HIGH);
		digitalWrite(c1, LOW);
		digitalWrite(c2, LOW);
		digitalWrite(c3, LOW);

		/*
		 pull the second plane to ground and 
		 turn on the second horizontal row of columns
		*/
		digitalWrite(plane2, LOW);
		digitalWrite(c4, HIGH);
		digitalWrite(c5, HIGH);
		digitalWrite(c6, HIGH);
		delay(3);
		// turn off the second plane and row of columns.
		digitalWrite(plane2, HIGH);
		digitalWrite(c4, LOW);
		digitalWrite(c5, LOW);
		digitalWrite(c6, LOW);

		/*
		 pull the third plane to ground and 
		 turn on the third horizontal row of columns
		*/
		digitalWrite(plane3, LOW);
		digitalWrite(c7, HIGH);
		digitalWrite(c8, HIGH);
		digitalWrite(c9, HIGH);
		delay(3);
		// turn off the third plane and row of columns.
		digitalWrite(plane3, HIGH);
		digitalWrite(c7, LOW);
		digitalWrite(c8, LOW);
		digitalWrite(c9, LOW);
	}
}

// tilts the plane of lit LEDs to the right
void spinRight() {

	// this needs to stay animated for about 100 milliseconds
	// so we loop it a bunch of times
	for (int i = 0; i < 10; ++i) {
		/*
		 pull the first plane to ground and 
		 turn on the first horizontal row of columns
		*/
		digitalWrite(plane1, LOW);
		digitalWrite(c7, HIGH);
		digitalWrite(c8, HIGH);
		digitalWrite(c9, HIGH);
		delay(3);
		// turn off the first plane and row of columns.
		digitalWrite(plane1, HIGH);
		digitalWrite(c7, LOW);
		digitalWrite(c8, LOW);
		digitalWrite(c9, LOW);

		/*
		 pull the second plane to ground and 
		 turn on the second horizontal row of columns
		*/
		digitalWrite(plane2, LOW);
		digitalWrite(c4, HIGH);
		digitalWrite(c5, HIGH);
		digitalWrite(c6, HIGH);
		delay(3);
		// turn off the second plane and row of columns.
		digitalWrite(plane2, HIGH);
		digitalWrite(c4, LOW);
		digitalWrite(c5, LOW);
		digitalWrite(c6, LOW);

		/*
		 pull the third plane to ground and 
		 turn on the third horizontal row of columns
		*/
		digitalWrite(plane3, LOW);
		digitalWrite(c1, HIGH);
		digitalWrite(c2, HIGH);
		digitalWrite(c3, HIGH);
		delay(3);
		// turn off the third plane and row of columns.
		digitalWrite(plane3, HIGH);
		digitalWrite(c1, LOW);
		digitalWrite(c2, LOW);
		digitalWrite(c3, LOW);
	}
}


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

	// start by turning on all the LEDs on the second plane.
	digitalWrite(plane2, LOW);

	digitalWrite(c1, HIGH);
	digitalWrite(c2, HIGH);
	digitalWrite(c3, HIGH);
	digitalWrite(c4, HIGH);
	digitalWrite(c5, HIGH);
	digitalWrite(c6, HIGH);
	digitalWrite(c7, HIGH);
	digitalWrite(c8, HIGH);
	digitalWrite(c9, HIGH);

	delay(100);
	digitalWrite(plane2, HIGH);

	// tilt the plane of lit LEDs to the left
	spinLeft();

	// light up all the center columns of the cube
	digitalWrite(plane1, LOW);
	digitalWrite(plane2, LOW);
	digitalWrite(plane3, LOW);

	digitalWrite(c4, HIGH);
	digitalWrite(c5, HIGH);
	digitalWrite(c6, HIGH);

	delay(100);
	digitalWrite(plane1, HIGH);
	digitalWrite(plane2, HIGH);
	digitalWrite(plane3, HIGH);

	// tilt the plane of lit LEDs to the right
	spinRight();
}