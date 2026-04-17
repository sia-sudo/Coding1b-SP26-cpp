// Stephanie 
// Favorite Game Library HW
// Using Vectors, iterators, loops?, algorithms, and "else"?

#include <iostream>
#include <string>           // to make getline() work
#include <vector>           // needed for iterators
#include <algorithm>        // to sort() and to make a list

using namespace std;

int main() {

    cout << "Favorite Games Library\n";

    // setup
    string input;
    vector<string> games;   // list recreated every loop?

    do {
                            // show menu
        cout << "\nWhat would you like to do? 'add', 'edit', 'remove', 'show all', 'quit'.\n";
        cout << "Type: ";
        getline(cin, input);

        // vector
        if (input == "add") {
            cout << "Type game or 'done'.\n";
                            // word.push_back()

            while (true) {
                            // allows us to get spaces between game names
                getline(cin, input);

                if(input == "done") break;
                            // adds game names to the vector
                            // adds at the end
                games.push_back(input);
                cout << "You added a game! Add another game or 'done'.\n";
            }
        }
    

        // need a vector for show all
        // 'else if' used for another comparison
        // 'else' followed if initial 'if' is false
        
        else if (input == "show all") {
            if (games.empty()) {
                cout << "It's dry in here, add games!\n";
                continue;
            }

            sort(games.begin(), games.end());

            cout << "\nYour Games\n";

                            // interator loop??
                            // iter = pointer at things and gets a value
            vector<string>::iterator iter;
            for (iter = games.begin(); iter != games.end(); iter++){
                cout << " " << *iter << "\n";
                            // *iter get value
            }

            cout << "So far you have " << games.size() << " games\n";
    
        }

                            // an array
                            // algorithms
        else if (input == "edit") {
            cout << "Type game name to make changes\n";
            getline(cin, input);

            vector<string>::iterator iter;
            iter = find(games.begin(), games.end(), input);

            if (iter !=games.end()) {
                cout << "You chose " << *iter << "\n";
                cout << "New game\n";

                string newName;
                getline(cin, newName);
                            // changes the pointer???
                *iter = newName;
                cout << "Done.\n";

            }
            else {
                cout << "You don't have it here.\n";
            }
        }

        // removing
        else if (input == "remove") {
            cout << "What game do you want to remove?\n";
            getline(cin, input);

            vector<string>::iterator iter;
            iter = find(games.begin(), games.end(), input);

            if (iter != games.end()) {
                cout << "Taking out " << *iter << "\n";

                games.erase(iter);
                cout << "Removed. \n";
            }else {
                cout << "You don't have it here.\n";
            }
        }
        
        // quit
        else if (input == "quit") {
            cout << "Please never play again! Thank you!!!\n";
            break;
        }

    } while(true);
    
    return 0;

    // vector stores data
    // loop runs program
    // input decides action
    // find() is like location
    // iterator points thing
    // *iter reads or changes thing
    // erase() removes
}