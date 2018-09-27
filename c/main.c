#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "mongoose.h"

int handler(struct mg_connection *conn, enum mg_event ev) {

	if (ev == MG_REQUEST) {
		
		printf("hola\n");

		// /* rest */
		// if (strcmp(conn->request_method, "OPTIONS") == 0){
			// char* mimeType = "application/json";
			// mg_printf(conn,
				// "HTTP/1.1 200 OK\r\n"
				// "Cache: no-cache\r\n"
				// "Access-Control-Allow-Origin: *\r\n"
				// "Access-Control-Allow-Methods: GET,PUT,POST,OPTIONS,DELETE\r\n"
				// "Content-Type: %s\r\n"
				// "Content-Length: %d\r\n"
				// "\r\n",
				// mimeType,
				// 0);

			// mg_write(conn, "", 0);
			// return MG_TRUE;
		// }

		// _reply(conn);
		return MG_TRUE;
	} else {
		if (ev == MG_AUTH) {
			return MG_TRUE;
		} else {
			return MG_FALSE;
		}
	}
}



/* ---------------------------- */

int main() {


	struct mg_server *mg_server = mg_create_server(NULL, handler);
	mg_set_option(mg_server, "listening_port", "8090");

	for (;;) {
		mg_poll_server(mg_server, 1000);
		// if (this->api->closeServer == 1){
			// break;
		// }
	}

	mg_destroy_server(&(mg_server));

}

/* --------------------- */

