//includes the LCD library
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>
 // Init the LCD with the stated pin numbers
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
unsigned long time;
Servo servo_m;
char* password="1997";
int position=0;

const byte ROWS=4;
const byte COLS=4;
char keys[ROWS][COLS]={
  {'1','2','3','A'},
   {'4','5','6','B'},
    {'7','8','9','C'},
     {'*','0','#','D'}
  };
byte rowPins[ROWS]={8,7,6,9};
byte colPins[COLS]={5,4,3,2};
Keypad keypad=Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

void setup()
{
 // Sets the no. of rows and columns of the LCD
 lcd.begin(16, 2);
   servo_m.attach(10);
  Locked(true);
}
void loop()
{
 // Read the number of elapsed seconds from the program start
 time = millis() / 1000;
 // Set the cursor on col 0, row 0 (first row)
 lcd.setCursor(0, 0);
 // Write a string of characters
lcd.setCursor(0, 0);
  lcd.print("    Hello");
  lcd.setCursor(0, 1);
  lcd.print(" Enter Password");
 // Move the cursor in the middle of the second row (row 1)
 lcd.setCursor(7, 1);

 
 {char key=keypad.getKey();
 
if (key=='A' || key=='B'|| key=='C'|| key=='D')
{position=0;
Locked(true);

}

else if (key==password[position])
{position++;if(position==4)
{Locked(false);
 lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Verified ");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0, 0);
}}
if(key=='0')
{setLoop(true);}
delay(100);}}

void Locked(int locked)
{if (locked)
{servo_m.write(10);}
else
{servo_m.write(90);}}
 
void setLoop(int loope)
{if (loope)
{for (position = 0; position <= 180; position += 1) { 
    
    servo_m.write(position);             
    delay(15);                      
  }
  for (position = 180; position >= 0; position -= 1) { 
    servo_m.write(position);             
    delay(15);                      
  }}
   }
