//**********************************************************************************************************************************
// Filename: ProgramExample.h
// Date: 09.05.2018
// Author: Joao Pombas
// Company: LOKA SYSTEMS
// Version: 1.0
// Description:
//**********************************************************************************************************************************
#ifndef PROGRAM_EXAMPLE_H_
#define PROGRAM_EXAMPLE_H_


//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************
#include "../../../components/ProgramLoader/include/Program.h"
#include "BOARD_LokaV2.h"													// Aggregates all driver dependencies

//**********************************************************************************************************************************
//                                                      Global Variables
//**********************************************************************************************************************************


//**********************************************************************************************************************************
//                                                      Define Section
//**********************************************************************************************************************************

#define DEFAULT_SLEEP_TIME		30											// seconds
#define MY_PROGRAM_TAG			"examplePrg"

//**********************************************************************************************************************************
//                                                     Templates Section
//**********************************************************************************************************************************
class ProgramExample : public Program{

	public:																	// MANDATORY METHODS to the normal program behavior
		void setup ();
		bool loop ();
        unsigned long getNextTime();
        void setNextTime(unsigned long time);
        void setConfig(unsigned char * receivedMessage);
        void getConfig(char * configBuffer);
        unsigned char getProgramID();
        char* getProgramTAG();

	private:
        static unsigned long nextWakeUpTime;								// MANDATORY variables to the normal program behavior
        static bool executable;

        static unsigned long mySleepingTime;
};

#endif
