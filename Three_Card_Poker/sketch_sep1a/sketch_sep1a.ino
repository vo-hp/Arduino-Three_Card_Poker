#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

String enter = "Enter number: ";  // enter the number of players
String numberPlayers = "";
String 

bool wasEntered = false;  // the number of players was entered
bool needRe_entering = false;
bool wasNumberPlayersEntered = false;
bool werePlayersNamesEntered = false;

void clearLCD1() {
  lcd.setCursor(0, 0);
  lcd.print("                ");
}

void clearLCD2() {
  lcd.setCursor(0, 0);
  lcd.print("                ");
}

void enterPlayersName() {
  if (numberPlayers = "2" ) {
    
  }
}

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
}

void loop() {
  if (not wasEntered) {
    Serial.println("Welcome to three card porker");
    lcd.setCursor(0, 0);
    lcd.print("Welcome! ");
    delay(1000);
    Serial.println("Enter number: ");  // enter the number of players
    lcd.setCursor(0, 0);
    lcd.print("Enter number: ");  // enter the number of players
  }
  if (needRe_entering) {
    Serial.println("Pls re-enter: ");
    lcd.setCursor(0, 0);
    lcd.print("Pls re-enter: ");
    needRe_entering = false;
  }
  while (Serial.available() == 0) {
  }
  if (Serial.available() > 0) {
    if (not wasNumberPlayersEntered) {
      wasEntered = true;
      numberPlayers = Serial.readString();
      Serial.println(numberPlayers);
      lcd.setCursor(14, 0);
      lcd.print(numberPlayers.toInt());
      if (numberPlayers.toInt() < 2 or numberPlayers.toInt() > 17) {
        needRe_entering = true;
        wasNumberPlayersEntered = false;
      } else {
        wasNumberPlayersEntered = true;
        wasEntered = false;
      }
    }
    if (not werePlayersNamesEntered ) {
    }
    delay(1000);
    clearLCD1();
  }
}
        // wasNumberPlayersEntered = false;
