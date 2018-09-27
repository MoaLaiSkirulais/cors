#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "headers.h"


char headers[20][70];



int headers_get_headers() {
	
	size_t i = 0;
	
	for( i = 0; i < sizeof(headers) / sizeof(headers[0]); i++){
		
		printf("%s", headers[i]);

	}


}

int headers_load_headers() {
	
	int i;
	for (i = 0; i < 20; ++i){
		strcpy(headers[i], "undefined");
	}

}

/* --------------------- */

