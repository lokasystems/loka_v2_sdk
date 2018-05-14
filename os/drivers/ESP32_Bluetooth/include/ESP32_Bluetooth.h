//**********************************************************************************************************************************
// Filename: ESP32_Bluetooth.h
// Date: 09.02.2018
// Author: João Pombas
// Company: LOKA SYSTEMS
// Version: 1.0
// Description: Driver for the ESP32
//**********************************************************************************************************************************
#ifndef ESP32_BLUETOOTH_H_
#define ESP32_BLUETOOTH_H_

//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************

//**********************************************************************************************************************************
//                                                      Define Section
//**********************************************************************************************************************************

#define INQUIRY_DURATION		0x0a					// [0x01 - 0x30] discovery time, multiple of 1.28 sec

#define PAIRING_TIMEOUT			60000					// 30 seconds
#define READ_TIMEOUT			10000					// 10 seconds

//**********************************************************************************************************************************
//                                                     Templates Section
//**********************************************************************************************************************************
class Bluetooth {
public:
	static void init(unsigned long int boardNumber);
	static void disable();
	static void startSPP(void (*openCallback)(void), void (*dataCallback)(char*), void (*closeCallback)(void));
	static bool isConnected();
	static void write(char* str, int size);
	static unsigned int available();
	static char read();
};

#endif
