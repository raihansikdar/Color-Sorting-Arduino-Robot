#include <Servo.h>
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
#define x 12
Servo servo1;
Servo servo2;

int frequency = 0;
int color=0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  servo1.attach(7);
  servo2.attach(8);
  pinMode(OUTPUT,x);
  Serial.begin(9600);
}
void loop() {
  servo2.write(10);
  digitalWrite(x,HIGH);
  
  color = readColor();
  delay(10);  
 
  
  color=0;
}
// Custom Function - readColor()
int readColor() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);
  
  // Setting White filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int W = frequency;
  // Printing the value on the serial monitor
  Serial.print("W= ");//printing name
  Serial.print(frequency);//printing WHITE color frequency
  Serial.print("  ");
  delay(50);
  
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing BLUE color frequency
  Serial.println("  ");
  delay(50);
  
  if((R<350 && R> 280) &  (W>500 &&W<600 )){         //R= 304  W= 579  B= 496 
    servo1.write(90); // Red
    servo2.write(100);
    delay(1000);

Serial.println("Red.........") ;
    
  
  }
  if((R<650 && R>460) && (W>600&&W<648) &&  (B>430 && B<520)){         //R= 616  W= 648  B= 480
    servo1.write(130);
    servo2.write(100);
    delay(1000);
    Serial.println("Blue............");
  }
  if((R<300 && R> 270) & (W>260 &&W<310)&(B>240 && B<570 )){          // R= 285  W= 283  B= 257
    servo1.write(150);
    servo2.write(100);
    delay(1000);
    Serial.println("white......");
  }
 
  return color;  
}
