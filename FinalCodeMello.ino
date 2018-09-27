#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            23
//#define counter 0

#define  NUMPIXELS      516
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval  = 50;
int Brightness  = 100;
int count=0;

//fadefollow
int a1=0;
int b1=0;
int c1=0;
int a2=0;
int b2=0;
int c2=0;

int Pulses = 70;
int x = NUMPIXELS/Pulses;

//everyodd
int a=0;
int b=0;
int c=0;

//mirror
int randomx = 0;
int randomy = 0;
int randomz = 0;

int randomx2 = 0;
int randomy2 = 0;
int randomz2 = 0;

//standard
int jump=0;


//the button to end all buttons
const int  buttonPin=16;
int buttonPushCounter=0;
int buttonState=0;
int lastButtonState=0;

HardwareSerial Serial1(2);
void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show();
  pinMode(5, OUTPUT);
  digitalWrite(5,HIGH);

  pinMode(buttonPin,INPUT);
  Serial.begin(115200);
}

void loop() {
fadefollow();
strip.clear();
//everyodd();
standard();
strip.clear();
mirror();

}

void fadefollow() {
a1 = random(2)*Brightness;
b1 = random(2)*Brightness;
c1 = random(2)*Brightness;
a2 = random(2)*Brightness;
b2 = random(2)*Brightness;
c2 = random(2)*Brightness;
if (a1+b1+c1==0 || a2+b2+c2==0) {
  return fadefollow();
}

for(int j=0;j<NUMPIXELS;j++) {
  count=j;
  for (int i=-4;i<NUMPIXELS;i++) {
    if ((i+count) % x == 0) {
          strip.setPixelColor(i+3,strip.Color(a1*0.1,b1*0.1,c1*0.1));
          strip.setPixelColor(i+2,strip.Color(a1*0.2+a2*0.1,b1*0.2+b2*0.1,c1*0.2+c2*0.1));
          strip.setPixelColor(i+1,strip.Color(a1*0.05+a2*0.5,b1*0.05+b2*0.5,c1*0.05+c2*0.5));
          strip.setPixelColor(i,strip.Color(a2,b2,c2));
          strip.setPixelColor(i+4,strip.Color(0,0,0));
          //strip.setPixelColor(i-1,strip.Color(0,0,0));
          //strip.show();
    }
    else {
    }
  }
  strip.show();
  delay(delayval);
}
}

void everyodd() {
  for (int i = 0;i<NUMPIXELS/2;i++) {
    strip.setPixelColor(i*2,strip.Color(50,0,50));
    strip.show();
  }
  delay(10000000);
}

void mirror() {
  // put your main code here, to run repeatedly
  for (int q=0;q<2;q++) {
      randomx = random(2)*random(10,Brightness/2);
      randomy = random(2)*random(10,Brightness/2);
      randomz = random(2)*random(10,Brightness/2);
      randomx2 = random(2)*random(10,Brightness/2);
      randomy2 = random(2)*random(10,Brightness/2);
      randomz2 = random(2)*random(10,Brightness/2);
      if (randomx+randomy+randomz==0) {return loop();
      }
      if (randomx2+randomy2+randomz2==0) {return loop();
      }
    for (int i=0;i<(NUMPIXELS/2)+1;i=(i+1)){
      strip.setPixelColor(i, strip.Color(randomx,randomy,randomz));
      strip.setPixelColor(NUMPIXELS-i, strip.Color(randomx,randomy,randomz));
      strip.show();
      delay(delayval);
    }
    for (int j=0;j<(NUMPIXELS/2)+1;j++){
      strip.setPixelColor(NUMPIXELS/2+1-j, strip.Color(randomx2,randomy2,randomz2));
      strip.setPixelColor((NUMPIXELS/2)+1+j, strip.Color(randomx2,randomy2,randomz2));
      strip.show();
      delay(delayval);
    }   
}
}

void standard() {
  // put your main code here, to run repeatedly:
for (int y=0;y<10;y++) {
  for(int j=0;j<8;j++) {
    jump=j;
    for (int i=-4;i<NUMPIXELS;i++) {
      if ((i+jump) % 8 == 0) {
            strip.setPixelColor(i,strip.Color(0,50,50));
            strip.setPixelColor(i+1,strip.Color(0,50,50));
            strip.setPixelColor(i+2,strip.Color(0,50,50));
            strip.setPixelColor(i+3,strip.Color(0,50,50));
            strip.setPixelColor(i+4,strip.Color(0,3,3));
            strip.setPixelColor(i+5,strip.Color(0,3,3));
            strip.setPixelColor(i+6,strip.Color(0,3,3));
            strip.setPixelColor(i+7,strip.Color(0,3,3));
            //strip.show();
      }
      else {
      }
    }
    strip.show();
    delay(200);
}
}
}
