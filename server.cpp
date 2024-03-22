#include "server.h"
#include <iostream>

//This are the headers for winsock
#include <winsock2.h>
#include <ws2tcpip.h>
//#include <winsock2.h>



//This is the port number which the client number connect to
#define DEFAULT_PORT "27015"

server::server()
{
	// The winsock is initialised here
	init_winsock();
	
	//This is a wrapper for the getaddr function
	init_getaddrinfo();

	//This would create the socket
	init_socket();

	//This function is called to bind the socket
	bind_socket();
}


server::~server()
{
	freeaddrinfo(result);
	closesocket(listen_sock);
	WSACleanup();
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


//This is the wrapper for getaddrinfo function
int server::init_getaddrinfo()
{
	ZeroMemory(&hints,sizeof(hints));
	hints.ai_family = AF_INET; //This is for IPv4 address family
	hints.ai_protocol = IPPROTO_TCP; //This is for TCP protocol
	hints.ai_flags = AI_PASSIVE; //


	//Resolve the local address and port to be used by the server
	// The getaddrinfo function provides protocol independent translation from an ANSI host name to an address
	int init_res = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	
	///This is for fault tolerence
	if(init_res !=0)
	{
		std::cout<<"getaddrinfo failed: "<< init_res<<std::endl;
		WSACleanup();
		return 1;
	}

	std::cout<< "getaddrinfo successful"<<std::endl;
	return 0;
}


int server::init_socket()
{
	//The socket function is called to create a socket that is bound to a specific transport service provider
	listen_sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

	//This is for fault tolerence
	if (listen_sock == INVALID_SOCKET)
	{
		std::cout<<"Error at socket(): " << WSAGetLastError()<<std::endl;
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	std::cout<<"Socket Initialised Successfully"<<std::endl;

	return 0;

}

//This is a wrapper for the bind function
int server::bind_socket()
{
	//Setting up the TCP listening socket
	int init_res = bind(listen_sock, result->ai_addr,(int)result->ai_addrlen);

	//This is for fault tolerance
	if(init_res == SOCKET_ERROR)
	{
		std::cout<<"Bind failed with error: "<< WSAGetLastError()<<std::endl;
		freeaddrinfo(result);
		closesocket(listen_sock);
		WSACleanup();
		return 1;
	}

	std::cout<< "Binding Successful"<<std::endl;
	freeaddrinfo(result);
	return 0;
}


