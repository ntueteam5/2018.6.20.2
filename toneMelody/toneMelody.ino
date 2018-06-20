#include "pitches.h"
const int interruptNumber = 0;
const int ledPin =  13;  
const int buttonPin1 = 2;  
const int buttonPin2 = 3; 
int state = 0;
int buttonState1 = 0;
int buttonState2 = 0;
volatile boolean buttonState = LOW;
// notes in the melody:
int melody[] = {
  NOTE_G5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_G5
};
int melody1[] = {
  NOTE_E6, NOTE_C6, NOTE_D6, NOTE_G5, NOTE_G5, NOTE_D6, NOTE_E6, NOTE_C6
};
int melody2[] = {
  NOTE_C5, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 2, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2
};
int noteDurations1[] = {
  2, 2, 2, 1, 2, 2, 2, 1,
};

int num = 13;
int num1 = 8;

void buttonStateChanged() {
  state =! state; 
  
}

void setup() {
  Serial.begin(9600);
  // iterate over the notes of the melody:
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin1, INPUT); 
    pinMode(buttonPin2, INPUT); 
    attachInterrupt(interruptNumber, buttonStateChanged, CHANGE);
}

void loop() {
  buttonState = digitalRead(buttonPin1);
  
  
  if (state == HIGH) {
    int num = 13;
    for (int thisNote = 0; thisNote < num; thisNote++) {
      buttonState = digitalRead(buttonPin1);
      Serial.print(buttonState);Serial.print('\t');Serial.println(state);
      attachInterrupt(interruptNumber, buttonStateChanged, CHANGE);
      if (state == LOW){num=0;}
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    }
   }
  if (state == LOW) {
    noTone(8);
    int num1 = 8;
    for (int thisNote = 0; thisNote < num1; thisNote++) {
      buttonState = digitalRead(buttonPin1);
      Serial.print(buttonState);Serial.print('\t');Serial.println(state);
      attachInterrupt(interruptNumber, buttonStateChanged, CHANGE);
      if (state == HIGH){num1=0;}
    int noteDuration1 = 1000 / noteDurations1[thisNote];
    tone(8, melody1[thisNote], noteDuration1);
    int pauseBetweenNotes = noteDuration1 * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    }
   }
} 
/*#include "pitches.h"
const byte intPin=2;
volatile boolean state = LOW;
int melody1[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int melody2[] = {
  NOTE_C4, NOTE_B3, 0, NOTE_G3, NOTE_A3, NOTE_G3,  NOTE_G3, NOTE_C4
};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations1[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
int noteDurations2[] = {
  4, 4, 4, 4, 4, 8, 8, 4
};
void int0() {   //interrupt handler
  if(state==HIGH) {state = LOW;} 
  else{state = HIGH;}//reverse state 
}
void setup() { 

//enable pull-up resistor of input pin
    for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration1 = 1000 / noteDurations1[thisNote];
    tone(8, melody1[thisNote], noteDuration1);
    int pauseBetweenNotes = noteDuration1 * 1.30;
    delay(pauseBetweenNotes);  
    pinMode(intPin, INPUT_PULLUP);
    attachInterrupt(0, int0, LOW); //assign int0
  }

}
void loop() {
   if (state) {    
    for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration1 = 1000 / noteDurations1[thisNote];
    tone(8, melody1[thisNote], noteDuration1);
    int pauseBetweenNotes = noteDuration1 * 1.30;
    delay(pauseBetweenNotes);  } 
   }//turn LED on
  else {    
    for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration2 = 1000 / noteDurations2[thisNote];
    tone(8, melody2[thisNote], noteDuration2);
    int pauseBetweenNotes = noteDuration2 * 1.30;
    delay(pauseBetweenNotes);  }  //turn LED on
    }
}*/
