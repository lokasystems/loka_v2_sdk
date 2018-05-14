//**********************************************************************************************************************************
// Filename: ProgramTemplate.cpp
// Date: 09.05.2018
// Author: Joao Pombas
// Company: LOKA SYSTEMS
// Version: 1.0
// Description:
//**********************************************************************************************************************************


//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************
#include "include/ProgramTemplate.h"

//**********************************************************************************************************************************
//                                                     External Functions
//**********************************************************************************************************************************


//**********************************************************************************************************************************
//                                                     Global Variables
//**********************************************************************************************************************************

RTC_DATA_ATTR unsigned long ProgramTemplate::nextWakeUpTime;					  // MANDATORY variables to the normal program behavior
RTC_DATA_ATTR bool ProgramTemplate::executable;

//**********************************************************************************************************************************
//                                                        Code Section
//**********************************************************************************************************************************

//**********************************************************************************************************************************
// Header: ProgramTemplate::setConfig
// Function: Used in Sigfox PROTOCOL to set program configurations over the air
//**********************************************************************************************************************************
void ProgramTemplate::setConfig(unsigned char * newConfig){						   //				#########  UNUSED YET  #########
//	char str [32];
//	Board::setFlash(FLASH_CONFIGS_PAGE, "program", getProgramTAG());
//	Board::setFlash(FLASH_CONFIGS_PAGE, getProgramTAG(), str);

// Parse newConfig and sets in flash the new program configuration
}


//**********************************************************************************************************************************
// Header: ProgramTemplate::getConfig
// Function: Used in Sigfox PROTOCOL to get program configurations, returned in configBuffer
//**********************************************************************************************************************************
void ProgramTemplate::getConfig(char * configBuffer){								//				#########  UNUSED YET  #########
//	char configValue[FLASH_SIZE_MAX + 1] = {0};
//	Board::getFlash(FLASH_CONFIGS_PAGE, getProgramTAG(), configValue, 0);

// Parse custom configuration values, and build configBuffer
}


//**********************************************************************************************************************************
// Header: ProgramTemplate::getProgramID
// Function: Retrieves the program ID
//**********************************************************************************************************************************
unsigned char ProgramTemplate::getProgramID(){									   //				#########  UNUSED YET  #########
	return 255;																	   // Default, used to identify program to set/get
}																				   // the program configurations over SIGFOX


//**********************************************************************************************************************************
// Header: ProgramTemplate::getProgramTAG
// Function: Retrieves the program TAG
//**********************************************************************************************************************************
char* ProgramTemplate::getProgramTAG(){
	return "example";														// Used in Get/Set Flash methods to identify the program
}																			// when save the custom program configurations


//**********************************************************************************************************************************
// Header: ProgramTemplate::setup
// Function: Runs every reset of the ESP32, normally to retrieve/set state variables
//**********************************************************************************************************************************
void ProgramTemplate::setup(){
//	char configValue[FLASH_SIZE_MAX + 1] = {0};
//
//	Board::getFlash(FLASH_CONFIGS_PAGE, "program", configValue);					// Gets the chosen program to execute
//	if (strlen(configValue) == 0 || strcmp(configValue, getProgramTAG()) == 0)
//		Board::getFlash(FLASH_CONFIGS_PAGE, getProgramTAG(), configValue, 0);		// Retrieves the program configuration values

// Parse custom configuration values

// CUSTOM CODE SECTION

	executable = true;																// This variable is used to decide if the program
}																					// is in conditions to run (in loop call)

//**********************************************************************************************************************************
// Header: ProgramTemplate::loop
// Function: Program entry point
//**********************************************************************************************************************************
bool ProgramTemplate::loop() {

	if(executable) {
		nextWakeUpTime += 30; // PROGRAM SLEEPING TIME;

		// CUSTOM CODE SECTION

	}
	return executable;																// Is MANDATORY to program loader knows if
}																					// the program was executed

//**********************************************************************************************************************************
// Header: ProgramTemplate::setNextTime
// Function: Sets the next wakeUp time, used in program loader
//**********************************************************************************************************************************
void ProgramTemplate::setNextTime(unsigned long time) {
	nextWakeUpTime = time;
}

//**********************************************************************************************************************************
// Header: ProgramTemplate::getNextTime
// Function: Retrieves the next wakeUp time, used in program loader
//**********************************************************************************************************************************
unsigned long ProgramTemplate::getNextTime() {
	return nextWakeUpTime;
}

