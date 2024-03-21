#pragma once

#include <iostream>
//For Winsock
#include <winsock2.h>
#include <ws2tcpip.h>


class server
{

	public:
		server();
		~server();


	private:
		//WSADATA contains information about Windows socket Implementation
		WSADATA wsaData;

		// This is the function to initialise winsock
		int init_winsock();
		int init_getaddrinfo();

		// This struct addrinfo is used by the getaddrinfo
		struct addrinfo *result = NULL, *prt = NULL, hints;

		//This SOCKET object is for the server to listen for the client connections.
		SOCKET listen_sock = INVALID_SOCKET;


		// This function calls the socket function and ensures a valid socket
		int init_socket();
};
