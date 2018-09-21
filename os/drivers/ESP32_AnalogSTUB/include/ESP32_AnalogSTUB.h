//**********************************************************************************************************************************
// Filename: ESP32_AnalogSTUB.h
// Date: 18.07.2018
// Author: Joao Pombas
// Company: LOKA SYSTEMS
// Version: 1.0
// Description: Driver for the ESP32_AnalogSTUB
//**********************************************************************************************************************************
#ifndef ESP32_ANALOG_STUB_H_
#define ESP32_ANALOG_STUB_H_

//**********************************************************************************************************************************
//                                                      Includes Section
//**********************************************************************************************************************************

#include "BOARD_LokaV2.h"
#include "driver/adc.h"

//**********************************************************************************************************************************
//                                                      Define Section
//**********************************************************************************************************************************


//**********************************************************************************************************************************
//                                                     Templates Section
//**********************************************************************************************************************************
class AnalogSTUB{
public:
	static uint32_t getADC1GpioNum(adc_channel_t channel);
	static uint32_t getADC2GpioNum(adc_channel_t channel);
	static void initAnalogPin(adc_unit_t adc_unit, adc_channel_t channel, adc_atten_t atten);
	static void adcConfigWidth(adc_unit_t adc_unit, adc_bits_width_t width_bit);
	static uint32_t adc1ReadValue(adc1_channel_t channel, uint32_t samples);
	static uint32_t adc2ReadValue(adc2_channel_t channel, uint32_t samples);
	static int hallSensorRead();
};


#endif
