#include <SPI.h>
#include <Ethernet.h>
#include<RFID.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
#define SS_PIN 8
#define RST_PIN 9
RFID rfid(SS_PIN,RST_PIN);
int serNum[5];
bool access = false;
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,16);
IPAddress server(192,168,1,10);
EthernetClient client;
int temp;
void setup() {
  Serial.begin(9600);
  delay(100);
  Ethernet.begin(mac, ip);
  SPI.begin();
    rfid.init();
    lcd.begin(16,2);
lcd.backlight();
}
void loop() { 
   lcd.setCursor(0,0);
   lcd.print(" Scan Your Card");
   delay(1000);
   if(rfid.isCard()){
        if(rfid.readCardSerial()){
            Serial.print(rfid.serNum[0]);
            Serial.print(" ");
            Serial.print(rfid.serNum[1]);
            Serial.print(" ");
            Serial.print(rfid.serNum[2]);
            Serial.print(" ");
            Serial.print(rfid.serNum[3]);
            Serial.print(" ");
            Serial.print(rfid.serNum[4]);
            Serial.println("");
            int cards[][5] = {
  {151,247,113,169,184},{64,6,82,163,183}
};
            for(int x = 0; x < sizeof(cards); x++){
              for(int i = 0; i < sizeof(rfid.serNum); i++ ){
                  if(rfid.serNum[i] != cards[x][i]) {
                      access = false;
                      break;
                  } else {
                      access = true;
                  }
              }
              if(access) break;
            }
           
        }   
       if(access){
          Serial.println("Welcome!"); 
          lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("Attendance");
         lcd.setCursor(0,1);
         lcd.print("Recorded.");
         delay(20000);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("Welcome!");
         delay(2000);
         temp=1;
      } else {
           Serial.println("Not Registered");
           lcd.clear();
           lcd.setCursor(0,0); 
           lcd.print("Not Registered");
           delay(20000);
       }        
    }
    if(temp==1){
  if (client.connect(server, 80)) {
    Serial.print("connected");
    client.print("GET /Main/test.php?");
    client.print("value=");
    client.print(rfid.serNum[0]);
    client.print(rfid.serNum[1]);
    client.print(rfid.serNum[2]);
    client.print(rfid.serNum[3]);
    client.print(rfid.serNum[4]);
    client.println(" HTTP/1.1");
    client.println("Host: 192.168.1.10"); 
    client.println("Connection: close");
    Serial.println("completed");
    client.println(); 
    client.println(); 
    client.stop(); 
    temp=0;   
  }}
  else {
    Serial.println("--> connection failed\n");
  }
  rfid.halt();
  
   }
