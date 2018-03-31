#include <iostream>
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
	cout << "HOST: " << args[1] << endl << "PORT: " <<  args[2] << endl;
	return 1;
}