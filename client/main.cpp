#include <iostream>
#include <string>
#include <ctime>

// takes the hostname and a port number
int main(int argc, char** args){
	// gets the date and time
	time_t now = time(0);
	char* dt = ctime(&now);

	std::cout << "CHATCLIENT" << "                                          " << dt;
	std::cout << "----------------------------------------------------------------------------" << "|" << std::endl;
	if(argc < 3){
		std::cout << "No hostname and port." << std::endl;
		return 0;
	}

	// print the input
	std::cout << "HOST: " << args[1] << std::endl;
	std::cout << "PORT: " <<  args[2] <<std::endl;

	// get the host and port
	std::string HOST = args[1];
	int port  = atoi(args[2]);

	// default the port
	if(port == 0) port = 7777;

	// check for error on input
	std::cout << HOST << std::endl;
	std::cout << port << std::endl;

	// exit
	return 1;
}