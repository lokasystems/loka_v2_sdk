//**********************************************************************************************************************************
// Filename: GeoAPI.h
// Date: 01.04.2018
// Author: João Pombas
// Company: LOKA SYSTEMS
// Version: 1.0
// Description: API used by GeoService component
//**********************************************************************************************************************************

#ifndef GEOAPI_H_
#define GEOAPI_H_

//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************

#include "APStructs.h"

#include "BOARD_LokaV2.h"
#include "../../../main/configs.h"

#include "ESP32_SPIFFS.h"
#include "ESP32_Wifi.h"

#include "RadioAPI.h"

//**********************************************************************************************************************************
//                                                      Define Section
//**********************************************************************************************************************************

#define DEBUG_GEO				DEBUG

#define SAVE_SHORT_SCAN			false

#define CONTEXT_DATA_SAVED		4			// Context saved between iterations

#define MIN_DATA_SIZE			(int)(ceil((140 + (CONTEXT_DATA_SAVED*180)) / 16) * 16)


//**********************************************************************************************************************************
//                                                     Templates Section
//**********************************************************************************************************************************
class GeoAPI {

	public:
		static unsigned long int getDeviceID();
		static char* getData();
		static void scan(accessPoints* aps);
		static void directScan(accessPoints* aps, accessPoints* filterList, char ignoreBssidAndChannel = 0);
		static char additionalInfoToSend();
		static void deliver(unsigned char* buffer);
		static void postponedReport(char* fileName, unsigned long timestamp, char* buffer, int sizeToWrite);
		static int readFile(char* fileName, char* buffer, int sizeToRead, int readOffset);

	private:
		static char data[MIN_DATA_SIZE];
		static void history(unsigned long timestamp, accessPoints* aps, char* historyFile);
};

#endif
