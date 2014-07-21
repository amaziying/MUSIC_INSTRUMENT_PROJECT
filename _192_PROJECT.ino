// BUTTONS CORRESPOND TO NOTES (arranged low to high)
// CONNECTED TO PINS
const int f = 4;
const int g= 5;
const int a = 6;
const int b = 7;
const int c = 8;
int d = 9;
int e = 10;

// Declare speaker
int speaker = 11;

//LIST OF FREQUECIES PER NOTE
// Each frequency is a variable

float F_normal = 174.61;
float G_normal = 196.00;
float A_normal = 220.00;
float B_normal = 246.94;
float C_normal = 261.63;
float D_normal = 293.66;
float E_normal = 329.63;

float F_sharp = 185.00;
float F_flat = E_normal;
float G_sharp = 207.65;
float G_flat = 185.00;
float A_sharp = 233.08;
float A_flat = 207.65;
float B_sharp = C_normal;
float B_flat = 233.08;
float C_sharp = 277.18;
float C_flat = B_normal; 
float D_sharp = 311.13;
float D_flat = C_sharp;
float E_sharp = F_flat;
float E_flat = 311.13;

// variable qualifier - variable 'state' will be loaded from RAM
// this is for interrupt function for the buttons
volatile int flat=LOW;
volatile int sharp=LOW;

void setup(){

pinMode(a,INPUT);
pinMode(b,INPUT);
pinMode(c,INPUT);
pinMode(d,INPUT);
pinMode(e,INPUT);
pinMode(f,INPUT);
pinMode(g,INPUT);

pinMode(speaker, OUTPUT);

// parameter1 - interrupt (0 or 1)
// parameter2 - name of the interrupt handler function 
// parameter3 - trigger(CHANGE,LOW,RISING or FALLING)
// this interrupt function is mapped to pin 2
attachInterrupt(0,notes,LOW);

// parameter1 - interrupt (0 or 1)
// parameter2 - name of the interrupt handler function 
// parameter3 - trigger(CHANGE,LOW,RISING or FALLING)
// this interrupt function is mapped to pin 3
attachInterrupt(1,flat_sharp,LOW);

}

void loop(){
//digitalWrite(pin,state);

}

// interrupt handler function 
void notes(){
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


}


