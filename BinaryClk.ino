/*
  BinaryClk - An open-source binary clock for Arduino. 
  HH:MM:SS. Active high/low configuration, depending on the used transistor package.
  created 19 Sep 2013
  by A. Saieed - a DOT saieed AT gmail.com
  
  Licensed under CC-BY-NC-SA 3.0 - http://creativecommons.org/licenses/by-nc-sa/3.0/
  
  Based on the code at:
    http://www.instructables.com/id/Arduino-Powered-Binary-Clock/step5/Arduino-Sketch/
    Created by David A. Mellis, November 2, 2007.
*/
  


#define LED_ON HIGH
#define LED_OFF LOW

#define s0_0 22
#define s0_1 24
#define s0_2 26
#define s0_3 28

#define s1_0 30
#define s1_1 32
#define s1_2 34


#define m0_0 36
#define m0_1 38
#define m0_2 40
#define m0_3 42

#define m1_0 44
#define m1_1 46
#define m1_2 48


#define h0_0 23
#define h0_1 25
#define h0_2 27
#define h0_3 29

#define h1_0 31
#define h1_1 33

#define btn_m 52
#define btn_h 50

int second=0, minute=0, hour=0; //start the time on 00:00:00
int sunit = 0;
int munit = 0;
int hunit = 0;
int vals=0;
int valm=0;
int valh=0;
int ledstats = 0;
int i= 0;
boolean light = 1;



void setup() { //set outputs and inputs

  pinMode(s0_0, OUTPUT);pinMode(s0_1, OUTPUT);pinMode(s0_2, OUTPUT);pinMode(s0_3, OUTPUT); //units sec
  pinMode(s1_0, OUTPUT);pinMode(s1_1, OUTPUT);pinMode(s1_2, OUTPUT); // tens sec
  
  pinMode(m0_0, OUTPUT);pinMode(m0_1, OUTPUT);pinMode(m0_2, OUTPUT);pinMode(m0_3, OUTPUT); //units min
  pinMode(m1_0, OUTPUT);pinMode(m1_1, OUTPUT);pinMode(m1_2, OUTPUT); //tens min
  
  pinMode(h0_0, OUTPUT);pinMode(h0_1, OUTPUT);pinMode(h0_2, OUTPUT);pinMode(h0_3, OUTPUT); //units hr
  pinMode(h1_0, OUTPUT);pinMode(h1_1, OUTPUT); //tens hr
  
  
  pinMode(btn_m, INPUT);
  pinMode(btn_h, INPUT);
  
  digitalWrite(btn_m, HIGH);
  digitalWrite(btn_h, HIGH);
}


void loop() {

static unsigned long lastTick = 0; // set up a local variable to hold the last time we moved forward one second
// (static variables are initialized once and keep their values between function calls)

// move forward one second every 1000 milliseconds
if (millis() - lastTick >= 1000) {
  lastTick = millis();
  second++;
  }

// move forward one minute every 60 seconds
if (second >= 60) {
  minute++;
  second = 0; // reset seconds to zero
  }

// move forward one hour every 60 minutes
if (minute >=60) {
  hour++;
  minute = 0; // reset minutes to zero
  }

if (hour >=24) {
  hour=0;
  minute = 0; // reset minutes to zero
  }
  
 sunit = second%10; //sets the variable sunit, munit and hunit for the unit digits
 munit = minute%10; 
 hunit = hour%10;

//
// ledstats = digitalRead(24);  // read input value, for setting leds off, but keeping count
//  if (ledstats == LOW){
//    light=!light;
//    delay(250);
//  }
//    
//   if(light== LOW){
//  for(i=1;i<=20;i++){
//  digitalWrite(i, HIGH);}
//  
//  } else  {
    
  //seconds units
  if(sunit == 1 || sunit == 3 || sunit == 5 || sunit == 7 || sunit == 9) {  digitalWrite(s0_0, LED_ON);} else {  digitalWrite(s0_0, LED_OFF);}
  if(sunit == 2 || sunit == 3 || sunit == 6 || sunit == 7) {digitalWrite(s0_1, LED_ON);} else {digitalWrite(s0_1,LED_OFF);}
  if(sunit == 4 || sunit == 5 || sunit == 6 || sunit == 7) {digitalWrite(s0_2, LED_ON);} else {digitalWrite(s0_2,LED_OFF);}
  if(sunit == 8 || sunit == 9) {digitalWrite(s0_3, LED_ON);} else {digitalWrite(s0_3,LED_OFF);}

  //seconds 
  if((second >= 10 && second < 20) || (second >= 30 && second < 40) || (second >= 50 && second < 60))  {digitalWrite(s1_0, LED_ON);} else {digitalWrite(s1_0,LED_OFF);}
  if(second >= 20 && second < 40)  {digitalWrite(s1_1, LED_ON);} else {digitalWrite(s1_1,LED_OFF);}
  if(second >= 40 && second < 60) {digitalWrite(s1_2, LED_ON);} else {digitalWrite(s1_2,LED_OFF);}


  //minutes units
  if(munit == 1 || munit == 3 || munit == 5 || munit == 7 || munit == 9) {  digitalWrite(m0_0, LED_ON);} else {  digitalWrite(m0_0, LED_OFF);}
  if(munit == 2 || munit == 3 || munit == 6 || munit == 7) {digitalWrite(m0_1, LED_ON);} else {digitalWrite(m0_1,LED_OFF);}
  if(munit == 4 || munit == 5 || munit == 6 || munit == 7) {digitalWrite(m0_2, LED_ON);} else {digitalWrite(m0_2,LED_OFF);}
  if(munit == 8 || munit == 9) {digitalWrite(m0_3, LED_ON);} else {digitalWrite(m0_3,LED_OFF);}

  //minutes 
  if((minute >= 10 && minute < 20) || (minute >= 30 && minute < 40) || (minute >= 50 && minute < 60))  {digitalWrite(m1_0, LED_ON);} else {digitalWrite(m1_0,LED_OFF);}
  if(minute >= 20 && minute < 40)  {digitalWrite(m1_1, LED_ON);} else {digitalWrite(m1_1,LED_OFF);}
  if(minute >= 40 && minute < 60) {digitalWrite(m1_2, LED_ON);} else {digitalWrite(m1_2,LED_OFF);}

  //hour units
  if(hunit == 1 || hunit == 3 || hunit == 5 || hunit == 7 || hunit == 9) {digitalWrite(h0_0, LED_ON);} else {digitalWrite(h0_0,LED_OFF);}
  if(hunit == 2 || hunit == 3 || hunit == 6 || hunit == 7) {digitalWrite(h0_1, LED_ON);} else {digitalWrite(h0_1,LED_OFF);}
  if(hunit == 4 || hunit == 5 || hunit == 6 || hunit == 7) {digitalWrite(h0_2, LED_ON);} else {digitalWrite(h0_2,LED_OFF);}
  if(hunit == 8 || hunit == 9) {digitalWrite(h0_3, LED_ON);} else {digitalWrite(h0_3,LED_OFF);}

  //hour
  if(hour >= 10 && hour < 20)  {digitalWrite(h1_0, LED_ON);} else {digitalWrite(h1_0,LED_OFF);}
  if(hour >= 20 && hour < 24)  {digitalWrite(h1_1, LED_ON);} else {digitalWrite(h1_1,LED_OFF);}

//  }

  valm = digitalRead(btn_m);    // add one minute when pressed
   if(valm== LOW) {
   minute++;
   second=0;
   delay(250);
  }
  
  valh = digitalRead(btn_h);    // add one hour when pressed
   if(valh==LOW) {
   hour++;
   second=0;
   delay(250);
  }


}
