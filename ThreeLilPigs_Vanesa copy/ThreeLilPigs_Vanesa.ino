/*
   AET Three Little Pigs
   Team Name: Tauricorn
   Team Members: Jennifer and Vanesa
   Description: Button and Servo Program
*/

// Ask Teacher Taylor, piezzo sound, &&,
//Servo Code Library
#include<Servo.h>
#include "pitches.h"

//constants   can change pin numbers if needed

//servo is the piece move electricity thru, WOLF IS pressing a button
const int strawSWITCH  = 5;
const int stickSWITCH = 6;
const int brickSWITCH = 7;

const int piggy1SERVOPIN  = 8;
const int piggy2SERVOPIN  = 2;
const int piggy3SERVOPIN  = 3;

const int buzzerPIN = 9;

int melody[] = {/// sounds
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

//VARIABLES

int strawValue;
int stickValue;
int brickValue;
int lastStrawValue;
int lastStickValue;
int lastBrickValue;
Servo piggy1Servo;
Servo piggy2Servo;
Servo piggy3Servo;


void buzzerFunction(){
  for (int thisNote = 0; thisNote < 8; thisNote++) {

        // to calculate the note duration, take one second divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / noteDurations[thisNote];
        tone(buzzerPIN, melody[thisNote], noteDuration);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(buzzerPIN);
   }
}

void setup() {
  Serial.begin(9600);
  piggy1Servo.attach(piggy1SERVOPIN);
  piggy2Servo.attach(piggy2SERVOPIN);
  piggy3Servo.attach(piggy3SERVOPIN);
  piggy1Servo.write(0);
  piggy2Servo.write(0);
  piggy3Servo.write(0);
  pinMode(strawSWITCH, INPUT);
  pinMode(stickSWITCH, INPUT);
  pinMode(brickSWITCH, INPUT);
}

//Serial.println(digitalRead(pin#));

void loop() { //
  strawValue = digitalRead(strawSWITCH);
  stickValue = digitalRead(stickSWITCH);
  brickValue = digitalRead(brickSWITCH);

  //house 1
  if (strawValue != lastStrawValue) {
    if (strawValue == HIGH) { //if wolf is at house and activates switch house with piggy spins, needed for each pig  IDEA:// place wolf at third house, nothing happens but house shakes, bring wolf closer spot, third piggy shows knife
      piggy1Servo.write (180); //ask about house staying in place after it spins
      buzzerFunction();
    }
    lastStrawValue = strawValue;
    }
    //House 2
    if (stickValue != lastStickValue) {
      if (stickValue == HIGH) {
        piggy2Servo.write (180);
        buzzerFunction();
      }
      lastStickValue = stickValue;
    }
    //House 3
    if (brickValue != lastBrickValue) {
      if (brickValue == HIGH) {
        piggy3Servo.write (180);
        buzzerFunction();
      }
      lastBrickValue = brickValue;   
      }
}
