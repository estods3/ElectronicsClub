const int SERPin = 3;    //<-----corresponds to P1.1 on MSP430
const int RclockPin = 6; //<-----corresponds to P1.4 on MSP430
const int SclockPin = 7; //<-----corresponds to P1.5 on MSP430
const int timeDelay = 700; //MAKE THIS WHATEVER YOU WANT! (NOTE: the number is in milliseconds!!!)
void setup() {
  //NO NEED TO EDIT THIS STUFF!
  pinMode(SERPin, OUTPUT);      
  pinMode(RclockPin, OUTPUT);      
  pinMode(SclockPin, OUTPUT);     
}

void writehigh(){
  //this function sets SclockPin to 0 so that it can write to the register
  //then writes a HIGH value to SER (Serial pin)
  //afterward, it writes a HIGH value to the SclockPin to finish writing
  digitalWrite(SclockPin, LOW);
  digitalWrite(SERPin, HIGH);
  digitalWrite(SclockPin, HIGH);
}
void writelow(){
  //this function sets SclockPin to 0 so that it can write to the register
  //then writes a LOW value to SER (Serial pin)
  //afterward, it writes a HIGH value to the SclockPin to finish writing
  digitalWrite(SclockPin, LOW);
  digitalWrite(SERPin, LOW);
  digitalWrite(SclockPin, HIGH);
}
void printByte(byte b){ 
    //just call the function with a byte variable parameter to print that data to the shift register!
    //using a bitwise AND operation (which looks like "&") we can determine whether each bit in "byte b" is a 1 or 0
    //if the condition in the "if((b & c) == c)" statement is true, then there is a 1 at the current position so light up the LED
    //else there must be a 0 so we turn off the LED!
    digitalWrite(RclockPin, LOW);
    for(byte c = 0b10000000; c > 0; c /= 2){
      if((b & c) == c){
        writehigh();
      } else{
        writelow();
      } 
    }
    digitalWrite(RclockPin, HIGH);
}

void loop() {
  //This is where we use the functions above to create a 8 bit binary counter!
  for(byte b = 0b00000000; b < 256; b+=0b00000001){
    printByte(b);
    delay(timeDelay);
  }
}
