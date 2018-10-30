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

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <cstring>

#include "../../../components/Console/include/ConsoleInterface.h"

#include "InputOutput.h"
#include "LIS3DE_Acceleration.h"
#include "ESP32_RTC.h"
#include "SIM33ELA_GPS.h"
#include "ESP32_Wifi.h"
#include "ESP32_SerialPort.h"
#include "ESP32_Bluetooth.h"
#include "ESP32_SPIFFS.h"
#include "ESP32_AnalogSTUB.h"
#include "SIGFOX_Protocol.h"
#include "ESP32_HTTP.h"
#include "BOARD_LokaV2_ULP.h"

#include "ParseNumerics.h"



#include "esp32/ulp.h"
#include "soc/sens_reg.h"
#include "soc/rtc.h"
#include "soc/rtc_cntl_reg.h"
#include "soc/apb_ctrl_reg.h"
#include "sys/time.h"

extern "C" {
	#include "rom/uart.h"
	#include "driver/gpio.h"
	#include "driver/rtc_io.h"
	#include "nvs_flash.h"
	#include "nvs.h"
	#include "stdlib.h"
	#include "esp_system.h"
	#include "rom/rtc.h"
	#include "esp_sleep.h"
}

//**********************************************************************************************************************************
//                                                      Defined Section
//**********************************************************************************************************************************

#define FLASH_CONFIGS_PAGE								"CONFIGS"
#define FLASH_SIZE_MAX 									64

#define PROGRAM_SIGFOX_PROTOCOL_TIME_RESOLUTION			60

														// Flushes UART pending data, sleeps, dummy operations until sleeping
#define stubSleep()										while(REG_GET_FIELD(UART_STATUS_REG(0), UART_ST_UTX_OUT)); \
														CLEAR_PERI_REG_MASK(RTC_CNTL_STATE0_REG, RTC_CNTL_SLEEP_EN); \
														SET_PERI_REG_MASK(RTC_CNTL_STATE0_REG, RTC_CNTL_SLEEP_EN); \
														while(true);

#define DEBUG_RTC(...) 									ets_printf(__VA_ARGS__)

//**********************************************************************************************************************************
//                                                      Templates Section
//**********************************************************************************************************************************
class Board {
public:
	static char* getMAC();
	static unsigned long int getID();
	static char* getPAC();

	static void initPin(digio gpio);
	static void pinMode(digio gpio, pin_mode mode);
	static void digitalWrite(digio gpio, uint8_t value);
	static unsigned char digitalRead(digio gpio);

	static void blinkLED(unsigned int blinks, unsigned int time_on1, unsigned int time_off1, unsigned int time_on2, unsigned int time_off2);

	static void setFlash(const char* page, const char* name, const char* value);
	static void getFlash(const char* page, const char* name, char* value);
	static void getFlash(const char* page, const char* param_s, char* value, int index);

	static double getInputVoltageLoad();
	static double getInputVoltageOpen();

	static void enableWakeUp(unsigned int mask);
	static void disableWakeUp(unsigned int mask);
	static void setWakeUp(unsigned int mask);

	static void resetWakeUp();
	static void setWakeStub(void (*wakeStub)());
	static void setWakeUpTime(unsigned int ticks);

	static uint64_t convertSecondsToTicks(uint64_t seconds);
	static uint64_t convertTicksToSeconds(uint64_t ticks);
	static uint64_t convertMSecondsToTicks(uint64_t millis);
	static uint64_t convertTicksToMSeconds(uint64_t ticks);
};

#endif
