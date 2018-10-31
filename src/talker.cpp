/*
 * @file talker.cpp
 * @Copyright MIT license
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 * @author Bala Murali Manoghar Sai Sudhakar
 * @brief This demonstrates simple sending of messages over the ROS system and depicts a talker node.
 */

/*
 * MIT License
 *
 * Copyright (c) 2018 Bala Murali Manoghar Sai Sudhakar
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#include <sstream>

#include "ros/ros.h"
#include "std_msgs/String.h"

/**
 * @brief Main block that runs the node.
 * @param argc Number of command line arguments
 * @param argv Pointer to command line arguments
 * @return Status of execution
 */
int main(int argc, char **argv) {
  // Initializing ROS node
  ros::init(argc, argv, "talker");
  // Creating node handle
  ros::NodeHandle n;
  // Creating publisher object
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  // Setup loop rate
  ros::Rate loop_rate(10);
  // Message counter
  int count = 0;
  // Loop till ROS system is active
  while (ros::ok()) {
    // Creating message object
    std_msgs::String msg;
    // Creaing string stream object
    std::stringstream ss;
    // Sending message to string stream
    ss << "Hello Terps!! " << count;
    // Assign message to object
    msg.data = ss.str();
    // Printing on console output
    ROS_INFO_STREAM(msg.data.c_str());
    // Publish message to topic
    chatter_pub.publish(msg);
    // Check for call back
    ros::spinOnce();
    // Wait for required time
    loop_rate.sleep();
    ++count;
  }
  return 0;
}
