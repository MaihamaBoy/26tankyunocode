const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 5;
float distance_former = 0;

void setup() {
  long duration0;

  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin,OUTPUT);

  //とりが信号を送る（初期状態の記録をするため）
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration0 = pulseIn(echoPin, HIGH);

  // 距離を計算（音速343m/s）
  distance_former = duration0 * 0.034 / 2;

}

void loop() {
  long duration;
  float distance;

  // トリガ信号を送る
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // EchoピンがHIGHになっている時間を測定
  duration = pulseIn(echoPin, HIGH);

  // 距離を計算（音速343m/s）
  distance = duration * 0.034 / 2;

 //距離の変化が現在の距離の5%以上の大きさだったら開いたと判定する
  if ((distance_former - distance ) >= distance * 0.1){

    digitalWrite(ledPin,HIGH);
    delay(100);
    digitalWrite(ledPin,LOW);
    delay(100);
    digitalWrite(ledPin,HIGH);
    delay(100);
    digitalWrite(ledPin,LOW);

  } else {
  
    digitalWrite(ledPin,LOW);
  
  }

  // シリアルモニタに表示
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

 //距離の前後変化比較用のやつです。
  distance_former = distance;

  delay(500);
}

