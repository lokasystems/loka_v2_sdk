//**********************************************************************************************************************************
// Filename: ProgramExample.h
// Date: 09.05.2018
// Author: Joao Pombas
// Company: LOKA SYSTEMS
// Version: 1.0
// Description:
//**********************************************************************************************************************************
#ifndef PROGRAM_EXAMPLE_ULP_H_
#define PROGRAM_EXAMPLE_ULP_H_


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

#define MY_ULP_PROGRAM_TAG		"ulpExample"

//**********************************************************************************************************************************
//                                                     Templates Section
//**********************************************************************************************************************************
class ProgramExampleULP : public Program{

	public:																	// MANDATORY METHODS to the normal program behavior
		void setup ();
		bool loop ();
        unsigned long getNextTime();
        void setNextTime(unsigned long time);
        void setConfig(unsigned char header, unsigned char* newConfig);
        void getConfig(char * configBuffer);
        char* getProgramTAG();
        bool isExecutable();
        unsigned long wakeupStub(void);

	private:
        static unsigned long nextWakeUpTime;								// MANDATORY variables to the normal program behavior
        static bool executable;
        static bool initiated;
        static void configureACC();
};

#endif
