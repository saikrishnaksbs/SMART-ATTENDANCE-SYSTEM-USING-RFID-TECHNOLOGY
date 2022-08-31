#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);

void setup()
{
  mySerial.begin(9600);     
  Serial.begin(9600);    
  delay(100);
}
void loop()
{
  if (Serial.available()>0)
      SendMessage();
}
 void SendMessage()
{
  mySerial.println("AT+CMGF=1");    
  delay(1000);  
  mySerial.println("AT+CMGS=\"+918790879328\"\r"); 
  delay(1000);
  mySerial.println("Your Ward is Absent today");
  delay(100);
   mySerial.println((char)26);
  delay(1000);
  
}

