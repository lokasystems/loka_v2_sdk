//**********************************************************************************************************************************
// Filename: ProgramExample.cpp
// Date: 09.05.2018
// Author: Joao Pombas
// Company: LOKA SYSTEMS
// Version: 1.0
// Description:
//**********************************************************************************************************************************


//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************
#include "include/ProgramExample.h"

//**********************************************************************************************************************************
//                                                     External Functions
//**********************************************************************************************************************************


//**********************************************************************************************************************************
//                                                     Global Variables
//**********************************************************************************************************************************

RTC_DATA_ATTR unsigned long ProgramExample::nextWakeUpTime;					  // MANDATORY variables to the normal program behavior
RTC_DATA_ATTR bool ProgramExample::executable;

RTC_DATA_ATTR unsigned long	ProgramExample::mySleepingTime;
RTC_DATA_ATTR unsigned long	myIterationCounter;

//**********************************************************************************************************************************
//                                                        Code Section
//**********************************************************************************************************************************

//**********************************************************************************************************************************
// Header: ProgramExample::setConfig
// Function: Used in Sigfox PROTOCOL to set program configurations over the air
//**********************************************************************************************************************************
void ProgramExample::setConfig(unsigned char header, unsigned char* newConfig){	//				#########  UNUSED YET  #########
//	char str [32];
//	Board::setFlash(FLASH_CONFIGS_PAGE, "program", getProgramTAG());
//	Board::setFlash(FLASH_CONFIGS_PAGE, getProgramTAG(), str);

// Parse newConfig and sets in flash the new program configuration
}


//**********************************************************************************************************************************
// Header: ProgramExample::getConfig
// Function: Used in Sigfox PROTOCOL to get program configurations, returned in configBuffer
//**********************************************************************************************************************************
void ProgramExample::getConfig(char * configBuffer){								//				#########  UNUSED YET  #########
//	char configValue[FLASH_SIZE_MAX + 1] = {0};
//	Board::getFlash(FLASH_CONFIGS_PAGE, getProgramTAG(), configValue, 0);

// Parse custom configuration values, and build configBuffer
}																   // the program configurations over SIGFOX


//**********************************************************************************************************************************
// Header: ProgramExample::getProgramTAG
// Function: Retrieves the program TAG
//**********************************************************************************************************************************
char* ProgramExample::getProgramTAG(){
	return MY_PROGRAM_TAG;													// Used in Get/Set Flash methods to identify the program
}																			// when save the custom program configurations


//**********************************************************************************************************************************
// Header: ProgramExample::wakeupStub
// Function: Runs every time the ESP32 wakes-up, checks conditions, may set the processor back to sleep
//**********************************************************************************************************************************
unsigned long RTC_IRAM_ATTR ProgramExample::wakeupStub(void){
	return NULL;														// NULL: ignored	0: Wakes up the main processor,
}																		// other values: (Sleep time in clock ticks)


//**********************************************************************************************************************************
// Header: ProgramExample::setup
// Function: Runs every reset of the ESP32, normally to retrieve/set state variables
//**********************************************************************************************************************************
void ProgramExample::setup(){
	char configValue[FLASH_SIZE_MAX + 1] = {0};

	Board::getFlash(FLASH_CONFIGS_PAGE, "program", configValue);					// Gets the chosen program to execute
	if (strlen(configValue) == 0 || strcmp(configValue, getProgramTAG()) == 0) {
		Board::getFlash(FLASH_CONFIGS_PAGE, getProgramTAG(), configValue, 0);		// Retrieves the program configuration values
																					// (separated in configurations by ',')
		// CUSTOM CODE SECTION

		if (strlen(configValue) == 0)
			mySleepingTime = DEFAULT_SLEEP_TIME;									// Default value chosen (in seconds) for this program
		else
			mySleepingTime = atol(configValue);

//
//		Board::pinMode(GPIO2, OUTPUT);												// Define GPIO2 as output to use later
//		Board::digitalWrite(GPIO2, LOW);
//
//		Board::pinMode(GPIO36, INPUT);												// Define GPIO36 as input to use later
//
		Board::pinMode(ACC_INT, INPUT);

		executable = true;
	} else {																		// According IF condition above:
		executable = false;															// Runs if no program was registered or this program
	}																				// is in the "param" program field
}

//**********************************************************************************************************************************
// Header: ProgramExample::loop
// Function: Program entry point
//**********************************************************************************************************************************
bool ProgramExample::loop() {

	if(getUptime() >= nextWakeUpTime) {
		nextWakeUpTime += mySleepingTime; 											// PROGRAM SLEEPING TIME - in this case is passed
																					// and dynamically changed in program config
		// CUSTOM CODE SECTION

		myIterationCounter++;
		consoleDebug("%s:\t\t Hello, it's my [%ld] run iteration.", MY_PROGRAM_TAG, myIterationCounter);

//		//**************************************************************************************************************************
//		// Gets Device ID, MAC and PAC
//		//**************************************************************************************************************************
//		extern unsigned long int boardID;											// RTC_DATA_ATTR
//		extern char boardMACString[18];												// RTC_DATA_ATTR
//		extern char boardPACString[17];												// RTC_DATA_ATTR
//
//		Board::getID();
//		Board::getMAC();
//		Board::getPAC();
//
//		consoleDebug("%s:\t\t DeviceID: %ld \t\t MAC: %s \t\t PAC: %s", MY_PROGRAM_TAG, boardID, boardMACString, boardPACString);
//		//	OR
//		consoleDebug("%s:\t\t DeviceID: %ld \t\t MAC: %s \t\t PAC: %s", MY_PROGRAM_TAG, Board::getID(), Board::getMAC(), Board::getPAC());
//
//
//		//**************************************************************************************************************************
//		// Blinks the built-in LED 5 times (600ms HIGH, 300ms LOW)
//		//**************************************************************************************************************************
//		consoleDebug("%s:\t\t Blinking LED for 5 times", MY_PROGRAM_TAG);
//		Board::blinkLED(5, 600, 300, 0, 0);
//
//
//		//**************************************************************************************************************************
//		// Sets GPIO2 ON for 2 seconds
//		//**************************************************************************************************************************
//		consoleDebug("%s:\t\t Turning ON GPIO2 for 2 seconds", MY_PROGRAM_TAG);
//		Board::digitalWrite(GPIO2, HIGH);
//		delay_s(2);																	// OR  you could call delay_ms(2000);
//		Board::digitalWrite(GPIO2, LOW);
//
//
//		//**************************************************************************************************************************
//		// Reads the GPIO4 digital value
//		//**************************************************************************************************************************
//		bool GPIO_State = Board::digitalRead(GPIO36);
//		consoleDebug("%s:\t\t GPIO36 value...\t\t Digital: %d [0-1]", MY_PROGRAM_TAG, GPIO_State);
//
//
//		//**************************************************************************************************************************
//		// Turns on the BLuetooth module, sends the string "Hello" and waits for characters
//		//**************************************************************************************************************************
//		Bluetooth::init(Board::getID());
//
//		//With callbacks ->  Bluetooth::startSPP(void (*openCallback)(void), void (*dataCallback)(char*), void (*closeCallback)(void));			OR
//		Bluetooth::startSPP((void(*)())NULL, (void(*)(char*))NULL, (void(*)())NULL);
//
//		for(int i = 0; i < 120; i++){												// waits 120 seconds for any client connection
//			if(Bluetooth::isConnected()){
//
//				consoleDebug("%s:\t\t Connected, sending data...", MY_PROGRAM_TAG);
//				Bluetooth::write("Hello", strlen("Hello"));
//
//				for(int j = 0; j < 30; j++){										// waits 30 seconds for the incoming messages
//					if(Bluetooth::available() > 0){
//
//						consoleDebug("%s:\t\t Reading %d bytes...", MY_PROGRAM_TAG, Bluetooth::available());
//
//						while(Bluetooth::available() > 0) {
//							consoleDebug("%s:\t\t %c", MY_PROGRAM_TAG, (char)Bluetooth::read());
//						}
//					}
//					delay_s(1);
//				}
//				break;
//			}
//			delay_s(1);
//		}
//
//
//		//**************************************************************************************************************************
//		// Gets the device up time and the current time
//		//**************************************************************************************************************************
//		uint64_t upTime, currentTime;
//		upTime = getUptime();
//		currentTime = getTime();
//		consoleDebug("%s:\t\t Up time: %ld \t\t Current time: %ld", MY_PROGRAM_TAG, upTime, currentTime);
//
//
//		//**************************************************************************************************************************
//		// Writes, appends and reads data from a file stored in the Flash
//		//**************************************************************************************************************************
//		char* fileName = "exampleFile";
//		char* dataToWrite = "Data to write in the example file\n";
//		char* dataReadFromFile;
//
//		SPIFFS::writeFile(fileName, dataToWrite, strlen(dataToWrite), false);		// Create or re-write the file with the new data
//
//		// To append data int the file, should call this method with "append" parameter TRUE
//		SPIFFS::writeFile(fileName, dataToWrite, strlen(dataToWrite), true);		// Open the  file and append the new data
//
//		dataReadFromFile = (char*) malloc(100);
//		SPIFFS::readFile(fileName, dataReadFromFile, 100, 0);										// Parameters: fileName, pointer to the read buffer,
//		consoleDebug("%s:\t\t Data read from file: \n%s", MY_PROGRAM_TAG, dataReadFromFile);		// buffer size and read (file) offset
//		free(dataReadFromFile);
//
//		SPIFFS::removeFile(fileName);												// Remove the file
//
//
//		//**************************************************************************************************************************
//		// Turns on the WiFi module, try to connect to the chosen AP and turns off the WiFi module
//		//**************************************************************************************************************************
//		bool result;
//		consoleDebug("%s:\t\t Connecting to: TEST_SSID", MY_PROGRAM_TAG);
//		WiFi::turnOn();
//		result = WiFi::connectAP("TEST_SSID", "MY_APSSWORD");
//		WiFi::turnOff();
//		consoleDebug("%s:\t\t Connection attempt result: %s", MY_PROGRAM_TAG, (result ? "SUCCESS" : "FAILED"));
//
//
//		//**************************************************************************************************************************
//		// Initializes the accelerometer and gets the temperature
//		//**************************************************************************************************************************
//		int temperature;
//		LIS3DE::init(1);																			// Initializes the accelerometer
//		temperature = LIS3DE::getTemperature(0);
//		LIS3DE::close();																			// Free the accelerometer driver
//		consoleDebug("%s:\t\t Read temperature:  %d ºC", MY_PROGRAM_TAG, temperature);
//
//
//		//**************************************************************************************************************************
//		// Turns on the Sigfox module, sends a analog and custom messages and finally turns off the Sigfox module
//		//**************************************************************************************************************************
//		SigfoxProtocol::turnOnRadio();												// Turns on the Radio (Sigfox) module
//		SigfoxProtocol::sendAnalogValue(GPIO36, (double)123);						// Sends to the server a analog value
//		SigfoxProtocol::sendMessage((unsigned char*)"Hello", strlen("Hello"));		// Send a custom message, size should be less than 12 bytes
//		SigfoxProtocol::turnOffRadio();												// Turns off the Radio module
//
//
//		//**************************************************************************************************************************
//		// Executes a network update (over WiFi)
//		//**************************************************************************************************************************
//		bool result;
//		WiFi::turnOn();
//		if(WiFi::connectAP("loka", "lokalokaloka")) {
//			consoleDebug("%s:\t\t Connected to the AP, trying to get the new image...", MY_PROGRAM_TAG);
//			HTTP::networkUpdate(NULL);												// Gets a image from the DM default endpoint
//		}																			// Parameter could be replaced by other endpoint with a custom image
//		WiFi::turnOff();

		return true;
	}
	return false;																// Is MANDATORY to program loader knows if
}																				// the program was executed

//**********************************************************************************************************************************
// Header: ProgramExample::isExecutable
// Function: Returns if program is able to execute
//**********************************************************************************************************************************
bool ProgramExample::isExecutable() {
	return executable;
}

//**********************************************************************************************************************************
// Header: ProgramExample::setNextTime
// Function: Sets the next wakeUp time, used in program loader
//**********************************************************************************************************************************
void ProgramExample::setNextTime(unsigned long time) {
	nextWakeUpTime = time;
}

//**********************************************************************************************************************************
// Header: ProgramExample::getNextTime
// Function: Retrieves the next wakeUp time, used in program loader
//**********************************************************************************************************************************
unsigned long ProgramExample::getNextTime() {
	return nextWakeUpTime;
}

