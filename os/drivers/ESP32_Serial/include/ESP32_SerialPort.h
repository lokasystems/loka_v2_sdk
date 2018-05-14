//**********************************************************************************************************************************
// Filename: ESP32_SerialPort.h
// Date: 18.10.2017
// Author: Rafael Pires
// Company: LOKA SYSTEMS
// Version: 1.0
// Description: Driver for the ESP32 Real Time Clock
//**********************************************************************************************************************************
#ifndef ESP32_SERIALPORT_H_
#define ESP32_SERIALPORT_H_


//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************

//**********************************************************************************************************************************
//                                                      Defined Section
//**********************************************************************************************************************************
#define DF_BAUDRATE 115200
#define DF_SERIAL_TX_BUFFER_SIZE 256
#define DF_SERIAL_RX_BUFFER_SIZE 256

//**********************************************************************************************************************************
//                                                      Templates Section
//**********************************************************************************************************************************
class SerialPort {
	public:
		SerialPort();
		int init(int id);
		int init(int id, long baudRate);
		int init(int id, long baudRate, unsigned long txBuffer, unsigned long rxBuffer);
		int write(unsigned char *buffer,int size);
		int write(char *buffer,int size);
		int write(uint8_t c);
		int write(char *buffer);
		unsigned char read();
		unsigned char read(int timeout);
		unsigned int read(char * data);
		unsigned int read(char * data, int timeout);
		unsigned int available(void);
		int close();

};


#endif
