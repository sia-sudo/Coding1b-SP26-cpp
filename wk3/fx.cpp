// stephanie coding 1b
// functions

/*
    functions
        returnType functionsName (input parameters) {code}
    

*/

#include <iostream>
#include <string>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
#include <vector>

using namespace std;

// declaring and defining a new function
// the return type is void, which means it returns NOTHING
// the name of the functions is "sayHello"
// the input parameters go in the parenthesis... this function doesn't have any.
// then the code goes between {curly braces}
void sayHello() {
    cout << "Hello\n";
}

void doAddition(int firstNum, int secondNum) {
    cout << "our first number is " << firstNum << ".\n";
    cout << "our first number is " << secondNum << ".\n";
    cout << "together they make " << firstNum + secondNum << ".\n";
}

// dont forget to include <stdlib> and <ctime>
// this functions will return an interger
int dieRoll(int sides = 6) {
    return rand() % sides + 1; // add!!!!
}

// create a function
// return type is bool
// name is askYesNo
// no input parameters (for now)

bool askYesNo(string question = "do you want to keep playing?") {
    while (true) {
        cout << question << " ('yes'/'no')\n";
        string input;
        getline (cin, input);

        if(input == "yes") {
            return true;
        }
        else if(input == "no") {
            return false;
        }
        else {
            cout << "i did not understand. Please type 'yes' or 'no'.\n";
        }
    }
}

// variable scope
// global variables
// passing by reference
// #include <vector>

void showVec(vector<string> vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
}

// create a reference with an ampersand next to the variable type.
// int& number; or string& name;

// references let us edit the original.
void addStringToVec(vector<string>& vec) {
    cout << "What name would you like to add?\n";
    string input;
    getline(cin, input);

    vec.push_back(input);

    // showVec(vec);           // the added name exist here
}

int main() {
    srand(time(0));         // seed the random number generator
    vector<string> names = {"finn", "jake", "Marceline", "BMO", "princess B"};

    // calling the showVec() functions and and sending it our vector of names.
    showVec(names);

    addStringToVec(names);  // try to add a string to our names vector.

    showVec(names);         // notice that it DOESNT add the string to our names vector.

    cout << "finally, functions\n";

    sayHello();

    doAddition(14, 3);
    
    cout << "lets roll the dice! our first number is " << dieRoll(6) << "./n";

    doAddition(dieRoll(20), dieRoll(20));
    doAddition(dieRoll(), dieRoll(222));

    if(askYesNo()) {
        cout << "lets start the next level\n";
    }
    else {
        cout << "thanks for playing\n";
        return 0;
    }
    if(askYesNo("do you like watermelon?")) {
        cout << "They're good\n";
    }
    else {
        cout << "ok\n";
    }

    return 0;
}