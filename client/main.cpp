#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// takes the hostname and a port number
int main(int argc, char** args){
	// gets the date and time
	time_t now = time(0);
	char* dt = ctime(&now);

	cout << "CHATCLIENT" << "                                          " << dt;
	cout << "----------------------------------------------------------------------------" << "|" << endl;
	if(argc < 3){
		cout << "No hostname and port." << endl;
		return 0;
	}
	
	// print the input
	cout << "HOST: " << args[1] << endl << "PORT: " <<  args[2] << endl;

	// get the host and port
	string HOST = args[1];
	int port  = atoi(args[2]);

	// default the port
	if(port == 0) port = 7777;

	// check for error on input
	cout << HOST << endl;
	cout << port << endl;

	// exit
	return 1;
}