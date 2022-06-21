/*Code for a 4x4 Keypad & 16x2 LCD display interafed with arduino Mega for simulation */
#include <LiquidCrystal.h>          // LCD library 
#include <Keypad.h>                 // Keypad library/header for matrix style keypads 

const byte ROWS = 4;                // No of rows for 4x4 keypad is 4
const byte COLS = 4;                // No of columns for 4x4 keypad is 4

//Assign key values in 4x4 matrix
char keys[ROWS][COLS] =
{
  {'7','8','9','/'},
  {'4','5','6','X'},
  {'1','2','3','-'},
  {'O','0','=','+'}
};
//Connections for the row pinouts of the keypad to the arduino Mega
byte rowPins[ROWS] = {2, 3, 4, 5};              //Row-Pins: pin-2:R1,pin-3:R2,pin-4:R3,pin5:R4

//Connections for the column pinouts of the keypad to the arduino Uno
byte colPins[COLS] = {6, 7, 8, 9};              //Column-Pins: pin-6:C1,pin-7:C2,pin-8:C3,pin-9:C4
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);      // 16x2 LCD connection to Arduino Mega

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );   // initialize Keypad library and gets values

void setup(){
  lcd.begin(16, 2);                                                         // deminsion of the LCD
  lcd.setCursor(0,0);                                                       // set the cursor of the lcd at row-0 and column-0 
  lcd.print("Press any key in");                                            // first display
  delay(2000);
  for(int i=0; i<16; i++)                                                 //for making the display move to...
    {
     lcd.scrollDisplayRight();                                            //...the left for 16 spaces
     delay(300);
    }
  lcd.clear();
  lcd.setCursor(0,0);                                                     // set the cursor of the lcd at row-1 and column-0     
  lcd.print("the keypad ");                                               // second display
  lcd.setCursor(0,1);
  lcd.print("Please:"); 
  delay(2000);
  for(int i=0; i<12; i++)                                                 //for making the display move to...
    {
     lcd.scrollDisplayLeft();                                             //...the left for 12 spaces
     delay(300);
    }
    
  lcd.clear();                                                              // clear the display
  lcd.setCursor(0,0);
  lcd.blink();
}
  
void loop(){
  char key = keypad.getKey();                                               // pressed key will be fetched by using getkey()  
  if (key){
    lcd.print(key);                                                         // display the pressed value to the LCD
    delay(2000);
  }
}
