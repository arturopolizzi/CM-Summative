int val; //initialising the value to which the analog pin reading is assigned
const int FLEX_PIN = A0; //initialising the analog pin

void setup() 
{
  Serial.begin(9600); //initialising Serial
  pinMode(FLEX_PIN, INPUT); //assigning input pin as flex sensor pin
}

void loop() 
{
  val = analogRead(FLEX_PIN); //assgning the value to which the analog pin reading is assigned
  int constrainedVal = constrain(val, 175, 225); //constraining to the values that represent the flex sensor fully extended or fully bent
  int mappedVal = map(constrainedVal, 175, 225, 0, 127); //mapping those to 0-127, the values taken by MIDI

  // Serial.println(val);
  // Serial.println(constrainedVal);
  Serial.println(mappedVal);   //priniting the values taken to serial monitor
}