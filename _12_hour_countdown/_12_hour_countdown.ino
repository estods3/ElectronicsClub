const int SERPin = 19;
const int RclockPin = 18;
const int SclockPin = 17;
const int oneSecond = 1000;
void setup()
{
  pinMode(SERPin, OUTPUT);      
  pinMode(RclockPin, OUTPUT);      
  pinMode(SclockPin, OUTPUT);    
}
void writehigh(){
  //this function writes a HIGH (logic 1) value to the shift register at the point it is called.
  //it first sets the SclockPin to 0 so that it can write to the register and then writes a HIGH value to SER (Serial pin)
  //afterward, it writes a HIGH value to the SclockPin to finish writing
  digitalWrite(SclockPin, LOW);
  digitalWrite(SERPin, HIGH);
  digitalWrite(SclockPin, HIGH);
}
void writelow(){
  //this function writes a LOW value (logic 0) to the shift register at the point it is called.
  //it first sets the SclockPin to 0 so that it can write to the register and then writes a LOW value to SER (Serial pin)
  //afterward, it writes a HIGH value to the SclockPin to finish writing
  digitalWrite(SclockPin, LOW);
  digitalWrite(SERPin, LOW);
  digitalWrite(SclockPin, HIGH);
}  
void initialClock(){
  //This function writes an initial value to the clock.
  //That way, there is a value on the screen before the first minute goes by.
  digitalWrite(RclockPin, LOW);
  //This section generates a 0 in the tens hours place --->    0X:XX
  writelow();
  writelow();
  writelow();
  writelow();

  //This section generates an 8 in the ones hours place --->    X8:XX
  writehigh();
  writelow();
  writelow();
  writelow();
  
  //This section generates a 2 in the tens minutes splace --->    XX:2X
  writelow();
  writelow();
  writehigh();
  writelow();
  
  //This section generates a 3 in the ones minutes place --->    XX:X3  
  writelow();
  writelow();
  writehigh();
  writehigh();
  digitalWrite(RclockPin, HIGH);  
  
}
void loop()
{
 
    //----------------
    //INITIALIZATION
    //----------------
  
    //initialize an initial condition to the clock
    initialClock();
    
    //The following looping sctructure will count down for 60 seconds before decrimenting the minute hand.
    //the loops will continue this process until 60 minutes have passed. At this point, the hours counter will be decrememnted
    //this process will continue until the clock has gone through 24 hours.
    
    for(int h = 23; h > 0; h--){
      for(int m = 59; m >= 0; m--){
        for(int s = 0; s <= 60; s++){
          //delay 1000 miliseconds 60 times ---> wait one minute
          delay(1000);
        }
        //a minute has passed by, so we can now update the 7 segment display.
        //open a clock for writing. This allows us to add values to the shift registers but
        //wont send those values out of the shift register until RclockPin recieves a HIGH value
        digitalWrite(RclockPin, LOW);
    
        //--------------------
        //VARIABLE DECLARATION
        //--------------------
    
        //the variables are used to store the values from the h and m varaibles of the for loops
        //the h and m variables hold the hours and minutes respectively. However, we need varaibles o and t 
        //to hold the ones and tens place respectively.
        
        //ones place digit initialized to the remainder after the hours is divided by 10 ---> o now holds the ones place of the hours
        byte o = h % 10;
        //tens place digit initialized to 0 ---> t holds 0
        byte  t = 0;
        //if the hours are greater than 9, then there is a value other than 0 in the hour's tens place ---> t is reassigned to the value of the tens place in h
        if(h > 9){
             t = (h-o)/10;
        }
        
        //---------------------
        // HOURS       TENS PLACE 7 SEGMENT
        //
        //all parts of this section convert the value in the variable t for the tens place of the hours section
        // to a list of HIGH and LOW values to write to the shift register.
        //---------------------
        
        //b holds the temporary value of a specific bit. Right now, it is examining the 4th bit from the right
        byte b = t & 0b00001000; 
        //if this bit is a one, then that means we should write a HIGH value (or logic 1) to the shift register in that position
        if(b == 0b00001000){
          writehigh();
        } else{
          writelow();
        }
        b = t & 0b0000100;
        //if this bit is a one, then that means we should write a HIGH value (or logic 1) to the shift register in that position
        if(b == 0b00000100){
          writehigh();
        } else{
          writelow();
        }
        b = t & 0b00000010; 
        //if this bit is a one, then that means we should write a HIGH value (or logic 1) to the shift register in that position
        if(b == 0b00000010){
          writehigh();
        } else{
          writelow();
        }
        b = t & 0b00000001; 
        //if this bit is a one, then that means we should write a HIGH value (or logic 1) to the shift register in that position
        if(b == 0b00000001){
        writehigh();
        } else{
          writelow();
        }
       
        
        //---------------------
        // HOURS       ONES PLACE 7 SEGMENT
        //
        //all parts of this section convert the value in the variable o for the ones place of the hours section
        // to a list of HIGH and LOW values to write to the shift register.
        //---------------------        
        
        b = o & 0b00001000;
        //if this bit is a one, then that means we should write a HIGH value (or logic 1) to the shift register in that position
        if(b == 0b00001000){
          writehigh();
        } else{
          writelow();
        }
        b = o & 0b0000100;
        //if this bit is a one, then that means we should write a HIGH value (or logic 1) to the shift register in that position
        if(b == 0b00000100){
          writehigh();
        } else{
          writelow();
        } 
        b = o & 0b00000010; 
        //if this bit is a one, then that means we should write a HIGH value (or logic 1) to the shift register in that position
        if(b == 0b00000010){
          writehigh();
        } else{
          writelow();
        }
        b = o & 0b00000001; 
        //if this bit is a one, then that means we should write a HIGH value (or logic 1) to the shift register in that position
        if(b == 0b00000001){
          writehigh();
        } else{
           writelow();
        }
    
    
        //----------------------------------
        //REINITIALIZE VARIABLES FOR MINUTES
        //----------------------------------
    
        //ones place digit of the minutes variable m ----> o is assigned the ones place of the minutes counter
        o = m % 10;
        //tens place digit is initialized to 0.
        t = 0;
        //tens place digit is assigned the value of the tens place if the hours counter, h, is greater than 9
        if(m > 9){
           t = (m-o)/10;
        }
    
        //---------------------
        // MINUTES        TENS PLACE 7 SEGMENT
        //
        //all parts of this section convert the value in the variable t for the tens place of the minutes section
        // to a list of HIGH and LOW values to write to the shift register.
        //---------------------      
        
        b = t & 0b00001000; 
        //if this bit is a one, then that means we should write a HIGH value (or logic 1) to the shift register in that position
        if(b == 0b00001000){
          writehigh();
        } else{
          writelow();
        }
        b = t & 0b0000100;
        //if this bit is a one, then that means we should write a HIGH value (or logic 1) to the shift register in that position
        if(b == 0b00000100){
          writehigh();
        } else{
          writelow();
        }
        b = t & 0b00000010; 
        //if this bit is a one, then that means we should write a HIGH value (or logic 1) to the shift register in that position
        if(b == 0b00000010){
          writehigh();
        } else{
          writelow();
        }
        b = t & 0b00000001; 
        //if this bit is a one, then that means we should write a HIGH value (or logic 1) to the shift register in that position
        if(b == 0b00000001){
          writehigh();
        } else{
           writelow();
        }
    
        //---------------------
        // MINUTES         ONES PLACE 7 SEGMENT
        //
        //all parts of this section convert the value in the variable o for the ones place of the minutes section
        // to a list of HIGH and LOW values to write to the shift register.
        //---------------------
        
        b = o & 0b00001000;
        //if this bit is a one, then that means we should write a HIGH value (or logic 1) to the shift register in that position
        if(b == 0b00001000){
          writehigh();
        } else{
          writelow();
        }
        b = o & 0b0000100;
        //if this bit is a one, then that means we should write a HIGH value (or logic 1) to the shift register in that position
        if(b == 0b00000100){
          writehigh();
        } else{
          writelow();
        }
        b = o & 0b00000010; 
        //if this bit is a one, then that means we should write a HIGH value (or logic 1) to the shift register in that position
        if(b == 0b00000010){
          writehigh();
        } else{
          writelow();
        }
        b = o & 0b00000001; 
        //if this bit is a one, then that means we should write a HIGH value (or logic 1) to the shift register in that position
        if(b == 0b00000001){
          writehigh();
        } else{
           writelow();
        }
        //change the RclockPin to HIGH to send all values just stored in the shift registers above into the rest of the circuit.
        //this way, all of the values are changed at once instead of one at a time as they are changed in the code
        digitalWrite(RclockPin, HIGH);
      }
    }
}
