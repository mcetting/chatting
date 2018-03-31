#include <iostream>

#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>

// macros
#define D_PORT 7777

// takes a port
int main(int argc, char** args){
	int PORT, opt;
	struct sockaddr_in address;
	opt = 1;
	if(argc < 2){
		std::cout << "No port specified" << std::endl;
		PORT = D_PORT;
	}else{
		PORT = atoi(args[1]);
	}

	// make the socket
	int server_fd;
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
		std::cout << "socket error" << std::endl;
	    exit(EXIT_FAILURE);
	}

	// attatch the socket
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
    	std::cout << "socket attatch error" << std::endl;
        exit(EXIT_FAILURE);
    }

    // edit address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // bind
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0){
        std::cout << "bind error" << std::endl;
        exit(EXIT_FAILURE);
    }
    
	// listen for a connection


	std::cout << "LOCALHOST - " << PORT << std::endl;
	return 0;
}