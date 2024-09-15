# HTTP Server using C++
A simple HTTP server using C++ and Winsock. This is a beginner project intended to learn. Therefore, the coding has a lot of indentation.

This would be a great start to learn how to make an HTTP server that outputs a basic HTTP response along with a HTML page to show on the web browser


#### Contents
- [Building](#building)
- [Technologies Used](#technologies-used)
- [Commit Details](#commit-details)


#### Prerequisites 
This is only for windows as some of the components used are Windows only

---
### Building

- First the build files have to be generated using cmake. Here MinGW used
, MinGW build files are generated using the `-G` flag and specified the build folder using `-B` flag

    ```powershell
    cmake -G "MinGW Makefiles" -B .\build\
    ```

<br>

- Then the executable have to be built using this:
    
    ```powershell
    cmake --build .\build\
    ```
<br>

:warning:*Here the build folder is `.\build`*

---

### Technologies Used
- C++
- WinSock
- CMake
- gcc (for compiling C++)

---


### Commit Details

##### Sends data
- Sends a HTTP message with the HTML to show in the browser
- "index.html" is the file for the server to show to the client
- Added a file named "server_extra.cpp" which would hold all the definition for the functions used for aesthetic purpose.
- Here, a thing to be noted that, this extra things can be removed without compromising any functionality
- After Sending the data, the sockets are closed
- The cleanup and closing happens on the deletion of the server object


<br>

##### Listening to socket and Accepting Client Connection
- Starts Listening to the socket using the listen function
- Creates a Client socket
- Accepts the client socket when went into the url
- Created a port view to view the URL in terminal

<br>

##### Binded The Socket
- Binded the socket with the address which was picked up using getaddrinfo function
- After binding, the getaddrinfo function is no longer needed.
- The freeaddrinfo function is called to free the memory allocated by the getaddrinfo function for this address information.
- Added Documentation for all this

<br>

##### Created a socket
- Created a wrapper for using getaddrinfo function which provides protocol-independent translation from an ANSI host name to an address.
- Created a socket which the client will listen for connection with fault tolerance
- Added documentation for all this
- Added building process in the Readme.md

<br>

##### Added Readme
- Added a Readme.md describing the building process
- Adding documentation for the code

<br>

##### Initialised Winsock
- Initialised Winsock using the official documentation.
-  Here, the Winsock is linked with the main using cmake.
-  And, upon initialising or failing it outputs a message showing the status of the initialisation

<br>

##### Initial Commit
- Created all the boiler plate for the project including the main file and the Cmake file to build the source.


