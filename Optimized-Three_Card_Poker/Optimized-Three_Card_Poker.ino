#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int maxPlayers = 17;
String player[maxPlayers];
String playerscard[3][maxPlayers];
int sumPlayersCards[maxPlayers];

bool isDigitString(const String& str) {
  for (char c : str) {
    if (!isdigit(c)) {
      return false;
    }
  }
  return true;
}

bool isValidCard(const String& card) {
  if (card == "J" || card == "Q" || card == "K" || card == "A") {
    return true;
  }
  int num = card.toInt();
  return (num >= 2 && num <= 10);
}

int sum(String a, String b, String c) {
  int result = 0;
  
  String cards[] = {a, b, c};
  for (String card : cards) {
    if (card == "J" || card == "Q" || card == "K") {
      result += 10;
    } else if (card == "A") {
      result += 11;
    } else if (card.toInt() >= 2 && card.toInt() <= 10) {
      result += card.toInt();
    }
  }
  
  return result % 10;
}


void displayMessage(const String& message) {
  Serial.println(message);
  lcd.setCursor(0, 0);
  lcd.print(message);
  delay(1000);
}

int inputNumberPlayers() {
  displayMessage("Enter number of players: ");
  while (true) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    if (isDigitString(input)) {
      int num = input.toInt();
      if (num >= 2 && num <= maxPlayers) {
        return num;  // This is just a void return to exit the function
      }
    }
    if (input != "") {
      displayMessage("Invalid input. Please try again.");
      displayMessage("Enter number of players: ");
    }
  }
}

void inputPlayerNames(int numPlayers) {
  for (int i = 0; i < numPlayers; i++) {
    displayMessage("Player " + String(i + 1) + "'s name: ");
    while (true) {
      String tempPlayer = Serial.readStringUntil('\n');
      tempPlayer.trim();
      if (tempPlayer != "") {
        player[i] = tempPlayer;
        break;
      }
    }
  }
}

void inputPlayerCards(int numPlayers) {
  for (int i = 0; i < numPlayers; i++) {
    for (int j = 0; j < 3; j++) {
      displayMessage("Player " + player[i] + "'s card " + String(j + 1) + ": ");
      while (true) {
        String tempplayerscard = Serial.readStringUntil('\n');
        tempplayerscard.trim();
        if (tempplayerscard != "" and isValidCard(tempplayerscard)) {
          playerscard[j][i] = tempplayerscard;
          break;
        }
        if (tempplayerscard != "") {
          displayMessage("Invalid card. Please try again.");
        }
      }
    }
    sumPlayersCards[i] = sum(playerscard[0][i], playerscard[1][i], playerscard[2][i]);
    Serial.println("sum = " + String(sumPlayersCards[i]));
  }
}

void bubbleSortPlayers(int numPlayers) {
  for (int i = 0; i < numPlayers - 1; i++) {
    for (int j = 0; j < numPlayers - i - 1; j++) {
      if (sumPlayersCards[j] < sumPlayersCards[j + 1]) {
        // Swap scores
        int tempScore = sumPlayersCards[j];
        sumPlayersCards[j] = sumPlayersCards[j + 1];
        sumPlayersCards[j + 1] = tempScore;

        // Swap player names
        String tempPlayer = player[j];
        player[j] = player[j + 1];
        player[j + 1] = tempPlayer;
      }
    }
  }
}

void setup() {
  Serial.begin(19200);
  lcd.init();
  lcd.backlight();
  Serial.println("Welcome to three-card poker");
  lcd.setCursor(0, 0);
  lcd.print("Welcome!");
}

void loop() {
  int numPlayers = inputNumberPlayers();
  inputPlayerNames(numPlayers);
  inputPlayerCards(numPlayers);
  bubbleSortPlayers(numPlayers);
  Serial.println("Winner is " + player[0] + " - " + String(sumPlayersCards[0]));
  lcd.clear();
}
