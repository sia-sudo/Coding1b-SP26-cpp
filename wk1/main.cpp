// Stephanie Coding 1 Spring 2026
// Variables and logic

// compile with the developer Command Prompt
//'cl /EHsc main.cpp' is what you type to compile
// 'main' or 'main.exe' to run the program.

#include <iostream>
using namespace std;

int main() {
    cout << "Let's learn about variables and logic!\n";

    // declaring and defining variables
    int playerAge = -1;
    string playerName=  "Darth Vader";
    float happinessPercent = 0.61f;
    bool keepPlaying = true;

    // just like a branch in unreal engine
    if(playerAge == -1){
        cout << "How old are you?\n";
        cin >> playerAge;

        if(playerAge <= 12){
            cout << "I'm sorry, this game is for grown ups!\n";
            return 0;   //quit the game early
        }
        else{
            cout << "Wow, " << playerAge << " years, that is a long time!\n";
        }   

        if(playerName == "Darth Vader"){
            cout << "is your name " << playerName << "?\n";
            string input; 
            cin >> input;
            if(input == "yes"){
                cout << "Well, that's convenient!\n";

            }
            else {
                cout << "What is your name?\n";
                cin >> playerName;
            }

            cout << "Hello" << playerName << ".\n";

        } //end of if(playerAge)

        // the AND operator '88 requires that all tests are true
        if(playerAge == 37 && playerName == 'Brian'){
            debug = true;
            cout << "Hello creator. Debug mode is ON.\n";

        } //end

        if(debug) {
            cout << "\n\tDEBUG Mode\n\n";
            cout << "playerAge = " << playerAge << ".\n";
            cout << "playerName = " << playerName << ".\n";
            cout << "happinessPercent = " << hapinessPercent << ".\n";
            cout << "keepPlaying = " << keepPlaying << ".\n";
        }
    }   

    return 0;
}