#include <Bounce.h>

int columns[] = {7, 8, 9, 10, 11, 12, 6, 14, 15, 16, 17, 18};
int rows[] = {23, 22, 21, 20, 19};  
int colRow[] = {};
int colNum;
int rowNum;
int buttonPressed;
int buttonPushed;
int lastButtonPushed;
int buttonUpdate;
const int rowCount = 5;
const int colCount = 12;
int board[rowCount][colCount] = {{1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12},
                                 {13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24},
                                 {25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36},
                                 {37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48},
                                 {49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60}};
                                 
char layer1[rowCount][colCount] = {{'esc', '0', '1', '2', '3', '4', '5', '6', '7', '8','9', 'extra'},
                                  {'tab', 'y', 'p', 'f', 'g', '|', '/', 'r', 'h', 'k', 'l', 'j'},
                                  {'ctrl', 'a', 'Ø', 'e', 'i', ',', '.', 'd', 't', 'n', 's', 'enter'},
                                  {'shift', 'z', 'x', 'c', 'v', ';', 'accent', 'b', 'm', 'w', 'u', 'q'},
                                  {'alt', '-', '+', 'super', 'fn', 'back', '  k k', 'fn', 'left', 'up', 'down', 'right'}};
                                 
void setup() {
    for (int colPin = 0; colPin < colCount; colPin++) {
      pinMode(columns[colPin], INPUT_PULLUP);
    }
    for (int rowPin = 0; rowPin < rowCount; rowPin++) {
      pinMode(rows[rowPin], OUTPUT);
    }
    
    
}

void row(int rowNum){
  digitalWrite(rows[rowNum], LOW);
  delay(2);
  col(0, rowNum);
  col(1, rowNum);  
  col(2, rowNum);  
  col(3, rowNum);  
  col(4, rowNum);  
  col(5, rowNum);  
  col(6, rowNum);  
  col(7, rowNum);  
  col(8, rowNum);  
  col(9, rowNum);  
  col(10, rowNum);  
  col(11, rowNum);   
  digitalWrite(rows[rowNum], HIGH);
  delay(2);
}

void col(int colNum, int rowNum){
  buttonPressed = digitalRead(columns[colNum]);
  buttonPushed = board[rowNum][colNum];
  if((buttonPressed  == LOW) && (buttonPushed != lastButtonPushed)){
    char prt = layer1[rowNum][colNum];
    Keyboard.print(prt);
    Serial.println(prt);
    lastButtonPushed = board[rowNum][colNum];
  }
  buttonUpdate = digitalRead(columns[colNum]);
  if((buttonPushed == lastButtonPushed) && (buttonUpdate == HIGH)) {
    lastButtonPushed = 0;
  }
}

void loop() {
  row(0);
  row(1);
  row(2);
  row(3);
  row(4);
}
