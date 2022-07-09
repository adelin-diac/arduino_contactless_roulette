int LEDg = 2;
int LED3 = 3;
int LED4 = 4;
int LED5 = 5;
int LED6 = 6;
int LED7 = 7;
int LED8 = 8;
int LED9 = 9;
int LED10 = 10;
int exdelayT = 150;
int delayT = 50;
int readPin = A0;
int readVal;
float V2 = 0;
int repeat;
int randInt;
int win;
int winT = 5000;
int flashT = 150;

void setup() {
  for(int i=2; i<=10; i++){  // set mode for pins 2-10
     pinMode(i, OUTPUT); 
  }
  pinMode(readPin, INPUT);
  randomSeed(analogRead(A5));
  Serial.begin(9600);
}

void loop() {
  randomSeed(analogRead(A5));
  randInt = random(5,16);
  randomSeed(analogRead(A5));
  win = random(2,11);
  repeat =0;
  readVal = analogRead(readPin);
  V2 = readVal*(5./1023.);
  Serial.println(V2);

  
  if(V2 < 3.5 ){
   while(repeat < randInt){
    for(int i=2; i<=10; i++){
       digitalWrite(i, HIGH);
       delay(delayT);
        if(i == 10){
          delay(exdelayT);
        } // if i=10 Function
    } // FOR write high
  
    for(int i=2; i<=10; i++){
       digitalWrite(i, LOW);
      delay(delayT);
      } // FOR write low
      repeat++;
     } // while
     digitalWrite(win, HIGH);
     delay(flashT);
     digitalWrite(win, LOW);
     delay(flashT);
     digitalWrite(win, HIGH);
     delay(flashT);
     digitalWrite(win, LOW);
     delay(flashT);
     digitalWrite(win, HIGH);
     delay(winT);
    } // if V2

    else{
      for(int i=2; i<=10; i++){  // set mode for pins 1-9
     digitalWrite(i, LOW); 
        } // FOR turning off LEDs
    } // else 
    
  
}
