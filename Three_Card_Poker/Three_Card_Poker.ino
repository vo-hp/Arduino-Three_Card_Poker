#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);


int countCards;
int countPlayers;

String numberPlayers = "";
String player[4][17];
String card;

bool containNotOnlyDigits(const String& str) {
  for (int c = 0; c < str.length(); c++) {
    char d = str[c];
    if (!isdigit(d)) {
      return true;
    }
  }
  return false;
}

bool containNotOnlyCard(const String cards) {
  if ( cards.length() >= 2) {
    if ( containNotOnlyDigits(cards) ) {
      return true;
    }    
  }
  if (cards != "J" and cards != "Q" and cards != "K" and cards != "A") {
    if (cards.toInt() < 2 or cards.toInt() > 10) {
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
  lcd.print(numberPlayers);
  delay(1000);
  if (numberPlayers.toInt() < 2 or numberPlayers.toInt() > 17 or containNotOnlyDigits(numberPlayers)) {
    lcd.clear();
    Serial.println("Please re-enter: ");
    lcd.setCursor(0, 0);
    lcd.print("Pls re-enter: ");
    while (Serial.available() > 0) {
      Serial.read();
    }
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
      player[0][countNumber] = Serial.readStringUntil('\n');
      player[0][countNumber].trim();
      Serial.println(player[0][countNumber]);
      lcd.setCursor(0, 1);
      lcd.print(player[0][countNumber]);
      delay(1000);
    }
    while (Serial.available() > 0) {
      Serial.read();
    }
  }
}

void processPlayersCards() {
  for (int countPlayers = 0; countPlayers < numberPlayers.toInt(); countPlayers++) {
    for (int countCards = 0; countCards < 3; countCards++) {
      lcd.clear();
      Serial.println("P" + String(countPlayers + 1) + "'s card " + String(countCards + 1) + ": ");
      lcd.setCursor(0, 0);
      lcd.print("P" + String(countPlayers + 1) + "'s card " + String(countCards + 1) + ":");
      while (Serial.available() == 0) {}
      if (Serial.available() > 0) {
        checkCard();
        while (Serial.available()) {
          Serial.read();
        }
      }
    }
  }
}

void checkCard() {
  player[countCards + 1][countPlayers] = Serial.readStringUntil('\n');
  player[countCards + 1][countPlayers].trim();
  Serial.println(player[countCards + 1][countPlayers]);
  lcd.setCursor(14, 0);
  lcd.print(player[countCards + 1][countPlayers]);
  delay(1000);
  card = player[countCards + 1][countPlayers];
  if (containNotOnlyCard(card)) {
    lcd.clear();
    Serial.println("Re-enter card: ");
    lcd.setCursor(0, 0);
    lcd.print("Re-enter card: ");
    while (Serial.available()) {
      Serial.read();
    }
    while (Serial.available() == 0) {}
    checkCard();
  }
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
  processPlayersCards();
  lcd.clear();
}