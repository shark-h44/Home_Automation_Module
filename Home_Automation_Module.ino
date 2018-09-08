
#define LED_RED_PIN   13
#define LED_GREEN_PIN 15
#define LED_BLUE_PIN   2

#define RELAY_1_PIN   5
#define RELAY_2_PIN   17
#define RELAY_3_PIN   16
#define RELAY_4_PIN   4
#define RELAY_5_PIN   12
#define RELAY_6_PIN   14
#define RELAY_7_PIN   27
#define RELAY_8_PIN   26


void setup() {
 
  Serial.begin(115200);
  delay(1000);

  // initialize the digital pin as an output.
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);
  
  pinMode(RELAY_1_PIN, OUTPUT);
  pinMode(RELAY_2_PIN, OUTPUT);
  pinMode(RELAY_3_PIN, OUTPUT);
  pinMode(RELAY_4_PIN, OUTPUT);
  pinMode(RELAY_5_PIN, OUTPUT);
  pinMode(RELAY_6_PIN, OUTPUT);
  pinMode(RELAY_7_PIN, OUTPUT);
  pinMode(RELAY_8_PIN, OUTPUT);
  

 
void loop() {
  testLed();
  testRelay();
}
 
