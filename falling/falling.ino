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

	//leave the column on
	digitalWrite(c1, HIGH);

	// turn them on one after the other
	digitalWrite(plane1, LOW);
	delay(200);
	digitalWrite(plane2, LOW);
	delay(200);
	digitalWrite(plane3, LOW);
	delay(20);

	// then turn them off one after the other
	digitalWrite(plane1, HIGH);
	delay(200);
	digitalWrite(plane2, HIGH);
	delay(200);
	digitalWrite(plane3, HIGH);
	delay(20);

	digitalWrite(c1, LOW);

	digitalWrite(c5, HIGH);
	digitalWrite(c7, HIGH);
	digitalWrite(c9, HIGH);

	digitalWrite(plane1, LOW);
	delay(200);
	digitalWrite(plane2, LOW);
	delay(200);
	digitalWrite(plane3, LOW);
	delay(20);

	digitalWrite(plane1, HIGH);
	delay(200);
	digitalWrite(plane2, HIGH);
	delay(200);
	digitalWrite(plane3, HIGH);
	delay(20);

	digitalWrite(c5, LOW);
	digitalWrite(c7, LOW);
	digitalWrite(c9, LOW);

  digitalWrite(c2, HIGH);
  digitalWrite(c8, HIGH);

  digitalWrite(plane1, LOW);
  delay(200);
  digitalWrite(plane2, LOW);
  delay(200);
  digitalWrite(plane3, LOW);
  delay(20);

  digitalWrite(plane1, HIGH);
  delay(200);
  digitalWrite(plane2, HIGH);
  delay(200);
  digitalWrite(plane3, HIGH);
  delay(20);

  digitalWrite(c2, LOW);
  digitalWrite(c8, LOW);

  digitalWrite(c9, HIGH);

  digitalWrite(plane1, LOW);
  delay(200);
  digitalWrite(plane2, LOW);
  delay(200);
  digitalWrite(plane3, LOW);
  delay(20);

  digitalWrite(plane1, HIGH);
  delay(200);
  digitalWrite(plane2, HIGH);
  delay(200);
  digitalWrite(plane3, HIGH);
  delay(20);

  digitalWrite(c9, LOW);

  digitalWrite(c7, HIGH);
  digitalWrite(c6, HIGH);

  digitalWrite(plane1, LOW);
  delay(200);
  digitalWrite(plane2, LOW);
  delay(200);
  digitalWrite(plane3, LOW);
  delay(20);

  digitalWrite(plane1, HIGH);
  delay(200);
  digitalWrite(plane2, HIGH);
  delay(200);
  digitalWrite(plane3, HIGH);
  delay(20);

  digitalWrite(c7, LOW);
  digitalWrite(c6, LOW);
}
