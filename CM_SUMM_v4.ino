#include <MIDIUSB.h> //importing the arduino MIDIUSB library

int val; //initialising the value to which the analog pin reading is assigned
const int FLEX_PIN = A0; //initialising the analog pin
const int MIDI_CHANNEL = 1; //initialising the MIDI channel used for the signal mapping
const int MIDI_CC = 15; //initialising the MIDI control change channel used for the signal mapping

void setup() 
{
  Serial.begin(9600); //initialising Serial
  pinMode(FLEX_PIN, INPUT); //assigning input pin as flex sensor pin
}

void sendMidiData(int mappedVal)
{
  midiEventPacket_t event = {0x0B, 0xB0 | MIDI_CHANNEL, MIDI_CC, mappedVal}; //creating a MIDI event packet to be sent to my DAW
  MidiUSB.sendMIDI(event); //sending the MIDI info to my DAW
}

void loop() 
{
  val = analogRead(FLEX_PIN); //assgning the value to which the analog pin reading is assigned
  int constrainedVal = constrain(val, 175, 225); //constraining to the values that represent the flex sensor fully extended or fully bent
  int mappedVal = map(constrainedVal, 175, 225, 0, 127); //mapping those to 0-127, the values taken by MIDI

  // Serial.println(val);
  // Serial.println(constrainedVal);
  Serial.println(mappedVal);  //priniting the values taken to serial monitor
  sendMidiData(mappedVal); //I created a function to pass to instead of sending the midi signal in the loop function for less lag
}