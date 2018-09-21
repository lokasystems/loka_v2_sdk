/*
 * ApStructs.h
 *
 *  Created on: Apr 5, 2018
 *      Author: esp32
 */

#ifndef COMPONENTS_UTILS_INCLUDE_APSTRUCTS_H_
#define COMPONENTS_UTILS_INCLUDE_APSTRUCTS_H_

//**********************************************************************************************************************************
//                                                      Define Section
//**********************************************************************************************************************************

typedef struct accessPoint{
	signed char rssi;
	unsigned char channel;
	char ssid[33];
	unsigned char mac[6];
}accessPoint;

typedef struct accessPoints{
	int size;
	unsigned char weight;
	accessPoint **aps;
}accessPoints;

typedef struct friendlyAccessPoint{
	char ssid[33];
	char password[63];
}friendlyAccessPoint;

#endif /* COMPONENTS_UTILS_INCLUDE_APSTRUCTS_H_ */
