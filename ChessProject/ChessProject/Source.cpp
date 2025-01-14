#include "Pipe.h"
#include "LocationException.h"
#include "Board.h"
#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::string;

// Role: Main function to manage communication with the graphics backend and handle chess moves.
// Input: None
// Output: None (Operates as a controller for the chess game)
void main()
{
    Board B; // Initialize the chessboard

    Pipe p;
    bool isConnect = p.connect(); // Attempt to connect to the graphics interface

    string ans;
    while (!isConnect)
    {
        cout << "Cannot connect to graphics" << endl;
        cout << "Do you want to try again or exit? (0 - Try again, 1 - Exit)" << endl;
        std::cin >> ans;

        if (ans == "0")
        {
            cout << "Trying to connect again..." << endl;
            std::this_thread::sleep_for(std::chrono::seconds(5));
            isConnect = p.connect();
        }
        else
        {
            p.close();
            return;
        }
    }

    char msgToGraphics[1024];

    // Send the initial board state to the graphics
    strcpy_s(msgToGraphics, B.boardString().c_str());
    p.sendMessageToGraphics(msgToGraphics);

    // get message from graphics
    string msgFromGraphics = p.getMessageFromGraphics();
    while (msgFromGraphics != "quit")
    {
        B.move(msgFromGraphics[1], msgFromGraphics[0], msgFromGraphics[3], msgFromGraphics[2]);

        // Prepare response message for the graphics interface
        msgToGraphics[0] = (char)(B._code + '0');
        msgToGraphics[1] = '\0';

        // Send the result of the operation back to the graphics
        p.sendMessageToGraphics(msgToGraphics);

        // Receive the next message from the graphics
        msgFromGraphics = p.getMessageFromGraphics();
    }

    // Close the connection to the graphics interface
    p.close();
}
