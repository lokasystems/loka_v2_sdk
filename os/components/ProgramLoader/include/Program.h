//**********************************************************************************************************************************
// Filename: Program.h
// Date: 18.10.2017
// Author: Rafael Pires
// Company: LOKA SYSTEMS
// Version: 1.0
// Description: Defines the programs class
//**********************************************************************************************************************************


//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************
#ifndef PROGRAM_H_
#define PROGRAM_H_

//**********************************************************************************************************************************
//                                                      Defines Section
//**********************************************************************************************************************************

//**********************************************************************************************************************************
//                                                        Template Section
//**********************************************************************************************************************************
class Program{
    public:
        virtual void setup() = 0; 							// Runs every reset of the ESP32, normally to retrieve/set state variables
        													// Should not be used to initialize hardware peripherals
        virtual bool loop() = 0;							// Main code of the program
        virtual unsigned long getNextTime();				// Retrieves/sets the time for the next execution
        virtual void setNextTime(unsigned long time);
        virtual void setConfig(unsigned char * newConfig);
        virtual void getConfig(char * configBuffer);
        virtual unsigned char getProgramID();
        virtual char* getProgramTAG();
        virtual bool isExecutable();

};

template<class T> Program* program_factory(){
    return new T;
}

typedef Program* (*program_creator)(void);

class ProgramRegistration{
    public:
        ProgramRegistration(program_creator);
};

#define REGISTER_PROGRAM(program) \
    ProgramRegistration _program_registration_ ## program(&program_factory<program>); \

#endif


