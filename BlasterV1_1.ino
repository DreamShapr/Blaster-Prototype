#include "SoftwareSerial.h"
#include "DFPlayer_Mini_Mp3.h"
#include <Adafruit_SSD1306.h>
#include <U8g2lib.h>
#include <Wire.h>

SoftwareSerial mySerial(11, 12); // RX, TX

//Displays
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
int visorChange = 0;

// Pins
int trigger = 10;
int reload = 8;
int ammo = 10;
int laser = 13;


void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  
  mp3_set_serial(mySerial);
  mp3_set_volume(15);       // set volume (30 max)
  mp3_set_EQ(0);   

  pinMode(trigger,INPUT_PULLUP);
  pinMode(trigger, INPUT);
  digitalWrite(trigger, HIGH);

  pinMode(reload,INPUT_PULLUP);
  pinMode(reload, INPUT);
  digitalWrite(reload, HIGH);

  pinMode(laser,OUTPUT);
  digitalWrite(laser,LOW);

  u8g2.begin();
  u8g2.clear();
  u8g2.sendBuffer();  
}

void loop() { 
    if(digitalRead(trigger)== HIGH) {
    if (ammo != 0) {
      mp3_play(5); 
      digitalWrite(laser,HIGH);
      delay(1200);
      ammo = ammo - 1; 
      digitalWrite(laser,LOW);
      delay(100);
    }else {
      mp3_play(2); 
      delay(1200); 
    }
  } 
  else {
    if(digitalRead(reload) == LOW) {
      mp3_play(3);
      delay(1200);
      ammo = 10;
    }
  }

  u8g2.firstPage(); 
  do {
    int a = random(2, 24);
    int b = random(2, 24);
    int c = random(2, 24);
    int d = random(2, 24);
    int e = random(2, 24);
   
    //Draw Scope
    u8g2.drawCircle(64, 30, 30);//Outer Ring
    u8g2.drawCircle(64, 30, 4);//Inner ring
    
    if (visorChange < 15) {
      u8g2.drawLine(40, 30, 30, 30);//left hash
      u8g2.drawLine(88, 30, 98, 30);//right hash
      u8g2.drawLine(64, 60, 64, 50);//bottom hash
      u8g2.drawLine(64, 2, 64, 10);//top hash
    }
    else {
      u8g2.drawLine(30, 2, 54, 25);//top left
      u8g2.drawLine(98, 2, 74, 25);//top right
      u8g2.drawLine(30, 60, 54, 40);//bottom left
      u8g2.drawLine(98, 60, 74 ,40);//bottom right
    }

    if(visorChange >= 30) {
      visorChange = 0;      
    }
    visorChange = visorChange + 1;
    u8g2.setFont(u8g2_font_tom_thumb_4x6_tf);
    u8g2.setCursor (92, 12);
    u8g2.print("IH-23");
    u8g2.setCursor(104, 52);
    u8g2.print("TDK");
    u8g2.setCursor(104, 64);
    u8g2.print(e);
    u8g2.print("Z");
    //Top Left Bars
    u8g2.drawLine(2, 2, a, 2);//bar 1
    u8g2.drawLine(2, 6, b, 6);//bar 2
    u8g2.drawLine(2, 10, c, 10);//bar 3
    u8g2.drawLine(2, 14, d, 14);//bar 4

    // BAR 5
    if (ammo >= 9) {
    u8g2.drawLine(2, 30, 17, 30);
    u8g2.drawLine(2, 31, 17, 31);
    u8g2.drawLine(2, 32, 17, 32);
    u8g2.drawLine(2, 33, 17, 33);
    }

    // BAR 4
    if (ammo >= 7) {
    u8g2.drawLine(2, 37, 17, 37);
    u8g2.drawLine(2, 38, 17, 38);
    u8g2.drawLine(2, 39, 17, 39);
    u8g2.drawLine(2, 40, 17, 40);
    }

    // BAR 3
    if (ammo >= 5) {
    u8g2.drawLine(2, 44, 17, 44);
    u8g2.drawLine(2, 45, 17, 45);
    u8g2.drawLine(2, 46, 17, 46);
    u8g2.drawLine(2, 47, 17, 47);
    }

    // BAR 2
    if (ammo >= 3) {
    u8g2.drawLine(2, 51, 17, 51);
    u8g2.drawLine(2, 52, 17, 52);
    u8g2.drawLine(2, 53, 17, 53);
    u8g2.drawLine(2, 54, 17, 54);
    }

    // BAR 1
    if (ammo >= 2) {
    u8g2.drawLine(2, 58, 17, 58);
    u8g2.drawLine(2, 59, 17, 59);
    }

    // BAR 1/2
    if (ammo >= 1) {
    u8g2.drawLine(2, 60, 17, 60);
    }
        
    // BAR 1/4
    if (ammo > 0) {
        u8g2.drawLine(2, 61, 17, 61);
    }

    delay(50);
  } while ( u8g2.nextPage() );
  
}
