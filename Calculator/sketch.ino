#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>

// Display setup
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

// Keypad setup
const byte KEYPAD_ROWS = 4;
const byte KEYPAD_COLS = 4;
byte rowPins[KEYPAD_ROWS] = {5, 4, 3, 2};
byte colPins[KEYPAD_COLS] = {A3, A2, A1, A0};
char keys[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1', '2', '3', '+'},  // Keypad layout: 1, 2, 3, +
  {'4', '5', '6', '-'},  // Keypad layout: 4, 5, 6, -
  {'7', '8', '9', '*'},  // Keypad layout: 7, 8, 9, *
  {'.', '0', '=', '/'}   // Keypad layout: ., 0, =, /
};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS);

uint64_t value = 0;

// Function to display splash screen
void showSplashScreen() {
  lcd.print("My");
  lcd.setCursor(3, 0); // Set cursor position for 'Arduino'
  String message = "Calculator";
  for (byte i = 0; i < message.length(); i++) {
    lcd.print(message[i]);
    delay(50);
  }
  delay(500);
}

// Function to update cursor
void updateCursor() {
  if (millis() / 250 % 2 == 0 ) {
    lcd.cursor(); // Enable cursor blinking
  } else {
    lcd.noCursor(); // Disable cursor blinking
  }
}

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);

  showSplashScreen(); // Display splash screen
  lcd.clear();
  lcd.cursor();

  lcd.setCursor(1, 0); // Set cursor position
}

char operation = 0;
String memory = "";
String current = "";
uint64_t currentDecimal;
bool decimalPoint = false;

// Function to perform calculation
double calculate(char operation, double left, double right) {
  switch (operation) {
    case '+': return left + right;
    case '-': return left - right;
    case '*': return left * right;
    case '/': return left / right;
  }
}

// Function to process keypad input
void processInput(char key) {
  if ('-' == key && current == "") {
    current = "-";
    lcd.print("-");
    return;
  }

  switch (key) {
    case '+':
    case '-':
    case '*':
    case '/':
      if (!operation) {
        memory = current;
        current = "";
      }
      operation = key;
      lcd.setCursor(0, 1); // Set cursor position for operation
      lcd.print(key); // Print operation
      lcd.setCursor(current.length() + 1, 1); // Set cursor position for next input
      return;

    case '=':
      float leftNum = memory.toDouble();
      float rightNum = current.toDouble();
      memory = String(calculate(operation, leftNum, rightNum));
      current = "";
      lcd.clear();
      lcd.setCursor(1, 0); // Set cursor position
      lcd.print(memory); // Print result
      lcd.setCursor(0, 1); // Set cursor position for operation
      lcd.print(operation); // Print operation
      return;

  }

  if ('.' == key && current.indexOf('.') >= 0) {
    return;
  }

  if ('.' != key && current == "0") {
    current = String(key);
  } else if (key) {
    current += String(key);
  }

  lcd.print(key); // Print input
}

void loop() {
  updateCursor(); // Update cursor

  char key = keypad.getKey(); // Get key from keypad
  if (key) {
    processInput(key); // Process keypad input
  }
}
