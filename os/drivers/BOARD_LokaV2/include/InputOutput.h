//**********************************************************************************************************************************
// Filename: BOARD_LokaV2.cpp
// Date: 18.10.2017
// Author: Rafael Pires
// Company: LOKA SYSTEMS
// Version: 1.0
// Description: Code to operate the LOKA V2 board firmware
//**********************************************************************************************************************************
#ifndef INPUTOUTPUT_H_
#define INPUTOUTPUT_H_


//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************
extern "C" {
	#include "driver/gpio.h"
}

//**********************************************************************************************************************************
//                                                      Defined Section
//**********************************************************************************************************************************


#define BUTTON  						GPIO_NUM_35
#define LED 							GPIO_NUM_0

#define GPIO2 							GPIO_NUM_2
#define GPIO4 							GPIO_NUM_4
#define GPIO13							GPIO_NUM_13
#define GPIO14							GPIO_NUM_14
#define GPIO15 							GPIO_NUM_15
#define GPIO25					 		GPIO_NUM_25
#define GPIO32 							GPIO_NUM_32
#define GPIO33 							GPIO_NUM_33
#define GPIO36 							GPIO_NUM_36
#define GPIO37 							GPIO_NUM_37
#define GPIO38 							GPIO_NUM_38
#define GPIO39 							GPIO_NUM_39

enum pin_mode{
	INPUT,
	OUTPUT,
	INPUT_PULLDOWN,
	INPUT_PULLUP
} ;

enum{
	LOW,
	HIGH
};

typedef gpio_num_t digio;


#endif
