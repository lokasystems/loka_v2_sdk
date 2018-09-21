//**********************************************************************************************************************************
// Filename: RadioAPI.h
// Date: 18.09.2018
// Author: João Pombas
// Company: LOKA SYSTEMS
// Version: 1.0
// Description: RadioAPI component
//**********************************************************************************************************************************
#ifndef RADIO_API_H_
#define RADIO_API_H_

//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************

#include "BOARD_LokaV2.h"
#include "SIGFOX_Protocol.h"

//**********************************************************************************************************************************
//                                                      Define Section
//**********************************************************************************************************************************

//**********************************************************************************************************************************
//                                                     Templates Section
//**********************************************************************************************************************************
class Radio {

	public:
		static void turnOn();
		static void turnOff();
		static char sendMessage(unsigned char* message, int size, char requestAck = false);
		static char sendGPIOValue(int gpio, char value, char requestAck = false);
		static char sendAnalogValue(int port, double value, char requestAck = false);
		static char sendAnalogValue(int port, double value, int port2, double value2, char requestAck = false);
		static char sendGPSPosition(double latitude, double longitude, double speed, double timestamp, char requestAck = false);
		static int sendMessageAndReadResponse(unsigned char* message, int size, unsigned char* response, int timeout);

	private:

};


#endif
