void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int illuminance = analogRead(A0);
  if(illuminance >= 0 && illuminance < 1024)
  {
    Serial.print("Illuminance : ");
    Serial.println(illuminance);
    delay(1000);
  }
}


