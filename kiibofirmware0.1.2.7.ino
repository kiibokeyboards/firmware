//declare some variables

//input and output pins in a matrix
int columns[] = {7, 8, 9, 10, 11, 12, 6, 14, 15, 16, 17, 18};
int rows[] = {23, 22, 21, 20, 19}; 

//Matrix dimensions
const int rowCount = 5;   //the width of the matrices.
const int colCount = 12;  //The height of the matrices.

//initialization of key numbers
int board[rowCount][colCount] = {{1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12},
                                 {13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24},
                                 {25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36},
                                 {37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48},
                                 {49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60}};

//initialization of layer matrices                                
char layer1[rowCount][colCount] = {{'esc', '0', '1', '2', '3', '4', '5', '6', '7', '8','9', 'extra'},
                                  {'tab', 'y', 'p', 'f', 'g', '|', '/', 'r', 'h', 'k', 'l', 'j'},
                                  {'ctrl', 'a', 'Ø', 'e', 'i', ',', '.', 'd', 't', 'n', 's', 'enter'},
                                  {'shift', 'z', 'x', 'c', 'v', ';', 'accent', 'b', 'm', 'w', 'u', 'q'},
                                  {'alt', '-', '+', 'super', 'fn', 'back', '  k k', 'fn', 'left', 'up', 'down', 'right'}};

//used cols and row number in the matrices
int colNum;
int rowNum;

//state of button variables
int buttonPressed;
int buttonPushed;
int lastButtonPushed;
int buttonUpdate;
                              
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
  delay(2);                         //Wait for 2ms to not to interrupt with the same function but with other parameters.
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
  delay(2);                         //Another 2ms delay with the same purpose as the previous one.
}

void col(int colNum, int rowNum){                                       //Function row() that reads an input and prints a character.
  buttonPressed = digitalRead(columns[colNum]);                         //Read the state of an input.
  buttonPushed = board[rowNum][colNum];                                 //Declare which key number is used.
  if((buttonPressed  == LOW) && (buttonPushed != lastButtonPushed)){    //Check if an input is LOW and if the same button wasn't the previous button pressed. 
    char prt = layer1[rowNum][colNum];                                  //Get the right character from the matrix layer1.
    Keyboard.print(prt);                                                //Print the character as keyboard output.
    Serial.println(prt);                                                //Print the character in the Serial Monitor for debugging purposes.
    lastButtonPushed = board[rowNum][colNum];                           //Declare the last keynumber which was being used.
  }
  buttonUpdate = digitalRead(columns[colNum]);                          //Declare the state of the input again.                           
  if((buttonPushed == lastButtonPushed) && (buttonUpdate == HIGH)) {    //Check if its was the previous button which was pressed and if it is now HIGH.
    lastButtonPushed = 0;                                               //Reset the last buttonPushed state.
  }
}

