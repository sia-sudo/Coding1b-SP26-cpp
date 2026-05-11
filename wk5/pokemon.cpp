// classes assignment

// pokemon assignment

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class critter {
private:
    string name;
    int health;
    int damage;
    int hunger;
    bool alive;

public:

    // constructor
    critter(string givenName, int givenHealth, int givenDamage) {
        name = givenName;
        health = givenHealth;
        damage = givenDamage;
        hunger = 0;
        alive = true;
    }

    // default constructor
    critter() {
        name = "blob";
        health = 50;
        damage = 5;
        hunger = 0;
        alive = true;
    }

    // status function
    void listen() {
        cout << "\n===== STATUS =====\n";
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Damage: " << damage << endl;
        cout << "Hunger: " << hunger << endl;

        if(alive) {
            cout << "Status: Alive\n";
        }
        else {
            cout << "Status: Defeated\n";
        }

        cout << "==================\n";
    }

    // feed function
    void feed() {

        hunger -= 3;

        if(hunger < 0) {
            hunger = 0;
        }

        cout << name << " has been fed.\n";
        cout << "Hunger is now " << hunger << ".\n";
    }

    // train function
    void train() {

        if(hunger > 10) {
            cout << name << " is too hungry to train.\n";
            return;
        }

        if(hunger > 5) {
            cout << name << " looks hungry...\n";
        }

        hunger++;

        int randomNum = rand() % 2;

        if(randomNum == 0) {
            health += 10;
            cout << name << "'s health increased.\n";
        }
        else {
            damage += 2;
            cout << name << "'s damage increased.\n";
        }
    }

    // battle function
    void battle() {

        if(hunger > 10) {
            cout << name << " is too hungry to battle.\n";
            return;
        }

        if(hunger > 5) {
            cout << name << " looks hungry...\n";
        }

        hunger++;

        int enemyHealth = 40;

        cout << "\nA wild enemy appeared!\n";

        while(enemyHealth > 0 && health > 0) {

            cout << "\n1. Attack\n";
            cout << "2. Heal\n";
            cout << "3. Run Away\n";

            int choice;
            cin >> choice;

            // attack
            if(choice == 1) {

                enemyHealth -= damage;

                cout << name << " attacks!\n";
                cout << "Enemy health: " << enemyHealth << endl;

                // enemy attacks back
                if(enemyHealth > 0) {

                    health -= 8;

                    cout << "Enemy attacks back!\n";
                    cout << name << "'s health: " << health << endl;
                }
            }

            // heal
            else if(choice == 2) {

                health += 10;

                cout << name << " healed!\n";

                // enemy attacks while healing
                health -= 5;

                cout << "Enemy attacks while healing!\n";
                cout << name << "'s health: " << health << endl;
            }

            // run away
            else if(choice == 3) {

                cout << name << " ran away!\n";
                return;
            }

            else {
                cout << "Invalid choice.\n";
            }

            // lose condition
            if(health <= 0) {

                health = 0;
                alive = false;

                cout << name << " has been defeated...\n";
            }
        }

        // win condition
        if(enemyHealth <= 0) {
            cout << "Enemy defeated!\n";
        }
    }

    // setters
    void setName(string givenName) {
        name = givenName;
    }

    void setHealth(int givenHealth) {

        if(givenHealth < 0) {
            health = 0;
        }
        else {
            health = givenHealth;
        }
    }

    void setDamage(int givenDamage) {
        damage = givenDamage;
    }

    void setHunger(int givenHunger) {
        hunger = givenHunger;
    }

    // getters
    string getName() {
        return name;
    }

    int getHealth() {
        return health;
    }

    int getDamage() {
        return damage;
    }

    int getHunger() {
        return hunger;
    }

    bool getAlive() {
        return alive;
    }
};

int main() {

    srand(time(0));

    vector<string> names;
    string temp;

    // open text file
    ifstream file("names.txt");

    // read names into vector
    while(getline(file, temp)) {
        names.push_back(temp);
    }

    file.close();

    // make sure file worked
    if(names.size() == 0) {
        cout << "Could not read names.txt\n";
        return 1;
    }

    // random name
    int randomIndex = rand() % names.size();

    string randomName = names[randomIndex];

    cout << "Your critter's name is " << randomName << "!\n";

    // create critter
    critter pet(randomName, 100, 10);

    int choice = 0;

    while(choice != 5 && pet.getAlive()) {

        cout << "\n===== MENU ===== (Enter a number!!!)\n";
        cout << "1. Feed\n";
        cout << "2. Train\n";
        cout << "3. Listen\n";
        cout << "4. Battle\n";
        cout << "5. Quit\n";

        cin >> choice;


        // fixing error
        if(cin.fail()) {

        cin.clear();              
        cin.ignore(1000, '\n');   

        cout << "Please enter a number.\n";

        continue;
        }

        if(choice == 1) {
            pet.feed();
        }

        else if(choice == 2) {
            pet.train();
        }

        else if(choice == 3) {
            pet.listen();
        }

        else if(choice == 4) {
            pet.battle();
        }

        else if(choice == 5) {
            cout << "Goodbye!\n";
        }

        else {
            cout << "Invalid option.\n";
        }
    }

    return 0;
}