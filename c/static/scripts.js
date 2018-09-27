
// -------
// sample1
// -------

function sample1() {
	
	var params = {		
	};

	var url = "http://172.22.107.5:8090";
	
	$.ajax({
		
		data: params,
		url: url,
		type: 'get',
		// contentType: "application/json; charset=utf-8",
		
		success: function (response) {
			console.log("response", response)
		},

		error: function (response) {
			console.log("error", response)
		}
	});
}

// -----------
// sample_post
// -----------

function sample_post() {
	
	var params = {		
	};

	var url = "http://172.22.107.5:8090";
	
	$.ajax({
		
		data: params,
		url: url,
		type: 'post',
		// contentType: "application/json; charset=utf-8",

		success: function (response) {
			console.log("success", response)
		},

		error: function (response) {
			console.log("error", response)
		}
	});
}

// -------------------------
// sample_non_simple_request 
// -------------------------

function sample_non_simple_request() {
	
	var params = {		
	};

	var url = "http://172.22.107.5:8090";
	
	$.ajax({
		
		data: params,
		url: url,
		type: 'post',
		contentType: "application/json; charset=utf-8",
	
		success: function (response) {
			console.log("success", response)
		},

		error: function (response) {
			console.log("error", response)
		}
	});
}
