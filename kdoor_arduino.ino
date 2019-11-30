const int trigPin = 4;
const int echoPin = 5;
const int trigPin1 = 6;
const int echoPin1 = 7;
// defines variables
long duration; 
int distance;
long duration1;
int distance1;
bool sensor1 = false;
bool sensor2 = false;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication

}
// out : 1 in: 0

void loop() 
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
if (distance<10)
{
if (sensor2)
{

Serial.println("0");
}
sensor1 = true;
}

int count =0;
if ((sensor1) and (count<10))
{
  
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1, HIGH);
distance1 = duration1*0.034/2;

if (distance1<10)
{
Serial.println("1");
sensor2 = true;
}
delay(100);
count+=1;
}
delay(1000);
}
