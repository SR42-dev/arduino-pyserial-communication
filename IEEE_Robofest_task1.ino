#define ena 5
#define enb 6
#define lb 8
#define lf 9
#define rb 10
#define rf 11
#define del 100
#define ldr1 A0
#define ldr2 A1

// defines pins numbers
const int trigPin = 3;  //D4
const int echoPin = 2;  //D3

// defines variables
long duration;
float distance;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  analogWrite(ena, 255);
  analogWrite(enb, 255);
  pinMode (ldr1, INPUT);
  pinMode (ldr2, INPUT);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
   // Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
//Serial.println(distance);
if (distance < 15)  {
    digitalWrite(ena, LOW);
digitalWrite(enb, LOW);
  }
  else {
    digitalWrite(ena, HIGH);
digitalWrite(enb, HIGH);
  }

int LDRval1 = analogRead (ldr1);
int LDRval2 = analogRead (ldr2);

//int LDRval1 = 10;
//int LDRval2 = 50;
Serial.println(LDRval1);
Serial.println(LDRval2);
  
delay(500);
 // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // put your main code here, to run repeatedly:
  if (Serial.available()>0){
    char cg = Serial.read();
    //Serial.println(cg);
    if (LDRval1>25 && LDRval2>25){
      digitalWrite(lf, HIGH);
      digitalWrite(lb, LOW);
      digitalWrite(rf, HIGH);
      digitalWrite(rb, LOW);
      delay(del);
      digitalWrite(lf, LOW);
      digitalWrite(lb, LOW);
      digitalWrite(rf, LOW);
      digitalWrite(rb, LOW);
    }
    
   
    if (LDRval1<25 && LDRval2>25){
      digitalWrite(lf, LOW);
      digitalWrite(lb, HIGH);
      digitalWrite(rf, HIGH);
      digitalWrite(rb, LOW);
      delay(del);
      digitalWrite(lf, LOW);
      digitalWrite(lb, LOW);
      digitalWrite(rf, LOW);
      digitalWrite(rb, LOW);
    }
    if (LDRval1>25 && LDRval2<25){
      digitalWrite(lf, HIGH);
      digitalWrite(lb, LOW);
      digitalWrite(rf, LOW);
      digitalWrite(rb, HIGH);
      delay(del);
      digitalWrite(lf, LOW);
      digitalWrite(lb, LOW);
      digitalWrite(rf, LOW);
      digitalWrite(rb, LOW);
    }
    if (LDRval1<25 && LDRval2<25){
      digitalWrite(lf, LOW);
      digitalWrite(lb, LOW);
      digitalWrite(rf, LOW);
      digitalWrite(rb, LOW);
      delay(del);
    }
  }
}
