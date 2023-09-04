#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);


String numberPlayers = "";
String playerName[17];
int player1Card[3];

bool containNotOnlyDigits(const String& str) {
  for (int c = 0; c < str.length(); c++) {
    char d = str[c];
    if (!isdigit(d)) {
      return true;
    }
  }
  return false;
}

void checkNumberPlayers() {
  numberPlayers = Serial.readStringUntil('\n');
  numberPlayers.trim();
  Serial.println(numberPlayers);
  lcd.setCursor(14, 0);
  lcd.print(numberPlayers.toInt());
  delay(1000);
  if (numberPlayers.toInt() < 2 or numberPlayers.toInt() > 17 or containNotOnlyDigits(numberPlayers)) {
    lcd.clear();
    Serial.println("Please re-enter: ");
    lcd.setCursor(0, 0);
    lcd.print("Pls re-enter: ");
    while (Serial.available() == 0) {}
    if (Serial.available() > 0) {
      checkNumberPlayers();
    }
  }
}

void processPlayersName() {
  for (int countNumber = 0; countNumber < numberPlayers.toInt(); countNumber++) {
    lcd.clear();
    Serial.println("Player" + String(countNumber + 1) + "'s name: ");
    lcd.setCursor(0, 0);
    lcd.print("Player" + String(countNumber + 1) + "'s name: ");
    while (Serial.available() == 0) {}
    if (Serial.available() > 0) {
      playerName[countNumber] = Serial.readStringUntil('\n');
      playerName[countNumber].trim();
      Serial.println(playerName[countNumber]);
      lcd.setCursor(0, 1);
      lcd.print(playerName[countNumber]);
      delay(1000);
    }
    while (Serial.available() > 0) {
      Serial.read();
    }
  }
}

void processPlayersCard() {

}

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
}

void loop() {
  Serial.println("Welcome to three card porker");
  lcd.setCursor(0, 0);
  lcd.print("Welcome! ");
  delay(1000);
  Serial.println("Enter number: ");  // enter the number of players
  lcd.setCursor(0, 0);
  lcd.print("Enter number: ");  // enter the number of players
  while (Serial.available() == 0) {
  }
  if (Serial.available() > 0) {
    checkNumberPlayers();
  }
  processPlayersName();

  lcd.clear();
}