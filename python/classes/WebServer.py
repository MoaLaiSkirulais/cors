# third
import platform
from flask_cors import CORS
from flask import Flask, jsonify, request
from flask import Response
from flask import send_from_directory
import time
import logging
import os

from flask_pymongo import PyMongo

#-------------
# WebServer
#-------------
class WebServer:
	
	def __init__(self):
	
		self.host = "0.0.0.0"
		self.port = 5001
		self.app = ''
		self.database = ''


	#-------------
	# init
	#-------------
	def init(self):
		
		self.app = Flask(__name__, static_url_path='/mnt/dev/xtras/users/MoaLaiSkirulais/cors/static/')
		cors = CORS(self.app, resources={r"/*": {"origins": "*"}})
					
		# cors
		# ------------
		@self.app.route("/cors", methods=['GET', 'POST'])
		def cors():
			
			# print("request.headers['Content-Type']", request.headers['Content-Type'])
			
			if 'CONTENT_TYPE' in request.headers:
				return jsonify({"El Content-Type es": request.headers['Content-Type']})
			else:
				return jsonify({"El Content-Type es": "No enviado"})

			
		# static_file
		# -----------
		@self.app.route('/static/<path:path>')		
		def static_file(path):			
			root_dir = os.path.dirname(os.getcwd())
			root_dir = os.path.join(root_dir, 'cors', 'static')
			return send_from_directory(root_dir, path)

						

	#-------------
	# run
	#-------------
	def run(self):
	
		print("Running Flask HTTP Server")
		self.app.run(debug=True, port=self.port, host=self.host)
