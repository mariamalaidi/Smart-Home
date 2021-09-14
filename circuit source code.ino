#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "//";
char ssid[] = "//";
char pass[] = "//";


BlynkTimer timer;
#define trig D5
#define echo D6
#define MQ2 A0
#define flame D0
#define Buzzer D8

int pinValue;
int partyState;
int houseLight = D1;
int redPin= D2;
int greenPin = D3;
int bluePin = D7;
int gamingState;
int relaxState;
int ligh;

void ultrasonic() {
  digitalWrite(trig, LOW);
  delayMicroseconds(4);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long t = pulseIn(echo, HIGH);
  long cm = t / 29 / 2;
  Blynk.virtualWrite(V4, cm);
  if(pinValue == 1 && cm <= 100){
 Blynk.notify("Warning! Security Alert !");
   digitalWrite(Buzzer, HIGH);

  }
}

void gassensor() {
  int value = analogRead(MQ2);
  Serial.println(value);
  value = map(value, 0, 1024, 0, 100);
  if (value <= 35) {
   // digitalWrite(Buzzer, LOW);
  } else if (value >= 45) {
    Blynk.notify("Warning! Gas leak detected !");
   digitalWrite(Buzzer, HIGH);

  }
  Blynk.virtualWrite(V1, value);
   Blynk.virtualWrite(D8,  HIGH);
}


void flamesensor() {
  bool value = digitalRead(flame );
  if (value == 1) {
  //  digitalWrite(Buzzer, LOW);
  } else if (value == 0) {
    Blynk.notify("Warning! Fire was detected");
  digitalWrite(Buzzer, HIGH);

  }
   Blynk.virtualWrite(D8,  HIGH);
}

void rgb(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}

void party(){
  if(partyState == 1){
     Blynk.virtualWrite(V13, LOW);
      Blynk.virtualWrite(V14, LOW);
    gamingState = 0;
    relaxState = 0;
rgb(255, 64, 0);delay(100);
rgb(255, 128, 0);delay(100);
rgb(255, 191, 0);delay(100);
rgb(255, 255, 0);delay(100);
rgb(191, 255, 0);delay(100);
rgb(128, 255, 0);delay(100);
rgb(64, 255, 0);delay(100);
rgb(0, 255, 0);delay(100);
rgb(0, 255, 64);delay(100);
rgb(0, 255, 128);delay(100);
rgb(0, 255, 191);delay(100);
rgb(0, 255, 255);delay(100);
rgb(0, 191, 255);delay(100);
rgb(0, 128, 255);delay(100);
rgb(0, 64, 255);delay(100);
rgb(0, 0, 255);delay(100);
rgb(64, 0, 255);delay(100);
rgb(128, 0, 255);delay(100);
rgb(191, 0, 255);delay(100);
rgb(255, 0, 255);delay(100);
rgb(255, 0, 191);delay(100);
rgb(255, 0, 128);delay(100);
rgb(255, 0, 64);delay(100);
rgb(255, 0, 0);delay(100);

  }
}
 
 void gamingMode(){
   if(gamingState == 1){
      partyState = 0;
      relaxState = 0;
       Blynk.virtualWrite(V12, LOW);
        Blynk.virtualWrite(V14, LOW);
rgb(231, 5, 10);delay(100);

rgb(232, 0, 19);delay(100);
rgb(234, 0, 25);delay(100);
rgb(235, 0, 31);delay(100);
rgb(236, 0, 37);delay(100);
rgb(236, 0, 42);delay(100);
rgb(237, 0, 47);delay(100);
rgb(237, 0, 52);delay(100);
rgb(237, 0, 58);delay(100);
rgb(237, 0, 63);delay(100);
rgb(237, 0, 68);delay(100);
rgb(236, 0, 73);delay(100);
rgb(235, 0, 78);delay(100);
rgb(234, 0, 83);delay(100);
rgb(232, 0, 89);delay(100);
rgb(231, 0, 94);delay(100);
rgb(229, 0, 100);delay(100);
rgb(226, 0, 105);delay(100);
rgb(223, 0, 111);delay(100);
rgb(220, 0, 116);delay(100);
rgb(217, 0, 122);delay(100);
rgb(213, 0, 128);delay(100);
rgb(205, 0, 140);delay(100);
rgb(200, 0, 145);delay(100);

rgb(194, 0, 151);delay(100);

rgb(188, 0, 157);delay(100);
rgb(182, 0, 163);delay(100);
rgb(175, 0, 168);delay(100);

rgb(168, 0, 174);delay(100);
rgb(160, 0, 180);delay(100);

rgb(151, 0, 185);delay(100);
rgb(141, 0, 190);delay(100);
rgb(130, 0, 196);delay(100);
rgb(118, 0, 201);delay(100);
rgb(104, 0, 205);delay(100);
rgb(87, 0, 210);delay(100);
rgb(65, 0, 215);delay(100);
rgb(28, 15, 219);delay(100);
rgb(0, 214, 255);delay(100);
rgb(0, 218, 255);delay(100);
rgb(0, 222, 251);delay(100);
rgb(0, 238, 233);delay(100);
rgb(0, 241, 229);delay(100);
rgb(0, 245, 226);delay(100);
rgb(0, 248, 222);delay(100);
rgb(0, 252, 219);delay(100);
rgb(6, 255, 217);delay(100);
rgb(53, 9, 255);delay(100);
rgb(68, 4, 254);delay(100);
rgb(81, 0, 253);delay(100);
rgb(91, 0, 252);delay(100);
rgb(100, 0, 251);delay(100);
rgb(109, 0, 250);delay(100);
rgb(117, 0, 249);delay(100);
rgb(124, 0, 248);delay(100);
rgb(131, 0, 247);delay(100);
rgb(137, 0, 246);delay(100);
rgb(143, 0, 245);delay(100);
rgb(149, 0, 244);delay(100);
rgb(155, 0, 243);delay(100);
rgb(160, 0, 242);delay(100);
rgb(165, 0, 241);delay(100);
rgb(170, 0, 240);delay(100);
rgb(175, 0, 239);delay(100);
rgb(180, 0, 238);delay(100);
rgb(184, 0, 237);delay(100);
rgb(189, 0, 236);delay(100);
rgb(193, 0, 234);delay(100);
rgb(197, 0, 233);delay(100);
rgb(201, 0, 232);delay(100);
rgb(205, 0, 231);delay(100);
rgb(209, 0, 230);delay(100);
rgb(213, 0, 229);delay(100);
rgb(216, 0, 228);delay(100);
rgb(220, 0, 227);delay(100);
rgb(224, 0, 226);delay(100);
rgb(227, 0, 225);delay(100);
rgb(230, 0, 224);delay(100);
rgb(234, 0, 223);delay(100);
rgb(237, 0, 222);delay(100);
rgb(240, 0, 222);delay(100);
rgb(243, 0, 221);delay(100);
rgb(246, 0, 220);delay(100);
rgb(249, 0, 219);delay(100);
rgb(252, 0, 218);delay(100);
rgb(255, 5, 217);delay(100);


   }
 }

 void relaxMode(){
      if(relaxState == 1){
      partyState = 0;
      gamingState = 0;
       Blynk.virtualWrite(V12, LOW);
        Blynk.virtualWrite(V13, LOW);
        rgb(9, 255, 21);delay(100);
rgb(41, 255, 16);delay(100);
rgb(57, 255, 9);delay(100);
rgb(70, 255, 2);delay(100);
rgb(81, 255, 0);delay(100);
rgb(90, 255, 0);delay(100);
rgb(98, 255, 0);delay(100);
rgb(106, 255, 0);delay(100);
rgb(113, 255, 0);delay(100);
rgb(120, 255, 0);delay(100);
rgb(127, 255, 0);delay(100);
rgb(133, 255, 0);delay(100);
rgb(139, 255, 0);delay(100);
rgb(144, 255, 0);delay(100);
rgb(150, 255, 0);delay(100);
rgb(155, 255, 0);delay(100);
rgb(160, 255, 0);delay(100);
rgb(165, 255, 0);delay(100);
rgb(170, 255, 0);delay(100);
rgb(175, 255, 0);delay(100);
rgb(179, 255, 0);delay(100);
rgb(184, 255, 0);delay(100);
rgb(188, 255, 0);delay(100);
rgb(193, 255, 0);delay(100);
rgb(197, 255, 0);delay(100);
rgb(201, 255, 0);delay(100);
rgb(206, 255, 0);delay(100);
rgb(210, 255, 0);delay(100);
rgb(214, 255, 0);delay(100);
rgb(218, 255, 0);delay(100);
rgb(222, 255, 0);delay(100);
rgb(225, 255, 0);delay(100);
rgb(229, 255, 0);delay(100);
rgb(233, 255, 0);delay(100);
rgb(237, 255, 0);delay(100);
rgb(240, 255, 0);delay(100);
rgb(244, 255, 0);delay(100);
rgb(247, 255, 0);delay(100);
rgb(251, 255, 5);delay(100);
rgb(251, 255, 5);delay(100);
rgb(245, 255, 22);delay(100);
rgb(238, 255, 34);delay(100);
rgb(232, 255, 43);delay(100);
rgb(226, 255, 50);delay(100);
rgb(220, 255, 58);delay(100);
rgb(214, 255, 64);delay(100);
rgb(208, 255, 71);delay(100);
rgb(202, 255, 77);delay(100);
rgb(196, 255, 83);delay(100);
rgb(190, 255, 89);delay(100);
rgb(184, 255, 95);delay(100);
rgb(178, 255, 101);delay(100);
rgb(172, 255, 106);delay(100);
rgb(166, 255, 112);delay(100);
rgb(160, 255, 117);delay(100);
rgb(154, 255, 123);delay(100);
rgb(148, 255, 128);delay(100);
rgb(142, 255, 133);delay(100);
rgb(136, 255, 138);delay(100);
rgb(131, 255, 143);delay(100);
rgb(125, 255, 148);delay(100);
rgb(119, 255, 153);delay(100);
rgb(113, 255, 158);delay(100);
rgb(107, 255, 163);delay(100);
rgb(100, 255, 168);delay(100);
rgb(94, 255, 173);delay(100);
rgb(88, 255, 177);delay(100);
rgb(82, 255, 182);delay(100);
rgb(75, 255, 186);delay(100);
rgb(69, 255, 190);delay(100);
rgb(62, 255, 195);delay(100);
rgb(56, 255, 199);delay(100);
rgb(49, 255, 203);delay(100);
rgb(42, 255, 207);delay(100);
rgb(34, 255, 210);delay(100);
rgb(26, 255, 214);delay(100);
rgb(18, 255, 218);delay(100);
rgb(9, 255, 221);delay(100);


 }
 }

void setup()
{

  Serial.begin(115200);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(houseLight, OUTPUT);

  digitalWrite(houseLight,HIGH);
  digitalWrite(Buzzer,LOW);
  Blynk.begin(auth, ssid, pass);

  timer.setInterval(10L, ultrasonic);
  timer.setInterval(10L, gassensor);
  timer.setInterval(10L, flamesensor);
  timer.setInterval(10L, party);
  timer.setInterval(10L, gamingMode);
  timer.setInterval(10L, relaxMode);
}

void loop()
{
   
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}

BLYNK_WRITE(V11) {
  if (param.asInt()) {
        //HIGH
       pinValue = 1;
    } else {
       //LOW
      pinValue = 0;
    }
    Serial.println("Hey ");
    Serial.print(pinValue);
}

BLYNK_WRITE(V21) {
  if (param.asInt()) {
        //HIGH
       pinValue = 1;
       
 Blynk.notify("/Security system on!");
    } else {
       //LOW
      pinValue = 0;
    }
  
}
BLYNK_WRITE(V12) {
  if (param.asInt()) {
        //HIGH
      partyState = 1;
    } else {
       //LOW
    partyState = 0;
    }
}

BLYNK_WRITE(V13) {
  if (param.asInt()) {
        //HIGH
       gamingState = 1;
    } else {
       //LOW
      gamingState = 0;
}
}
BLYNK_WRITE(V14) {
  if (param.asInt()) {
        //HIGH
       relaxState
        = 1;
    } else {
       //LOW
      relaxState
       = 0;
}
}
BLYNK_WRITE(V23) {
  if (param.asInt()) {
        //HIGH
       digitalWrite(D1,HIGH);
    } else {
        digitalWrite(D1,LOW);
}
}
