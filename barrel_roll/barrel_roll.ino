/*
 This code makes a barrel roll animation for a 3x3x3 LED cube.

 I'm using multiplexing to drive all the 27 LEDs this cube uses, so:

 * Each vertical column of LEDs has a common anode.
 * Each horizontal plane of LEDs has a common cathode.

 This way if I connect column 1 to power and plane 1 to ground 
 the LED at 1,0,0 turns on(read: top corner)

 I'm using digital pins 2 to 7 and analog pins 0 to 5 since the spacing 
 of the holes on my perf board doesn't allow me to use pins 8 to 13.
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


void spin1() {
	
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

	spin1();
}