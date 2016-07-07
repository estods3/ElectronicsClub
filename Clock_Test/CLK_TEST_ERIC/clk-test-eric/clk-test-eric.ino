/* Shift Register LED Animation

Created by Eric Bauer
Last Modified: 2/24/15
 
 */

// set pin numbers:
const int DSpin =  19;      // the serial data pin
const int STCPpin = 18;     // the Storage Register clock pin (loads the shift register buffer)
const int SHCPpin = 17;     // the Shift Register clock pin (loads serial data into the shift register buffer)
const int SERPin = 19;
const int RclockPin = 18;
const int SclockPin = 17; 

// Frame and Play speed information
byte frames[] = {0b00010010, 0b00110100, 0b10001000, 0b10001000};             // custom animation frames can be hardcoded
byte frameDurations[] = {1, 1, 1, 1};
int numberOfFrames = 4;
float framesPerSecond = 2;
int msecondsPerFrame = 5000;//float(1/framesPerSecond)*1000; // milliseconds ot delay


// Animation functions
void playFrames(int framesAtOnce); // hardcoded animation

// Shift Register functions
void shiftOutNew(byte data);

/****************************************
*        Main Control Functions
*****************************************/

void setup() {
  // set the digital pin as output:
  pinMode(DSpin, OUTPUT); 
  pinMode(STCPpin, OUTPUT); 
  pinMode(SHCPpin, OUTPUT); 
  //initialize pin states (don't want to clock anything in yet
  digitalWrite(STCPpin, LOW);
  digitalWrite(SHCPpin, LOW);
  digitalWrite(DSpin, LOW);  
}

void loop()
{
  //NOTE: Comment out one of these functions to choose an animation
  
  //playFrames(2);
  //playScanner();
  shiftOutNew(frames[0]);
  shiftOutNew(frames[1]);
  delay(msecondsPerFrame);
  shiftOutNew(frames[2]);
  shiftOutNew(frames[3]);
  delay(msecondsPerFrame);
  
}

/****************************************
*        Shift Register Functions
*****************************************/

void shiftOutNew(byte data){
 int dataState = 0;
 digitalWrite(STCPpin, LOW);
 for(int i = 7; i>=0; i--){ //start by shifting out the LSB
  digitalWrite(SHCPpin, LOW);  
  dataState = (0b10000000 >> i) & data; // test each bit of "data"
  digitalWrite(DSpin, dataState);
  delay(5);
  digitalWrite(SHCPpin, HIGH);
  
 } 
 digitalWrite(STCPpin, HIGH); // load the buffer and output the frame
}

/****************************************
*        LED Animation Functions
*****************************************/


void playFrames(int framesAtOnce){
 for(int i = 0; i<numberOfFrames; i++){
   shiftOutNew(frames[i]);
   delay(msecondsPerFrame);
 }  
}



