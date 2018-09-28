#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "headers.h"

// ------
// locals
// ------

int total_headers=0;
char headers[20][70];
char *Buffer;

// -------------------
// headers_get_headers
// -------------------

char *headers_get_headers() {

	char *Buffer = malloc(1000);
	strcpy(Buffer, "");
	
	int i = 0;
	for( i = 0; i < total_headers; i++){		
		sprintf(Buffer, "%s%s", Buffer, headers[i]);
	}
	
	// printf("%s", Buffer);
	return Buffer;
}

// --------------------
// headers_load_headers
// --------------------

int headers_load_headers() {

	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	total_headers=0;

	fp = fopen("headers.ini", "r");

	/* loop */
	while ((read = getline(&line, &len, fp)) != -1) {
		strcpy(headers[total_headers], line);
		total_headers++;
	}

	/* close */
	fclose(fp);
	if (line) {
		free(line);
	}

}

// https://developer.mozilla.org/es/docs/Web/HTTP/Access_control_CORS