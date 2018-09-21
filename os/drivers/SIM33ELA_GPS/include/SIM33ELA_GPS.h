//**********************************************************************************************************************************
// Filename: SIM33ELA_GPS.cpp
// Date: 22.01.2018
// Author: Hugo Silva
// Company: LOKA SYSTEMS
// Version: 1.0
// Description: Driver for the module SIM33ELA GPS
// 				NOTES: Module not fully tested!!!
//				ATTENTION:	- Instruction set is probably NMEA messages for NavSpark-GL. Please review TinyGPS messages
//							- User have to redefine UART pins in InputOutput.h
//**********************************************************************************************************************************
#ifndef SIM33ELA_GPS_H_
#define SIM33ELA_GPS_H_

//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************


//**********************************************************************************************************************************
//                                                      Define Section
//**********************************************************************************************************************************

#define GPS_LAST_FIX_TIME_INTERVAL		10*3600	// seconds
#define GPS_COLD_START_TIMEOUT 			600		// seconds
#define GPS_WARM_START_TIMEOUT 			120		// seconds

//**********************************************************************************************************************************
//                                                     Templates Section
//**********************************************************************************************************************************
class GPS_SIM33ELA{
public:
	static void init();
	static void reset();
	static void gpsTurnON(unsigned char balloonMode);
	static void gpsBackupMode();
	static void gpsSleepMode();
	static bool gpsFixStatus();
	static bool getGPSCoordinates(float* latitude, float* longitude, float* altitude, float* speed, int timeOut);
	static float distanceBetween(float lat1, float long1, float lat2, float long2);
};

#endif
