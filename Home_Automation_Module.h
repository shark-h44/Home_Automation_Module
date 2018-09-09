// **********************************************************************************
// Home automation module
// **********************************************************************************
// Copyright (C) 2018 Stéphane CHARGUI
// Licence MIT
//
// History : 
//  09/09/2017 Stéphane CHARGUI : Initialisation à partir du projet REMORA de Charles-Henri Hallard
//
// **********************************************************************************
#ifndef HOME_AUTOMATION_MODULE_H_
#define HOME_AUTOMATION_MODULE_H_

// Définir ici le type de carte utilisé
#define BOARD_VERSION 2    // Version 2

// Version logicielle 
#define SOFT_VERSION "1.0.0"

#define DEFAULT_WIFI_AP_PASS "AutoùationModule_WiFi"

// Définir ici les identifiants de
// connexion à votre réseau Wifi
// =====================================
  #define DEFAULT_WIFI_SSID "VotreSSID"
  #define DEFAULT_WIFI_PASS "VotreClé"

  // =====================================

  #include "Arduino.h"
  #include <EEPROM.h>
  #include <FS.h>
  #include <SPI.h>
  #include <Wire.h>
//#include "esp_task_wdt.h"
//#include <Adafruit_GFX.h>
//#include <Adafruit_SSD1306.h>
  #include "Test_card.h"
  #include <WiFi.h>
  #include <WiFiClient.h>
  #include <WebServer.h>
  #include <ESPmDNS.h>
  
  //#include <Ticker.h>
  //#include <NeoPixelBus.h>

extern "C" {
//#include "user_interface.h"
}

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

#define FNCT_RELAIS_ARRET 0 // Mode arrêt du relais
#define FNCT_RELAIS_FORCE 1 // Mode marche forcée du relais
#define FNCT_RELAIS_AUTO 2  // Mode auto du relais

  #include "./LibMCP23017.h"
  #include "./LibSSD1306.h"
  #include "./LibGFX.h"
  //#include "./LibULPNode_RF_Protocol.h"
  //#include "./LibLibTeleinfo.h"
  //#include "./LibRadioHead.h"
  //#include "./LibRHReliableDatagram.h"

  #define _yield  yield
 // #define _wdt_feed ESP.wdtFeed
  #define DEBUG_SERIAL  Serial
  //#define DEBUG_INIT
  #define REBOOT_DELAY    100     /* Delay for rebooting once reboot flag is set */


#define DEBUG // Décommenter cette ligne pour activer le DEBUG serial

// I prefix debug macro to be sure to use specific for THIS library
// debugging, this should not interfere with main sketch or other
// libraries
#ifdef DEBUG
#define Debug(x)    DEBUG_SERIAL.print(x)
#define Debugln(x)  DEBUG_SERIAL.println(x)
#define DebugF(x)   DEBUG_SERIAL.print(F(x))
#define DebuglnF(x) DEBUG_SERIAL.println(F(x))
#define Debugf(...) DEBUG_SERIAL.printf(__VA_ARGS__)
#define Debugflush  DEBUG_SERIAL.flush
#else
#define Debug(x)
#define Debugln(x)
#define DebugF(x)
#define DebuglnF(x)
#define Debugf(...)
#define Debugflush()
#endif

// Includes du projets remora
#include "config.h"
//#include "linked_list.h"
#include "i2c.h"
//#include "rfm.h"
//#include "display.h"
#include "pilotes.h"
//#include "tinfo.h"
//#include "webserver-module.h"
//#include "webclient.h"

// RGB LED related MACROS
  #define COLOR_RED     rgb_brightness, 0, 0
  #define COLOR_ORANGE  rgb_brightness, rgb_brightness>>1, 0
  #define COLOR_YELLOW  rgb_brightness, rgb_brightness, 0
  #define COLOR_GREEN   0, rgb_brightness, 0
  #define COLOR_CYAN    0, rgb_brightness, rgb_brightness
  #define COLOR_BLUE    0, 0, rgb_brightness
  #define COLOR_MAGENTA rgb_brightness, 0, rgb_brightness

  // On ESP8266 we use NeopixelBus library to drive neopixel RGB LED
//  #define RGB_LED_PIN 0 // RGB Led driven by GPIO0
//  #define LedRGBOFF() { rgb_led.SetPixelColor(0,0); rgb_led.Show(); }
//  #define LedRGBON(x) { RgbColor color(x); rgb_led.SetPixelColor(0,color); rgb_led.Show(); }
  //#define LedRGBOFF() {}
  //#define LedRGBON(x) {}



  // Creation macro unique et indépendante du type de
  // carte pour le controle des I/O
  #define _digitalWrite(p,v)  digitalWrite(p,v)
  #define _pinMode(p,v)       pinMode(p,v)
//#define _wdt_feed esp_task_wdt_feed()


// Masque de bits pour le status global de l'application
#define STATUS_MCP    0x0001 // I/O expander detecté
#define STATUS_OLED   0x0002 // Oled detecté


// Variables exported to other source file
// ========================================
// define var for whole project

// status global de l'application
extern uint16_t status;
extern unsigned long uptime ;
extern uint8_t rgb_brightness;
extern bool   reboot; /* Flag to reboot the ESP */
extern uint16_t status; // status global de l'application


#endif
