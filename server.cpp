#include "server.h"
//#include <winsock2.h>

server::server()
{
	// The winsock is initialised here
	init_winsock();
}

server::~server()
{
}


int server::init_winsock()
{
	int init_res;

	//WSAStartup function is called to initiate use of WS2_32.dll
	//It also returns a integer value and check for errors
	init_res = WSAStartup(MAKEWORD(2,2), &wsaData);

	if(init_res !=0)
	{
		std::cout<<"WSAStartup failed: "<< init_res<<std::endl;
		return 1;
	}
	std::cout<<"WSAStartup Passed"<<std::endl;
	return 1;
}
