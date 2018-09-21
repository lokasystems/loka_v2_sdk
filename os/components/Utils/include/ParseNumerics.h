//**********************************************************************************************************************************
// Filename: ParseNumerics.h
// Date: 18.10.2017
// Author: Rafael Pires
// Company: LOKA SYSTEMS
// Version: 1.0
// Description: Parses different numeric formats into/from a byte stream
//**********************************************************************************************************************************
#ifndef UTILS_PARSE_NUMERICS_H_
#define UTILS_PARSE_NUMERICS_H_


//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


//**********************************************************************************************************************************
//                                                     Templates Section
//**********************************************************************************************************************************
void insertInt(unsigned char *packet, int32_t value, int position);
int32_t readInt(char *packet, int position);
void insertFloat(unsigned char *packet, float value, int position);
float readFloat(char *packet, int position);
double readDouble(char *packet, int position);
void insertDouble(unsigned char *packet, double value, int position);
uint32_t readValueFromMessage(char* msg, int startPosition, int length);

#endif
