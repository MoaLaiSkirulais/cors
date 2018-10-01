var jano_ip = "172.22.107.225"

// -----------------------------------
// simple_get
// -----------------------------------

function simple_get() {

	var params = {};

	var url = "http://" + jano_ip;

	$.ajax({

		url: url,
		type: 'get',

		success: function (response) {
			console.log("response", response)
		},

		error: function (xhr, status, error) {
			var err = eval("(" + xhr.responseText + ")");
			console.log("!", err.Message);

		}
	});
}


// -----------------------------------
// simple_post
// -----------------------------------

function simple_post() {

	var params = {};

	var url = "http://" + jano_ip;

	$.ajax({

		url: url,
		type: 'post',

		success: function (response) {
			console.log("response", response)
		},

		error: function (xhr, status, error) {
			var err = eval("(" + xhr.responseText + ")");
			console.log("!", err.Message);

		}
	});
}

// -----------------------------------
// simple_post_ext
// -----------------------------------

function simple_post_ext() {

	var params = {};

	var url = "http://" + jano_ip + "/ext";

	$.ajax({

		url: url,
		type: 'post',

		success: function (response) {
			console.log("response", response)
		},

		error: function (xhr, status, error) {
			console.log("xhr", xhr);
			console.log("status", status);
			console.log("error", error);

		}
	});
}

// -----------------------------------
// simple_post_ext_params
// -----------------------------------

function simple_post_ext_params() {

	var params = "0001|0000";
	// var params = "{\"command\":\"020A\", \"command_extension\":\"0000\"}";
	// var params = "{\"commands\":\"020A\", \"command_extension\":\"0000\"}";
	// var params = "{\"command\":\"020A\", \"command_extension\":\"0000\",\"concha\":0}";
	// var params = "[1,1,1,1,1,1,1,1,1,1]";

	var url = "http://" + jano_ip + "/ext";

	$.ajax({

		data: params,
		url: url,
		type: 'post',

		success: function (response) {
			console.log("response", response)
		},

		error: function (xhr, status, error) {
			console.log("xhr", xhr);
			console.log("status", status);
			console.log("error", error);

		}
	});
}

// -----------------------------------
// change_cors
// -----------------------------------

function change_cors() {

	var params = {
		"Access-Control-Allow-Origin": "casa", 
		"Access-Control-Allow-Methods": "PUT,POST", 
		"Access-Control-Allow-Headers": "content-type", 
		"Access-Control-Allow-Credentials": "true", 
		"Access-Control-Max-Age": "*", 
		"Access-Control-Expose-Headers": "*"
	};
	
	params = JSON.stringify(params);
	console.log("params", params)

	var url = "http://" + jano_ip + "/cors";

	$.ajax({

		data: params,
		url: url,
		type: 'post',

		success: function (response) {
			console.log("response", response)
		},

		error: function (xhr, status, error) {
			console.log("xhr", xhr);
			console.log("status", status);
			console.log("error", error);

		}
	});
}

// -----------------------------------
// complex_post_ext_params
// -----------------------------------

function complex_post_ext_params() {

	var params = "0001|0000";
	var params = "{\"command\":\"020A\", \"command_extension\":\"0000\"}";

	var url = "http://" + jano_ip + "/ext";

	$.ajax({

		data: params,
		url: url,
		type: 'post',
		contentType: "application/json; charset=utf-8",

		success: function (response) {
			console.log("response", response)
		},

		error: function (xhr, status, error) {
			console.log("xhr", xhr);
			console.log("status", status);
			console.log("error", error);

		}
	});
}