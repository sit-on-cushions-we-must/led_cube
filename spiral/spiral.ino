/*
 This code makes a spiraling animation for a 3x3x3 LED cube.

 I'm using multiplexing to drive all the 27 LEDs this cube uses, so:

 * Each vertical column of LEDs has a common anode.
 * Each horizontal plane of LEDs has a common cathode.

 This way if I connect column 1 to power and plane 1 to ground 
 the LED at 1,0,0 turns on(read: top corner)

 I'm using digital pins 2 to 7 and analog pins 0 to 5 since the spacing 
 of the holes on my perf board doesn't allow me to use pins 8 to 13.

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

/*
 To make the spiral effect we turn on the LEDs on the edge of the top 
 plane one after the other, then we do the same thing on the second 
 plane, then the third, and to spiral back up the cube we start on the third plane,
 then go to the second, then the first.
*/

void loop() {

	///////////////////////////////////////////////
	// spiral down the cube
	///////////////////////////////////////////////

	// circle round the first plane
	digitalWrite(plane1, LOW);

	digitalWrite(c1, HIGH);
	delay(100);
	digitalWrite(c1, LOW);
	digitalWrite(c2, HIGH);
	delay(100);
	digitalWrite(c2, LOW);
	digitalWrite(c3, HIGH);
	delay(100);
	digitalWrite(c3, LOW);
	digitalWrite(c6, HIGH);
	delay(100);
	digitalWrite(c6, LOW);
	digitalWrite(c9, HIGH);
	delay(100);
	digitalWrite(c9, LOW);
	digitalWrite(c8, HIGH);
	delay(100);
	digitalWrite(c8, LOW);
	digitalWrite(c7, HIGH);
	delay(100);
	digitalWrite(c7, LOW);
	digitalWrite(c4, HIGH);
	delay(100);
	digitalWrite(c4, LOW);

	digitalWrite(plane1, HIGH);

	// circle round the second plane
	digitalWrite(plane2, LOW);

	digitalWrite(c1, HIGH);
	delay(100);
	digitalWrite(c1, LOW);
	digitalWrite(c2, HIGH);
	delay(100);
	digitalWrite(c2, LOW);
	digitalWrite(c3, HIGH);
	delay(100);
	digitalWrite(c3, LOW);
	digitalWrite(c6, HIGH);
	delay(100);
	digitalWrite(c6, LOW);
	digitalWrite(c9, HIGH);
	delay(100);
	digitalWrite(c9, LOW);
	digitalWrite(c8, HIGH);
	delay(100);
	digitalWrite(c8, LOW);
	digitalWrite(c7, HIGH);
	delay(100);
	digitalWrite(c7, LOW);
	digitalWrite(c4, HIGH);
	delay(100);
	digitalWrite(c4, LOW);

	digitalWrite(plane2, HIGH);

	// circle round the third plane
	digitalWrite(plane3, LOW);

	digitalWrite(c1, HIGH);
	delay(100);
	digitalWrite(c1, LOW);
	digitalWrite(c2, HIGH);
	delay(100);
	digitalWrite(c2, LOW);
	digitalWrite(c3, HIGH);
	delay(100);
	digitalWrite(c3, LOW);
	digitalWrite(c6, HIGH);
	delay(100);
	digitalWrite(c6, LOW);
	digitalWrite(c9, HIGH);
	delay(100);
	digitalWrite(c9, LOW);
	digitalWrite(c8, HIGH);
	delay(100);
	digitalWrite(c8, LOW);
	digitalWrite(c7, HIGH);
	delay(100);
	digitalWrite(c7, LOW);
	digitalWrite(c4, HIGH);
	delay(100);
	digitalWrite(c4, LOW);

	digitalWrite(plane3, HIGH);

  ///////////////////////////////////////////////
	// spiral up the cube
	///////////////////////////////////////////////

	// circle round the third plane
	digitalWrite(plane3, LOW);

	digitalWrite(c1, HIGH);
	delay(100);
	digitalWrite(c1, LOW);
	digitalWrite(c2, HIGH);
	delay(100);
	digitalWrite(c2, LOW);
	digitalWrite(c3, HIGH);
	delay(100);
	digitalWrite(c3, LOW);
	digitalWrite(c6, HIGH);
	delay(100);
	digitalWrite(c6, LOW);
	digitalWrite(c9, HIGH);
	delay(100);
	digitalWrite(c9, LOW);
	digitalWrite(c8, HIGH);
	delay(100);
	digitalWrite(c8, LOW);
	digitalWrite(c7, HIGH);
	delay(100);
	digitalWrite(c7, LOW);
	digitalWrite(c4, HIGH);
	delay(100);
	digitalWrite(c4, LOW);

	digitalWrite(plane3, HIGH);

	// circle round the second plane
	digitalWrite(plane2, LOW);

	digitalWrite(c1, HIGH);
	delay(100);
	digitalWrite(c1, LOW);
	digitalWrite(c2, HIGH);
	delay(100);
	digitalWrite(c2, LOW);
	digitalWrite(c3, HIGH);
	delay(100);
	digitalWrite(c3, LOW);
	digitalWrite(c6, HIGH);
	delay(100);
	digitalWrite(c6, LOW);
	digitalWrite(c9, HIGH);
	delay(100);
	digitalWrite(c9, LOW);
	digitalWrite(c8, HIGH);
	delay(100);
	digitalWrite(c8, LOW);
	digitalWrite(c7, HIGH);
	delay(100);
	digitalWrite(c7, LOW);
	digitalWrite(c4, HIGH);
	delay(100);
	digitalWrite(c4, LOW);

	digitalWrite(plane2, HIGH);

	// circle round the first plane
	digitalWrite(plane1, LOW);

	digitalWrite(c1, HIGH);
	delay(100);
	digitalWrite(c1, LOW);
	digitalWrite(c2, HIGH);
	delay(100);
	digitalWrite(c2, LOW);
	digitalWrite(c3, HIGH);
	delay(100);
	digitalWrite(c3, LOW);
	digitalWrite(c6, HIGH);
	delay(100);
	digitalWrite(c6, LOW);
	digitalWrite(c9, HIGH);
	delay(100);
	digitalWrite(c9, LOW);
	digitalWrite(c8, HIGH);
	delay(100);
	digitalWrite(c8, LOW);
	digitalWrite(c7, HIGH);
	delay(100);
	digitalWrite(c7, LOW);
	digitalWrite(c4, HIGH);
	delay(100);
	digitalWrite(c4, LOW);

	digitalWrite(plane1, HIGH);
}