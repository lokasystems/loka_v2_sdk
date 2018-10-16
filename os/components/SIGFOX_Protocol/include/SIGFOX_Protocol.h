//**********************************************************************************************************************************
// Filename: SIGFOX_Protocol.h
// Date: 18.10.2017
// Author: Rafael Pires
// Company: LOKA SYSTEMS
// Version: 1.0
// Description: Handles data transmission over SIGFOX
//**********************************************************************************************************************************
#ifndef SIGFOX_PROTOCOL_H_
#define SIGFOX_PROTOCOL_H_


//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************


//**********************************************************************************************************************************
//                                                      Define Section
//**********************************************************************************************************************************


//**********************************************************************************************************************************
//                                                     Templates Section
//**********************************************************************************************************************************
class SigfoxProtocol{
	public:
		static void turnOnRadio();
		static void turnOffRadio();
		static int sendGPIOValue(int gpio, char value, char sendAsDownlink = false);
		static int sendAnalogValue(int port, double value, char sendAsDownlink = false);
		static int sendAnalogValue(int port, double value, int port2, double value2, char sendAsDownlink = false);
		static int sendGPSPosition(double latitude, double longitude, double speed, double timestamp, char sendAsDownlink = false);
		static int sendTextLog(char log, char sendAsDownlink = false);
		static int sendRawMessage(unsigned char* message, int size, char sendAsDownlink = false, unsigned char* response = NULL);
		static int sendAck();
};

#endif
