import sys
sys.path.insert(0, './classes')
from WebServer import WebServer
from flask import request

if __name__ == "__main__":
	server = WebServer()
	server.port = 5001
	server.init()
	server.run()