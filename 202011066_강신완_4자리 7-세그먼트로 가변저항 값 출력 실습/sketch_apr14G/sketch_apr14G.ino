int segPin[8] = {2, 3, 4, 5, 6, 7, 8,9};
int digPin[4] = {13, 12, 11, 10};
int delayTime = 3;
byte Numbers[10] = {0b11111100, 0b01100000, 0b11011010, 0b11110010, 0b01100110,
                    0b10110110, 0b10111110, 0b11100100, 0b11111110, 0b11110110};
void displayNumber(int pos, int n) {
  for (int i=0; i<4; i++) {
    if (digPin[i] == pos) {
      digitalWrite(digPin[i], LOW);
    }      
    else {
      digitalWrite(digPin[i], HIGH);
    }
  }
  for(int i = 0; i < 8; i++){
    byte segment = (Numbers[n] & (0x01 << i)) >> i;
    if(segment == 1){
      digitalWrite(segPin[7 - i], HIGH);
    } 
    else {
      digitalWrite(segPin[7 - i], LOW);
    }
  }
  delay(delayTime);
}
void setup() {
  Serial.begin(9600);
  for(int i=0; i<4; i++) {
    pinMode(digPin[i], OUTPUT);
  }
  for(int i=0; i<8; i++) {
    pinMode(segPin[i], OUTPUT);
  }
  // put your setup code here, to run once:
}
void clearLEDs() {
  for(int i=0; i<4; i++) {
    digitalWrite(digPin[i], LOW);
  }
  for(int i=0; i<8; i++) {
    digitalWrite(segPin[i], LOW);
  } 
}
int n =0;
int readValue;
void loop() {
  n++;
  if (n % 50 == 1) {
    readValue = analogRead(A0);
    Serial.println(readValue);
  }
  int c[4] = {0, 0, 0, 0};
  c[0] = readValue/1000;
  c[1]=(readValue/100)%10;
  c[2]=(readValue/10)%10;
  c[3]=readValue%10;
  for (int i=0; i<4; i++) displayNumber(digPin[i],c[i]);
  clearLEDs();
  delay(delayTime);
  // put your main code here, to run repeatedly:

}
