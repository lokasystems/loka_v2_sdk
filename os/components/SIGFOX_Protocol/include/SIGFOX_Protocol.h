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
		static int sendGPIOValue(int gpio, char value);
		static int sendAnalogValue(int port, double value);
		static int sendAnalogValue(int port, double value, int port2, double value2);
		static int sendGPSPosition(double latitude, double longitude, double speed, double timestamp);
		static int sendTextLog(char log);
		static int sendMessage(unsigned char* message, int size);
		static int sendRawDownlinkMessage(unsigned char* message, int size, unsigned char* response); // snedwondlinkmessage
		static int sendAck();
};

#endif
