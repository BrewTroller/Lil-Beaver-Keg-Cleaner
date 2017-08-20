#include <Wire.h> 
#include <LiquidCrystal_I2C.h>



#define BACKLIGHT_PIN     13
#define MAINDRAIN_PIN     1
#define WATERIN_PIN       2
#define CLEANER_PIN       3
#define CLEANERRETURN_PIN 4
#define SANI              5
#define SANIRETURN_PIN    6
#define CO2_PIN           7
#define AIR_PIN           8
#define btst              0
#define WATER_CYCLES      3
#define CLEAN_CYCLES      3
#define SANI_CYCLES       3
#define CO2_PURGE         3

//LiquidCrystal_I2C lcd(0x3f);  // Set the LCD I2C address

//LiquidCrystal_I2C lcd(0x3f, BACKLIGHT_PIN, POSITIVE);  // Set the LCD I2C address

LiquidCrystal_I2C lcd(0x3f, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

// Creat a set of new characters
const uint8_t charBitmap[][8] = {
   { 0xc, 0x12, 0x12, 0xc, 0, 0, 0, 0 },
   { 0x6, 0x9, 0x9, 0x6, 0, 0, 0, 0 },
   { 0x0, 0x6, 0x9, 0x9, 0x6, 0, 0, 0x0 },
   { 0x0, 0xc, 0x12, 0x12, 0xc, 0, 0, 0x0 },
   { 0x0, 0x0, 0xc, 0x12, 0x12, 0xc, 0, 0x0 },
   { 0x0, 0x0, 0x6, 0x9, 0x9, 0x6, 0, 0x0 },
   { 0x0, 0x0, 0x0, 0x6, 0x9, 0x9, 0x6, 0x0 },
   { 0x0, 0x0, 0x0, 0xc, 0x12, 0x12, 0xc, 0x0 }
   
};

void setup()
{
   int charBitmapSize = (sizeof(charBitmap ) / sizeof (charBitmap[0]));

  // Switch on the backlight
  pinMode ( BACKLIGHT_PIN, OUTPUT );
  digitalWrite ( BACKLIGHT_PIN, HIGH );
  
  lcd.begin(16,2);               // initialize the lcd 

   for ( int i = 0; i < charBitmapSize; i++ )
   {
      lcd.createChar ( i, (uint8_t *)charBitmap[i] );
   }

  lcd.home ();                   // go home
  lcd.print("Hello Chad ");  
  lcd.setCursor ( 0, 1 );        // go to the next line
  lcd.print ("Lets Wash Kegs");
  delay ( 3000 );
}

void loop()
{
//   lcd.home ();
//   // Do a little animation by writing to the same location
//   for ( int i = 0; i < 2; i++ )
//   {
//      for ( int j = 0; j < 16; j++ )
//      {
//         lcd.print (char(random(7)));
//      }
//      lcd.setCursor ( 0, 1 );
//   }
//   delay (200);
  lcd.home ();
  lcd.print("Lil Beaver Keg Washer v1.0");
  lcd.setCursor ( 0, 2);
  lcd.print ("W:");
  lcd.print (WATER_CYCLES);
  lcd.print (" C:");
  lcd.print (CLEAN_CYCLES);
  lcd.print (" S:");
  lcd.print (SANI_CYCLES);
  lcd.print (" G:");
  lcd.print (CO2_PURGE);

  btst == digitalRead(2);
  Serial.begin(9600);
  Serial.print("test\n");
  Serial.print(btst);
  delay (1000);
  
  
  
}
