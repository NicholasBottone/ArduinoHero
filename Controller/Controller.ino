int RED_BUTTON = 6;
int BLUE_BUTTON = 7;
int GREEN_BUTTON = 8;
int YELLOW_BUTTON = 9;
int PURPLE_BUTTON = 10;

int STRUM_BUTTON_UP = 4;
int STRUM_BUTTON_DOWN = 5;

void setup() {
  Serial.begin(9600);
  while (!Serial); // Wait for Serial to initialize
  pinMode(RED_BUTTON, INPUT);
  pinMode(BLUE_BUTTON, INPUT);
  pinMode(GREEN_BUTTON, INPUT);
  pinMode(YELLOW_BUTTON, INPUT);
  pinMode(PURPLE_BUTTON, INPUT);
  pinMode(STRUM_BUTTON_UP, INPUT);
  pinMode(STRUM_BUTTON_DOWN, INPUT);

  attachInterrupt(STRUM_BUTTON_UP, strumInterrupt, RISING);
  attachInterrupt(STRUM_BUTTON_DOWN, strumInterrupt, RISING);
}

void loop() {
}

void strumInterrupt() {
  // if(digitalRead(STRUM_BUTTON_UP) == 1) Serial.println("STRUM UP PUSHED");
  // if(digitalRead(STRUM_BUTTON_DOWN) == 1) Serial.println("STRUM DOWN PUSHED");

  if(digitalRead(RED_BUTTON) == 1) 
    {Serial.print("R ");
  } else {
    Serial.print("- ");
  }

  if(digitalRead(PURPLE_BUTTON) == 1) {
    Serial.print("P ");
  } else {
    Serial.print("- ");
  }

  if(digitalRead(GREEN_BUTTON) == 1){
    Serial.print("G ");
  } else {
    Serial.print("- ");
  }

  if(digitalRead(YELLOW_BUTTON) == 1) {
    Serial.print("Y ");
  } else {
    Serial.print("- ");
  }

  if(digitalRead(BLUE_BUTTON) == 1) {
    Serial.println("B");
  } else {
    Serial.println("-");
  }
  
  delay(100);
}
