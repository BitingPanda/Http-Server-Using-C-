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
};
