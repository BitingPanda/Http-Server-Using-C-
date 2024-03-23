#pragma once

#include <iostream>

//For Winsock
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <Windows.h>

//This is for file reading and writing
#include <fstream>

//Macro
//This is the port number which the client number connect to
#define DEFAULT_PORT "27015"

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

		//This function is called to bind the socket to an address
		int bind_socket();


		//This would create a wrapper on the listen function
		int listen_socket();

		//This would accept the connection
		int accept_connection();

		//This is the client socket
		SOCKET client_sock = INVALID_SOCKET;

		//This would show the port (Extra)
		void port_view();


		//This stores the url in a string (Extra)
		std::string url;

		//This would open the port in a browser(Extra)
		void port_open();

		//This is the loading animation(Extra)
		void loading_animation();


		//These would hide and show the cursor(Extra)
		void hideCursor();
		void showCursor();


		//This function would create functionality to send data
		int send_data();
};



