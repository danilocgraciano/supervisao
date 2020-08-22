#define LENGTH 128

#define TX HIGH
#define RX LOW
#define RTS 11

//Caso não esteja definido, presume-se TTL
#define RS485

byte buffer[LENGTH];
byte request[8] = {1, 3, 2, 0, 0, 40, 68, 108};


int state = TX;
unsigned long txMillis;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(30);
  Serial1.begin(115200, SERIAL_8N1, 9, 10);
  Serial1.setTimeout(30);

#ifdef RS485
  pinMode(RTS, OUTPUT);
#endif

}

void loop() {

  if (state == TX) {

#ifdef RS485
    digitalWrite(RTS, TX);
    delay(10);
#endif

    Serial1.write(request, sizeof(request));
    Serial1.flush();

    Serial.print("TX: ");
    log(request, sizeof(request));

    state = RX;
    txMillis = millis();

#ifdef RS485
    digitalWrite(RTS, RX);
    delay(10);
#endif

  } else {

    if (Serial1.available()) {
      memset(buffer, 0, LENGTH);
      int length = Serial1.readBytes(buffer, LENGTH);
      Serial.print("RX: ");
      log(buffer, length);
      state = TX;
    } else {
      if ((millis() - txMillis) >= 5000) {
        state = TX;
      }
    }

  }

}

void log(byte data[], int size) {
  for (int i = 0; i < size; i++) {
    Serial.print(data[i]);
    if (i + 1 < size) {
      Serial.print(", ");
    }

  }
  Serial.println();
}
