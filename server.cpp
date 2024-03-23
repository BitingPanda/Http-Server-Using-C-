#include "server.h"
#include <fstream>
#include <iostream>

//This are the headers for winsock
#include <sstream>
#include <string>
#include <winsock2.h>
#include <winuser.h>
#include <ws2tcpip.h>

//#include <shellapi.h>



server::server()
{
	//This would hide the cursor for looking better (Optional)
	hideCursor();
	//This would show the port number to copy
	port_view();
	// The winsock is initialised here
	init_winsock();
	
	//This is a wrapper for the getaddr function
	init_getaddrinfo();

	//This would create the socket
	init_socket();

	//This function is called to bind the socket
	bind_socket();

	//This would start listening the socket
	listen_socket();

	//This would open the port on the browser
	port_open();

	//This would accept the connection
	accept_connection();

	//This send the data which is a HTML file with the HTTP request
	send_data();

	//This would show the cursor (Optional)
	showCursor();
}

//This would clean up everything upon deletion of the server object
server::~server()
{
	freeaddrinfo(result);
	closesocket(listen_sock);
	closesocket(client_sock);
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

	//Frees up the result pointer
	freeaddrinfo(result);
	return 0;
}

int server::listen_socket()
{
	//This listen function will listen to the socket created
	if( listen( listen_sock, SOMAXCONN) == SOCKET_ERROR)
	{
		std::cout<< "Listen failed with error: "<<WSAGetLastError()<<std::endl;
		closesocket(listen_sock);
		WSACleanup();
		return 1;
	}
	
	std::cout<<"Listening..."<<std::endl;
	
	//loading_animation() would replace the static output
	//This is buggy as of now
	//loading_animation();

	return 0;
}

//This would accpet the connection
int server::accept_connection()
{

	//Accept a client sock
	client_sock = accept(listen_sock, NULL, NULL);
	
	//This would create a fault tolerance for accepting the connection
	if(client_sock == INVALID_SOCKET)
	{
		std::cout<< "Accept Failed: "<< WSAGetLastError()<<std::endl;
		closesocket(listen_sock);
		WSACleanup();
		return 1;
	}

	std::cout<< "Connection Accepted!" <<std::endl;
	return 0;
}


int server::send_data()
{
	//This block would read content from the html file
	std::ifstream file("index.html");
	std::stringstream buffer;
	buffer<<file.rdbuf();
	std::string content = buffer.str();

	//Construct HTTP response with the HTML page
	std::string http_response = "HTTP/1.1 200 OK\r\n";
	http_response += "Content-Type: text/html\r\n";
	http_response += "Content-Length: " + std::to_string(content.size())+ "\r\n\r\n";
	http_response += content;


	//This sends the data to the client
	int send_result = send(client_sock, http_response.c_str(), http_response.size(),0);
	
	//Creates Fault tolerence for Sending Data
	if(send_result == SOCKET_ERROR)
	{
		std::cout<<"Send Failed: "<< WSAGetLastError()<<std::endl;
		closesocket(client_sock);
		WSACleanup();
		return 1;
	}

	std::cout<< "Sending Successful!"<<std::endl;
	return 0;
	
}
