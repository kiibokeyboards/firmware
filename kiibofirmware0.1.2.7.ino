//declare some variables

//input and output pins in a matrix
int columns[] = {7, 8, 9, 10, 11, 12, 6, 14, 15, 16, 17, 18};
int rows[] = {23, 22, 21, 20, 19}; 

//Matrix dimensions
const int rowCount = 5;   //the width of the matrices.
const int colCount = 12;  //The height of the matrices.

//initialization of key numbers
int keyNumbers[rowCount][colCount] = {{1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12},
                                 {13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24},
                                 {25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36},
                                 {37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48},
                                 {49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60}};

int stateMatrix[rowCount][colCount] = {{0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0},
                                      {0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0},
                                      {0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0},
                                      {0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0},
                                      {0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0}};

////initialization of layer matrices                                
int layer1[rowCount][colCount] = {{KEY_ESC, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0, KEY_0},
                                  {KEY_TAB, KEY_Y, KEY_P, KEY_F, KEY_G, KEY_BACKSLASH, KEY_SLASH, KEY_R, KEY_H, KEY_K, KEY_L, KEY_J},
                                  {MODIFIERKEY_CTRL, KEY_A, KEY_O, KEY_E, KEY_I, KEY_COMMA, KEY_PERIOD, KEY_D, KEY_T, KEY_N, KEY_S, KEY_ENTER},
                                  {MODIFIERKEY_SHIFT, KEY_Z, KEY_X, KEY_C, KEY_V, KEY_SEMICOLON, KEY_QUOTE, KEY_B, KEY_M, KEY_W, KEY_U, KEY_Q},
                                  {MODIFIERKEY_ALT, KEY_MINUS, KEY_EQUAL, MODIFIERKEY_GUI, 101, KEY_BACKSPACE, KEY_SPACE, 101, KEY_LEFT, KEY_UP, KEY_DOWN, KEY_RIGHT}};
                                  
//String layer2[rowCount][colCount] = {{"esc", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "extra"},
//                                     {"tab", "A", "p", "f", "g", "|", "/", "r", "h", "k", "l", "j"},
//                                     {"ctrl", "a", "o", "e", "i", ",", ".", "d", "t", "n", "s", "enter"},
//                                     {"shift", "z", "x", "c", "v", ";", "accent", "b", "m", "w", "u", "q"},
//                                     {"alt", "-", "+", "super", "fn", "back", "space", "fn", "left", "up", "down", "right"}};


//used cols and row number in the matrices
int colNum;
int rowNum;

//state of button variables
int buttonState;
int lastButtonState;
                           
void setup() {                                          //Setup function of all pins to input or output.
    for (int colPin = 0; colPin < colCount; colPin++) { //Setup all column pins as INPUT_PULLUP.
      pinMode(columns[colPin], INPUT_PULLUP);           //Note that INPUT_PULLUP is being used for better keypresses.
    }                                                   //This means that all logic is reversed.
    for (int rowPin = 0; rowPin < rowCount; rowPin++) { //Setup all row pins as OUTPUT.
      pinMode(rows[rowPin], OUTPUT);
    }
    
    
}

void loop() { //Looped function which runs function row() with different parameters
  row(0);     //run funcion row where the parameter between brackets is the row that must be used in the function row()
  row(1);       
  row(2);     
  row(3);     
  row(4);     
}

void row(int rowNum){               //Function row() which reads the state of each input
  digitalWrite(rows[rowNum], LOW);  //Set output on the used row to LOW. Which means in reversed logic that the output is "on".
  delay(1);                         //Wait for 2ms to not to interrupt with the same function but with other parameters.
  col(0, rowNum);                   //Run function col() where the first parameter is the column number and the second the row number.
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
  digitalWrite(rows[rowNum], HIGH); //Reset the output to HIGH to put the output "off".
  delay(1);                         //Another 2ms delay with the same purpose as the previous one.
}

void col(int colNum, int rowNum){                                       //Function row() that reads an input and prints a character.
  buttonState = digitalRead(columns[colNum]);                         //Read the state of an input.
  lastButtonState = stateMatrix[rowNum][colNum];                                 //Declare which key number is used.
  if((buttonState  == LOW) && (lastButtonState != 1)){    //Check if an input is LOW and if the same button wasn't the previous button pressed. 
    int KEY = layer1[rowNum][colNum];  //Get the right character from the matrix layer1.
    Keyboard.set_key1(KEY);
    Keyboard.send_now(); 
    stateMatrix[rowNum][colNum] = 1;                          //Declare the last keynumber which was being used.
  }
  //buttonUpdate = digitalRead(columns[colNum]);                          //Declare the state of the input again.                         
  if((lastButtonState == 1) && (buttonState == HIGH)) {    //Check if its was the previous button which was pressed and if it is now HIGH.
    Keyboard.set_key1(0);
    Keyboard.send_now();
    stateMatrix[rowNum][colNum] = 0;
  }
}
