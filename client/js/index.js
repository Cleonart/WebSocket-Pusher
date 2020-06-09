// create new pusher instance
var pusher = new Pusher('f2299725eb727e961ede', {
	 cluster: 'ap1'
});

// make channel
var channel = pusher.subscribe('my-channel');
channel.bind('my-event', function(data) {
	updateStatus(data.channel, data.message);
});

// update status
function updateStatus(channel, message){

	var data  = document.getElementById("container" + channel);
	var stats = document.getElementById("status" + channel);

	if(message == 0 || message == "0"){
 		//data.style.backgroundColor = "green";
 		stats.style.backgroundColor = "green";
 		stats.innerText = "Aman";
	}

	else if(message == 0.5 || message == "0.5"){
 		//data.style.backgroundColor = "yellow";
 		stats.style.backgroundColor = "yellow";
	 	stats.innerText = "Berasap";
	}

	else if(message == 1 || message == "1"){
	 	//data.style.backgroundColor = "red";
	 	stats.style.backgroundColor = "red";
	 	stats.innerText = "Kebakaran";
	}

}