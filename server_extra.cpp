#include "server.h"
#include <thread>
#include <chrono>

//This is the definition for hide cursor()
//This hides the cursor for better aesthetics
void server::hideCursor() 
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

//This would show the cursor after being hidden by the hideCursor()
void server::showCursor() 
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

//This would show the url in the console
void server::port_view()
{
	std::cout<< "http://localhost:"<< DEFAULT_PORT << "/"<<std::endl;
	url += "http://localhost:" DEFAULT_PORT "/";
}

//This would open the browser in the default browser
void server::port_open()
{

	ShellExecute(NULL,"open",url.c_str(),NULL,NULL,SW_SHOWNORMAL);
}


// This is a listening animation
// WARNING: As of now It is buggy
void server::loading_animation() {
    while (true) {
        std::cout << "\rListening" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "\rListening." << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "\rListening.." << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "\rListening..." << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
