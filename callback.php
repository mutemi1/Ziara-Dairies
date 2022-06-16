<?php
/**
 * Get Any Control Commands From Dashboard
 * */

// get message string
$body = @file_get_contents("php://input");
$response = json_decode($body);
$message = $response->message;
// send message string
$command='mosquitto_pub -t test/device1 -m "'.$message.'"';
echo $command;
shell_exec($command); 
?>