// BUTTONS CORRESPOND TO NOTES (arranged low to high)
// CONNECTED TO PINS
int f = 3;
int g = 4;
int a = 5;
int b = 6;
int c = 7;
int d = 8;
int e = 9;

// Declare speaker
int speaker = 10;

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
//float F_flat; can't find this?
float G_sharp = 207.65;
float G_flat = 185.00;
float A_sharp = 233.08;
float A_flat = 207.65;
//float B_sharp; can't find this?
float B_flat = 233.08;
float C_sharp = 277.18;
//float C_flat; can't find this?? 
float D_sharp = 311.13;
//float D_flat; can't find this gah
//float E_sharp; whattt can't find
float E_flat = 311.13;

float F_octave_high = 349.23;
float G_octave_high = 392.00;
float A_octave_high = 440.00;
float B_octave_high = 493.88;
float C_octave_high = 523.25;
float D_octave_high = 587.33;
float E_octave_high = 659.25;


// variable qualifier - variable 'state' will be loaded from RAM
volatile int state=LOW;

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
attachInterrupt(0,handler,CHANGE);

}

void loop(){
//digitalWrite(pin,state);

// CODE TO MAKE SPEAKER SPEAK
//tone(speaker, FREQUENCY);

}

// interrupt handler function 
void handler(){
state=!state;
}


