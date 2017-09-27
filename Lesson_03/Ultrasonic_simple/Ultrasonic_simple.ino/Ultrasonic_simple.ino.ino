int trig = 4 ; 
int echo = 3 ;
int led[] = {5,6,7,8,9,10,11,12,13};

void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig , HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  int duration = pulseIn(echo, HIGH);
  int dis = duration / 29 / 2 ; 

  Serial.print("dis : ");
  Serial.println(dis);
}
