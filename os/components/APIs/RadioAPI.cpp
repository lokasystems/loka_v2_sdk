//**********************************************************************************************************************************
// Filename: RadioAPI.cpp
// Date: 18.09.2018
// Author: João Pombas
// Company: LOKA SYSTEMS
// Version: 1.0
// Description: RadioAPI component
//**********************************************************************************************************************************

//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************

#include "include/RadioAPI.h"

//**********************************************************************************************************************************
//                                                     External Functions
//**********************************************************************************************************************************

//**********************************************************************************************************************************
//                                                      Global Variables
//**********************************************************************************************************************************

//**********************************************************************************************************************************
//                                                        Code Section
//**********************************************************************************************************************************

//**********************************************************************************************************************************
// Header: Radio::turnOn
// Function: Turns the radio module on
//**********************************************************************************************************************************
void Radio::turnOn(){
	SigfoxProtocol::turnOnRadio();
}

//**********************************************************************************************************************************
// Header: Radio::turnOff
// Function: Turns the radio module off
//**********************************************************************************************************************************
void Radio::turnOff(){
	SigfoxProtocol::turnOffRadio();
}


//**********************************************************************************************************************************
// Header: Radio::turnOn
// Function: Sends data through an established technology
//**********************************************************************************************************************************
char Radio::sendMessage(unsigned char* message, int size, char requestAck){
	unsigned char response[12] = {0};								// value not used later, allocated space needed if requestAck = 1

	consoleDebug("GeoAPI:\t\t\t Sending SIGFOX message");
	return SigfoxProtocol::sendRawMessage(message, size, requestAck, response);
}


//**********************************************************************************************************************************
// Header: Radio::sendMessageAndReadResponse
// Function: Sends raw data over an established technology and wait for response
//**********************************************************************************************************************************
int Radio::sendMessageAndReadResponse(unsigned char* message, int size, unsigned char* response, int timeout){
	consoleDebug("GeoAPI:\t\t\t Sending SIGFOX message");			// timeout unused in sendRawMessage as parameter
	return SigfoxProtocol::sendRawMessage(message, size, true, response);
}


//**********************************************************************************************************************************
// Header: Radio::sendAnalogValue
// Function: Sends an analog port value through an established technology
//**********************************************************************************************************************************
char Radio::sendAnalogValue(int port, double value, char requestAck){
	return SigfoxProtocol::sendAnalogValue(port, value, requestAck);
}


//**********************************************************************************************************************************
// Header: Radio::sendAnalogValue
// Function: Sends two analog port value through an established technology
//**********************************************************************************************************************************
char Radio::sendAnalogValue(int port, double value, int port2, double value2, char requestAck){
	return SigfoxProtocol::sendAnalogValue(port, value, port2, value2, requestAck);
}


//**********************************************************************************************************************************
// Header: Radio::sendGPIOValue
// Function: Sends a digital value through an established technology
//**********************************************************************************************************************************
char Radio::sendGPIOValue(int gpio, char value, char requestAck){
	return SigfoxProtocol::sendGPIOValue(gpio, value, requestAck);
}


//**********************************************************************************************************************************
// Header: Radio::sendGPSPosition
// Function: Sends GPS coordinates over an established technology
//**********************************************************************************************************************************
char Radio::sendGPSPosition(double latitude, double longitude, double speed, double timestamp, char requestAck){
	return SigfoxProtocol::sendGPSPosition(latitude, longitude, speed, timestamp, requestAck);
}
