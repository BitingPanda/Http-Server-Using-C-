#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>


class server
{

	public:
		server();
		~server();


	private:
		WSADATA wsaData;

		int init_winsock();
};
