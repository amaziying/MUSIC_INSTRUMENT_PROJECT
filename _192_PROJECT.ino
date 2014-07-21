// BUTTONS CORRESPOND TO NOTES (arranged low to high)

// CONNECTED TO PINS
const int f = 4;
const int g= 5;
const int a = 6;
const int b = 7;
const int c = 8;
<<<<<<< HEAD
const int d = 9;
const int e = 10;
const int flatpin = 11;
const int sharppin= 12;

// Declare speaker
const int speaker=13;
=======
int d = 9;
int e = 10;

// Declare speaker
int speaker = 11;
>>>>>>> FETCH_HEAD

//LIST OF FREQUECIES PER NOTE
// Each frequency is a variable

const float F_normal = 174.61;
const float G_normal = 196.00;
const float A_normal = 220.00;
const float B_normal = 246.94;
const float C_normal = 261.63;
const float D_normal = 293.66;
const float E_normal = 329.63;
const float F_sharp = 185.00;
const float F_flat = E_normal;
const float G_sharp = 207.65;
const float G_flat = 185.00;
const float A_sharp = 233.08;
const float A_flat = 207.65;
const float B_sharp = C_normal;
const float B_flat = 233.08;
const float C_sharp = 277.18;
const float C_flat = B_normal; 
const float D_sharp = 311.13;
const float D_flat = C_sharp;
const float E_sharp = F_flat;
const float E_flat = 311.13;

// variable qualifier - variable 'state' will be loaded from RAM
// this is for interrupt function for the buttons
volatile int flat=LOW;
volatile int sharp=LOW;
<<<<<<< HEAD
volatile int state=HIGH;
=======
>>>>>>> FETCH_HEAD

void setup(){

pinMode(a,INPUT_PULLUP);
pinMode(b,INPUT_PULLUP);
pinMode(c,INPUT_PULLUP);
pinMode(d,INPUT_PULLUP);
pinMode(e,INPUT_PULLUP);
pinMode(f,INPUT_PULLUP);
pinMode(g,INPUT_PULLUP);

// parameter1 - interrupt (0 or 1)
// parameter2 - name of the interrupt handler function 
// parameter3 - trigger(CHANGE,LOW,RISING or FALLING)
// this interrupt function is mapped to pin 2
attachInterrupt(0,notes,FALLING);

// parameter1 - interrupt (0 or 1)
// parameter2 - name of the interrupt handler function 
// parameter3 - trigger(CHANGE,LOW,RISING or FALLING)
<<<<<<< HEAD
// this interrupt function is mapped to pin 3
/*attachInterrupt(1,flat_sharp,CHANGE);*/
=======
// this interrupt function is mapped to pin 2
attachInterrupt(0,notes,LOW);

// parameter1 - interrupt (0 or 1)
// parameter2 - name of the interrupt handler function 
// parameter3 - trigger(CHANGE,LOW,RISING or FALLING)
// this interrupt function is mapped to pin 3
attachInterrupt(1,flat_sharp,LOW);
>>>>>>> FETCH_HEAD

//Begin serial monitor.
Serial.begin(9600);
}



void loop(){
if (state==LOW){
if (digitalRead(f)==LOW) {
  tone(speaker, F_normal);
  while (digitalRead(f)==LOW){}
  noTone(speaker);
  Serial.println("f");

}

else if (digitalRead(g)==LOW) {
  tone(speaker, G_normal);
  while (digitalRead(g)==LOW){}
  noTone(speaker);
  Serial.println("g");

}

else if (digitalRead(a)==LOW) {
  tone(speaker, A_normal);
  while (digitalRead(a)==LOW){}
  noTone(speaker);
  Serial.println("a");
}

else if (digitalRead(b)==LOW) {

<<<<<<< HEAD
  tone(speaker, B_normal);
  while (digitalRead(b)==LOW){}
  noTone(speaker);
  Serial.println("b");
}

else if (digitalRead(c)==LOW) {

  tone(speaker, C_normal);
  while (digitalRead(c)==LOW){}
  noTone(speaker);
  Serial.println("c");
}

else if (digitalRead(d)==LOW) {
  tone(speaker, D_normal);
  while (digitalRead(d)==LOW){}
  noTone(speaker);
  Serial.println("d");
}

else if (digitalRead(e)==LOW) {
  tone(speaker, E_normal);
  while (digitalRead(e)==LOW){}
  noTone(speaker);
  Serial.println("e");
}
state=HIGH;
=======
>>>>>>> FETCH_HEAD
}
}

/*void hold_note(int note){
  while (digitalRead(note)==LOW){}
}*/

// interrupt handler function 
void notes(){
<<<<<<< HEAD
  state=LOW;
  
=======
state1=!state1;


//WITH ANOJAN'S SETUP - INTERRUPT ALWAYS HIGH UNTIL IT DETECTS LOW
// PINS STAY LOW UNTIL HIGH)
//This is half pseudo and half real code.
//To make speaker output frequency, use if statements 

if (digitalRead(f)==HIGH) {
  tone(speaker, F_normal);
}

if (digitalRead(g)==HIGH) {
  tone(speaker, G_normal);
}

if (digitalRead(a)==HIGH) {
  tone(speaker, A_normal);
}

if (digitalRead(b)==HIGH) {
  tone(speaker, B_normal);
}

if (digitalRead(c)==HIGH) {
  tone(speaker, C_normal);
}

if (digitalRead(d)==HIGH) {
  tone(speaker, D_normal);
}

if (digitalRead(e)==HIGH) {
  tone(speaker, E_normal);
}

void flat_sharp(){


>>>>>>> FETCH_HEAD
}


void flat_sharp(){
  
}




