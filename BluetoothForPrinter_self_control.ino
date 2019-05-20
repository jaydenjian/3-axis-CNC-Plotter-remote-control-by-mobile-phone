#include <SoftwareSerial.h>
SoftwareSerial BTSerial(13, 12); // RX | TX
char ch;
void setup()
{
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(19200);  // HC-06 current bound rate (default 9600)
}
void loop()
{
  // Keep reading from HC-06 and send to Arduino Serial Monitor
  if (BTSerial.available())
    ch=BTSerial.read();
  // Keep reading from Arduino Serial Monitor and send to HC-06
   if(ch =='f'){             //forward
       Serial.print("forward");
       Serial.print("\n");
    }
    if(ch=='b'){            //backward
      Serial.print("backward");
       Serial.print("\n");
    }
    if(ch=='l'){          //left
      Serial.print("left");
       Serial.print("\n");
    }
    if(ch=='r'){        //right
      Serial.print("right");
       Serial.print("\n");
    }
    if(ch=='d'){      //pen down
      Serial.print("down");
       Serial.print("\n");
    }
    if(ch=='u'){    //pen up
      Serial.print("up");
       Serial.print("\n");
    }
   if(ch =='m'){  //Auto Start
       Serial.print("Auto Start");
       Serial.print("\n");
    }
}
