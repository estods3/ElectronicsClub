const int SERPin = 19;
const int RclockPin = 18;
const int SclockPin = 17;
const int fiveSeconds = 5000;
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
        digitalWrite(RclockPin, LOW);
        //---------------------
        //MINUTES
        //--------------------- 
        //ONES PLACE 7 SEGMENT:       8
        //---------------------
        writehigh();
        writelow();
        writelow();
        writelow();
        
        //---------------------
        //MINUTES
        //---------------------
        // TENS PLACE 7 SEGMENT:       4
        //---------------------
        writelow();
        writehigh();
        writelow();
        writelow();
        //---------------------
        //HOURS
        //---------------------
        // ONES PLACE 7 SEGMENT:       2
        //---------------------
        writelow();
        writelow();
        writehigh();
        writelow();
        //---------------------
        //HOURS
        //---------------------
        // TENS PLACE 7 SEGMENT:       1
        //---------------------
        writelow();
        writelow();
        writelow();
        writehigh();
        digitalWrite(RclockPin, HIGH);
}
