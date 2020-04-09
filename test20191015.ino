const byte A = 5;  // 馬達A的致能接腳
const byte pin1 = 10;  // 馬達A的正反轉接腳
const byte pin3 = 8;  // 馬達A的正反轉接腳
const byte speed = 200;
const byte TrigPin = 12;  // 超音波模組的觸發腳
const byte EchoPin = 13;  // 超音波模組的接收腳
long duration, cm, inches;

const int buzzer = 2;
const int Led=3;                                             
const int fireSensor=7;                                      
int val;  

void Stop() {  // 馬達停止
  analogWrite(A, 0); // 馬達A的PWM輸出
  
 }

  void forward(){      // 馬達轉向：前進（兩個馬達都正轉）
   analogWrite(A, speed);  // 馬達A的PWM輸出
  digitalWrite(pin1, HIGH);  
  digitalWrite(pin3, LOW);
 }
void setup() {
   Serial.begin (9600); 
  pinMode(pin1, OUTPUT);    // 觸發腳設定成「輸出」
  pinMode(pin3, OUTPUT);    // 接收腳設定成「輸入」
  pinMode(TrigPin, OUTPUT);    // 觸發腳設定成「輸出」
  pinMode(EchoPin, INPUT);    // 接收腳設定成「輸入」
    pinMode(Led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(fireSensor,INPUT);
}

void loop() {
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(TrigPin, HIGH);     // 給 Trig 高電位，持續 10微秒
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  pinMode(EchoPin, INPUT);             // 讀取 echo 的電位
  duration = pulseIn(EchoPin, HIGH);   // 收到高電位時的時間
 
  cm = (duration/2) / 29.1;         // 將時間換算成距離 cm 或 inch  
  inches = (duration/2) / 74; 

  Serial.print("Distance : ");  
  Serial.print(inches);
  Serial.print("in,   ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(250);
  
  val=digitalRead(fireSensor);
  if(val==LOW)
  { 
    digitalWrite(Led,HIGH);  
    digitalWrite(buzzer,HIGH); 
    delay(3000);
  }else{ 
    digitalWrite(Led,LOW);
    digitalWrite(buzzer,LOW);
  }
  forward();
   

}
