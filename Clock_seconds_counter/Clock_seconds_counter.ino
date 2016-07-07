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
  digitalWrite(SclockPin, LOW);
  digitalWrite(SERPin, HIGH);
  digitalWrite(SclockPin, HIGH);
}
void writelow(){
  digitalWrite(SclockPin, LOW);
  digitalWrite(SERPin, LOW);
  digitalWrite(SclockPin, HIGH);
}  
void loop()
{
  for(int i = 0; i < 10; i++){
        
        delay(oneSecond);
        digitalWrite(RclockPin, LOW);
        byte o = i;

        //---------------------
        // ONES PLACE 7 SEGMENT
        //---------------------
        byte b = o & 0b00001000;
        if(b == 0b00001000){
          writehigh();
        } else{
          writelow();
        }
        b = o & 0b0000100;
        if(b == 0b00000100){
          writehigh();
        } else{
          writelow();
        }
        
        b = o & 0b00000010; 
        if(b == 0b00000010){
          writehigh();
        } else{
          writelow();
        }
        
        b = o & 0b00000001; 
        if(b == 0b00000001){
          writehigh();
        } else{
           writelow();
        }
        
        //---------------------
        // TENS PLACE 7 SEGMENT
        //---------------------
        b = o & 0b00001000; 
        if(b == 0b00001000){
          writehigh();
        } else{
          writelow();
        }
        b = o & 0b0000100;
        if(b == 0b00000100){
          writehigh();
        } else{
          writelow();
        }
        
        b = o & 0b00000010; 
        if(b == 0b00000010){
          writehigh();
        } else{
          writelow();
        }
        
        b = o & 0b00000001; 
        if(b == 0b00000001){
          writehigh();
        } else{
           writelow();
        }
        

        //---------------------
        // ONES PLACE 7 SEGMENT
        //---------------------
        b = o & 0b00001000;
        if(b == 0b00001000){
          writehigh();
        } else{
          writelow();
        }
        b = o & 0b0000100;
        if(b == 0b00000100){
          writehigh();
        } else{
          writelow();
        }
        
        b = o & 0b00000010; 
        if(b == 0b00000010){
          writehigh();
        } else{
          writelow();
        }
        
        b = o & 0b00000001; 
        if(b == 0b00000001){
          writehigh();
        } else{
           writelow();
        }
        
        //---------------------
        // TENS PLACE 7 SEGMENT
        //---------------------
        b = o & 0b00001000; 
        if(b == 0b00001000){
          writehigh();
        } else{
          writelow();
        }
        b = o & 0b0000100;
        if(b == 0b00000100){
          writehigh();
        } else{
          writelow();
        }
        
        b = o & 0b00000010; 
        if(b == 0b00000010){
          writehigh();
        } else{
          writelow();
        }
        
        b = o & 0b00000001; 
        if(b == 0b00000001){
          writehigh();
        } else{
           writelow();
        }
        
        digitalWrite(RclockPin, HIGH);
  }
  delay(oneSecond);
}
