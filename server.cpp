#include "server.h"
#include <winsock2.h>

server::server()
{
	std::cout<<"Hello World"<<std::endl;
	init_winsock();
}

server::~server()
{
	std::cout<<"Bye World"<<std::endl;
}


int server::init_winsock()
{
	int init_res;

	init_res = WSAStartup(MAKEWORD(2,2), &wsaData);

	if(init_res !=0)
	{
		std::cout<<"WSAStartup failed: "<< init_res<<std::endl;
		return 1;
	}
	std::cout<<"WSAStartup Passed"<<std::endl;
	return 1;
}
