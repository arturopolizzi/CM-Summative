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

  Serial.println(val);  //priniting the value taken to serial monitor
}