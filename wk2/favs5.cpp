// Stephanie 
// Favorite Game Library HW
// Using Vectors, iterators, loops?, algorithms, and else statements?

#include <iostream>
#include <string>           // to make getline() work
#include <vector>           // needed for iterators
#include <algorithm>        // to sort() and to make a list

using namespace std;

int main() {

    cout << "Favorite Games Library\n";

    string input;
    vector<string> games;   // list recreated every loop?

    do {

        cout << "\nWhat would you like to do? 'add', 'edit', 'remove', 'show all', 'quit'.\n";
        cout << "Type: ";
        getline(cin, input);

        // vector
        if (input == "add") {
            cout << "Type game or 'done'.\n";
                            // word.push_back()

            while (true) {
                getline(cin, input);

                if(input == "done") break;

                games.push_back(input);
                cout << "You added a game! Add another game or 'done'.\n";
            }
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
        vector<string>::iterator iter;
        for (iter = games.begin(); iter != games.end(); iter++){
            cout << " iter " << *iter << "\n";
        }

        cout << "So far you have " << games.total() << " games\n";
    }
}