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

		char content[] = "{}";
		unsigned int contentLength = strlen(content);
		char httpStatus[] = "200";

		char* mimeType = "application/json";
		
		mg_printf(conn,
			"HTTP/1.1 %s OK\r\n"
			"Cache: no-cache\r\n"
			"%s"
			"Content-Type: %s\r\n"
			"Content-Length: %d\r\n"
			"\r\n",
			httpStatus, 
			headers_get_headers(), 
			mimeType,
			contentLength);

		mg_write(conn, content, contentLength);
		printf("METHOD: %s\n", conn->request_method);
		return MG_TRUE;

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
