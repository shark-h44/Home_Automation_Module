
// https://github.com/zhouhan0126/WIFIMANAGER-ESP32
//


#include "Home_Automation_Module.h"

/*


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
  
}
 
void loop() {
  testLed();
  testRelay();
}
*/

////////////////////////////////////////////////////////////////

  #include <EEPROM.h>
  #include <FS.h>
  #include <ArduinoOTA.h>
  #include <Wire.h>
  #include <SPI.h>
  #include <Ticker.h>

  #include "./LibMCP23017.h"
  #include "./LibSSD1306.h"
  #include "./LibGFX.h"




// Variables globales
// ==================
// status global de l'application
uint16_t status = 0;
unsigned long uptime = 0;
bool first_setup;

  // Use WiFiClient class to create a connection to WEB server
  WiFiClient client;

  // define whole brigtness level for RGBLED
  uint8_t rgb_brightness = 127;

  bool reboot = false;



/* ======================================================================
Function: setup
Purpose : prepare and init stuff, configuration, ..
Input   : -
Output  : -
Comments: -
====================================================================== */
void setup()
{
  uint8_t rf_version = 0;

  DEBUG_SERIAL.begin(115200);

  // says main loop to do setup
  first_setup = true;

  Debugln("Starting main setup");
  Debugflush();
}



/* ======================================================================
Function: mysetup
Purpose : prepare and init stuff, configuration, ..
Input   : -
Output  : -
Comments: -
====================================================================== */
void mysetup()
{
 
    // Et on affiche nos paramètres
    Debugln("Core Network settings");
    Debug("IP   : "); Debugln(WiFi.localIP());
    Debug("Mask : "); Debugln(WiFi.subnetMask());
    Debug("GW   : "); Debugln(WiFi.gatewayIP());
    Debug("SSDI : "); Debugln(WiFi.SSID());
    Debug("RSSI : "); Debug(WiFi.RSSI());Debugln("dB");


  // Init bus I2C
  i2c_init();

  Debug("Soft Version ");
  Debugln(SOFT_VERSION);
  
  #ifdef MOD_OLED
    Debug("OLED ");
  #endif
 
  Debugln();

  // Init des fils pilotes
  if (pilotes_setup())
    status |= STATUS_MCP ;

  #ifdef MOD_OLED
    // Initialisation de l'afficheur
    if (display_setup())
    {
      status |= STATUS_OLED ;
      // Splash screen
      display_splash();
    }
  #endif


  // Feed the dog
  //_wdt_feed();

  // Led verte durant le test
  //LedRGBON(COLOR_GREEN);

  // nous avons fini, led Jaune
  //LedRGBON(COLOR_YELLOW);

  // Hors gel, désactivation des fils pilotes
  initFP();

  // On etteint la LED embarqué du core
  //LedRGBOFF();

  Debugln("Starting main loop");
  Debugflush();
}



/* ======================================================================
Function: loop
Purpose : boucle principale du programme
Input   : -
Output  : -
Comments: -
====================================================================== */
void loop()
{
  static bool refreshDisplay = false;
  static bool lastcloudstate;
  static unsigned long previousMillis = 0;  // last time update
  unsigned long currentMillis = millis();
  bool currentcloudstate ;

  // our own setup
  if (first_setup) {
    mysetup();
    first_setup = false;
  }

  /* Reboot handler */
  if (reboot) {
    delay(REBOOT_DELAY);
    ESP.restart();
  }

  // Gérer notre compteur de secondes
  if ( millis()-previousMillis > 1000) {
    // Ceci arrive toute les secondes écoulées
    previousMillis = currentMillis;
    uptime++;
    refreshDisplay = true ;
    #ifdef BLYNK_AUTH
      if ( Blynk.connected() ) {
        String up    = String(uptime) + "s";
        String papp  = String(mypApp) + "W";
        String iinst = String(myiInst)+ "A";
        Blynk.virtualWrite(V0, up, papp, iinst, mypApp);
        _yield();
      }
    #endif
  } else {
    #ifdef BLYNK_AUTH
      Blynk.run(); // Initiates Blynk
    #endif
  }

  #ifdef MOD_OLED
    // pour le moment on se contente d'afficher la téléinfo
    screen_state = screen_teleinfo;

    // Modification d'affichage et afficheur présent ?
    if (refreshDisplay && (status & STATUS_OLED))
      display_loop();
      _yield();
  #endif

  // çà c'est fait
  refreshDisplay = false;



}

 
