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
int mintues1 = 22;
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

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

for(int i = 2; i <= 10; i++) {
  pinMode(i, OUTPUT);
}
for(int a = 22; a <= 42; a += 2) {
  pinMode(a, OUTPUT);
}
}

void loop() {
  // put your main code here, to run repeatedly:

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






  

}
