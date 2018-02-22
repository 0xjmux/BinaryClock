//Written by PwnKitteh, 2017
//This code is designed to be run on a binary clock to help keep the time
//It gets the time from the computer it's connected to, so as long as that clock is good, the time should be right. 
#include <RTClib.h>

#include <Wire.h>

RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//variable declaration, have to do each one 

int hours10 = 2;
int hours20 = 3;
int hours1 = 4;
int hours2 = 5;
int hours4 = 6;
int hours8 = 7;

int minutes10 = 8;
int minutes20 = 9;
int minutes40 = 10;

int minutes1 = 22;
int minutes2 = 24;
int minutes4 = 26;
int minutes8 = 28;

int seconds10 = 30;
int seconds20 = 32;
int seconds40 = 34;
int seconds1 = 36;
int seconds2 = 38;
int seconds4 = 40;
int seconds8 = 42;

int chour = 0;

int cmin1 = 0;
int cmin10 = 0;

int csec1 = 0;
int csec10 = 0;


void setup() {
  while (!Serial); // for Leonardo/Micro/Zero
  // put your setup code here, to run once:
  Serial.begin(57600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  for (int i = 2; i <= 10; i++) {
    pinMode(i, OUTPUT);
  }
  for (int a = 22; a <= 42; a += 2) {
    pinMode(a, OUTPUT);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
DateTime now = rtc.now();
    
    
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    Serial.println();
    //delay(1000);
    chour=now.hour();

    switch(chour) {  //this statement calls the hour value based on the time
      case 1: 
      hour1();
      break;

      case 2:
      hour2();
      break;

      case 3:
      hour3();
      break;

      case 4:
      hour4();
      break;

      case 5:
      hour5();
      break;

      case 6:
      hour6();
      break;

      case 7:
      hour7();
      break;

      case 8:
      hour8();
      break;

      case 9:
      hour9();
      break;

      case 10:
      hour10();
      break;

      case 11:
      hour11();
      break;

      case 12:
      hour12();
      break;
    }


    cmin1 = (now.minute()) % 10;
    cmin10 = (now.minute()) / 10;

    //Serial.print(cmin1);
    //Serial.println(cmin10);

    switch(cmin10) {
      case 1: 
      minute10();
      break;

      case 2:
      minute20();
      break;

      case 3:
      minute30();
      break;

      case 4:
      minute40();
      break;

      case 5:
      minute50();
      break;

      default:
      CLEARMIN10();
      break;
    }

    switch(cmin1) {
      case 1: 
      minute1();
      break;

      case 2:
      minute2();
      break;

      case 3:
      minute3();
      break;

      case 4:
      minute4();
      break;

      case 5:
      minute5();
      break;

      case 6:
      minute6();
      break;

      case 7:
      minute7();
      break;

      case 8:
      minute8();
      break;

      case 9:
      minute9();
      break;

      default:
      CLEARMIN1();
      break;

    } 
    //Seconds 10s block

    csec1 = (now.second()) % 10;
    csec10 = (now.second()) / 10;


    //Serial.print("csec 10: ");
    //Serial.print(csec10);
    //Serial.print("csec 1: ");
    //Serial.println(csec1);
    

    switch(csec10) {
      case 1: 
      second10();
      break;

      case 2:
      second20();
      break;

      case 3:
      second30();
      break;

      case 4:
      second40();
      break;

      case 5:
      second50();
      break;

      default:
      CLEARSEC10();
      break;
    }

    //Seconds 1s column
    switch(csec1) {
      case 1: 
      second1();
      break;

      case 2:
      second2();
      break;

      case 3:
      second3();
      break;

      case 4:
      second4();
      break;

      case 5:
      second5();
      break;

      case 6:
      second6();
      break;

      case 7:
      second7();
      break;

      case 8:
      second8();
      break;

      case 9:
      second9();
      break;

      default:
      CLEARSEC1();
      break;

      
    }
    

    
    

}

//Call these functions to orchestrate the numbers of the clock based on the clock timer unit, CLEARALL will turn all the LEDs off.   digitalWrite(, HIGH);
void hour1() {
  CLEARHOUR();
  digitalWrite(hours1, HIGH);
}

void hour2() {
  CLEARHOUR();
  digitalWrite(hours2, HIGH);
}

void hour3() {
  CLEARHOUR();
  digitalWrite(hours1, HIGH);
  digitalWrite(hours2, HIGH);
}

void hour4() {
  CLEARHOUR();
  digitalWrite(hours4, HIGH);
}

void hour5() {
  CLEARHOUR();
  digitalWrite(hours4, HIGH);
  digitalWrite(hours1, HIGH);
}

void  hour6() {
  CLEARHOUR();
  digitalWrite(hours4, HIGH);
  digitalWrite(hours2, HIGH);
}

void hour7() {
  CLEARHOUR();
  digitalWrite(hours4, HIGH);
  digitalWrite(hours2, HIGH);
  digitalWrite(hours1, HIGH);
}

void  hour8() {
  CLEARHOUR();
  digitalWrite(hours8, HIGH);
}

void  hour9() {
  CLEARHOUR();
  digitalWrite(hours8, HIGH);
  digitalWrite(hours1, HIGH);
}

void  hour10() {
  CLEARHOUR();
  digitalWrite(hours10, HIGH);
}

void  hour11() {
  CLEARHOUR();
  digitalWrite(hours10, HIGH);
  digitalWrite(hours1, HIGH);
}
void  hour12() {
  CLEARHOUR();
  digitalWrite(hours10, HIGH);
  digitalWrite(hours2, HIGH);
}
//Will not do this for minutes, will take forever. Instead, parse the mins value and seperate the two numbers, and then address it through that.

void minute10() {
  CLEARMIN10();
  digitalWrite(minutes10, HIGH);
}
void minute20() {
  CLEARMIN10();
  digitalWrite(minutes20, HIGH);
}
void minute30() {
  CLEARMIN10();
  digitalWrite(minutes10, HIGH);
  digitalWrite(minutes20, HIGH);
}
void minute40() {
  CLEARMIN10();
  digitalWrite(minutes40, HIGH);
}
void minute50() {
  CLEARMIN10();
  digitalWrite(minutes10, HIGH);
  digitalWrite(minutes40, HIGH);
}
//ADD DEFAULT IN SWITCH  CASE STATEMENT THAT DEFAULTS TO OFF FOR A ZERO TENS VALUE


//minute 1s value

void minute1() {
  CLEARMIN1();
  digitalWrite(minutes1, HIGH);
}
void minute2() {
  CLEARMIN1();
  digitalWrite(minutes2, HIGH);
}
void minute3() {
  CLEARMIN1();
  digitalWrite(minutes1, HIGH);
  digitalWrite(minutes2, HIGH);
}
void minute4() {
  CLEARMIN1();
  digitalWrite(minutes4, HIGH);
}
void minute5() {
  CLEARMIN1();
  digitalWrite(minutes1, HIGH);
  digitalWrite(minutes4, HIGH);
}
void minute6() {
  CLEARMIN1();
  digitalWrite(minutes2, HIGH);
  digitalWrite(minutes4, HIGH);
}
void minute7() {
  CLEARMIN1();
  digitalWrite(minutes1, HIGH);
  digitalWrite(minutes2, HIGH);
  digitalWrite(minutes4, HIGH);
}
void minute8() {
  CLEARMIN1();
  digitalWrite(minutes8, HIGH);
  }
void minute9() {
  CLEARMIN1();
  digitalWrite(minutes1, HIGH);
  digitalWrite(minutes8, HIGH);
}

//START OF THE SECONDS COLUMN OF METHODS
 void second10() {
  CLEARSEC10();
  digitalWrite(seconds10, HIGH);
 }
 void second20() {
  CLEARSEC10();
  digitalWrite(seconds20, HIGH);
 }
 void second30() {
  CLEARSEC10();
  digitalWrite(seconds10, HIGH);
  digitalWrite(seconds20, HIGH);
 }
 void second40() {
  CLEARSEC10();
  digitalWrite(seconds40, HIGH);
 }
 void second50() {
  CLEARSEC10();
  digitalWrite(seconds10, HIGH);
  digitalWrite(seconds40, HIGH);
 }

//Seconds 1s

void second1() {
  CLEARSEC1();
  digitalWrite(seconds1, HIGH);
 }
 void second2() {
  CLEARSEC1();
  digitalWrite(seconds2, HIGH);
 }
 void second3() {
  CLEARSEC1();
  digitalWrite(seconds1, HIGH);
  digitalWrite(seconds2, HIGH);
 }
 void second4() {
  CLEARSEC1();
  digitalWrite(seconds4, HIGH);
 }
 void second5() {
  CLEARSEC1();
  digitalWrite(seconds1, HIGH);
  digitalWrite(seconds4, HIGH);
 }
 void second6() {
  CLEARSEC1();
  digitalWrite(seconds2, HIGH);
  digitalWrite(seconds4, HIGH);
 }
 void second7() {
  CLEARSEC1();
  digitalWrite(seconds1, HIGH);
  digitalWrite(seconds2, HIGH);
  digitalWrite(seconds4, HIGH);
 }
 void second8() {
  CLEARSEC1();
  digitalWrite(seconds8, HIGH);
 }
 void second9() {
  CLEARSEC1();
  digitalWrite(seconds1, HIGH);
  digitalWrite(seconds8, HIGH);
 }



//Clearing functions : these clear the values for hr, min, or sec in order for the next value to be passed. 


void CLEARHOUR() {
  digitalWrite(hours1 , LOW);
  digitalWrite(hours2 , LOW);
  digitalWrite(hours4 , LOW);
  digitalWrite(hours8 , LOW);
  digitalWrite(hours10 , LOW);
  digitalWrite(hours20 , LOW);
  
}


void CLEARMIN10() {
  digitalWrite(minutes10, LOW);
  digitalWrite(minutes20, LOW);
  digitalWrite(minutes40, LOW);
  
}
void CLEARMIN1() {
  digitalWrite(minutes1, LOW);
  digitalWrite(minutes2, LOW);
  digitalWrite(minutes4, LOW);
  digitalWrite(minutes8, LOW);
  
}


void CLEARSEC10() {
  digitalWrite(seconds10, LOW);
  digitalWrite(seconds20, LOW);
  digitalWrite(seconds40, LOW);

  
}

void CLEARSEC1() {
  digitalWrite(seconds1, LOW);
  digitalWrite(seconds2, LOW);
  digitalWrite(seconds4, LOW);
  digitalWrite(seconds8, LOW);
  
  
}


void CLEARALL() {
  for (int b = 2; b <= 10; b++) {
    digitalWrite(b, LOW);
  }
  for (int c = 22; c <= 42; c += 2) {
    digitalWrite(c, LOW);
  }
}

/*     LED CYCLE PROGRAM
    for(int b = 2; b <= 10; b++) {
    digitalWrite(b, HIGH);
    delay(500);
    digitalWrite(b, LOW);
    }

    for(int c = 22; c <= 42; c += 2) {
    digitalWrite(c, HIGH);
    delay(500);
    digitalWrite(c, LOW);
    }
  */



  /*    METHOD FOR LED ADDRESSING
      void  () {
      digitalWrite(, HIGH);
      digitalWrite(, HIGH);
    }


  */


