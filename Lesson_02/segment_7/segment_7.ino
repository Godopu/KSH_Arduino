/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  int i;
  
  Serial.begin(9600);
  
  for(i=2 ; i<10 ; i++)
  {
    pinMode(i, OUTPUT);  
    digitalWrite(i, HIGH);
    Serial.println(i);
  }
  for(i=10 ; i<18 ; i++)
  {
    pinMode(i, OUTPUT);  
    digitalWrite(i, HIGH);
    Serial.println(i);
  }
}

// the loop function runs over and over again forever
void loop() {
  int i , j;

  for(j = 0 ; j < 10 ; j++)
  {
    printDigit(2 , j);
    for(i=0 ; i < 10 ; i++)
    {
      printDigit(10 , i);
    
      delay(1000);                       // wait for a second
    }
  }
  
}

void printDigit(int base , int num){
  switch(num)
  {
    case 0:
      digitalWrite('a'-'a'+base, LOW);
      digitalWrite('b'-'a'+base, LOW);
      digitalWrite('c'-'a'+base, LOW);
      digitalWrite('d'-'a'+base, LOW);
      digitalWrite('e'-'a'+base, LOW);
      digitalWrite('f'-'a'+base, LOW);
      digitalWrite('g'-'a'+base, HIGH);
      digitalWrite('h'-'a'+base, HIGH);
    break;

    case 1:
      digitalWrite('a'-'a'+base, HIGH);
      digitalWrite('b'-'a'+base, LOW);
      digitalWrite('c'-'a'+base, LOW);
      digitalWrite('d'-'a'+base, HIGH);
      digitalWrite('e'-'a'+base, HIGH);
      digitalWrite('f'-'a'+base, HIGH);
      digitalWrite('g'-'a'+base, HIGH);
      digitalWrite('h'-'a'+base, HIGH);
    break;

    case 2:
      digitalWrite('a'-'a'+base, LOW);
      digitalWrite('b'-'a'+base, LOW);
      digitalWrite('c'-'a'+base, HIGH);
      digitalWrite('d'-'a'+base, LOW);
      digitalWrite('e'-'a'+base, LOW);
      digitalWrite('f'-'a'+base, HIGH);
      digitalWrite('g'-'a'+base, LOW);
      digitalWrite('h'-'a'+base, HIGH);
    break;

    case 3:
      digitalWrite('a'-'a'+base, LOW);
      digitalWrite('b'-'a'+base, LOW);
      digitalWrite('c'-'a'+base, LOW);
      digitalWrite('d'-'a'+base, LOW);
      digitalWrite('e'-'a'+base, HIGH);
      digitalWrite('f'-'a'+base, HIGH);
      digitalWrite('g'-'a'+base, LOW);
      digitalWrite('h'-'a'+base, HIGH);
    break;

    case 4:
      digitalWrite('a'-'a'+base, HIGH);
      digitalWrite('b'-'a'+base, LOW);
      digitalWrite('c'-'a'+base, LOW);
      digitalWrite('d'-'a'+base, HIGH);
      digitalWrite('e'-'a'+base, HIGH);
      digitalWrite('f'-'a'+base, LOW);
      digitalWrite('g'-'a'+base, LOW);
      digitalWrite('h'-'a'+base, HIGH);
    break;

    case 5:
      digitalWrite('a'-'a'+base, LOW);
      digitalWrite('b'-'a'+base, HIGH);
      digitalWrite('c'-'a'+base, LOW);
      digitalWrite('d'-'a'+base, LOW);
      digitalWrite('e'-'a'+base, HIGH);
      digitalWrite('f'-'a'+base, LOW);
      digitalWrite('g'-'a'+base, LOW);
      digitalWrite('h'-'a'+base, HIGH);
    break;

    case 6:
      digitalWrite('a'-'a'+base, LOW);
      digitalWrite('b'-'a'+base, HIGH);
      digitalWrite('c'-'a'+base, LOW);
      digitalWrite('d'-'a'+base, LOW);
      digitalWrite('e'-'a'+base, LOW);
      digitalWrite('f'-'a'+base, LOW);
      digitalWrite('g'-'a'+base, LOW);
      digitalWrite('h'-'a'+base, HIGH);
    break;

    case 7:
      digitalWrite('a'-'a'+base, LOW);
      digitalWrite('b'-'a'+base, LOW);
      digitalWrite('c'-'a'+base, LOW);
      digitalWrite('d'-'a'+base, HIGH);
      digitalWrite('e'-'a'+base, HIGH);
      digitalWrite('f'-'a'+base, LOW);
      digitalWrite('g'-'a'+base, HIGH);
      digitalWrite('h'-'a'+base, HIGH);
    break;

    case 8:
      digitalWrite('a'-'a'+base, LOW);
      digitalWrite('b'-'a'+base, LOW);
      digitalWrite('c'-'a'+base, LOW);
      digitalWrite('d'-'a'+base, LOW);
      digitalWrite('e'-'a'+base, LOW);
      digitalWrite('f'-'a'+base, LOW);
      digitalWrite('g'-'a'+base, LOW);
      digitalWrite('h'-'a'+base, HIGH);
    break;

    case 9:
      digitalWrite('a'-'a'+base, LOW);
      digitalWrite('b'-'a'+base, LOW);
      digitalWrite('c'-'a'+base, LOW);
      digitalWrite('d'-'a'+base, LOW);
      digitalWrite('e'-'a'+base, HIGH);
      digitalWrite('f'-'a'+base, LOW);
      digitalWrite('g'-'a'+base, LOW);
      digitalWrite('h'-'a'+base, HIGH);
    break;
    
  }
}

