/*
  Copyright 2016 Kiibo 
 
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
  
  Dit is een programma waarmee je kan testen of alle toetsen van het kiibo toetsenbord correct werken.
  Je moet de combinatie kiezen van de row en colom kiezen voor de toets die je wil testen.
  De colom wordt als input gebruikt en de row als output. Als het goed is zie je in de 
  Serial Monitor als er geen toetsen zijn ingedrukt alleen maar eenen. Zodra de teste toets
  wordt ingedrukt moet er een afwisseling van eenen en nullen verschijnen op de Serial Monitor.
 
  Kiibo pinout:
  Col1  7
  Col2  8
  Col3  9
  Col4  10
  Col5  11
  Col6  12
  Col7  13
  Col8  14
  Col9  15
  Col10 16
  Col10 17
  Col12 18
  Row1  23
  Row2  22
  Row3  21
  Row4  20
  Row5  19
 */
 

void setup() {
  //start de serial Connection 
  Serial.begin(9600);
  //gebruik het pin nummer van de te meten colom als INPUT met ingebouwde pull-up weerstand
  pinMode(11, INPUT);
  //het pin nummer van de te meten row als OUTPUT
  pinMode(23, OUTPUT); 

}

void loop() {
  //lees de waarde van een bepaalde input
  long switchVal = digitalRead(11);
  //laat de waarde van de toets zien in de Serial Monitor
  Serial.println(switchVal);

  //Doordat we INPUT_PULLUP gebruiken is alle "logic"
  //omgekeerd. Een signaal is HIGH als het circuit open
  //is en LOW als er een knop is ingedrukt.
  if (switchVal == HIGH) {
    digitalWrite(23, LOW);
  } else {
    digitalWrite(23, HIGH);
  }
  delay(100);
}



