//**********************************************************************************************************************************
// Filename: main.cpp
// Date: 18.10.2017
// Author: Rafael Pires
// Company: LOKA SYSTEMS
// Version: 1.0
// Description: Code for the LOKA firmware entry point and program scheduler
//**********************************************************************************************************************************


//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************

#include "AppMain.h"
#include "programs.h"

//**********************************************************************************************************************************
//                                                        Code Section
//**********************************************************************************************************************************

extern bool excludeSigfoxProgram;

//**********************************************************************************************************************************
// Header: app_main
// Function: LOKA firmware entry point
//**********************************************************************************************************************************
extern "C" void app_main (void){

	excludeSigfoxProgram = true;													// Exclude Program Sigfox execution

	appMain();
}

