
// -------
// sample1
// -------

function sample1() {

	var params = {};

	var url = "http://172.22.107.5:8090";

	$.ajax({

		data: params,
		url: url,
		type: 'get',
		// contentType: "application/json; charset=utf-8",

		success: function (response) {
			console.log("response", response)
		},

		error: function (xhr, status, error) {
			var err = eval("(" + xhr.responseText + ")");
			console.log("!", err.Message);

		}
	});
}

// -----------
// sample_post
// -----------

function sample_post() {

	var params = {};

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
			var err = eval("(" + xhr.responseText + ")");
			console.log("!", err.Message);
		}
	});
}

// -------------------------
// sample_non_simple_contenttype
// -------------------------

function sample_non_simple_contenttype() {

	var params = {};

	var url = "http://172.22.107.5:8090";

	$.ajax({

		data: params,
		url: url,
		type: 'post',
		contentType: "application/json; charset=utf-8",

		success: function (response) {
			console.log("success", response)
		},

		error: function (xhr, status, error) {
			// var err = JSON.parse(xhr.responseText);
			console.log(xhr);
		}
	});
}

// -------------------------
// sample_non_method_put
// -------------------------

function sample_non_method_put() {

	var params = {};

	var url = "http://172.22.107.5:8090";

	$.ajax({

		data: params,
		url: url,
		type: 'put',
		contentType: "application/json; charset=utf-8",

		success: function (response) {
			console.log("success", response)
		},

		error: function (xhr, status, error) {
			// var err = JSON.parse(xhr.responseText);
			console.log(xhr);
		}
	});
}
