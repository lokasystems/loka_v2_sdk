//**********************************************************************************************************************************
// Filename: MonitoringAPI.h
// Date: 13.08.2018
// Author: João Pombas
// Company: LOKA SYSTEMS
// Version: 1.0
// Description: API used by MonitoringService component
//**********************************************************************************************************************************

#ifndef MONITORING_API_H_
#define MONITORING_API_H_

//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************

#include "BOARD_LokaV2.h"
#include "SIM33ELA_GPS.h"
#include "RadioAPI.h"

#include "../../../components/Utils/include/SensorStructs.h"
#include "Tracking.h"

#include "soc/timer_group_reg.h"

//**********************************************************************************************************************************
//                                                      Define Section
//**********************************************************************************************************************************

#define RULES_NUMBER				5		// CONST defined at MonitoringService

// ADC Configuration
#define DEFAULT_ADC_SAMPLES			10
#define DEFAULT_ADC_ATTEN			ADC_ATTEN_0db

// Movement
#define MOVEMENT_THRESHOLDS			{2, 2, 3, 4, 5, 6, 8, 10, 20, 30, 40, 50, 60, 80, 100, 126}

// Time scaling
#define PRE_SCALING_ARRAY			{1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000}
#define SENSOR_DELAY_ARRAY			{0, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000} // ms

typedef struct newMonitoringRule{
	unsigned char enabled;
	sensor_read sensorRead;
	sensor_enable sensorEnableOn;
	sensor_enable sensorEnableOff;
	unsigned int sensorEnableDelay;
    int lowThreshold;
    int highThreshold;
    unsigned char condition;
    unsigned char action;
    unsigned int prescale;
    unsigned char alarmMode;
    unsigned char alarmDownlinkRetry;
    char statisticReportEnabled;
    unsigned char statisticReportDownlinkRetry;
    unsigned char logData;

}newMonitoringRule;

//**********************************************************************************************************************************
//                                                     Templates Section
//**********************************************************************************************************************************
class MonitoringAPI {

	public:
		static int setRules(newMonitoringRule* rules, int maxRulesNumber);
		static void runTracking();
		static void sendLocation();
		static char sendCustomMessage(unsigned char* message, int size, char sendAsDownlink);
		static char sendSensorMessage(sensor_read sensor, int readValue, char sendAsDownlink);
		static void history(char* historyFile, unsigned long timestamp, sensor_read sensor, int readValue);
		static uint64_t convertSTUBTimeToSeconds(uint64_t stubTime);
		static uint64_t getDeviceTime();
		static uint64_t getSTUBTime();
		static void enableSensor(unsigned char port, unsigned char value);
		static void enableSensorDelay(unsigned int delay);
		static int readSensor(sensor_read sensorType);

	private:

};

#endif
