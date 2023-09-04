#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int countNumber = 1;
int stage = 0;

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
bool playersNamesNeedEntering = false;

bool player1NameNeedEntering = false;
bool player2NameNeedEntering = false;
bool player3NameNeedEntering = false;
bool player4NameNeedEntering = false;
bool player5NameNeedEntering = false;
bool player6NameNeedEntering = false;
bool player7NameNeedEntering = false;
bool player8NameNeedEntering = false;
bool player9NameNeedEntering = false;
bool player10NameNeedEntering = false;
bool player11NameNeedEntering = false;
bool player12NameNeedEntering = false;
bool player13NameNeedEntering = false;
bool player14NameNeedEntering = false;
bool player15NameNeedEntering = false;
bool player16NameNeedEntering = false;
bool player17NameNeedEntering = false;

bool player1NameNeedReading = false;
bool player2NameNeedReading = false;
bool player3NameNeedReading = false;
bool player4NameNeedReading = false;
bool player5NameNeedReading = false;
bool player6NameNeedReading = false;
bool player7NameNeedReading = false;
bool player8NameNeedReading = false;
bool player9NameNeedReading = false;
bool player10NameNeedReading = false;
bool player11NameNeedReading = false;
bool player12NameNeedReading = false;
bool player13NameNeedReading = false;
bool player14NameNeedReading = false;
bool player15NameNeedReading = false;
bool player16NameNeedReading = false;
bool player17NameNeedReading = false;



bool containNotOnlyDigits(const String& str) {
  return false;
  for (int c = 0; c < str.length(); c++) {
    char d = str[c];
    if (!isdigit(d)) {
      return true;
    }
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
  if (playersNamesNeedEntering) {
    if (player1NameNeedEntering) {
      Serial.println("Player1's Name: ");
      lcd.setCursor(0, 0);
      lcd.print("Player1's Name:");
      player1NameNeedReading = true;
      stage++;
      countNumber++;
      player1NameNeedEntering = false;
    }
    if (player2NameNeedEntering) {
      Serial.println("Player2's Name: ");
      lcd.setCursor(0, 0);
      lcd.print("Player2's Name:");
      player2NameNeedReading = true;
      countNumber++;
      player2NameNeedEntering = false;
    }
    if (player3NameNeedEntering) {
      Serial.println("Player3's Name: ");
      lcd.setCursor(0, 0);
      lcd.print("Player3's Name:");
      player3NameNeedReading = true;
      countNumber++;
      player3NameNeedEntering = false;
    }
    if (player4NameNeedEntering) {
      Serial.println("Player4's Name: ");
      lcd.setCursor(0, 0);
      lcd.print("Player4's Name:");
      player4NameNeedReading = true;
      countNumber++;
      player4NameNeedEntering = false;
    }
    if (player5NameNeedEntering) {
      Serial.println("Player5's Name: ");
      lcd.setCursor(0, 0);
      lcd.print("Player5's Name:");
      player5NameNeedReading = true;
      countNumber++;
      player5NameNeedEntering = false;
    }
    if (player6NameNeedEntering) {
      Serial.println("Player6's Name: ");
      lcd.setCursor(0, 0);
      lcd.print("Player6's Name:");
      player6NameNeedReading = true;
      countNumber++;
      player6NameNeedEntering = false;
    }
    if (player7NameNeedEntering) {
      Serial.println("Player7's Name: ");
      lcd.setCursor(0, 0);
      lcd.print("Player7's Name:");
      player7NameNeedReading = true;
      countNumber++;
      player7NameNeedEntering = false;
    }
    if (player8NameNeedEntering) {
      Serial.println("Player8's Name: ");
      lcd.setCursor(0, 0);
      lcd.print("Player8's Name:");
      player8NameNeedReading = true;
      countNumber++;
      player8NameNeedEntering = false;
    }
    if (player9NameNeedEntering) {
      Serial.println("Player9's Name: ");
      lcd.setCursor(0, 0);
      lcd.print("Player9's Name:");
      player9NameNeedReading = true;
      countNumber++;
      player9NameNeedEntering = false;
    }
    if (player10NameNeedEntering) {
      Serial.println("Player10's Name: ");
      lcd.setCursor(0, 0);
      lcd.print("Player10's Name:");
      player10NameNeedReading = true;
      countNumber++;
      player10NameNeedEntering = false;
    }
    if (player11NameNeedEntering) {
      Serial.println("Player11's Name: ");
      lcd.setCursor(0, 0);
      lcd.print("Player11's Name:");
      player11NameNeedReading = true;
      countNumber++;
      player11NameNeedEntering = false;
    }
    if (player12NameNeedEntering) {
      Serial.println("Player12's Name: ");
      lcd.setCursor(0, 0);
      lcd.print("Player12's Name:");
      player12NameNeedReading = true;
      countNumber++;
      player12NameNeedEntering = false;
    }
    if (player13NameNeedEntering) {
      Serial.println("Player13's Name: ");
      lcd.setCursor(0, 0);
      lcd.print("Player13's Name:");
      player13NameNeedReading = true;
      countNumber++;
      player13NameNeedEntering = false;
    }
    if (player14NameNeedEntering) {
      Serial.println("Player14's Name: ");
      lcd.setCursor(0, 0);
      lcd.print("Player14's Name:");
      player14NameNeedReading = true;
      countNumber++;
      player14NameNeedEntering = false;
    }
    if (player15NameNeedEntering) {
      Serial.println("Player15's Name: ");
      lcd.setCursor(0, 0);
      lcd.print("Player15's Name:");
      player15NameNeedReading = true;
      countNumber++;
      player15NameNeedEntering = false;
    }
    if (player16NameNeedEntering) {
      Serial.println("Player16's Name: ");
      lcd.setCursor(0, 0);
      lcd.print("Player16's Name:");
      player16NameNeedReading = true;
      countNumber++;
      player16NameNeedEntering = false;
    }
    if (player17NameNeedEntering) {
      Serial.println("Player17's Name: ");
      lcd.setCursor(0, 0);
      lcd.print("Player17's Name:");
      player17NameNeedReading = true;
      countNumber++;
      player17NameNeedEntering = false;
    }
  }
  while (Serial.available() == 0) {
  }
  if (Serial.available() > 0) {
    if (stage == 0) {
      wasEntered = true;
      numberPlayers = Serial.readString();
      Serial.println(numberPlayers);
      lcd.setCursor(14, 0);
      lcd.print(numberPlayers.toInt());
      if (numberPlayers.toInt() < 2 or numberPlayers.toInt() > 17 or containNotOnlyDigits(numberPlayers)) {
        needRe_entering = true;
        stage = 0;
        wasEntered = true;
      } else {
        playersNamesNeedEntering = true;
        player1NameNeedEntering = true;
      }
    }
    if (stage == 1) {
      if (player1NameNeedReading) {
        player1Name = Serial.readString();
        Serial.println(player1Name);
        lcd.setCursor(0, 1);
        lcd.print(player1Name);
        player2NameNeedEntering = true;
        if (countNumber > numberPlayers.toInt()) {
          playersNamesNeedEntering = false;
          player2NameNeedEntering = false;
          wasEntered = true;
          stage = 0;
        }
        player1NameNeedReading = false;
      }
      if (player2NameNeedReading) {
        player2Name = Serial.readString();
        Serial.println(player2Name);
        lcd.setCursor(0, 1);
        lcd.print(String(player2Name));
        player3NameNeedEntering = true;
        if (countNumber > numberPlayers.toInt()) {
          playersNamesNeedEntering = false;
          player3NameNeedEntering = false;
          wasEntered = false;
          stage = 0;
        }
        player2NameNeedReading = false;
      }
      if (player3NameNeedReading) {
        player3Name = Serial.readString();
        Serial.println(player3Name);
        lcd.setCursor(0, 1);
        lcd.print(String(player3Name));
        player4NameNeedEntering = true;
        if (countNumber > numberPlayers.toInt()) {
          playersNamesNeedEntering = false;
          player4NameNeedEntering = false;
          wasEntered = false;
          stage = 0;
        }
        player3NameNeedReading = false;
      }
      if (player4NameNeedReading) {
        player4Name = Serial.readString();
        Serial.println(player4Name);
        lcd.setCursor(0, 1);
        lcd.print(String(player4Name));
        player5NameNeedEntering = true;
        if (countNumber > numberPlayers.toInt()) {
          playersNamesNeedEntering = false;
          player5NameNeedEntering = false;
          wasEntered = false;
          stage = 0;
        }
        player4NameNeedReading = false;
      }
      if (player5NameNeedReading) {
        player5Name = Serial.readString();
        Serial.println(player5Name);
        lcd.setCursor(0, 1);
        lcd.print(String(player5Name));
        player6NameNeedEntering = true;
        if (countNumber > numberPlayers.toInt()) {
          playersNamesNeedEntering = false;
          player6NameNeedEntering = false;
          wasEntered = false;
          stage = 0;
        }
        player5NameNeedReading = false;
      }
      if (player6NameNeedReading) {
        player6Name = Serial.readString();
        Serial.println(player6Name);
        lcd.setCursor(0, 1);
        lcd.print(String(player6Name));
        player7NameNeedEntering = true;
        if (countNumber > numberPlayers.toInt()) {
          playersNamesNeedEntering = false;
          player7NameNeedEntering = false;
          wasEntered = false;
          stage = 0;
        }
        player6NameNeedReading = false;
      }
      if (player7NameNeedReading) {
        player7Name = Serial.readString();
        Serial.println(player7Name);
        lcd.setCursor(0, 1);
        lcd.print(String(player7Name));
        player8NameNeedEntering = true;
        if (countNumber > numberPlayers.toInt()) {
          playersNamesNeedEntering = false;
          player8NameNeedEntering = false;
          wasEntered = false;
          stage = 0;
        }
        player7NameNeedReading = false;
      }
      if (player8NameNeedReading) {
        player8Name = Serial.readString();
        Serial.println(player8Name);
        lcd.setCursor(0, 1);
        lcd.print(String(player8Name));
        player9NameNeedEntering = true;
        if (countNumber > numberPlayers.toInt()) {
          playersNamesNeedEntering = false;
          player9NameNeedEntering = false;
          wasEntered = false;
          stage = 0;
        }
        player8NameNeedReading = false;
      }
      if (player9NameNeedReading) {
        player9Name = Serial.readString();
        Serial.println(player9Name);
        lcd.setCursor(0, 1);
        lcd.print(String(player9Name));
        player10NameNeedEntering = true;
        if (countNumber > numberPlayers.toInt()) {
          playersNamesNeedEntering = false;
          player10NameNeedEntering = false;
          wasEntered = false;
          stage = 0;
        }
        player9NameNeedReading = false;
      }
      if (player10NameNeedReading) {
        player10Name = Serial.readString();
        Serial.println(player10Name);
        lcd.setCursor(0, 1);
        lcd.print(String(player10Name));
        player11NameNeedEntering = true;
        if (countNumber > numberPlayers.toInt()) {
          playersNamesNeedEntering = false;
          player11NameNeedEntering = false;
          wasEntered = false;
          stage = 0;
        }
        player10NameNeedReading = false;
      }
      if (player11NameNeedReading) {
        player11Name = Serial.readString();
        Serial.println(player11Name);
        lcd.setCursor(0, 1);
        lcd.print(String(player11Name));
        player12NameNeedEntering = true;
        if (countNumber > numberPlayers.toInt()) {
          playersNamesNeedEntering = false;
          player12NameNeedEntering = false;
          wasEntered = false;
          stage = 0;
        }
        player11NameNeedReading = false;
      }
      if (player12NameNeedReading) {
        player12Name = Serial.readString();
        Serial.println(player12Name);
        lcd.setCursor(0, 1);
        lcd.print(String(player12Name));
        player13NameNeedEntering = true;
        if (countNumber > numberPlayers.toInt()) {
          playersNamesNeedEntering = false;
          player13NameNeedEntering = false;
          wasEntered = false;
          stage = 0;
        }
        player12NameNeedReading = false;
      }
      if (player13NameNeedReading) {
        player13Name = Serial.readString();
        Serial.println(player13Name);
        lcd.setCursor(0, 1);
        lcd.print(String(player13Name));
        player14NameNeedEntering = true;
        if (countNumber > numberPlayers.toInt()) {
          playersNamesNeedEntering = false;
          player14NameNeedEntering = false;
          wasEntered = false;
          stage = 0;
        }
        player13NameNeedReading = false;
      }
      if (player14NameNeedReading) {
        player14Name = Serial.readString();
        Serial.println(player14Name);
        lcd.setCursor(0, 1);
        lcd.print(String(player14Name));
        player15NameNeedEntering = true;
        if (countNumber > numberPlayers.toInt()) {
          playersNamesNeedEntering = false;
          player15NameNeedEntering = false;
          wasEntered = false;
          stage = 0;
        }
        player14NameNeedReading = false;
      }
      if (player15NameNeedReading) {
        player15Name = Serial.readString();
        Serial.println(player15Name);
        lcd.setCursor(0, 1);
        lcd.print(String(player15Name));
        player16NameNeedEntering = true;
        if (countNumber > numberPlayers.toInt()) {
          playersNamesNeedEntering = false;
          player16NameNeedEntering = false;
          wasEntered = false;
          stage = 0;
        }
        player15NameNeedReading = false;
      }
      if (player16NameNeedReading) {
        player16Name = Serial.readString();
        Serial.println(player16Name);
        lcd.setCursor(0, 1);
        lcd.print(String(player16Name));
        player17NameNeedEntering = true;
        if (countNumber > numberPlayers.toInt()) {
          playersNamesNeedEntering = false;
          player17NameNeedEntering = false;
          wasEntered = false;
          stage = 0;
        }
        player16NameNeedReading = false;
      }
      if (player17NameNeedReading) {
        player17Name = Serial.readString();
        Serial.println(player17Name);
        lcd.setCursor(0, 1);
        lcd.print(String(player17Name));
        if (countNumber > numberPlayers.toInt()) {
          playersNamesNeedEntering = false;
          wasEntered = false;
          stage = 0;
        }
        player17NameNeedReading = false;
      }
    }
    delay(1000);
    lcd.clear();
  }
}
// wasEntered = false;