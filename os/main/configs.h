
#ifndef MAIN_CONFIGS_H_
#define MAIN_CONFIGS_H_

//**********************************************************************************************************************************
//                                                      Define Section
//**********************************************************************************************************************************

// Save in history timestamp protection
#define CHECK_VALID_TIMESTAMP(timestamp) 				(timestamp > 1000000000) // Discard values with wrong timestamp // TODO check this protection

// Movement
#define MOVEMENT_THRESHOLDS			{2, 2, 3, 4, 5, 6, 8, 10, 20, 30, 40, 50, 60, 80, 100, 126}

// History Files
#define SCAN_HISTORY_FILENAME		"scan_history"

#endif

