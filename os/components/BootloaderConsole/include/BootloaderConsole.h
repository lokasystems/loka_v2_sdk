//**********************************************************************************************************************************
// Filename: BootloaderConsole.h
// Date: 18.10.2017
// Author: Rafael Pires, Luis Rosado
// Company: LOKA SYSTEMS
// Version: 1.0
// Description: Implements bootloader console
//**********************************************************************************************************************************
#ifndef BOOTLOADER_CONSOLE_H_
#define BOOTLOADER_CONSOLE_H_


//**********************************************************************************************************************************
//                                                     Templates Section
//**********************************************************************************************************************************
class BootloaderConsole{
	public:
		static void init();
		static unsigned char initBT();
		static void closeBT();
};

#endif
