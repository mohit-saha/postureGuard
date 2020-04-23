#define trigpin 7
#define echopin 10
#define safepin 2
#define notsafe 4
float duration,distance;
float safedistance=0;
void setup() {
Serial.begin(9600);  // put your setup code here, to run once:
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
pinMode(safepin,OUTPUT);
pinMode(notsafe,OUTPUT);
}

void loop() {
  digitalWrite(safepin,LOW);
  digitalWrite(notsafe,LOW);
 digitalWrite(trigpin,LOW);
 delayMicroseconds(2);// put your main code here, to run repeatedly:
 digitalWrite(trigpin,HIGH);
 delayMicroseconds(2);

 duration =pulseIn(echopin,HIGH);

 distance =(duration/2)*0.0343;

 Serial.print("Distance =   ");
// Serial.print(distance);

if(distance >=50 && distance <=100){
  digitalWrite(safepin,HIGH);
  digitalWrite(notsafe,LOW);
  Serial.print(distance);
  }else{
    digitalWrite(safepin,LOW);
    digitalWrite(notsafe,HIGH);
    Serial.print("not safe maintain atleast 50 and atmost 100 cm ");
    }
    
 Serial.print("\n ");
 delay(1000);
}
