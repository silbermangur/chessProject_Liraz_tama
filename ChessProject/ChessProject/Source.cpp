/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include "LocationException.h"
#include "Board.h"
#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::string;


void main()
{
	Board B;

	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}
	

	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	strcpy_s(msgToGraphics,	B.boardString().c_str());

	
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();
	while (msgFromGraphics != "quit")
	{
		B.move(msgFromGraphics[1], msgFromGraphics[0], msgFromGraphics[3], msgFromGraphics[2]);
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		
		// YOUR CODE
		strcpy_s(msgToGraphics, "YOUR CODE"); // msgToGraphics should contain the result of the operation

		/******* JUST FOR EREZ DEBUGGING ******/
		int r = rand() % 10; // just for debugging......
		msgToGraphics[0] = (char)(B._code + '0');
		msgToGraphics[1] = 0;
		/******* JUST FOR EREZ DEBUGGING ******/

		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}