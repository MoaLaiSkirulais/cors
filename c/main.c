#include <stdlib.h>
#include <stdio.h>
#include <string.h>



/* ---------------------------- */

int main() {


	this->_mg_server = mg_create_server(this, this->handler);
	mg_set_option(this->_mg_server, "listening_port", this->port);

	for (;;) {
		mg_poll_server(this->_mg_server, 1000);
		if (this->api->closeServer == 1){
			break;
		}
	}

	mg_destroy_server(&(this->_mg_server));

}

/* --------------------- */

int handler(struct mg_connection *conn, enum mg_event ev) {

	if (ev == MG_REQUEST) {

		eppos_Httpserver *this = conn->server_param;

		this->api->log->setCall(this->api->log, "eppos_Httpserver", "handler");
		sprintf(this->api->log->msg, "Incoming request %d", ev);
		this->api->log->dolog(this->api->log, this->api->log->msg, "sys");

		/* rest */
		if (strcmp(conn->request_method, "OPTIONS") == 0){
			char* mimeType = "application/json";
			mg_printf(conn,
				"HTTP/1.1 200 OK\r\n"
				"Cache: no-cache\r\n"
				"Access-Control-Allow-Origin: *\r\n"
				"Access-Control-Allow-Methods: GET,PUT,POST,OPTIONS,DELETE\r\n"
				"Content-Type: %s\r\n"
				"Content-Length: %d\r\n"
				"\r\n",
				mimeType,
				0);

			mg_write(conn, "", 0);
			return MG_TRUE;
		}

		this->process(this, conn);

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

/* --------------------- */

static void _dev_test(eppos_Httpserver *this, struct mg_connection *conn) {

	this->api->log->setCall(this->api->log, "eppos_Httpserver", "process");
	this->api->log->dolog(this->api->log, "", "sys");

	char content[] = "hi";
	unsigned int contentLength = strlen(content);
	
	char httpStatus[] = "200";
	mg_printf(conn,
		"HTTP/1.1 %s OK\r\n"
		"Cache: no-cache\r\n"
		"Access-Control-Allow-Origin: *\r\n"
		"Access-Control-Allow-Methods: GET,PUT,POST,OPTIONS,DELETE\r\n"
		"Content-Type: application/json\r\n"
		"Content-Length: %d\r\n"
		"\r\n",
		httpStatus,
		contentLength
	);

	mg_write(conn, content, contentLength);
}

/* 
 * function: setPort 
 * description: setea el puerto con el cual va a startear el http webserver
 */

static int setPort(eppos_Httpserver *this, char *port) {

	if (strcmp(port, "") != 0){
		strcpy(this->port, port);
	}
	return 0;
}

/* --------------------- */

void eppos_Httpserver_init(eppos_Httpserver *obj){

	obj->api = eppos_ApiConn_get();

	strcpy(obj->port, "8090");
	obj->closeServer = 0;

	obj->create = create;
	obj->handler = handler;
	obj->process = _dev_test;
	obj->setPort = setPort;
	return;
}
	
}
