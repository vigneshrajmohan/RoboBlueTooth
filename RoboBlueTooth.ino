// Left motor pins
#define enableL 6     
#define LPin1 7       
#define LPin2 8       
// Right motor pins
#define enableR 11     
#define RPin1 9       
#define RPin2 10      

int rightspeed = 200;
int leftspeed = 200;
int response = 1;
int ledPin = 13; 
int state = 0;
int flag = 0; 
boolean condit = true;
long duration;
int distance;

void setup()
{
  Serial.begin (9600);
  
  // set all the motor control pins to outputs
  pinMode(enableR, OUTPUT);
  pinMode(enableL, OUTPUT);
  pinMode(RPin1, OUTPUT);
  pinMode(RPin2, OUTPUT);
  pinMode(LPin1, OUTPUT);
  pinMode(LPin2, OUTPUT);
  
  //LED
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop()
{
  if(Serial.available() > 0){
  state = Serial.read();
  flag=0;
}

//if else mess
 if (state == '0') {
   condit = false;
   digitalWrite(ledPin, LOW);
   if(flag == 0){
   Serial.println("STOP");
   flag = 1;
   
   motorsOff();
  }
}

 else if (state == '1') 
 {
   digitalWrite(ledPin, HIGH);

   if(flag == 0)
  {
    Serial.println("forward");
    condit = true;
    flag = 1;
 
  forward();
 }
 
}

}


//move forward
void forward()
{
  // set up both motors for forward direction
    digitalWrite(RPin1, HIGH);
    digitalWrite(RPin2, LOW);
    digitalWrite(LPin1, HIGH);
    digitalWrite(LPin2, LOW);

      analogWrite(enableR, 154);
      analogWrite(enableL, 180);
  }

 //turn off all motors 
void motorsOff()
  {
  digitalWrite(RPin1, LOW);
  digitalWrite(RPin2, LOW);
  digitalWrite(LPin1, LOW);
  digitalWrite(LPin2, LOW);
  }
