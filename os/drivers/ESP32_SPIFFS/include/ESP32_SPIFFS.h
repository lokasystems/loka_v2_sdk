//**********************************************************************************************************************************
// Filename: ESP32_SPIFFS.h
// Date: 05.02.2018
// Author: João Pombas
// Company: LOKA SYSTEMS
// Version: 1.0
// Description: Driver for the ESP32
//**********************************************************************************************************************************
#ifndef ESP32_SPIFFS_H_
#define ESP32_SPIFFS_H_

//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************


//**********************************************************************************************************************************
//                                                      Define Section
//**********************************************************************************************************************************


//**********************************************************************************************************************************
//                                                     Templates Section
//**********************************************************************************************************************************
class SPIFFS {
public:
	static void printSizeInfo();
	static FILE* getFile(char* fileName, char* openMode);
	static void writeFile(char* fileName, char* content, int size, bool append);
	static int readFile(char* fileName, char* content, int size, int offset);
	static void removeFile(char * fileName);
	static void writeHistory(char* fileName, unsigned long timestamp, int numberOfElements, void* firstElement, int elementSize, bool append);
};

#endif
