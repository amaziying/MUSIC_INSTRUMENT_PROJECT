//Final project by Anojan Gunasekaran, Ziying Zhang, and Adele Chui
//SYDE 192L for Orion Bruckman
//This prototype is a generates sound at specific frequencies everytime
//a button is pressed. The system of six buttons operates on a single 
//interrupt line. Everytime one of the six buttons is pressed, an
//interrupt is detected. When this occurs, the program looks for which
//pin has detected a change from HIGH to LOW. The buttons cause the 
//corresponding pin to go from HIGH to LOW, which tells the program
//to output a frequency. One of the buttons is a power button. Without
//pressing this button, the LED will not light up and the other buttons
//will not generate sound. Once the power button is pressed, the program
//will proceed to play notes as detected. The flat button simply operates
//in conjunction with the other notes to change the pitch from 'normal' to
//flat.

// BUTTONS CORRESPOND TO NOTES (arranged low to high)
//The following pins are on one interupt line
const int g = 5;
const int a = 6;
const int b = 7;
const int c = 8;
const int d = 9;
const int e = 10;

//The following pins are on our interupt pin
const int flatpin = 11;
const int startpin= 4;
const int stoppin=12;

// Declare speaker
const int speaker=13;


//LIST OF FREQUECIES PER NOTE
// Each frequency is a constant

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

// "volatile" variable qualifier - variable 'state' will be loaded from RAM
// this is for interrupt function for the buttons
volatile int flat=LOW;
volatile int start=LOW;
volatile int stopper=LOW;
volatile int state=HIGH;

//Declare variables for timer.
volatile float seconds = 0;
volatile long seconds_error = 0;
volatile float buttonstart;
volatile float buttonend;

//Variables to store the duration of each note.
float g_duration=0;
float a_duration=0;
float b_duration=0;
float c_duration=0;
float d_duration=0;
float e_duration=0;

//Variables for start and finish time of program.
float program_start=0;
float program_end=0;

//Function for Calculating Time
//This interrupt is trigered everytime the overflow resets to 0
//It takes 262144 microseconds for it to get triggered
//therefore 262.144 miliseconds
//we want error because we dont account for that in the beginning
//when it reaches 1000, we subtract accumulated error b 1000
//and the we add the error into the actual time
//because error is what time the timer has missed
//we got these value from data sheet

ISR(TIMER1_OVF_vect) {
  seconds+=262.144; 
  /* 
  seconds+=
  seconds_error += 144;
  
  if( seconds_error >= 1000)
  {
    seconds_error -= 1000;
    seconds+=1000;
  }*/
 
}

//Setup function
void setup(){

//Set pims as pullup pins.
//This means that when your button is not pressed, the button will
//always read a value of HIGH or 1 because it has been pulled up
//to 5VCC. When the button is pressed, it will go to GROUND or 0 volts.
pinMode(a,INPUT_PULLUP);
pinMode(b,INPUT_PULLUP);
pinMode(c,INPUT_PULLUP);
pinMode(d,INPUT_PULLUP);
pinMode(e,INPUT_PULLUP);
pinMode(g,INPUT_PULLUP);

pinMode(startpin, INPUT_PULLUP);
pinMode(stoppin, INPUT_PULLUP);

//Set speaker to output.
pinMode(speaker, OUTPUT);

//Declare interrupt functions.
//Parameter 1 - which interrupt pin it is mapped to
//0 is mapped to pin 2
//1 is mapped to pin 3
//Parameter 2 - name of handler function
//Parameter 3 - interrupt is triggered on a ____ edge.
attachInterrupt(0,notes,FALLING);
attachInterrupt(1,power_or_flat,FALLING);

//Timer/Counter Interrupt Mask Register 1
//Enables the timer interrupt and ties it to timer 1
//This enables by setting bits in the interrupt mask register
//The interrupt mask register specifies which interrupts are to be ignored

TIMSK1=(1<<TOIE1); // enabled global and timer overflow interrupt;

//Timer/Counter Control Register 1
//Specifies the timer register we are using - which is timer 1
//Resets all bits to enable normal timer mode
//Counts from 0 to the highest bits and then resets
//Other modes of operation- compare and PCM
TCCR1A = 0x00; // normal operation page 148 (mode0);

//Timer Counter Register
//Where the actual timer value is stored
//Clears the register so theres no initial value
//The two Timer/Counter I/O locations (TCNT1H and TCNT1L, combined TCNT1) give direct
//access, both for read and for write operations, to the Timer/Counter unit 16-bit counter.
//we chose 16 bits because that means more vents which means it counts more accurately

TCNT1=0x0000; // 16bit counter register

//Timer/Counter Control Register 2
//TCCR1B register’s 3 first bits saves value of counter clock prescaler
//Sets prescaler to 64
TCCR1B = ( _BV(CS11) | _BV(CS10) ); //sets prescaler value to 64

//Begin serial monitor.
//Sets data rate to 9600 bits per second
Serial.begin(9600);
}


void loop(){
 
//Start is set to high by user pressing the start button that
//triggers an interrupt and sets the start variable to HIGH when
//the startpin reads HIGH

if (start==HIGH){
  
//Stores the start time for the "song"
//Feedback to user that they can now play notes

  program_start=seconds;
  Serial.println("Program On");
  
//We can play notes as long as the stop button is not pressed
//Once the stop button is pressed, stopper will no longer equal HIGH
  
  while(stopper==LOW){
 
   
    if (state==LOW){ 
    
//When any of the note buttons are pressed, an interrupt is triggered
//And we record the beginning time of each button being pressed
//SO that the button tduration can be caluclated later.
 
  buttonstart=seconds;
 
//The followinf if statements alloperate the same:
//When a button is pressed, the program polls for the 
//pin that is now set to LOW. When it find the button,
//the program will print to the serial monitor which button
//has been pressed and call a function that plays a note. 
//See holdnote declaration at the bottom of the code
//for more information. AFter the button has been released
//the program will print to the serial monitor the total
//duration of that note. note_duration is used to store the 
//overall amount of time a note has been held, which will be
//displayed to the user at the end of the "song".
  
  //G note
  if (digitalRead(g)==LOW){
    Serial.println("G");
  holdnote(g, G_flat, G_normal);
  g_duration += seconds-buttonstart;
  Serial.println((seconds-buttonstart)/1000.00);
 }
 
 //A note
  else if (digitalRead(a)==LOW){
    Serial.println("A");
  holdnote(a, A_flat, A_normal);
  a_duration += seconds-buttonstart;
  Serial.println((seconds-buttonstart)/1000.00);
 }
 
 //B note
 else if (digitalRead(b)==LOW){
    Serial.println("B");
  holdnote(b, B_flat, B_normal);
  b_duration += seconds-buttonstart;
  Serial.println((seconds-buttonstart)/1000.00);
 }
 
 //C note
  else if (digitalRead(c)==LOW){
    Serial.println("C");
 holdnote(c, C_flat, C_normal);
  c_duration += seconds-buttonstart;
  Serial.println((seconds-buttonstart)/1000.00);
 }
 
 //D note
  else if (digitalRead(d)==LOW){
    Serial.println("D");
  holdnote(d, D_flat, D_normal);
  d_duration += seconds-buttonstart;
  Serial.println((seconds-buttonstart)/1000.00);
 }
 
 //E note
 else if (digitalRead(e)==LOW){
    Serial.println("E");
 holdnote(e, E_flat, E_normal);
  e_duration += seconds-buttonstart;
  Serial.println((seconds-buttonstart)/1000.00);
 }

//NoTone function stops the speaker after a button
//has been released. We then reset State to HIGH and flat to 
//LOW to reset the interrupt so it can be triggered again.
 noTone(speaker);
state=HIGH;
   flat=LOW;
}
}

//When the stop button is pressed, the program
//exits the while loop and records the stop time
//for the song. The program then prints out the stats
//for the "song" to the serial monitor.
program_end= seconds-program_start;
Serial.println("Program Ended");
Serial.println("You've played for ");
Serial.print(program_end/1000.00);
Serial.println(" seconds");
Serial.println("Total time G was played (s):");
Serial.println(g_duration/1000.00);
Serial.println("Total time A was played (s):");
Serial.println(a_duration/1000.00);
Serial.println("Total time B was played (s):");
Serial.println(b_duration/1000.00);
Serial.println("Total time C was played (s):");
Serial.println(c_duration/1000.00);
Serial.println("Total time D was played (s):");
Serial.println(d_duration/1000.00);
Serial.println("Total time E was played (s):");
Serial.println(e_duration/1000.00);

//At the very end of the program, we once
//again reset the start and stop variables
//so that the interrupt can be triggered once again.
start=LOW;
stopper=LOW;
}
}

//This is the first interrupt function.
//WHen triggered by any of the notes buttons,
//The state variable is switched to LOW, which 
//will trigger if statements in the void loop
//function.

void notes(){
  state=LOW;
}

//This is the second interrupt function.
//When triggered, depending on which of the
//buttons is pressed, a variable is set to high
//in order to trigger some sort of conditional
//statement in the void loop function.

void power_or_flat(){
  if (digitalRead(startpin)==LOW){
   start=HIGH;
  }
  if (digitalRead(stoppin)==LOW){
    stopper=HIGH;
  }
  if (digitalRead(flatpin)==LOW){
    flat=HIGH;
  }
}

//this function is a while loop that will 
//continoually check if the flat button is pressed
//while outputting a tone so long as a note button is held.
//Once the flat button is pressed, the if statement causes
//the speaker to output the other frequency.

void holdnote(int pin, float flatnote, float normalnote){
  while (digitalRead(pin)==LOW){
 
   if (flat==HIGH){
     tone(speaker, flatnote);
   }
   else{
     tone(speaker, normalnote);
   }
  }
  
}
