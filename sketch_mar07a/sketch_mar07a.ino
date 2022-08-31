#include <SPI.h>
#include <Ethernet.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include<Wire.h>
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,16);
IPAddress server(192,168,1,10);
EthernetClient client;
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
const byte numRows= 4; 
const byte numCols= 4; 
char keymap[numRows][numCols]=
{
{'3', '3', '2', '1'},
{'6', '6', '5', '4'},
{'9', '9', '8', '7'},
{'#', '#', '0', '*'}
};
byte rowPins[numRows] = {9,8,7,6}; 
byte colPins[numCols]= {5,4,3,2}; 
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
char newNum[12]="";
int x=0;  
int i=0,temp;
void setup()
{
Serial.begin(9600);
  delay(100);
  Ethernet.begin(mac, ip);
  SPI.begin();
lcd.begin(16,2);
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("Enter Phone to");
lcd.setCursor(0,1);
lcd.print("register:");
}

void loop() {
  int key = myKeypad.getKey();
    if (key!=NO_KEY && key!='#' && key!='*')
    {
      newNum[x] = key;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(newNum);
        newNum[x+1]='\0';   
        x++;   
    }
 temp=1;
 if(key=='*'&& temp==1)
 {
  lcd.clear();
    lcd.setCursor(0,0);
      lcd.print("Check Number('*'-confirm):");
    for(int i=0;i<15;i++){
      delay(1000);
    lcd.scrollDisplayLeft();
    lcd.setCursor(0,1);
    lcd.print(newNum);
    }
    if (client.connect(server, 80)) {
    Serial.print("connected");
    client.print("GET /Main/test5.php?");
    client.print("phno=");
    client.print(newNum);
    client.println(" HTTP/1.1");
    client.println("Host: 192.168.1.10"); 
    client.println("Connection: close");
    Serial.println("completed");
    client.println(); 
    client.println(); 
    client.stop();    
  }
  else {
    Serial.println("--> connection failed\n");
  }
  }
  }
