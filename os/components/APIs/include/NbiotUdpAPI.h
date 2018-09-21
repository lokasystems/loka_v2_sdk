//**********************************************************************************************************************************
// Filename: NbiotUdpAPI.h
// Date: 24.08.2018
// Author: João Pombas
// Company: LOKA SYSTEMS
// Version: 1.0
// Description: NB_IOT_UDP component
//**********************************************************************************************************************************
#ifndef NB_IOT_UDP_H_
#define NB_IOT_UDP_H_

//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************

#include "stdint.h"
#include "stdlib.h"
#include "soc/rtc.h"
#include "stdio.h"
#include "string.h"
#include "ctype.h"

#include "BOARD_LokaV2.h"

#include "NBIOT_BC68.h"
#include "ESP32_HTTP.h"

//**********************************************************************************************************************************
//                                                      Define Section
//**********************************************************************************************************************************

#define NB_RESPONSE_TIMEOUT				6	//seconds

//#define COAP_WIFI

//**********************************************************************************************************************************
//                                                     Templates Section
//**********************************************************************************************************************************
class UDP {

	public:
		static unsigned char begin(int port);
		static unsigned char beginPacket(char* ip, int port);
		static uint16_t write(uint8_t* buffer, uint16_t packetSize);
		static uint32_t read(uint8_t* buffer, uint32_t bufferSize);
		static uint32_t parsePacket();
		static unsigned char endPacket();
		static char* remoteIP();
		static int remotePort();

	private:

};


class NB_IOT_UDP : public UDP{

	public:
		static unsigned char begin(int port);
		static unsigned char beginPacket(char* ip, int port);
		static uint16_t write(uint8_t* buffer, uint16_t packetSize);
		static uint32_t read(uint8_t* buffer, uint32_t bufferSize);
		static uint32_t parsePacket();
		static unsigned char endPacket();
		static char* remoteIP();
		static int remotePort();

	private:


};

#endif
