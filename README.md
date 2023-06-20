# CM-Summative
## Formative assessment for unit IU000111, "Creative Making: Experience and Physical Computing"

# Introduction
My Arduino project submission is a voice-controlling glove. It uses a resistance reading from a flex sensor as its input, and can be used to pass MIDI Control Change signals to any USB MIDI–enabled piece of software, meaning you are able to add effects to your vocal performance in real time. The output is the audio of the vocal with glove-controlled FX. Check out the accompanying video to see the development process and result in action!

# Background and Idea Formation
My project stems from my practice as a composer and producer. My long–term goal is to create tools that facilitate and heighten creativity for myself and others. The main inspiration for this project was Imogen Heap's [Mi.Mu glove] (https://mimugloves.com/), which I wanted to partially recreate. I also wanted to discover how to communicate with my DAW using code, and felt this would be a perfect way to learn. I spoke to the technicians at CCI who advised a flex sensor attached to a glove would be a good way to achieve my goal of creating a tactile voice controller, and pointed me to this [flex sensor hookup guide] (https://learn.sparkfun.com/tutorials/flex-sensor-hookup-guide/all) and this [MIDI Arduino guide on the CCI wiki] (https://wiki.cci.arts.ac.uk/books/physical-computing/page/using-arduino-leonardo-to-send-usb-midi-data), both of which are the starting point of my work. 

# Hardware
The flex sensor is connected to the Arduino Leonardo via a breadboard. I made a long braided cable for ease of use when performing at a microphone. The cable is soldered on the flex sensor side and simply patched into the breadboard. Here is the hookup diagram for the hardware side (taken from the flex sensor hookup guide linked in the introduction): 

![example_circuit_bb](https://github.com/arturopolizzi/CM-Summative/assets/118212728/d64ef977-38a1-4662-9d53-bcfa0d7653e7)

Once software testing was complete, I bought a cheap sports glove and attached the flex sensor using a combination of thread stitching and superglue. The Arduino and breadboard components are placed in a cardboard box, for better presentability and ease of use.

# Software
the version numbers used to title the below sections of the software development process correspond to the version files present in the repository.

## Version 1
Once the hardware was set up, I needed to make sure my computer was taking appropriate readings from the flex sensor. I set up a sketch essentially the same as the Potentiometer excercise we did in class, and checked that the Serial monitor was changing as I played with the extension of the flex sensor.

## Version 2
I know that MIDI only accepts readings in range 0-127, so I wanted to constrain and map the readings currently being taken to reflect this. After a few different attempts I arrived at the mapping that kept within the range with the best readings from the flex sensor at full extension and full bend. I'm still just using the serial monitor at this point to check readings.

## Version 3
At this point I consulted the CCI wiki to figure out how to send the reading value out as a MIDI Control Change Signal. After some tries I am able to get Logic (the software I use to make music) to recognise the incoming MIDI signal and map it to a parameter such as the volume of  track, but it is laggy and inconsistent. After speaking to the technicians I realise the fact I am instructing Arduino IDE to send a MIDI signal in the loop() function is overloading my CPU.

## Version 4
I used a separate function to form the MIDI package and send it to the DAW and the issue of lag was resolved, making the glove usable!

# Evaluation
I'm happy with the end result of my project and think it is a good prototype for a more advanced glove which uses multiple flex sensors on multiple fingers to control many parameters. I wish I had made a smoothing algorithm, or created gates for the signal to pass out at one of 4 or 5 strengths, so that the signal from the glove and was less shaky. My fix was to adjust the signal constrainment and mapping so that it behaved more like a switch and less like a knob.
