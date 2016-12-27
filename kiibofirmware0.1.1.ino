#include <elapsedMillis.h>

elapsedMillis timer0;

int C1 = 7;
int C2 = 8;
int C3 = 9;
int C4 = 10;
int C5 = 11;
int C6 = 12;
int C7 = 6; // pin 13 bleek speciale pin te zijn
int C8 = 14;
int C9 = 15;
int C10 = 16;
int C11 = 17;
int C12 = 18;
int R1 = 23;
int R2 = 22;
int R3 = 21;
int R4 = 20;
int R5 = 19;

void setup() {
  //start de serial Connection 
  Serial.begin(9600);
  pinMode(C1, INPUT_PULLUP);
  pinMode(C2, INPUT_PULLUP);
  pinMode(C3, INPUT_PULLUP);
  pinMode(C4, INPUT_PULLUP);
  pinMode(C5, INPUT_PULLUP);
  pinMode(C6, INPUT_PULLUP);
  pinMode(C7, INPUT_PULLUP);
  pinMode(C8, INPUT_PULLUP);
  pinMode(C9, INPUT_PULLUP);
  pinMode(C10, INPUT_PULLUP);
  pinMode(C11, INPUT_PULLUP);
  pinMode(C12, INPUT_PULLUP);
  pinMode(R1, OUTPUT); 
  pinMode(R2, OUTPUT); 
  pinMode(R3, OUTPUT); 
  pinMode(R4, OUTPUT); 
  pinMode(R5, OUTPUT); 
  digitalWrite(R1, HIGH);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  digitalWrite(R4, HIGH);
  digitalWrite(R5, HIGH);
}

void loop() {
  digitalWrite(R1, LOW);
  int Col1 = digitalRead(C1);
  if(Col1 == LOW)
  {
    digitalWrite(R1, HIGH);
    Serial.println("1;1");
    delay(100);
  };
  int Col2 = digitalRead(C2);
  if(Col2 == LOW)
  {
    digitalWrite(R1, HIGH);
    Serial.println("2;1");
    delay(100);
  }
  int Col3 = digitalRead(C3);
  if(Col3 == LOW)
  {
    digitalWrite(R1, HIGH);
    Serial.println("3;1");
    delay(100);
  }
  int Col4 = digitalRead(C4);
  if(Col4 == LOW)
  {
    digitalWrite(R1, HIGH);
    Serial.println("4;1");
    delay(100);
  }
  int Col5 = digitalRead(C5);
  if(Col5 == LOW)
  {
    digitalWrite(R1, HIGH);
    Serial.println("5;1");
    delay(100);
  }
  int Col6 = digitalRead(C6);
  if(Col6 == LOW)
  {
    digitalWrite(R1, HIGH);
    Serial.println("6;1");
    delay(100);
  }
  int Col7 = digitalRead(C7);
  if(Col7 == LOW)
  {
    digitalWrite(R1, HIGH);
    Serial.println("7;1");
    delay(100);
  }
  int Col8 = digitalRead(C8);
  if(Col8 == LOW)
  {
    digitalWrite(R1, HIGH);
    Serial.println("8;1");
    delay(100);
  }
  int Col9 = digitalRead(C9);
  if(Col9 == LOW)
  {
    digitalWrite(R1, HIGH);
    Serial.println("9;1");
    delay(100);
  }
  int Col10 = digitalRead(C10);
  if(Col10 == LOW)
  {
    digitalWrite(R1, HIGH);
    Serial.println("10;1");
    delay(100);
  }
  int Col11 = digitalRead(C11);
  if(Col11 == LOW)
  {
    digitalWrite(R1, HIGH);
    Serial.println("11;1");
    delay(100);
  }
  int Col12 = digitalRead(C12);
  if(Col12 == LOW)
  {
    digitalWrite(R1, HIGH);
    Serial.println("12;1");
    delay(100);
  }
}

