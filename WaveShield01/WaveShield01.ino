/*
  This code is show how Arduino Wave Module works with Arduino.
  Code is not optimized. Any improving work on it is encouraged.
 (C) Copyright 2011 elechouse.com
 */
#define PlayCmd 0xfffe
#define TurnOffCmd 0xfff0 
#define Play_PauseCmd 0xfffe




int RST = 3;
int CLK = 9;
int DAT = 8; 
    
    
void setup() {   
    
    
    pinMode(RST, OUTPUT);
    pinMode(CLK, OUTPUT); 
    pinMode(DAT, OUTPUT);
    
    
    digitalWrite(RST, HIGH);
    digitalWrite(CLK, HIGH);
    digitalWrite(DAT, HIGH);
    
    digitalWrite(RST, LOW);
    delay(5);
    digitalWrite(RST, HIGH);
    delay(300);
}

void loop() {
   send(0xfff7);//set voice volumn to 7
  send(0x0000);//play file 0000
  delay(400000);//delay 10 seconds

  

  send(Play_PauseCmd);// pause
  delay(5000);
  send(Play_PauseCmd);//play
  
  
  
  while(1);
}

/****************************************************
The following function is used to send command to wave shield. 
You don't have to change it.

Send the file name to play the audio. 
If you need to play file 0005.AD4, write code: send(0x0005).
For more command code, please refer to the manual
*****************************************************/
void send(int data)
{
  digitalWrite(CLK, LOW);
  delay(2);
  for (int i=15; i>=0; i--)
  { 
    delayMicroseconds(50);
    if((data>>i)&0x0001 >0)
      {
        digitalWrite(DAT, HIGH);
        //Serial.print(1);
      }
    else
       {
         digitalWrite(DAT, LOW);
        // Serial.print(0);
       }
    delayMicroseconds(50);
    digitalWrite(CLK, HIGH);
    delayMicroseconds(50);
    
    if(i>0)
    digitalWrite(DAT, LOW);
    else
    digitalWrite(DAT, HIGH);
    delayMicroseconds(50);
    
    if(i>0)
    digitalWrite(CLK, LOW);
    else
    digitalWrite(CLK, HIGH);
  }
  
  delay(20); 
}


