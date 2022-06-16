<?php
while (1) {
        $conn = mysqli_connect("localhost","pms","Pms@2022");
        mysqli_select_db($conn, "solar");
        // default time zone
        date_default_timezone_set('Africa/Nairobi');
        $handle = fopen("php://stdin", "r");
        $line = fgets($handle);
        $data = explode("%", $line);
        $topic = "test/device1";

        /**
         * Extract variables in this order
         * 1 -> deviceid (imei)
         * 2 -> inlet total litres
         * 3 -> outlet total litres
         * 4 -> inlet temperature
         * 5 -> outlet temperature
         * 6 -> current sensor 1
         * 7 -> current sensor 2
         * 8 -> current sensor 3
         * 9 -> current sensor 4
         * 10 -> current sensor 
         * 11 -> pressure reading
         * 12 -> motor state (if system is open or closed)
         * */
        $device_id = $data[0];
        $inlet_vol = $data[1];
        $outlet_vol = $data[2];
        $inlet_temp = $data[3];
        $outlet_temp = $data[4];
        $ct1 = $dat3[5];
        $ct2 = $data[6];
        $ct3 = $data[7];
        $ct4 = $data[8];
        $ct5 = $data[9];
        $pressure_val = $data[10];
        $valve_state = $data[11];
        $date_stamp = date("d-m-Y");
        $time_stamp = date("H:i:s");

        /**
         * Logic for saving Data
         * 1. Insert data to Database
         * 2. Get Response from Database whether data has been saved or not
         * 3. Relay feedback to Hardware Device
         * **/
        $query = mysqli_query($conn, "INSERT INTO solar_data (device_id, inlet_vol, outlet_vol, inlet_temp, outlet_temp, ct1, ct2, ct3, ct4, ct5, pressure_val, valve_state, date_stamp, time_stamp) VALUES ('$device_id', '$inlet_vol', '$outlet_vol', '$inlet_temp', '$outlet_temp', '$ct1', '$ct2', '$ct3', '$ct4', '$ct5', '$pressure_val', '$valve_state', '$date_stamp', '$time_stamp')");
        if ($query) {
                $message = "Success. Data Saved Successfully";
        }
        else {
                $message = "Error!! Could Not Save Data.";
        }

        $command='mosquitto_pub -t test/device1 -m "'.$message.'"';
        echo $command;
        shell_exec($command); 
}
?>


