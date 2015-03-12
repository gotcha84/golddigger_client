# golddigger_client

The client node that runs on the dragonboard. Responsible for publishing the webcam feed and controlling the LED+buzzer based on topics published from the base station.

We set the dragonboard to a static IP of 192.168.1.220.

You should edit + run init_network.sh first to initialize the ROS_MASTER_URI to the base station and ROS_IP to the computer running this node.
