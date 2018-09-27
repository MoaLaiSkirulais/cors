function sample1() {
	
	var params = {		
	};

	var url = "http://172.22.107.5:8090";
	
	$.ajax({
		
		data: params,
		url: url,
		type: 'get',
		// contentType: "application/json; charset=utf-8",
		
		beforeSend: function () {
			console.log("before")
		},
		
		success: function (response) {
			console.log("response!!")
			console.log("response", response)
		},

		error: function (response) {
			console.log("error")
			console.log("response", response)
		}
	});
}
