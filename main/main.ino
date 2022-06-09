#include <LedControl.h>

int MATRIX_DIN = 11;
int MATRIX_CS = 7;
int MATRIX_CLK = 13;
LedControl lc = LedControl(MATRIX_DIN, MATRIX_CLK, MATRIX_CS, 0);

unsigned long delaytime=600;

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 15);
  lc.clearDisplay(0);
}

void resetRow() {
   for(int i = 0; i < 8; i++){
      lc.setRow(0, i, 0);
  } 
}

void writeLetter(byte *letterArray) {
  for (int i = 0; i < 8; i++){
    lc.setRow(0, i, letterArray[i]);
  }
  delay(delaytime);
  resetRow();
}

void writeArduinoOnMatrix() {
  byte b[8]= {B00000000,B01110000,B01001000,B01001000,B01110000,B01001000,B01001000,B01110000};
  byte e[8]= {B00000000,B01111000,B01000000,B01000000,B01110000,B01000000,B01000000,B01111000};
  byte t[8]= {B00000000,B01111100,B00010000,B00010000,B00010000,B00010000,B00010000,B00010000};
 
  byte w[8]= {B01000100,B01000100,B01000100,B01000100,B01010100,B01010100,B01101100,B01000100};
  byte i[8]= {B00000000,B00010000,B00000000,B00010000,B00010000,B00010000,B00010000,B00010000};
  byte n[8]= {B00000000,B01000100,B01100100,B01010100,B01010100,B01010100,B01001100,B01000100};
  
  byte qm[8]= {B00000000,B00010000,B00010000,B00010000,B00010000,B00010000,B00000000,B00010000};
  
  writeLetter(b);
  writeLetter(e);
  writeLetter(t);
  
  writeLetter(w);
  writeLetter(i);
  writeLetter(n);
  
  writeLetter(qm);
}

void loop() { 
  writeArduinoOnMatrix();
}
