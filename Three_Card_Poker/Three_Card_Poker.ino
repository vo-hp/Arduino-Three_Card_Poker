#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);



String numberPlayers = "";
String player[17];
String card;
String playerscard[3][17];
String sumPlayersCards[17];

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
  if (cards.length() >= 2) {
    if (containNotOnlyDigits(cards)) {
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

bool containMoreThan4Cards(const String d) {
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
      player[countNumber] = Serial.readStringUntil('\n');
      player[countNumber].trim();
      Serial.println(player[countNumber]);
      lcd.setCursor(0, 1);
      lcd.print(player[countNumber]);
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
        checkCard(countCards, countPlayers);
      }
      while (Serial.available() ) {
        Serial.read();
      }
    }
    Serial.println("sum = " + String(sum(playerscard[0][countPlayers], playerscard[1][countPlayers], playerscard[2][countPlayers])));
  }
}

void checkCard(int countCards, int countPlayers) {
  playerscard[countCards][countPlayers] = Serial.readStringUntil('\n');
  playerscard[countCards][countPlayers].trim();
  Serial.println(playerscard[countCards][countPlayers]);
  lcd.setCursor(14, 0);
  lcd.print(playerscard[countCards][countPlayers]);
  delay(1000);
  if (containNotOnlyCard(playerscard[countCards][countPlayers])) {
    lcd.clear();
    Serial.println("Re-enter card: ");
    lcd.setCursor(0, 0);
    lcd.print("Re-enter card: ");
    while (Serial.available()) {
      Serial.read();
    }
    while (Serial.available() == 0) {}
    checkCard(countCards, countPlayers);
  }
}


int sum(String a, String b, String c) {
  if (a == "J") { a = "10"; }
  if (b == "J") { b = "10"; }
  if (c == "J") { c = "10"; }
  if (a == "Q") { a = "10"; }
  if (b == "Q") { b = "10"; }
  if (c == "Q") { c = "10"; }
  if (a == "K") { a = "10"; }
  if (b == "K") { b = "10"; }
  if (c == "K") { c = "10"; }
  if (a == "A") { a = "11"; }
  if (b == "A") { b = "11"; }
  if (c == "A") { c = "11"; }
  int result = a.toInt() + b.toInt() + c.toInt();
  if (result > 10 and result < 20) {
    result = result - 10;
  }
  if (result > 20 and result < 30) {
    result = result - 20;
  }
  if (result > 30) {
    result = result - 30;
  }
  if (result == 10 or result == 20 or result == 30) {
    result = 0;
  }
  return result;
}

void arrangePlayers() {
  for ( int x = 0; x < numberPlayers.toInt(); x++) {
    for (int )
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

// vượt qua bốn lá
// hiển thị kết quả từng người
// hiển thị ngừoi chiến thắng