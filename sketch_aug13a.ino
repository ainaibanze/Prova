#include <BitbloqLiquidCrystal.h>
#include <Wire.h>

LiquidCrystal lcd(0);

int d1 = 12;
int d2 = 10;
int d3 = 11;
int d4 = 13;

int altaveu = 4;

int verd = 2;
int vermell = 3;

int codi[]={-1,-1,-1,-1};
int codi_encert[]={3,6,9,0};
int nou_v[]= {0,0,0,0};

int menu = 0;

int canvi = 0;
int n = 0;
int out = 0;
int seconds = 0;
int nou = 1;
long timee = 0;
int start = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  

  pinMode(d1, INPUT_PULLUP);
  pinMode(d2, INPUT_PULLUP);
  pinMode(d3, INPUT_PULLUP);
  pinMode(d4, INPUT_PULLUP);


  pinMode(altaveu, OUTPUT);
  pinMode(verd, OUTPUT);
  pinMode(vermell, OUTPUT);


  lcd.begin(16,2);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:

  if ( menu == 0 ){
    lcd.setCursor(0,0);
    lcd.print("Introdueix codi:");
    lcd.setCursor(0,1);
    lcd.print("   -  -  -  -   ");
    menu = 1;
    seconds = 0;
    canvi = 0;
    codi[0]=-1;
    codi[1]=-1;
    codi[2]=-1;
    codi[3]=-1;
    nou_v[0]=0;
    nou_v[1]=0;
    nou_v[2]=0;
    nou_v[3]=0;
    nou = 1;
    start = 0;
  }
  
  if ( menu == 1 ){
  
    if( digitalRead(d1) == 0 ){
      codi[0]=codi[0]+1;
      if (codi[0]==10) {
        codi[0] = 0;
      }
      lcd.setCursor(3,1);
      lcd.print(codi[0]);
      nou_v[0]=1;
      start = 1;
      if ( nou_v[0]==1 and nou_v[1]==1 and nou_v[2]==1 and nou_v[3]==1 ){
        timee = millis();
      }
    }
  
    if( digitalRead(d2) == 0 ){
      codi[1]=codi[1]+1;
      if (codi[1]==10) {
        codi[1] = 0;
      }
      lcd.setCursor(6,1);
      lcd.print(codi[1]);
      nou_v[1]=1;
      start = 1;
      if ( nou_v[0]==1 and nou_v[1]==1 and nou_v[2]==1 and nou_v[3]==1 ){
        timee = millis();
      }
    }
  
    if( digitalRead(d3) == 0 ){
      codi[2]=codi[2]+1;
      if (codi[2]==10) {
        codi[2] = 0;
      }
      lcd.setCursor(9,1);
      lcd.print(codi[2]);
      start = 1;
      nou_v[2]=1;
      if ( nou_v[0]==1 and nou_v[1]==1 and nou_v[2]==1 and nou_v[3]==1 ){
        timee = millis();
      }
    }
  
    if( digitalRead(d4) == 0 ){
      codi[3] = codi[3]+1;
      if (codi[3] == 10) {
        codi[3] = 0;
      }
      lcd.setCursor(12,1);
      lcd.print(codi[3]);
      start = 1;
      nou_v[3]=1;
      if ( nou_v[0]==1 and nou_v[1]==1 and nou_v[2]==1 and nou_v[3]==1 ){
        timee = millis();
      }
    }

    if (start == 0){
      timee = millis();
    }

    Serial.println(timee);
    
    if ((millis() - timee) > 2000 and nou_v[0]==1 and nou_v[1]==1 and nou_v[2]==1 and nou_v[3]==1){
      out = 0;
      delay(500);
      
      if ( codi[0] == 2 and codi[1] == 8 and codi[2] == 0 and codi[3] == 8 ){
        menu = 2;
        n = 0;
        start = 0;
      }
      else{
        if ( codi[0] != codi_encert[0] or codi[1] != codi_encert[1] or codi[2] != codi_encert[2] or codi[3] != codi_encert[3] ){
          digitalWrite(vermell, HIGH);
          lcd.setCursor(0,0);
          lcd.print("Codi Erroni !!! ");
          lcd.setCursor(0,1);
          lcd.print("                ");
          tone(altaveu, 200);
          noTone(altaveu);
          delay(1800);
          digitalWrite(vermell, LOW);
          menu = 0;
        }
        if ( codi[0] == codi_encert[0] and codi[1] == codi_encert[1] and codi[2] == codi_encert[2] and codi[3] == codi_encert[3] ){
          digitalWrite(verd, HIGH);
          lcd.setCursor(0,0);
          lcd.print("Porta oberta!!! ");
          lcd.setCursor(0,1);
          lcd.print("                ");
          tone(altaveu,300,1000);
          delay(100);
          tone(altaveu,450,1000);
          delay(100);
          tone(altaveu,600,1000);
          delay(100);
          tone(altaveu,300,1000);
          delay(100);
          tone(altaveu,450,1000);
          delay(100);
          tone(altaveu,600,1000);
          delay(100);
          tone(altaveu,750,1000);
          delay(100);
          tone(altaveu,450,1000);
          delay(100);
          tone(altaveu,900,1000);
          delay(1150);
          digitalWrite(verd, LOW);
          }
      }
    }
  
  
  }

  if ( menu == 2 ) {
    if ( n == 0 ){
      digitalWrite(verd, HIGH);
      digitalWrite(vermell, HIGH);
      canvi = 0;
      lcd.setCursor(0,0);
      lcd.print("Codi Nou:       ");
      lcd.setCursor(0,1);
      lcd.print("   -  -  -  -   ");
      codi_encert[0]=-1;
      codi_encert[1]=-1;
      codi_encert[2]=-1;
      codi_encert[3]=-1;
      nou_v[0]=0;
      nou_v[1]=0;
      nou_v[2]=0;
      nou_v[3]=0;
      n = 1;
    }

    if( digitalRead(d1) == 0 ){
      codi_encert[0]=codi_encert[0]+1;
      if (codi_encert[0]==10) {
        codi_encert[0] = 0;
      }
      lcd.setCursor(3,1);
      lcd.print(codi_encert[0]);
      nou_v[0]=1;
      start = 1;
      if ( nou_v[0]==1 and nou_v[1]==1 and nou_v[2]==1 and nou_v[3]==1 ){
        timee = millis();
      }
    }
  
    if( digitalRead(d2) == 0 ){
      codi_encert[1]=codi_encert[1]+1;
      if (codi_encert[1]==10) {
        codi_encert[1] = 0;
      }
      lcd.setCursor(6,1);
      lcd.print(codi_encert[1]);
      nou_v[1]=1;
      start = 1;
      if ( nou_v[0]==1 and nou_v[1]==1 and nou_v[2]==1 and nou_v[3]==1 ){
        timee = millis();
      }
    }
  
    if( digitalRead(d3) == 0 ){
      codi_encert[2]=codi_encert[2]+1;
      if (codi_encert[2]==10) {
        codi_encert[2] = 0;
      }
      lcd.setCursor(9,1);
      lcd.print(codi_encert[2]);
      nou_v[2]=1;
      start = 1;
      if ( nou_v[0]==1 and nou_v[1]==1 and nou_v[2]==1 and nou_v[3]==1 ){
        timee = millis();
      }
    }
  
    if( digitalRead(d4) == 0 ){
      codi_encert[3] = codi_encert[3]+1;
      if (codi_encert[3] == 10) {
        codi_encert[3] = 0;
      }
      lcd.setCursor(12,1);
      lcd.print(codi_encert[3]);
      nou_v[3]=1;
      start = 1;
      if ( nou_v[0]==1 and nou_v[1]==1 and nou_v[2]==1 and nou_v[3]==1 ){
        timee = millis();
      }
    }

    if (start == 0){
      timee = millis();
    }

    if ((millis() - timee) > 2000 and nou_v[0]==1 and nou_v[1]==1 and nou_v[2]==1 and nou_v[3]==1){
      lcd.setCursor(0,0);
      lcd.print("    Nou Codi    ");
      lcd.setCursor(0,1);
      lcd.print("    Introduit   ");
      menu = 0;
      delay(2000);
      digitalWrite(verd, LOW);
      digitalWrite(vermell, LOW);
      
    }
   }
  delay(175);
}


