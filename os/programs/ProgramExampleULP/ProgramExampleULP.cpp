//**********************************************************************************************************************************
// Filename: ProgramExampleULP.cpp
// Date: 09.05.2018
// Author: Joao Pombas
// Company: LOKA SYSTEMS
// Version: 1.0
// Description:
//**********************************************************************************************************************************


//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************
#include "include/ProgramExampleULP.h"

//**********************************************************************************************************************************
//                                                     External Functions
//**********************************************************************************************************************************

extern "C"{
	bool readMovement();
};

//**********************************************************************************************************************************
//                                                     Global Variables
//**********************************************************************************************************************************

RTC_DATA_ATTR unsigned long ProgramExampleULP::nextWakeUpTime;					  // MANDATORY variables to the normal program behavior
RTC_DATA_ATTR bool ProgramExampleULP::executable;
RTC_DATA_ATTR bool ProgramExampleULP::initiated;

//**********************************************************************************************************************************
//                                                        Code Section
//**********************************************************************************************************************************

//**********************************************************************************************************************************
// Header: ProgramExampleULP::setConfig
// Function: Used in Sigfox PROTOCOL to set program configurations over the air
//**********************************************************************************************************************************
void ProgramExampleULP::setConfig(unsigned char header, unsigned char* newConfig){ //				#########  UNUSED YET  #########
//	char str [32];
//	Board::setFlash(FLASH_CONFIGS_PAGE, "program", getProgramTAG());
//	Board::setFlash(FLASH_CONFIGS_PAGE, getProgramTAG(), str);

// Parse newConfig and sets in flash the new program configuration
}


//**********************************************************************************************************************************
// Header: ProgramExampleULP::getConfig
// Function: Used in Sigfox PROTOCOL to get program configurations, returned in configBuffer
//**********************************************************************************************************************************
void ProgramExampleULP::getConfig(char * configBuffer){								//				#########  UNUSED YET  #########
//	char configValue[FLASH_SIZE_MAX + 1] = {0};
//	Board::getFlash(FLASH_CONFIGS_PAGE, getProgramTAG(), configValue, 0);

// Parse custom configuration values, and build configBuffer
}																				   // the program configurations over SIGFOX


//**********************************************************************************************************************************
// Header: ProgramExampleULP::getProgramTAG
// Function: Retrieves the program TAG
//**********************************************************************************************************************************
char* ProgramExampleULP::getProgramTAG(){
	return MY_ULP_PROGRAM_TAG;												// Used in Get/Set Flash methods to identify the program
}																			// when save the custom program configurations


//**********************************************************************************************************************************
// Header: ProgramExampleULP::wakeupStub
// Function: Runs every time the ESP32 wakes-up, checks conditions, may set the processor back to sleep
//**********************************************************************************************************************************
unsigned long RTC_IRAM_ATTR ProgramExampleULP::wakeupStub(void){
	return NULL;														// NULL: ignored	0: Wakes up the main processor,
}																		// other values: (Sleep time in clock ticks)


//**********************************************************************************************************************************
// Header: ProgramExampleULP::setup
// Function: Runs every reset of the ESP32, normally to retrieve/set state variables
//**********************************************************************************************************************************
void ProgramExampleULP::setup(){
	char configValue[FLASH_SIZE_MAX + 1] = {0};

	Board::getFlash(FLASH_CONFIGS_PAGE, "program", configValue);					// Gets the chosen program to execute
	if (strlen(configValue) == 0 || strcmp(configValue, getProgramTAG()) == 0) {
		Board::getFlash(FLASH_CONFIGS_PAGE, getProgramTAG(), configValue, 0);		// Retrieves the program configuration values
																					// (separated in configurations by ',')
		// CUSTOM CODE SECTION

		Board::pinMode(ACC_INT, INPUT);
//		Board::pinMode(GPIO25, INPUT);												// Define GPIO25 as INPUT

		initiated = false;

		executable = true;
	} else {																		// According IF condition above:
		executable = false;															// Runs if no program was registered or this program
	}																				// is in the "param" program field
}

//**********************************************************************************************************************************
// Header: ProgramExampleULP::loop
// Function: Program entry point
//**********************************************************************************************************************************
bool ProgramExampleULP::loop() {
	bool execute = false;

	if(initiated == false) {
		configureACC();
		delay_s(6);																		// Accomodates for the accelerometer low pass
																						// filtering settling time
		readMovement();																	// Read the movement interrupt value
		initiated = true;
	} else {
		execute = readMovement();														// Read the movement interrupt value
	}

//	execute = Board::digitalRead(GPIO25);												// Read the (Interrupt) pin value

	if(execute) {

		consoleDebug("%s:\t\t Hello... Waked up from the movement trigger", MY_ULP_PROGRAM_TAG);

		// CUSTOM CODE SECTION

	}
																				// DEFAULT values: ULP_TIMER_WAKEUP | ULP_BUTTON_WAKEUP
//	Board::enableWakeUp(ULP_INTERRUPT_WAKEUP);									// The board wakes up with HIGH value on GPIO25
	Board::enableWakeUp(ULP_ACCELEROMETER_WAKEUP);								// The board wakes up with movement,

	return false;																// Is MANDATORY to program loader knows if
}																				// the program was executed

//**********************************************************************************************************************************
// Header: ProgramExampleULP::isExecutable
// Function: Returns if program is able to execute
//**********************************************************************************************************************************
bool ProgramExampleULP::isExecutable() {
	return executable;
}

//**********************************************************************************************************************************
// Header: ProgramExampleULP::setNextTime
// Function: Sets the next wakeUp time, used in program loader
//**********************************************************************************************************************************
void ProgramExampleULP::setNextTime(unsigned long time) {
	nextWakeUpTime = time;
}

//**********************************************************************************************************************************
// Header: ProgramExampleULP::getNextTime
// Function: Retrieves the next wakeUp time, used in program loader
//**********************************************************************************************************************************
unsigned long ProgramExampleULP::getNextTime() {
	return nextWakeUpTime;
}

//**********************************************************************************************************************************
// Header: ProgramMovement::configureACC
// Function: Configures the accelerometer with different movement detection threshold
//**********************************************************************************************************************************
void ProgramExampleULP::configureACC(){
	consoleDebug((char*)"%s:\t\t configuring accelerometer", MY_ULP_PROGRAM_TAG);

	while(LIS3DE::init(1) < 0){
		consoleDebug((char*)"%s:\t\t LIS3DE not initiated", MY_ULP_PROGRAM_TAG);
	}
	LIS3DE::setWakeUp(1, 6);		// [3] Threshold
}


