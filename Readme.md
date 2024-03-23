# HTTP Server using C++
A simple HTTP server using C++ and Winsock. This is a beginner project intended to learn. Therefore, the coding has a lot of indentation.


#### Contents
- [Technologies Used](#technologies-used)
- [Commit Details](#commit-details)
- [Building](#building)

---

### Technologies Used
- C++
- WinSock
- CMake
- gcc (for compiling C++)

---


### Commit Details

##### Listening to socket and Accepting Client Connection
- Starts Listening to the socket using the listen function
- Creates a Client socket
- Accepts the client socket when went into the url
- Created a port view to view the URL in terminal

##### Binded The Socket
- Binded the socket with the address which was picked up using getaddrinfo function
- After binding, the getaddrinfo function is no longer needed.
- The freeaddrinfo function is called to free the memory allocated by the getaddrinfo function for this address information.
- Added Documentation for all this

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
