<?php
	
	require __DIR__ . '/vendor/autoload.php';

	// make new connection
	$pusher = new Pusher\Pusher("5c9c7410e6ca2744c144", "b2850e5b2a9be4bae988", "565719", 
								array('cluster' => 'ap1'));

	// trigger connection
	if(isset($_GET['msg'])){
		$pusher->trigger('my-channel', 'my-event', array('message' => $_GET['msg']));
	}
?>