

void testLed(void)
{
  Serial.println("RGB led off");
  digitalWrite(LED_RED_PIN, LOW);
  digitalWrite(LED_GREEN_PIN, LOW);
  digitalWrite(LED_BLUE_PIN, LOW);
  delay(2000);

  Serial.println("RGB led red on");
  digitalWrite(LED_RED_PIN, HIGH); // turn the LED on 
  delay(1000); // wait for a second
  digitalWrite(LED_RED_PIN, LOW); // turn the LED off

  Serial.println("RGB led green on");
  digitalWrite(LED_GREEN_PIN, HIGH); // turn the LED on 
  delay(1000); // wait for a second
  digitalWrite(LED_GREEN_PIN, LOW); // turn the LED off
 
  Serial.println("RGB led blue on");
  digitalWrite(LED_BLUE_PIN, HIGH); // turn the LED on 
  delay(1000); // wait for a second
  digitalWrite(LED_BLUE_PIN, LOW); // turn the LED off
 }



void relayToogle (int num, int pin, int delayUp=2000, int delayDown=2000 )
{
  char buffer[12];
  
  sprintf(buffer, "Relay %d on",num);
  Serial.println(buffer);
  digitalWrite(pin, HIGH);
  delay(delayUp);

  sprintf(buffer, "Relay %d off",num);
  Serial.println(buffer); 
  digitalWrite(pin, LOW);
  delay(delayDown);
}

void testRelay(void)
{
  relayToogle(1, RELAY_1_PIN);
  relayToogle(2, RELAY_2_PIN);
  relayToogle(3, RELAY_3_PIN);
  relayToogle(4, RELAY_4_PIN);
  relayToogle(5, RELAY_5_PIN);
  relayToogle(6, RELAY_6_PIN);
  relayToogle(7, RELAY_7_PIN);
  relayToogle(8, RELAY_8_PIN);
 }
