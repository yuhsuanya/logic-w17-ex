const int buttonPin = 2;
int buttonState = 0;
int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
byte colDataMatrix[8] = { B01111111,
   B10111111,
   B11011111,
   B11101111,
   B11110111,
   B11111011,
   B11111101,
   B11111110
  };
                      
byte rowDataMatrix[8] = { B00011111,
    B01000010,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B01000010,
    B00111100
  };
byte rowDatabutton[8] = { 
  B00000000,
  B11111111,
  B00100100,
  B11111111,
  B01000010,
  B00111100,
  B11111111,
  B00000000
  };
// 定義顯示器顯示的時間 (延遲時間), 預設 1ms
int delay_time = 1;
       
void setup() {
  // put your setup code here, to run once:
pinMode(buttonPin, INPUT);
pinMode(latchPin,OUTPUT);
pinMode(clockPin,OUTPUT);
pinMode(dataPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonState = digitalRead(buttonPin);
if(buttonState == HIGH){
for(int i = 0; i < 8 ; i++){
 //byte colData = colDataMatrix[i];
digitalWrite(latchPin,LOW);
  //  pickDigit(i);
    shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
    shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[i]);
    //shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
    digitalWrite(latchPin,HIGH);
    delay(delay_time);
 }
}
else{
  for(int i = 0; i < 8 ; i++){
 //byte colData = colDataMatrix[i];
digitalWrite(latchPin,LOW);
  //  pickDigit(i);
    shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
    shiftOut(dataPin, clockPin, MSBFIRST, rowDatabutton[i]);
    //shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
    digitalWrite(latchPin,HIGH);
    delay(delay_time);}
  }
}
void pickDigit(int x) {
  byte rowByte = 1 << x;
  shiftOut(dataPin, clockPin, MSBFIRST, rowByte);

}

