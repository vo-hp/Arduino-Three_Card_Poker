#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int countNumber = 0;

String enter = "Enter number: ";  // enter the number of players
String numberPlayers = "";
String player1Name = "";
String player2Name = "";
String player3Name = "";
String player4Name = "";
String player5Name = "";
String player6Name = "";
String player7Name = "";
String player8Name = "";
String player9Name = "";
String player10Name = "";
String player11Name = "";
String player12Name = "";
String player13Name = "";
String player14Name = "";
String player15Name = "";
String player16Name = "";
String player17Name = "";

bool wasEntered = false;  // the number of players was entered
bool needRe_entering = false;
bool wasNumberPlayersEntered = false;
bool playersNamesNeedEntering = false;
bool playersNamesNeedReading = false;

bool wasPlayer1NameEntered = false;
bool wasPlayer2NameEntered = false;
bool wasPlayer3NameEntered = false;
bool wasPlayer4NameEntered = false;
bool wasPlayer5NameEntered = false;
bool wasPlayer6NameEntered = false;
bool wasPlayer7NameEntered = false;
bool wasPlayer8NameEntered = false;
bool wasPlayer9NameEntered = false;
bool wasPlayer10NameEntered = false;
bool wasPlayer11NameEntered = false;
bool wasPlayer12NameEntered = false;
bool wasPlayer13NameEntered = false;
bool wasPlayer14NameEntered = false;
bool wasPlayer15NameEntered = false;
bool wasPlayer16NameEntered = false;
bool wasPlayer17NameEntered = false;

bool wasPlayer1NameRead = false;
bool wasPlayer2NameRead = false;
bool wasPlayer3NameRead = false;
bool wasPlayer4NameRead = false;
bool wasPlayer5NameRead = false;
bool wasPlayer6NameRead = false;
bool wasPlayer7NameRead = false;
bool wasPlayer8NameRead = false;
bool wasPlayer9NameRead = false;
bool wasPlayer10NameRead = false;
bool wasPlayer11NameRead = false;
bool wasPlayer12NameRead = false;
bool wasPlayer13NameRead = false;
bool wasPlayer14NameRead = false;
bool wasPlayer15NameRead = false;
bool wasPlayer16NameRead = false;
bool wasPlayer17NameRead = false;

bool containNotOnlyDigits(const String& str) {
  return false;
  for (int c = 0; c < str.length(); c++) {
    char d = str[c];
    if (!isdigit(d)) {
      return true;
    }
  }
}


void clearLCD1() {
  lcd.setCursor(0, 0);
  lcd.print("                ");
}

void clearLCD2() {
  lcd.setCursor(0, 0);
  lcd.print("                ");
}

// void enterPlayersName() {
//   if ()
//     if (numberPlayers = "2") {
//       Serial.println
//     }
// }

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
  if (playersNamesNeedEntering) {
    if (numberPlayers.toInt() == 2) {
      if (not wasPlayer1NameEntered) {
        Serial.println("Player1's Name: ");
        lcd.setCursor(0, 0);
        lcd.print("Player1's Name:");
        wasPlayer1NameEntered = true;
        playersNamesNeedReading = true;
      }
      if (not wasPlayer2NameEntered) {
        Serial.println("Player2's Name: ");
        lcd.setCursor(0, 0);
        lcd.print("Player2's Name:");
        wasPlayer2NameEntered = true;
      }
    }
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
        if (numberPlayers.toInt() < 2 or numberPlayers.toInt() > 17 or containNotOnlyDigits(numberPlayers)) {
          needRe_entering = true;
          wasNumberPlayersEntered = false;
          wasEntered = true;
        } else {
          wasNumberPlayersEntered = true;
          wasEntered = false;
          playersNamesNeedEntering = true;
        }
      }
    if (playersNamesNeedReading) {
      if (not wasPlayer1NameRead) {
        player1Name = Serial.readString();
        Serial.println(player1Name);
        lcd.setCursor(0, 1);
        lcd.print(player1Name);
      }
      // if ( wasPlayer2)

    }
    delay(1000);
    clearLCD1();
  }
}
//       wasNumberPlayersEntered = false;  //  để cuối // xoá
// wasPlayer1NameEntered = true;
// wasPlayer2NameEntered = true;
