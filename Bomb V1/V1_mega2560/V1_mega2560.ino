#include <Keypad.h>
#include <LiquidCrystal.h>
#define pound 14
byte puste[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

int Scount = 0;
int Mcount = 30;
int Hcount = 0;
int DefuseTimer = 0; 

long secMillis = 0;
long interval = 1000;

char password[8];
int currentLength = 0;
int i = 0; 
char entered[8];

int ledPin = 53; // led
int ledPin2 = 51; // led
int ledPin3 = 49; // led

int explozja = 47;

LiquidCrystal lcd(A14, A13, A12, A11, A10, A9);

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {A7, A6, A5, A4};
byte colPins[COLS] = {A3, A2, A1, A0};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

////////////////////////////////////////////////////////////
void setup(){
  ////////////////////////////////////////////////////////////
lcd.createChar(0, puste);
  pinMode(ledPin, OUTPUT); // sets the digital pin as output
  pinMode(ledPin2, OUTPUT); // sets the digital pin as output
  pinMode(ledPin3, OUTPUT); // sets the digital pin as output
  pinMode (explozja, OUTPUT);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Bomb V1.0"); 
   lcd.setCursor(0,1);
  lcd.print("By ZabKoz#2744");
  delay(5000);
  lcd.clear();
   lcd.setCursor(3,0);
 lcd.print("Loading:");
 lcd.setCursor(0,1);
 lcd.write(8);
 delay(500);
 lcd.write(8);
 delay(500);
 lcd.write(8);
 delay(500);
 lcd.write(8);
 delay(500);
 lcd.write(8);
 delay(500);
 lcd.write(8);
 delay(500);
 lcd.write(8);
 delay(500);
 lcd.write(8);
 delay(500);
 lcd.write(8);
 delay(500);
 lcd.write(8);
 delay(500);
 lcd.write(8);
 delay(500);
 lcd.write(8);
 delay(500);
 lcd.write(8);
 delay(500);
 lcd.write(8);
 delay(500);
 lcd.write(8);
 delay(500);
 lcd.write(8);
 lcd.clear();
 lcd.setCursor(0,0);
 tone(52, 880, 200);
 lcd.print("Enter time:");
 lcd.setCursor(0,1);
 ustawienie(); 

    
}
void loop()////////////////////////////////////////////////////////
{
  
   char key1 = keypad.getKey(); // get the key
 { 
  if (key1 == '1')
    {
      tone(52, 880, 90);
      Mcount ++;
      ustawienie();
      }
      
    if (Mcount > 58){
      tone(52, 880, 90);
    Mcount = 0;
   Hcount ++;
     }
/////////////////////////////////////////
  if (key1 == '7')
    {
      tone(52, 880, 90);
      Mcount--;
     ustawienie();

      }
      
     if (Mcount < 0){
      tone(52, 880, 90);
     Hcount --;
     Mcount = 58;
    }
/////////////////////////////////////////
  if (key1 == '3')
    {
      tone(52, 880, 90);
      Scount ++;
      ustawienie();
      }
      
    if (Scount > 58){
      tone(52, 880, 90);
    Mcount ++;
   Scount = 0;
     }
/////////////////////////////////////////
  if (key1 == '9')
    {
      tone(52, 880, 90);
      Scount--;
     ustawienie();

      }
      
     if (Scount < 0){
      tone(52, 880, 90);
     Mcount --;
     Scount = 58;
    }
/////////////////////////////////////////
}


if (key1=='*')
{
  tone(52, 880, 90);
  lcd.clear();
  lcd.setCursor(0,0);
    lcd.print("Enter code:");
  while (currentLength < 8)
  
  {
    lcd.setCursor(currentLength + 4, 1);
    lcd.cursor();
    
    char key = keypad.getKey();
    
    key == NO_KEY;
    if (key != NO_KEY)
    {
      tone(52, 880, 90);
      if ((key != '*')&&(key != '#'))
      { 
      lcd.print(key);
      password[currentLength] = key;
      currentLength++;
      }
    }
  }

  if (currentLength == 8)
  {
    delay(1000);
    lcd.noCursor();
    lcd.clear();
    lcd.home();
    lcd.print("Wprowadzono: ");
    lcd.setCursor(4,1);
    tone(52, 880, 200);
    delay(300);
    tone(52, 660, 200);
    lcd.print(password[0]);
    lcd.print(password[1]);
    lcd.print(password[2]);
    lcd.print(password[3]);
    lcd.print(password[4]);
    lcd.print(password[5]);
    lcd.print(password[6]);
    lcd.print(password[7]);
    tone(1319, 200);
    delay(3000);
    lcd.clear();
    currentLength = 0;
    lcd.print("Click '5'");
    lcd.clear();
    }   
   
  
while ( key1!=NO_KEY){ 
  
  timer();
  char key2 = keypad.getKey(); 
  if (key2 == '*')
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Kod:  ");
      while (currentLength < 8)
        {
          
          timer();
          
          char key2 = keypad.getKey(); 
          if (key2 == '#')
            {
              currentLength = 0;
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("Code:  ");
              timer();

            }
          else                  
          if (key2 != NO_KEY)    
            {
              tone(52, 880, 200);
              lcd.setCursor(currentLength + 7, 0);
              lcd.cursor();
              lcd.print(key2);
              entered[currentLength] = key2;
              currentLength++;
              tone(1047, 200);
              delay(100);
              lcd.noCursor();
              lcd.setCursor(currentLength + 6, 0);
              lcd.print("*");
              lcd.setCursor(currentLength + 7, 0);
              lcd.cursor();
            }
        }

      if (currentLength == 8)
        {
          if (entered[0] == password[0] && entered[1] == password[1] && entered[2] == password[2] && entered[3] == password[3] &&entered[4] == password[4] && entered[5] == password[5] && entered[6] == password[6] && entered[7] == password[7])
            {
              lcd.noCursor();
              lcd.clear();
              lcd.home();
              lcd.print("Bomb");
              currentLength = 0;
              lcd.setCursor(0,1);
              lcd.print("Defused");
              analogWrite(ledPin,  59);
              analogWrite(ledPin2,  242);
              analogWrite(ledPin3,  21);
              
              delay(1000000000000000000000);
              
            }
            
      else
        {
          lcd.noCursor();
          lcd.clear();
          lcd.home();
          lcd.print("Wrong Password!");
          analogWrite(ledPin,  243);
          analogWrite(ledPin2,  22);
          analogWrite(ledPin3,  22);
         
    
          if (Hcount > 0)
            {
              Hcount = Hcount - 1;
            }
    
          if (Mcount > 0)
            {
              Mcount = Mcount - 59;
            }
          if (Scount > 0)
            {
              Scount = Scount - 59;
            }
        delay(1500);
        currentLength = 0;
       
          
        }
        
      }  
      
    }
    
} ///////////////////

  }
} 
  
 
  ////////////////////////////////////////////

 void updateScount(){
      //display hours - needs fixing for am pm

       if(Scount> 59){
        //reset to 1
        Scount = 1;
      }
      if(Scount< 10){
        lcd.setCursor(5,0);
        lcd.print(" ");
        lcd.setCursor(6,0);
      }
      else{
        lcd.setCursor(5,0);
      }
      lcd.print(Scount);
      
  }
  void ustawienie(){
     lcd.setCursor (0,1); // sets cursor to 2nd line
  lcd.print ("Timer:");

  if (Hcount >= 10)
    {
      lcd.setCursor (8,1);
      lcd.print (Hcount);
    }
  if (Hcount < 10) 
    {
      lcd.setCursor (8,1);
      lcd.write ("0");
      lcd.setCursor (9,1);
      lcd.print (Hcount);
    }

  lcd.print (":");

  if (Mcount >= 10)
    {
      lcd.setCursor (11,1);
      lcd.print (Mcount);
    }
  if (Mcount < 10) 
    {
      lcd.setCursor (11,1);
      lcd.write ("0");
      lcd.setCursor (12,1);
      lcd.print (Mcount);
    }
    
  lcd.print (":");

  if (Scount >= 10) 
    {
      lcd.setCursor (14,1);
      lcd.print (Scount);
    }
  if (Scount < 10) 
    {
      lcd.setCursor (14,1);
      lcd.write ("0");
      lcd.setCursor (15,1);
      lcd.print (Scount);
    }
    
    }
  
////////////////////////////////////////////////////////

void timer()
{
  
  if (Hcount <= 0)
  {
    if ( Mcount < 0 )
    {
      lcd.noCursor();
      tone(52, 880, 4000);
      lcd.clear();
      lcd.home();
      lcd.print("Bomb");
      lcd.setCursor (0,1);
      lcd.print("Exploded!");
      digitalWrite(explozja, HIGH);
      
      
      
      while (Mcount < 0) 
      {
        analogWrite(ledPin,  250);
        analogWrite(ledPin2, 0);
        analogWrite(ledPin3,  0);
      }
    } 
  }

  lcd.setCursor (0,1); // sets cursor to 2nd line
  lcd.print ("Timer:");

  if (Hcount >= 10)
    {
      lcd.setCursor (7,1);
      lcd.print (Hcount);
    }
  if (Hcount < 10) 
    {
      lcd.setCursor (7,1);
      lcd.write ("0");
      lcd.setCursor (8,1);
      lcd.print (Hcount);
    }

  lcd.print (":");

  if (Mcount >= 10)
    {
      lcd.setCursor (10,1);
      lcd.print (Mcount);
    }
  if (Mcount < 10) 
    {
      lcd.setCursor (10,1);
      lcd.write ("0");
      lcd.setCursor (11,1);
      lcd.print (Mcount);
    }
    
  lcd.print (":");

  if (Scount >= 10) 
    {
      lcd.setCursor (13,1);
      lcd.print (Scount);
    }
  if (Scount < 10) 
    {
      lcd.setCursor (13,1);
      lcd.write ("0");
      lcd.setCursor (14,1);
      lcd.print (Scount);
    }

  if (Hcount <0) 
    {
      Hcount = 0; 
    }

  if (Mcount <0) 
    {
      Hcount --; 
      Mcount = 59; 
    }

  if (Scount <1) // if 60 do this operation
    {
      Mcount --; // add 1 to Mcount
      Scount = 59; // reset Scount
    }

  if (Scount > 0) // do this oper. 59 times
    {
      unsigned long currentMillis = millis();
  
      if(currentMillis - secMillis > interval) 
        {
          tone(52, 880, 200);
          secMillis = currentMillis;
          Scount --; // add 1 to Scount
          analogWrite(ledPin,  247);
          analogWrite(ledPin2,  247);
          analogWrite(ledPin3,  73);
          delay(10); // waits for a second
          digitalWrite(ledPin, LOW); // sets the LED off
          digitalWrite(ledPin2, LOW);
          digitalWrite(ledPin3, LOW);
          delay(10); // waits for a second
         
          //lcd.clear();
        }
    }
}
