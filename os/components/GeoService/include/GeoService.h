//**********************************************************************************************************************************
// Filename: GeoService.h
// Date: 18.01.2018
// Author: João Pombas
// Company: LOKA SYSTEMS
// Version: 1.0
// Description: GeoService component
//**********************************************************************************************************************************
#ifndef GEO_SERVICE_H_
#define GEO_SERVICE_H_

//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************

#include "../../APIs/include/GeoAPI.h"

//**********************************************************************************************************************************
//                                                      Define Section
//**********************************************************************************************************************************

//**********************************************************************************************************************************
//                                                     Templates Section
//**********************************************************************************************************************************
class GeoService {

	public:
		static void init(unsigned char applyRules, char* rulesFilename, unsigned char fenceEnabled, char* fenceAPFilename, char* postponedReportFilename);
		static void reset();
		static bool run(unsigned long timestamp, unsigned char postponedReport);
		static size_t getDataSize();
};

#endif
