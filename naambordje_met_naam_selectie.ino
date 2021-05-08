//niks=1023
//select=640 600-800
//left=408 400-600
//up=102 60-200
//down=254 200-400
//right=0-60


#include <LiquidCrystal.h>
//LCD pin to Arduino
const int pin_RS = 8;
const int pin_EN = 9;
const int pin_d4 = 4;
const int pin_d5 = 5;
const int pin_d6 = 6;
const int pin_d7 = 7;
const int pin_BL = 10;
int bier, shots;
const char letters[] = {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int charindex = 0;
int charsSize = 0;
int cx = 0;
int cy = 0;
LiquidCrystal lcd( pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);
byte B[] = {
  B00001,
  B01110,
  B01110,
  B00001,
  B01110,
  B01110,
  B00001,
  B11111
};
byte E[] = {
  B11111,
  B11111,
  B10001,
  B01110,
  B00000,
  B01111,
  B10001,
  B11111
};
byte R[] = {
  B11111,
  B11111,
  B01001,
  B00110,
  B01111,
  B01111,
  B01111,
  B11111
};
byte S[] = {
  B10000,
  B01111,
  B01111,
  B10001,
  B11110,
  B11110,
  B00001,
  B11111
};
byte h[] = {
  B01111,
  B01111,
  B01001,
  B00110,
  B01110,
  B01110,
  B01110,
  B11111
};
byte o[] = {
  B11111,
  B11111,
  B10001,
  B01110,
  B01110,
  B01110,
  B10001,
  B11111
};
byte t[] = {
  B10111,
  B10111,
  B00011,
  B10111,
  B10111,
  B10110,
  B11001,
  B11111
};

byte i[]={
  B11011,
  B11111,
  B10011,
  B11011,
  B11011,
  B11011,
  B10001,
  B11111
};
void setup() {
  
  lcd.createChar(1, B);
  lcd.createChar(2, i);
  lcd.createChar(3, E);
  lcd.createChar(4, R);
  lcd.createChar(5, S);
  lcd.createChar(6, h);
  lcd.createChar(7, o);
  lcd.createChar(8, t);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Voer naam in met");
  lcd.setCursor(0,1);
  lcd.print("UP,DOWN & SELECT");
  charsSize = sizeof(letters);
  typnaam();
  }
void typnaam(){
  int x;
  charindex = 0;
  x = analogRead (0);
  while (x>800){
    delay(1);
    x = analogRead (0);
  }
  lcd.clear();
  while (x>=0 && x<=630 || x>800){ //while up of down of niks
    if(charindex == charsSize){
      charindex = 0;
    }
    if(charindex == -1){
      charindex = charsSize;
    }
    if(cx==0){
      lcd.setCursor(cx, 1);
      lcd.print("^                    ");
    }
    else{
      lcd.setCursor(cx-1, 1);
      lcd.print(" ^                     ");
    }
    if (x>60&&x<200) {                      // letter+
      charindex++;
      lcd.setCursor(cx, cy);
      lcd.print(letters[charindex]);
      delay(300);
    }
    if (x>200&&x<400) {                    // letter-
      charindex--;
      lcd.setCursor(cx, cy);
      lcd.print(letters[charindex]);
      delay(300);
    }
    if (x>=0 &&x<60){                     // letter ->
        cx++;
        charindex = 0;
      if(cx>16){
        cx==0;
      }
      delay(200);
    }
    if (x>400 && x<600){                   // letter <-
      cx--;
        charindex = 0;
      if(cx<0){
        cx==0;
      }
      delay(200);
    }
    
    x = analogRead (0);
  }
}
void loop() { 
     int x;
  x = analogRead (0);

  if (x < 60) {                              //right
    lcd.setCursor(0,1);
    lcd.print("Bier:");
    lcd.print(bier);
    lcd.print(" ");
    lcd.write(5);
    delay(100);
    lcd.write(6);
    delay(100);
    lcd.write(7);
    delay(100);
    lcd.write(8);
    lcd.print(":");
    lcd.print(shots);
    delay(500);
    x = analogRead (0);
    while (x<400 || x>800){
      if (x>60&&x<200){
        shots++;
        lcd.setCursor(5,1);
        lcd.print(bier);
        lcd.print(" ");
        lcd.write(5);
        lcd.write(6);
        lcd.write(7);
        lcd.write(8);
        lcd.print(":");
        lcd.print(shots);
        delay(500);
      }
    if (x>200 && x<400){
        shots--;
        lcd.setCursor(5,1);
        lcd.print(bier);
        lcd.print(" ");
        lcd.write(5);
        lcd.write(6);
        lcd.write(7);
        lcd.write(8);
        lcd.print(":");
        lcd.print(shots);
        delay(500);
      }    
      x = analogRead (0);
    }
  }
  else if (x < 200) {                      //up
    
  }
  else if (x < 400) {                      //down
    
  }
  else if (x < 600) {                      //left
    lcd.setCursor(0,1);
    lcd.write(1);
    delay(100);
    lcd.write(2);
    delay(100);
    lcd.write(3);
    delay(100);
    lcd.write(4);
    lcd.print(":");
    lcd.print(bier);
    lcd.print(" Shot:");
    lcd.print(shots);
    delay(100);
    x = analogRead (0);
    while (x>60 && x<600 || x>800){
      if (x>60&&x<200){
        bier++;
        lcd.setCursor(5,1);
        lcd.print(bier);
        lcd.print(" Shot:");
        lcd.print(shots);
        delay(500);
      }
    if (x>200 && x<400){
        bier--;
        lcd.setCursor(5,1);
        lcd.print(bier);
        lcd.print(" Shot:");
        lcd.print(shots);
        delay(500);
      }    
      x = analogRead (0);
    }
 
  }    
  
  else if (x < 800) {                         //select
    lcd.setCursor(0, 1);
    lcd.print("Bier:");
    lcd.print(bier);
    lcd.print(" Shot:");
    lcd.print(shots);
  }
}
