#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "mongoose.h"

#include "headers.h"

// --------------
// handler
// --------------

int handler(struct mg_connection *conn, enum mg_event ev) {

	if (ev == MG_REQUEST) {

		char content[] = "{}";
		unsigned int contentLength = strlen(content);
		char httpStatus[] = "200";

		char* mimeType = "application/json";
		
		mg_printf(conn,
			"HTTP/1.1 %s OK\r\n"
			"Cache: no-cache\r\n"
			"Access-Control-Allow-Origin: *\r\n"
			"Access-Control-Allow-Methods: GET,PUT,POST,OPTIONS,DELETE\r\n"
			"Content-Type: %s\r\n"
			"Content-Length: %d\r\n"
			"\r\n",
			httpStatus, 
			mimeType,
			contentLength);

		mg_write(conn, content, contentLength);
		printf("hola!!\n");
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

int main1() {

	struct mg_server *mg_server = mg_create_server(NULL, handler);
	mg_set_option(mg_server, "listening_port", "8090");

	for (;;) {
		mg_poll_server(mg_server, 1000);
	}

	mg_destroy_server(&(mg_server));

}

// --------------
// main
// --------------

int main() {

	headers_load_headers();
	headers_get_headers();

}
