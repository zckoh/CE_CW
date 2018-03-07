/*
 * program_counter.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: zckoh
 */

#include "program_counter.h"

NET_LAYER::NET_LAYER() {
	control1 = 0;
	control2 = 0;
	SRC_ADDR = 0;
	DEST_ADDR = 0;
	LENGTH = 0;
	CHECKSUM1 = 0;
	CHECKSUM2 = 0;
}

