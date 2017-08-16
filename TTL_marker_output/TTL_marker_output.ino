void setup() {
  // LED monitor pin.
  pinMode(13, OUTPUT); 
  
  // S1 pin.
  pinMode(2, OUTPUT); 
  
  // S2 pin.
  pinMode(3, OUTPUT); 
  
  // S4 pin.
  pinMode(4, OUTPUT); 
  
  // S8 pin.
  pinMode(5, OUTPUT); 
  
  // S16 pin.
  pinMode(6, OUTPUT);
   
  // S32 pin.
  pinMode(7, OUTPUT); 
  
  // S64 pin.
  pinMode(8, OUTPUT); 
  
  // Initialize serial.
  Serial.begin(128000);
}

void loop() {
  while (Serial.available()){

    // Read integer from serial connection.
    int inInt = (int)Serial.parseInt();

    // Turn on the appropriate pins based upon the binary mask from the read integer.
    digitalWrite(2, HIGH && (inInt & B00000001));
    digitalWrite(3, HIGH && (inInt & B00000010));
    digitalWrite(4, HIGH && (inInt & B00000100));
    digitalWrite(5, HIGH && (inInt & B00001000));
    digitalWrite(6, HIGH && (inInt & B00010000));
    digitalWrite(7, HIGH && (inInt & B00100000));
    digitalWrite(8, HIGH && (inInt & B01000000));

    // Turn on the LED to show that a TTL pulse has been output (useful for debugging).
    digitalWrite(13, HIGH);

    // Wait 5 ms.
    delay(5);

    // Turn all pins off.
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(13, LOW);
  }
}
