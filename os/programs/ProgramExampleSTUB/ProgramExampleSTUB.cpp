//**********************************************************************************************************************************
// Filename: ProgramExampleSTUB.cpp
// Date: 09.05.2018
// Author: Joao Pombas
// Company: LOKA SYSTEMS
// Version: 1.0
// Description:
//**********************************************************************************************************************************


//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************
#include "../ProgramExampleSTUB/include/ProgramExampleSTUB.h"

//**********************************************************************************************************************************
//                                                     External Functions
//**********************************************************************************************************************************

extern "C"{
	int readTemperature();
};

//**********************************************************************************************************************************
//                                                     Global Variables
//**********************************************************************************************************************************

RTC_DATA_ATTR unsigned long ProgramExampleSTUB::nextWakeUpTime;				// MANDATORY variables to the normal program behavior
RTC_DATA_ATTR bool ProgramExampleSTUB::executable;

RTC_DATA_ATTR unsigned long	ProgramExampleSTUB::mySleepingTime;
RTC_DATA_ATTR unsigned char	ProgramExampleSTUB::temperatureInterval;

RTC_DATA_ATTR int ProgramExampleSTUB::currentTemperature;

static const char RTC_RODATA_ATTR tempPrint[] = "\nEXAMPLE_STUB:\t\t Read temperature: %d ºC\n";				// TODO REMOVER

//**********************************************************************************************************************************
//                                                        Code Section
//**********************************************************************************************************************************

//**********************************************************************************************************************************
// Header: ProgramExampleSTUB::setConfig
// Function: Used in Sigfox PROTOCOL to set program configurations over the air
//**********************************************************************************************************************************
void ProgramExampleSTUB::setConfig(unsigned char * newConfig){						 //				#########  UNUSED YET  #########
//	char str [32];
//	Board::setFlash(FLASH_CONFIGS_PAGE, "program", getProgramTAG());
//	Board::setFlash(FLASH_CONFIGS_PAGE, getProgramTAG(), str);

// Parse newConfig and sets in flash the new program configuration
}


//**********************************************************************************************************************************
// Header: ProgramExampleSTUB::getConfig
// Function: Used in Sigfox PROTOCOL to get program configurations, returned in configBuffer
//**********************************************************************************************************************************
void ProgramExampleSTUB::getConfig(char * configBuffer){							//				#########  UNUSED YET  #########
//	char configValue[FLASH_SIZE_MAX + 1] = {0};
//	Board::getFlash(FLASH_CONFIGS_PAGE, getProgramTAG(), configValue, 0);

// Parse custom configuration values, and build configBuffer
}


//**********************************************************************************************************************************
// Header: ProgramExampleSTUB::getProgramID
// Function: Retrieves the program ID
//**********************************************************************************************************************************
unsigned char ProgramExampleSTUB::getProgramID(){								   //				#########  UNUSED YET  #########
	return 255;																	   // Default, used to identify program to set/get
}																				   // the program configurations over SIGFOX


//**********************************************************************************************************************************
// Header: ProgramExampleSTUB::getProgramTAG
// Function: Retrieves the program TAG
//**********************************************************************************************************************************
char* ProgramExampleSTUB::getProgramTAG(){
	return MY_STUB_PROGRAM_TAG;											// Used in Get/Set Flash methods to identify the program
}																		// when save the custom program configurations


//**********************************************************************************************************************************
// Header: ProgramExampleSTUB::wakeupStub
// Function: Runs every time the ESP32 wakes-up, checks temperature conditions, may set the processor back to sleep
//**********************************************************************************************************************************
unsigned long RTC_IRAM_ATTR ProgramExampleSTUB::wakeupStub(void){
	uint64_t readTemp;

	readTemp = readTemperature();													// Reads the temperature from ACC (in STUB mode)

	DEBUG_RTC(tempPrint, readTemp);													// Writes in console

	if( readTemp >= ProgramExampleSTUB::currentTemperature + ProgramExampleSTUB::temperatureInterval || \
		readTemp <= ProgramExampleSTUB::currentTemperature - ProgramExampleSTUB::temperatureInterval){
		return 0;																	// Wakes up the main processor
	}

	return ProgramExampleSTUB::mySleepingTime;																		// Sleep time in clock ticks
}



//**********************************************************************************************************************************
// Header: ProgramExampleSTUB::setup
// Function: Runs every reset of the ESP32, normally to retrieve/set state variables
//**********************************************************************************************************************************
void ProgramExampleSTUB::setup(){
	char configValue[FLASH_SIZE_MAX + 1] = {0};

	Board::getFlash(FLASH_CONFIGS_PAGE, "program", configValue);					// Gets the chosen program to execute
	if (strlen(configValue) == 0 || strcmp(configValue, getProgramTAG()) == 0) {

		// CUSTOM CODE SECTION

		Board::getFlash(FLASH_CONFIGS_PAGE, getProgramTAG(), configValue, 0);		// Retrieves the program configuration values
																					// (separated in configurations by ',')
		if (strlen(configValue) == 0)
			mySleepingTime = Board::convertSecondsToTicks(DEFAULT_SLEEP_TIME);		// Default value chosen in ticks (BECAUSE STUB requirement)
		else																		// for this program
			mySleepingTime = Board::convertSecondsToTicks(atol(configValue));

		Board::getFlash(FLASH_CONFIGS_PAGE, getProgramTAG(), configValue, 1);
		if (strlen(configValue) == 0)
			temperatureInterval = DEFAULT_TEMP_INTER;
		else
			temperatureInterval = atol(configValue);

		currentTemperature = -100;													// Sets the default temperature

		executable = true;
	} else {																		// According IF condition above:
		executable = false;															// Runs if no program was registered or this program
	}																				// is in the "param" program field
}

//**********************************************************************************************************************************
// Header: ProgramExampleSTUB::loop
// Function: Program entry point
//**********************************************************************************************************************************
bool ProgramExampleSTUB::loop() {
	int readTemp;

	LIS3DE::init(0);
	readTemp = LIS3DE::getTemperature(0);

	nextWakeUpTime = getUptime() + Board::convertTicksToSeconds(mySleepingTime);// PROGRAM SLEEPING TIME - in this case is passed
																					// and dynamically changed in program config

	if(readTemp >= ProgramExampleSTUB::currentTemperature + ProgramExampleSTUB::temperatureInterval || \
			readTemp <= ProgramExampleSTUB::currentTemperature - ProgramExampleSTUB::temperatureInterval){

		// CUSTOM CODE SECTION

		consoleDebug("%s:\t\t\t Hello... Waked up from a temperature variation!", MY_STUB_PROGRAM_TAG);

		consoleDebug("%s:\t\t\t My current temperature is %d ºC", MY_STUB_PROGRAM_TAG, readTemp);

		// CODE here....

		currentTemperature = readTemp;												// Sets the read current temperature used in the next STUB iterations
		return true;
	}
	return false;																	// Is MANDATORY to program loader knows if
}																					// the program was executed

//**********************************************************************************************************************************
// Header: ProgramExampleSTUB::isExecutable
// Function: Returns if program is able to execute
//**********************************************************************************************************************************
bool ProgramExampleSTUB::isExecutable() {
	return executable;
}

//**********************************************************************************************************************************
// Header: ProgramExampleSTUB::setNextTime
// Function: Sets the next wakeUp time, used in program loader
//**********************************************************************************************************************************
void ProgramExampleSTUB::setNextTime(unsigned long time) {
	nextWakeUpTime = time;
}

//**********************************************************************************************************************************
// Header: ProgramExampleSTUB::getNextTime
// Function: Retrieves the next wakeUp time, used in program loader
//**********************************************************************************************************************************
unsigned long ProgramExampleSTUB::getNextTime() {
	return nextWakeUpTime;
}

