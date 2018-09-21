//**********************************************************************************************************************************
// Filename: GPSAPI.h
// Date: 10.08.2018
// Author: João Pombas
// Company: LOKA SYSTEMS
// Version: 1.0
// Description: API used by GPSService component
//**********************************************************************************************************************************

#ifndef GPSAPI_H_
#define GPSAPI_H_

//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************

#include "BOARD_LokaV2.h"
#include "SIM33ELA_GPS.h"
#include "RadioAPI.h"

//**********************************************************************************************************************************
//                                                      Define Section
//**********************************************************************************************************************************

#define GPS_COLD_START_TIMEOUT 			600		// seconds
#define GPS_WARM_START_TIMEOUT 			120		// seconds

//**********************************************************************************************************************************
//                                                     Templates Section
//**********************************************************************************************************************************
class GPSAPI {

	public:
		static void getTimeoutValues(unsigned int* coldTimeout, unsigned int* warmTimeout);
		static void init();
		static void reset();
		static void turnON(unsigned char auxParam);
		static void turnOFF();
		static bool getGPSCoordinates(float* latitude, float* longitude, float* altitude, float* speed, int timeOut);
		static void sendMessage(double lat, double lng, double speed, double timestamp);

	private:

};

#endif
