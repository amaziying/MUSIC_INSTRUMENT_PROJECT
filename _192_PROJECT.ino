// BUTTONS CONNECTED TO PINS
int a = 3;
int b = 4;
int c = 5;
int d = 6;
int e = 7;
int f = 8;
int g = 9;

// Declare speaker
int speaker = 2;


// CODE TO MAKE SPEAKER SPEAK
tone(speaker, FREQUENCY);

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
digitalWrite(pin,state);
}
// interrupt handler function 
void handler()
state=!state;
}


