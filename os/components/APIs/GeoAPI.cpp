//**********************************************************************************************************************************
// Filename: GeoAPI.cpp
// Date: 01.04.2018
// Author: João Pombas
// Company: LOKA SYSTEMS
// Version: 1.0
// Description: API used by GeoService component
//**********************************************************************************************************************************

//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************
#include "../APIs/include/GeoAPI.h"

//**********************************************************************************************************************************
//                                                     External Functions
//**********************************************************************************************************************************


//**********************************************************************************************************************************
//                                                      Global Variables
//**********************************************************************************************************************************

RTC_DATA_ATTR char GeoAPI::data[MIN_DATA_SIZE];

extern unsigned long int boardID;

//**********************************************************************************************************************************
//                                                        Code Section
//**********************************************************************************************************************************

//**********************************************************************************************************************************
// Header: GeoAPI::getDeviceID
// Function: Retrieves the Device ID
//**********************************************************************************************************************************
unsigned long int GeoAPI::getDeviceID() {

	if(boardID == 0) {
		Board::getID();
	}

	return boardID;
}


//**********************************************************************************************************************************
// Header: GeoAPI::getData
// Function: Retrieves the data pointer to use between iterations
//**********************************************************************************************************************************
char* GeoAPI::getData() {
	return GeoAPI::data;
}


//**********************************************************************************************************************************
// Header: GeoAPI::scan
// Function: Performs a Full scan on all channels
//**********************************************************************************************************************************
void GeoAPI::scan(accessPoints* aps) {

	consoleDebug("GeoAPI:\t\t\t Performing WiFi scan");

#ifdef WIFI_EMULATED
	Emulator::scan(aps);
#else
	WiFi::scan(aps);
#endif
	GeoAPI::history(getTime(), aps, SCAN_HISTORY_FILENAME);
}


//**********************************************************************************************************************************
// Header: GeoAPI::directScan
// Function: Performs a selective scan based on AP SSIDs
//**********************************************************************************************************************************
void GeoAPI::directScan(accessPoints* aps, accessPoints* filterList, char ignoreBssidAndChannel) {

	consoleDebug("GeoAPI:\t\t\t Performing WiFi scan");

#ifdef WIFI_EMULATED
	Emulator::directScan(aps, filterList);
#else
	WiFi::directScan(aps, filterList, ignoreBssidAndChannel);
#endif
	if(SAVE_SHORT_SCAN) {
		GeoAPI::history(getTime(), aps, SCAN_HISTORY_FILENAME);
	}

}


//**********************************************************************************************************************************
// Header: GeoAPI::additionalInfoToSend
// Function: Gets additional info to join with result (size up to 7 bits)
//**********************************************************************************************************************************
char GeoAPI::additionalInfoToSend() {
	int temperature;
	char value[20];

	LIS3DE::init(1);
	temperature = LIS3DE::getTemperature(0);
	LIS3DE::close();

	return (temperature + 0x28);
}


//**********************************************************************************************************************************
// Header: GeoAPI::ReadFile
// Function: Gets the file content based on fileName passed by parameter
//**********************************************************************************************************************************
int GeoAPI::readFile(char* fileName, char* buffer, int sizeToRead, int readOffset) {
	int size;
	size = SPIFFS::readFile(fileName, buffer, sizeToRead, readOffset);
	return size;
}

//**********************************************************************************************************************************
// Header: GeoAPI::deliver
// Function: This method is called with the GeoService result
//**********************************************************************************************************************************
void GeoAPI::deliver(unsigned char* buffer) {
	Radio::turnOn();
	Radio::sendMessage(buffer, 12);
	Radio::turnOff();
}


//**********************************************************************************************************************************
// Header: GeoAPI::postponedReport
// Function: Stores a message in the Flash
//**********************************************************************************************************************************
void GeoAPI::postponedReport(char* fileName, unsigned long timestamp, char* buffer, int sizeToWrite){

	SPIFFS::writeHistory(fileName, timestamp, 1, buffer, sizeToWrite, true);
}


//**********************************************************************************************************************************
// Header: GeoAPI::History
// Function: This method is called to save seen APs
//**********************************************************************************************************************************
void GeoAPI::history(unsigned long timestamp, accessPoints* aps, char* historyFile) {

	// 	TODO: 	Implement usage management

	if (aps->size > 0) {

		consoleDebug("GeoAPI:\t\t\t Saving APs in history file");

		if(!CHECK_VALID_TIMESTAMP(timestamp)) {
			consoleDebug("GeoAPI: \t\t\t Entry with invalid timestamp: %ld", timestamp);
			return;
		}

		int dataSize = (aps->size) * sizeof(accessPoint); // Binary mode  AP SIMPLE
		char* dataToWrite;

		dataToWrite = (char*)malloc(dataSize);			/// join APs in contiguous memory

		for(int i = 0; i < aps->size; i++) {
			memcpy(dataToWrite+(i*sizeof(accessPoint)), aps->aps[i], sizeof(accessPoint));
		}

		SPIFFS::writeHistory(historyFile, timestamp, aps->size, dataToWrite, sizeof(accessPoint), true);
		free(dataToWrite);

		SPIFFS::printSizeInfo();
	}
}
