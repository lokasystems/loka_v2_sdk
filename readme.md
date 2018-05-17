Loka SDK
=============

-   [Introduction](#introduction)

-   [Install Prerequisites](#requirements)

-   [Bootloader](#bootloader)

-   [API Documentation](#api-documentation)

    -   [AppMain.h](#appmainh)

    -   [Program.h](#programh)

    -   [BOARD_LokaV2.h](#board_lokav2h)
	   
    -   [SIGFOX_Protocol.h](#sigfox_protocolh)

    -   [BootloaderConsole.h](#bootloaderconsoleh)
	
    -   [ConsoleInterface.h](#consoleinterfaceh)

    -   [ESP32_Bluetooth.h](#esp32_bluetoothh)
	
    -   [ESP32_RTC.h](#esp32_rtch)
	
    -   [ESP32_SerialPort.h](#esp32_serialporth)
	
    -   [ESP32_SPIFFS.h](#esp32_spiffsh)
	
    -   [ESP32_Wifi.h](#esp32_wifih)
	
    -   [LIS3DE_Acceleration.h](#lis3de_accelerationh)
	
    -   [ESP32_HTTP.h](#esp32_httph)

	

Introduction
------------

This repository provides the SDK for the LOKA development board.

The Loka Module System is revolutionary in its ability to be both flexible and scalable. Is composed by a multi-purpose board, a device management and geo location tool. The objective is to be the IoT platform of choice due to low cost, high flexibility and availability.

The multipurpose module, whose main function is a standalone low cost tracker, can be used as a mother board or a daughter board allowing to connect a variety of sensors.
This revolutionary concept, addresses the cost and the Time to Market problem to introduce the many new services that are made possible by low power, low cost Sigfox network.

For more information click [here](http://www.loka.systems).

**Contents:**

- Espressif IoT Development Framework (IDF)

- Include folder (OS) with the *.h files from the SDK

- Include a Program Template and a Program Example with some functionalities ready to run


Requirements
------------

-   Python v2 / v3 with the pySerial package installed (pip install pySerial) (To run the FirmwareProgrammer script)


Install Prerequisites
---------------------

To compile with ESP-IDF you need to get the following packages:

- CentOS 7::

        sudo yum install gcc git wget make ncurses-devel flex bison gperf python pyserial

- Ubuntu and Debian::

        sudo apt-get install gcc git wget make libncurses-dev flex bison gperf python python-serial

- Arch::

        sudo pacman -S --needed gcc git make ncurses flex bison gperf python2-pyserial


Toolchain Setup
---------------

1.  Clone the SDK repository:

        git clone https://github.com/lokasystems/loka_v2_sdk.git

    Go to the SDK folder:

        cd loka_vs_sdk

2.  ESP32 toolchain for Linux is available in folder IDF:

    The toolchain will be into ``~/YOUR_SDK_FOLDER/idf/xtensa-esp32-elf/`` directory.

    To use it, you will need to update your ``PATH`` environment variable in ``~/.profile`` file. To make ``xtensa-esp32-elf`` available for all terminal sessions, add the following line to your ``~/.profile`` file::

        sudo nano ~/.profile

        PATH="$HOME/bin:$HOME/.local/bin:$PATH"
        PATH="$PATH:$HOME/YOUR_SDK_FOLDER/idf/xtensa-esp32-elf/bin"
        PATH="$PATH:$HOME/YOUR_SDK_FOLDER/idf/esp32ulp-elf-binutils/bin"

3.  Log off and log in back to make the ``.profile`` changes effective. Run the following command to verify if ``PATH`` is correctly set::

        printenv PATH

    You are looking for similar result containing toolchain's path at the end of displayed string::

        $ printenv PATH
        /home/user-name/bin:/home/user-name/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/user-name/YOUR_SDK_FOLDER/idf/xtensa-esp32-elf/bin

    Instead of ``/home/user-name`` there should be a home path specific to your installation.

4.  Set the ``IDF_PATH`` environment variable in ``~/.bashrc`` file::

        sudo nano ~/.bashrc

        export IDF_PATH="$HOME/YOUR_SDK_FOLDER/idf"


Running the Example Program
---------------------------

Go to the OS folder and build:

        cd os/
        make

Upload to the board and see the execution result:

        make flash monitor
        
Permission issues /dev/ttyUSB0
------------------------------

With some Linux distributions you may get the ``Failed to open port /dev/ttyUSB0`` error message when flashing the ESP32. [This can be solved by adding the current user to the dialout group](http://esp-idf.readthedocs.io/en/latest/get-started/establish-serial-connection.html#linux-dialout-group)

Bootloader
----------

The LOKA board provides a bootloader shell to facilitate the firmware upload and the paramater configuration.

To access the bootloader, please follow the next steps.

-   Power off the Board

-   Connect the board serial port using a baudrate of 115200

-   Power on the board and press Ctrl+C right after it.


The Bootloader shell avalilable commands:


-   help

-   reset

-   param list

-   param get \<param\_name\>

-   param set \<param\_name\> \<param\_value\>

-   param unset \<param\_name\> \<param\_value\>

-   param clean

-   console update

-   network update \<url\>

-   sn



NOTE: Before use the network update \<url\> command, make sure that te wifi configuration is already correctly set.


API Documentation
-----------------

State Enum:

- HIGH
- LOW

Mode Enum:

- INPUT
- OUTPUT
- INPUT_PULLUP

NOTE: By Default in the CPU internal resistor is set to PULLUP. Otherwise "digitalWrite(HIGH)" must be called to change it to PULLDOWN.

#### AppMain.h

| **Method**    | **Description**                                      | **Syntax**                      | **Parameters**                                                                                                                    | **Return** |
|---------------|------------------------------------------------------|---------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|------------|
| appMain 	 | LOKA firmware entry point | appMain(); | None       		| None   	  |


#### Program.h

| **Method**    | **Description**                                      | **Syntax**                      | **Parameters**                                                                                                                    | **Return** |
|---------------|------------------------------------------------------|---------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|------------|
| setup         | Runs every reset of the ESP32,   normally to retrieve/set state variables         | PROGRAM_NAME::setup();                              | None                                                        | None                                            |
| loop          | Program entry point                                                               | PROGRAM_NAME::loop();                               | None                                                        | True: If program was executed. False: Otherwise |
| getNextTime   | Retrieves the next wakeUp time, used in program loader                            | PROGRAM_NAME::getNextTime();                        | None                                                        | New program wakeup time in seconds              |
| setNextTime   | Sets the next wakeUp time, used in program loader                                 | PROGRAM_NAME::setNextTime(unsigned long time) ;     | time: Next program wakeup time in seconds                   | None                                            |
| setConfig     | Used in Sigfox PROTOCOL to set program configurations over the   air              | PROGRAM_NAME::setConfig(unsigned char * newConfig); | newConfig: New program configuration to set in flash        | None                                            |
| getConfig     | Used in Sigfox PROTOCOL to get program configurations,   returned in configBuffer | PROGRAM_NAME::getConfig(char * configBuffer);       | configBuffer: The program configuration read from the flash | None                                            |
| getProgramID  | Retrieves the program ID                                                          | PROGRAM_NAME::getProgramID();                       | None                                                        | Program ID                                      |
| getProgramTAG | Retrieves the program TAG                                                         | PROGRAM_NAME::getProgramTAG();                      | None                                                        | Program TAG                                     |


#### BOARD_LokaV2.h

| **Method**    | **Description**                                      | **Syntax**                      | **Parameters**                                                                                                                    | **Return** |
|---------------|------------------------------------------------------|---------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|------------|
| getMAC        | Retrieves the board MAC address                | Board::getMAC();                                                                                                                      | None                                                                                                                                                                                                                                                                  | Board MAC address                |
| getID         | Retrieves the Sigfox id                        | Board::getID();                                                                                                                       | None                                                                                                                                                                                                                                                                  | Board identification number      |
| getPAC        | Retrieves the Sigfox pac                       | Board::getPAC();                                                                                                                      | None                                                                                                                                                                                                                                                                  | Board porting authorization code |
| pinMode       | Configures a GPIO pin                          | Board::pinMode(digio gpio, pin_mode mode);                                                                                            | gpio: GPIO pin. mode: Desired operation mode                                                                                                                                                                                                                          | None                             |
| digitalWrite  | Writes a digital value in the desired GPIO pin | Board::digitalWrite(digio gpio, uint8_t value);                                                                                       | gpio: GPIO pin. value Desired value to wirte in the pin                                                                                                                                                                                                               | None                             |
| digitalRead   | Reads the digital value from a GPIO pin        | Board::digitalRead(digio gpio);                                                                                                       | gpio: GPIO pin                                                                                                                                                                                                                                                        | Value read from the desired pin  |
| blinkLED      | Blinks the built-in LED in a given pattern     | Board::blinkLED(unsigned int blinks, unsigned int time_on1,   unsigned int time_off1, unsigned int time_on2, unsigned int time_off2); | blinks: Number of (blink) cycles. time_on1: Led time on (first   part of each cycle). time_off1: Led time off (first part of each cycle).   time_on2: Led time on (second part of each cycle). time_off2: Led time off   (second part of each cycle), in milliseconds | None                             |
| setFlash      | Sets a flash word in flash                     | Board::setFlash(const char* page, const char* name, const   char* value);                                                             | page: Flash page name. param_s: Param name. value: Value to   save in flash                                                                                                                                                                                           | None                             |
| getFlash      | Gets a flash word from the flash               | Board::getFlash(const char* page, const char* name, char*   value);                                                                   | page: Flash page name. param_s: Param name. value: Buffer to   save param value                                                                                                                                                                                       | None                             |
| getFlash      | Gets a flash word value from the flash         | Board::getFlash(const char* page, const char* param_s, char*   value, int index);                                                     | page: Flash page name. param_s: Param name. value: Buffer to   save param value. index: Index position of desired value                                                                                                                                               | None                             |
| enableWakeUp  | Enables a certain ULP wakeup mechanism         | Board::enableWakeUp(unsigned int mask);                                                                                               | mask: Enables a certain wakeup mode (Timer, Button, Acc or Pin   interrupt)                                                                                                                                                                                           | None                             |
| disableWakeUp | Disables a certain ULP wakeup mechanism        | Board::disableWakeUp(unsigned int mask);                                                                                              | mask: Enables a certain wakeup mode (Timer, Button, Acc or Pin   interrupt)                                                                                                                                                                                           | None                             |
| setWakeUp     | Sets a certain ULP wakeup mechanism            | Board::setWakeUp(unsigned int mask);                                                                                                  | mask: Enables a certain wakeup mode (Timer, Button, Acc or Pin   interrupt)                                                                                                                                                                                           | None                             |
| resetWakeUp   | Sets the RTC timer next wake-up                | Board::resetWakeUp();                                                                                                                 | None                                                                                                                                                                                                                                                                  | None                             |
| setWakeStub   | Sets the wakeup stub    method pointer         | Board::setWakeStub(void (*wakeStub)());                                                                                               | wakeStub: Pointer to the method executed in wakeup                                                                                                                                                                                                                    | None                             |
| setWakeUpTime | Sets the RTC timer next wake-up                | Board::setWakeUpTime(unsigned int seconds);                                                                                           | second: Number of seconds to sleep                                                                                                                                                                                                                                    | None                             |

#### SIGFOX_Protocol.h

| **Method**    | **Description**                                      | **Syntax**                      | **Parameters**                                                                                                                    | **Return** |
|---------------|------------------------------------------------------|---------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|------------|
| turnOnRadio            | Turns the SIGFOX radio on                            | SigfoxProtocol::turnOnRadio();                                                                        |                                                             None                                                             |         None |
| turnOffRadio           | Turns the SIGFOX radio off                           | SigfoxProtocol::turnOffRadio();                                                                       | None                                                                                                                         | None         |
| sendGPIOValue          | Sends a digital value through SIGFOX                 | SigfoxProtocol::sendGPIOValue(int gpio, char value);                                                  | gpio: GPIO pin. value: Value to send over Sigfox                                                                             | Message size |
| sendAnalogValue        | Sends an analog port value through SIGFOX            | SigfoxProtocol::sendAnalogValue(int port, double value);                                              | port: Device port.    value: Value to send over Sigfox                                                                       | Message size |
| sendAnalogValue        | Sends two analog port value through SIGFOX           | SigfoxProtocol::sendAnalogValue(int port, double value, int   port2, double value2);                  | port: Device port.    value: First value to send over Sigfox. port2: Device port.  value2: Second value to send over Sigfox. | Message size |
| sendGPSPosition        | Sends GPS coordinates over SIGFOX                    | SigfoxProtocol::sendGPSPosition(double latitude, double   longitude, double speed, double timestamp); | latitude: Latitude coordinate. longitude: Longitude   coordinate. speed: Speed to send. timestamp: Temporal reference        | Message size |
| sendTextLog            | Sends a text log through SIGFOX                      | SigfoxProtocol::sendTextLog(char log);                                                                | log: Value to send                                                                                                           | Message size |
| sendMessage            | Sends raw data over SIGFOX                           | SigfoxProtocol::sendMessage(unsigned char* message, int size);                                        | message: Message's payload. size: Payload's size                                                                             | Message size |
| sendRawDownlinkMessage | Sends raw data over SIGFOX and ask for downlink      | SigfoxProtocol::sendRawDownlinkMessage(unsigned char* message,   int size, unsigned char* response);  | message: Message's payload. size: Payload's size. response:   Downlink response                                              | Message size |
| sendAck                | Sends an acknowledge message after a SIGFOX downlink | SigfoxProtocol::sendAck();                                                                            | None                                                                                                                         | Message size |


#### BootloaderConsole.h

| **Method**    | **Description**                                      | **Syntax**                      | **Parameters**                                                                                                                    | **Return** |
|---------------|------------------------------------------------------|---------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|------------|
| init    	  | Initializes the Bootloader console                | BootloaderConsole::init();    | None       	   | None   	|
| initBT   	  | Initializes the Bootloader console over Bluetooth | BootloaderConsole::initBT();  | None       	   | None   	|
| closeBT 	  | Closes the Bootloader console over Bluetooth      | BootloaderConsole::closeBT(); | None           | None   	|


#### ConsoleInterface.h

| **Method**    | **Description**                                      | **Syntax**                      | **Parameters**                                                                                                                    | **Return** |
|---------------|------------------------------------------------------|---------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|------------|
| consoleDebug | Outputs a debug message | consoleDebug(char* format, ...); | format: Message to write in console | None   	   |


#### ESP32_Bluetooth.h

| **Method**    | **Description**                                      | **Syntax**                      | **Parameters**                                                                                                                    | **Return** |
|---------------|------------------------------------------------------|---------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|------------|
| init        | Initialize the Bluetooth module              | Bluetooth::init(unsigned long int boardNumber);                                                              | boardNumber: Board name shown to the others devices                                                                                                                                                | None                                                  |
| disable     | Disables the Bluetooth module                | Bluetooth::disable();                                                                                        | None                                                                                                                                                                                               | None                                                  |
| startSPP    | Starts the Serial Port Profile (SPP)         | Bluetooth::startSPP(void (*openCallback)(void), void   (*dataCallback)(char*), void (*closeCallback)(void)); | openCallback: Method called when occurs a pairing event.   dataCallback: Method called when module receives data from the paired device.   closeCallback: Method called when the connection closes | None                                                  |
| isConnected | Returns the bluetooth connection state       | Bluetooth::isConnected()                                                                                     | None                                                                                                                                                                                               | True: If paired with another device. False: otherwise |
| write       | Send a message over bluetooth (SPP)          | Bluetooth::write(char*   str, int size);                                                                     | None                                                                                                                                                                                               | None                                                  |
| available   | Returns the number of available characters   | Bluetooth::available();                                                                                      | None                                                                                                                                                                                               | Number of available bytes to read                     |
| read        | Reads an input from the bluetooth connection | Bluetooth::read();                                                                                           | None                                                                                                                                                                                               | A value (byte) read from the bluetooth connection     |


#### ESP32_RTC.h

| **Method**    | **Description**                                      | **Syntax**                      | **Parameters**                                                                                                                    | **Return** |
|---------------|------------------------------------------------------|---------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|------------|
| setTime   | Sets the current time of the board      | setTime(uint32_t t);                  | t: Current time in seconds                      | None                                     |
| getUptime | Returns the time since the last boot up | getUptime();                          | None                                            | Time (in seconds) since the last boot up |
| getTime   | Returns the current time of the board   | getTime();                            | None                                            | Current board time (in seconds)          |
| delay_s   | Sleeps a given number of seconds        | delay_s(unsigned long seconds);       | seconds: Sleep time period in seconds           | None                                     |
| delay_ms  | Sleeps a given number of milliseconds   | delay_ms(unsigned long milliseconds); | milliseconds: Sleep time period in milliseconds | None                                     |


#### ESP32_SerialPort.h

| **Method**    | **Description**                                      | **Syntax**                      | **Parameters**                                                                                                                    | **Return** |
|---------------|------------------------------------------------------|---------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|------------|
| init      | Initializes the Serial Port with the default baudrate 9600          | SerialPort::init(int id);                                                                  | id: The Serial Port Id (Default: 0)                                                                          | 1 if Success. -1 if error.                             |
| init      | Initializes the Serial Port the specified baudrate                  | SerialPort::init(int id, long baudRate);                                                   | id: The Serial Port Id (Default: 0) baudrate: The specified   baudrate                                       | 1 if Success. -1 if error.                             |
| init      | Initializes the SeialPort the specified baudrate and buffers   size | SerialPort::init(int id, long baudRate, unsigned long   txBuffer, unsigned long rxBuffer); | id: The Serial Port Id (Default: 0) baudrate: The specified   baudrate. txbuffer, rxbuffer: The buffers size | 1 if Success. -1 if error.                             |
| write     | Writes to the Serial Port                                           | SerialPort::write(unsigned char* buffer, int size);                                        | buffer: The payload to send. size: The size of the payload                                                   | Number of written bytes if Success. 0 if error.        |
| write     | Writes to the Serial Port                                           | SerialPort::write(char* buffer, int size);                                                 | buffer: The payload to send. size: The size of the payload                                                   | Number of written bytes if Success. 0 if error.        |
| write     | Writes to the Serial Port                                           | SerialPort::write(uint8_t c);                                                              | c: The byte to be sent                                                                                       | Number of written bytes if Success. 0 if error.        |
| write     | Writes to the Serial Port                                           | SerialPort::write(char *buffer);                                                           | buffer: The string array to be send                                                                          | Number of written bytes if Success. 0 if error.        |
| read      | Reads from the Serial Port                                          | SerialPort::read();                                                                        | None                                                                                                         | Retuns the content of the Rx Buffer of the Serial Port |
| read      | Reads from the Serial Port                                          | SerialPort::read(int timeout);                                                             | timeout: Read timeout in seconds                                                                             | Retuns the content of the Rx Buffer of the Serial Port |
| read      | Reads from the Serial Port                                          | SerialPort::read(char* data);                                                              | data: Read buffer. timeout: Read timeout in seconds                                                          | Returns the number of bytes read                       |
| read      | Reads from the Serial Port                                          | SerialPort::read(char* data, int timeout);                                                 | data: Read buffer                                                                                            | Returns the number of bytes read                       |
| available | Checks if there are any bytes on the SerialPort buffer              | SerialPort::available(void);                                                               | None                                                                                                         | Returns the number of bytes available to read          |
| close     | Closes the SerialPort                                               | SerialPort::close();                                                                       | None                                                                                                         | 1 if Success. -1 if error.                             |


#### ESP32_SPIFFS.h

| **Method**    | **Description**                                      | **Syntax**                      | **Parameters**                                                                                                                    | **Return** |
|---------------|------------------------------------------------------|---------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|------------|
| printSizeInfo | Prints the SPIFFS partition size                                    | SPIFFS::printSizeInfo();                                                                                                                 | None                                                                                                                                                                                                                                                                                               | None                 |
| writeFile     | Write the given content in a binary file (replace file if   exists) | SPIFFS::writeFile(char* fileName, char* content, int size,   bool append);                                                               | fileName: Name of file to write. content: Data to write in the   file. size: Size of data to write. append: Open mode (Replace content or   Append)                                                                                                                                                | None                 |
| readFile      | Read the file content if exists, return the content size            | SPIFFS::readFile(char* fileName, char** content, int size, int   offset)                                                                 | fileName: Name of file to read. content: Data read from the   file. size: Size of data to read (should coincide with read buffer size).   offset: File read offset                                                                                                                                 | Size of file content |
| removeFile    | Removes the given file                                              | SPIFFS::removeFile(char* fileName);                                                                                                      | fileName: Name of file to delete                                                                                                                                                                                                                                                                   | None                 |
| writeHistory  | Write a entry in a file with a pre-defined history format           | SPIFFS::writeHistory(char* fileName, unsigned long timestamp,   int numberOfElements, void* firstElement, int elementSize, bool append); | fileName: Name of history file to write. timestamp: Temporal   reference. numberOfElements: Number of elements to write in the file.   firstElement: Pointer to the first element to save in the hisotry.   elementSize: Size of a single element. append: Open mode (Replace content or   Append) | None                 |


#### ESP32_Wifi.h

| **Method**    | **Description**                                      | **Syntax**                      | **Parameters**                                                                                                                    | **Return** |
|---------------|------------------------------------------------------|---------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|------------|
| turnOn     | Turns on the Wifi module                         | WiFi::turnOn();                                               | None                                                         | None                                |
| turnOff    | Turns off the Wifi module                        | WiFi::turnOff();                                              | None                                                         | None                                |
| scan       | Performs a scan on all channels                  | WiFi::scan(accessPoints* aps);                                | aps: Seen access points list                                 | Number of access points seen        |
| directScan | Performs a scan on specified APs (based in SSID) | WiFi::directScan(accessPoints* aps, accessPoints* searchAps); | aps: Seen access points list. searchAps: Relevant APs filter | Number of access points seen        |
| connectAP  | Connects the board to the desired Access Point   | WiFi::connectAP(char* ssid, char* password);                  | ssid: Access point SSID. password: Access Point Password     | True if connected. False, otherwise |


#### LIS3DE_Acceleration.h

| **Method**    | **Description**                                      | **Syntax**                      | **Parameters**                                                                                                                    | **Return** |
|---------------|------------------------------------------------------|---------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|------------|
| init           | This function should be called before of any of the   accelerometer functions, it initializes the accelerometer on one of the two   operating modes described before. | LIS3DE::init(uint8_t mode);                       | mode: Operating mode of the accelerometer, Possible Values:   1-Motion Sensing Mode 2-Acceleration Reading Mode                   | Returns one int, if the configurations was succeed 1 otherwise   returns -1   |
| close          | Closes the SPI bus for the LIS3DE 																																	 | LIS3DE::close();                                  | None                                              																				 | None                                             							 |
| getTemperature | Reads the temperature in the LIS3DE, returns a calibration   corrected value                                                                                          | LIS3DE::getTemperature(uint8_t raw);              | raw: Temperature value compensation                                                                                               | Temperature read from the Accelerometer                                       |
| setWakeUp      | Configures the LIS3DE interrupt                                                                                                                                       | LIS3DE::setWakeUp(uint8_t itr, uint8_t thresh);   | itr: configure if the event can generate interruptions on   ACCELEROMETER pin thresh: acceleration threshold to trigger the event | None                                                                          |
| getWakeUp      | Gets the wakeUp event (check if occured)                                                                                                                              | LIS3DE::getWakeUp();                              | None                                                                                                                              | Returns one byte, if the wakeUp event had ocurr 0x40 otherwise   returns 0x00 |
| readRegister   | Reads a given 8 bit LIS3DE register                                                                                                                                   | LIS3DE::readRegister(uint8_t reg);                | reg: Register to read                                                                                                             | Value read from the register                                                  |
| readRegister16 | Reads a given 16 bit LIS3DE register                                                                                                                                  | LIS3DE::readRegister16(uint8_t reg);              | reg: Register to read                                                                                                             | Value read from the register                                                  |
| writeRegister  | Writes a given 8 bit LIS3DE register                                                                                                                                  | LIS3DE::writeRegister(uint8_t reg, uint8_t data); | reg: Register to write. data: Value to wirte in the register                                                                      | None                                                                          |


#### ESP32_HTTP.h

| **Method**    | **Description**                                      | **Syntax**                      | **Parameters**                                                                                                                    | **Return** |
|---------------|------------------------------------------------------|---------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|------------|
| networkUpdate | Performs OTA firmware update                         | HTTP::networkUpdate(char* cmd); | cmd: Custom URL to download the desired image. If empty this   method downloads a image (for this device) from the Device Manager | None   	  |
| getFile       | This method downloads a file from the Device Manager | HTTP::getFile(char* fileName);  | fileName: Name of file to download from the DM                                                                                    | None   	  |


