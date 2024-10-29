#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

int tryCount = 5;
const byte ROWS = 4; 
const byte COLS = 4; 
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

const int buzz = 12;
LiquidCrystal_I2C lcd(0x27, 20, 4); 
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

bool resetMode = false;
String checkReset;
const String defaultCode = "1234#"; // Twój 4-cyfrowy kod
const String resetCode = "*698412CBA*";
String currentCode = defaultCode;
String inputCode = ""; // Przechowuje wprowadzony kod

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(buzz, OUTPUT);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("WPROWADZONO: ");
  lcd.setCursor(0, 1);
  char customKey = customKeypad.getKey();
    if(resetMode == true){
    if (customKey == '#'){
      currentCode = inputCode + '#';
      Serial.println(currentCode);
      Serial.println("powtórz hasło:");
      resetMode = false;
    }

  }

  if (customKey) {
    inputCode += customKey; // Dodaj naciśnięty klawisz do kodu
    digitalWrite(buzz, HIGH);
    delay(30);
    digitalWrite(buzz, LOW);
    Serial.print("Wprowadzono: ");
   for (int i = 0; i < inputCode.length(); i++) {
    lcd.print("*");
  }
    Serial.println(inputCode);
    if(customKey == '*' && resetCode.length() == inputCode.length()){
      
      checkReset = inputCode;
      resetPass();
    }
    if (customKey == '#') {
      checkPass();
      inputCode = ""; // Resetuj kod po sprawdzeniu
    }
  }


}


bool checkPass(){
  lcd.clear();
  if(tryCount == 0){
    Serial.println("MF zadużo błędów!!!");
    delay(6000);
    tryCount = 5;
    return 0;
  }
  if(inputCode == currentCode){
    Serial.println("DOOR is opened!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Drzwi otwierają się!");
    digitalWrite(buzz, HIGH);
    delay(1000);
    digitalWrite(buzz, LOW);
    lcd.clear();
    return true;
  } else if(inputCode.length() >= currentCode.length()){
    Serial.println("bajojajo!!!");
    digitalWrite(buzz, HIGH);
    delay(100);
    digitalWrite(buzz, LOW);
    delay(85);
    digitalWrite(buzz, HIGH);
    delay(100);
    digitalWrite(buzz, LOW);
    tryCount -= 1;
    return false;
  } else{
      Serial.println("wpisz kod od nowa!!@");
      return false;
  }
}

bool resetPass(){

  if(checkReset == resetCode){
      inputCode = "";
      resetMode = true;
      return true;
  }
}
