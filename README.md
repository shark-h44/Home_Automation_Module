# Home_Automation_Module
DETAILED DESCRIPTION
Card based on ESP32 microcontroller.

This board was designed to drive 9 low power relays to control Yokis MVR500E rolling shutter automation.
As well as 8 zones (pilot wires) for heating.
It is possible to program the card via the planned PROG connector or by OTA (depending on the code)

Code under development (I accept help) a github will be set up soon

Last additions:
- RGB Led
- Grove I2C connector
- Display connector
- Double imprint for power supply via BAT + and BAT- terminals

Last corrections:
- Polarized relay wired upside down
- Miss track on pilot wire feed
- Added reset on I2C extender