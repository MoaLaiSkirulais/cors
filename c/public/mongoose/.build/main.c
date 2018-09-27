#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "eppos_Log.h"

/***********************/

int main() {
	
	eppos_Log eppos_log = eppos_Log_new();
	eppos_log.dolog(&eppos_log, "sdsad", "sys");

	// logger->setCall(logger, "eppos_Database", "init");
	// logger->dolog(logger, "start", );	

}
