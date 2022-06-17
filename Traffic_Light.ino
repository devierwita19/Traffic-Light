int redCar = 13;
int yellowCar = 12;
int greenCar = 11;
int greenPed = 2;
int redPed = 3;
int button = 7;
int crossTime = 2000;
unsigned long changeTime;

void setup() {
  // initialize timer
  changeTime = millis();
  //pins
  pinMode(redCar, OUTPUT);
  pinMode(yellowCar, OUTPUT);
  pinMode(greenCar, OUTPUT);
  pinMode(greenPed, OUTPUT);
  pinMode(redPed, OUTPUT);
  pinMode(button, INPUT);

  digitalWrite(greenCar, HIGH);
  digitalWrite(redPed, HIGH);
  digitalWrite(redCar, LOW);
  digitalWrite(yellowCar, LOW);
  digitalWrite(greenPed, LOW);

  Serial.begin(9600);
}

void loop() {
  int state = digitalRead(button);
  Serial.println(state);

  if (state == HIGH && (millis()-changeTime)>5000) {
    changeLights();
  }
}

void changeLights() {
  digitalWrite(greenCar, LOW);
  digitalWrite(yellowCar, HIGH);
  delay(2000);

  digitalWrite(yellowCar, LOW);
  digitalWrite(redCar, HIGH);

  digitalWrite(redPed, LOW);
  digitalWrite(greenPed, HIGH);
  delay(crossTime);

  for (int x=0; x<10; x++) {
    digitalWrite(greenPed, LOW);
    delay(100);
    digitalWrite(greenPed, HIGH);
    delay(100);
  }

  digitalWrite(greenPed, LOW);
  digitalWrite(redCar, LOW);
  digitalWrite(redPed, HIGH);
  digitalWrite(greenCar, HIGH);

  changeTime = millis();
}
