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
		static char sendGPIOValue(int gpio, char value, char sendAsDownlink = false);
		static char sendAnalogValue(int port, double value, char sendAsDownlink = false);
		static char sendAnalogValue(int port, double value, int port2, double value2, char sendAsDownlink = false);
		static char sendGPSPosition(double latitude, double longitude, double speed, double timestamp, char sendAsDownlink = false);
		static char sendTextLog(char log, char sendAsDownlink = false);
		static char sendMessage(unsigned char* message, int size, char sendAsDownlink = false);
		static int sendRawDownlinkMessage(unsigned char* message, int size, unsigned char* response); // sendDownlinkMessage
		static int sendAck();
};

#endif
