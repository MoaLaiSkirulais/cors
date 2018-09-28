#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "mongoose.h"
#include "headers.h"

// --------------
// handler
// --------------

int handler(struct mg_connection *conn, enum mg_event ev) {
	
	headers_load_headers();

	if (ev == MG_REQUEST) {
		
		/* vars */
		char httpStatus[10];
		char headers[1000]; 
		char mimeType[200];
		char content[500];
		
		if (
				(strcmp(conn->request_method, "PUT") == 0) || 
				(strcmp(conn->request_method, "POST") == 0) || 
				(strcmp(conn->request_method, "OPTIONS") == 0) || 
				(strcmp(conn->request_method, "GET") == 0)			
			){

			/* get, post */
			strcpy(httpStatus, "200");
			strcpy(headers, headers_get_headers());
			strcpy(mimeType, "application/json");
			strcpy(content, "{\"foo\":\"bar\"}");
			
			/* options */
			if (strcmp(conn->request_method, "OPTIONS") == 0) {
				strcpy(httpStatus, "200");
				strcpy(headers, headers_get_headers());
			}
			
			/* response */
			mg_printf(conn,
				"HTTP/1.1 %s OK\r\n"
				"Cache: no-cache\r\n"
				"%s"
				"Content-Type: %s\r\n"
				"Content-Length: %d\r\n"
				"\r\n",
				httpStatus, 
				headers, 
				mimeType,
				strlen(content));

			/* send */
			mg_write(conn, content, strlen(content));
			printf("METHOD: %s\n", conn->request_method);
			return MG_TRUE;
		}

	} else {
		
		if (ev == MG_AUTH) {
			return MG_TRUE;
		} else {
			return MG_FALSE;
		}
	}
}


// --------------
// main
// --------------

int main() {

	struct mg_server *mg_server = mg_create_server(NULL, handler);
	mg_set_option(mg_server, "listening_port", "8090");

	for (;;) {
		mg_poll_server(mg_server, 1000);
	}

	mg_destroy_server(&(mg_server));

}
