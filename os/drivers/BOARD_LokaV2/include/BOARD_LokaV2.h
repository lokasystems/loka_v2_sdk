//**********************************************************************************************************************************
// Filename: BOARD_LokaV2.h
// Date: 18.10.2017
// Author: Rafael Pires
// Company: LOKA SYSTEMS
// Version: 1.0
// Description: Code to operate the LOKA V2 board firmware
//**********************************************************************************************************************************
#ifndef BOARD_LOKAV2_H_
#define BOARD_LOKAV2_H_


//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************

#include <stdint.h>
#include <cstring>

#include "../../../components/Console/include/ConsoleInterface.h"

#include "InputOutput.h"
#include "LIS3DE_Acceleration.h"
#include "ESP32_RTC.h"
#include "ESP32_Wifi.h"
#include "ESP32_SerialPort.h"
#include "ESP32_Bluetooth.h"
#include "ESP32_SPIFFS.h"
#include "SIGFOX_Protocol.h"
#include "ESP32_HTTP.h"

//**********************************************************************************************************************************
//                                                      Defined Section
//**********************************************************************************************************************************

#define FLASH_CONFIGS_PAGE	"CONFIGS"
#define FLASH_SIZE_MAX 		32

//**********************************************************************************************************************************
//                                                      Templates Section
//**********************************************************************************************************************************
class Board {
public:
	static char* getMAC();
	static unsigned long int getID();
	static char* getPAC();

	static void pinMode(digio gpio, pin_mode mode);
	static void digitalWrite(digio gpio, uint8_t value);
	static unsigned char digitalRead(digio gpio);

	static void blinkLED(unsigned int blinks, unsigned int time_on, unsigned int time_off);

	static void setFlash(const char* page, const char* name, const char* value);
	static void getFlash(const char* page, const char* name, char* value);
	static void getFlash(const char* page, const char* param_s, char* value, int index);

	static void enableWakeUp(unsigned int mask);
	static void disableWakeUp(unsigned int mask);
	static void setWakeUp(unsigned int mask);
};

#endif
