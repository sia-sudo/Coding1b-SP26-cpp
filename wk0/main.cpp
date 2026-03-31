// Stephanie Barrera Coding 1 Spring 2026
// My first c++ Program

// to compile, open the 'Developer Command Prompt for VS'
// navigate to this folder with 'cd' for 'change directory'
// use the command 'g++ filename.cpp' (in this case, it's 'main.cpp)
// and then type 'filename' to run the .exe (in this case, it's main)
#include <iostream> // in out stream, for sending text to the console.
#include <string>   // for playerName

using namespace std; // so we don't have to type "std::" all the time.

    // here is where we start the program
int main(){
    // variables declared at the top is best practice.
    string playerName; //variables use camelCase

    // ask the player for their name
    cout << "what is your name, player? ";

    cin>> playerName;
    //greet the player
    cout << "Hello" <<playerName << "." << endl;

    // user Control+slash to comment out lines.

    //cout << "hello world" << endl;  // cout = console out, endl = end line

    return 0;   // end the program

}cd
