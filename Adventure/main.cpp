#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Function to roll a die with 6 sides
int RollDie(int sides = 6) {
    return rand() % sides + 1;
}

// Function to ask a yes/no question and return the player's input
string askYesNo(string question) {
    string response;
    cout << question << " (yes/no): ";
    cin >> response;
    return response;
}

int main() {
    srand(time(0)); // Seed the random number generator

    int health = 10; // Starting health
    int gold = 0; // Starting gold
    int turns = 0; // Number of turns

    do {
        turns++;

        // Ask the player if they want to go adventuring
        string response = askYesNo("Do you want to go adventuring?");

        if (response == "yes") {
            // Encounter an orc
            int orc_attack = RollDie(); // Orc's attack
            int player_block = RollDie(); // Player's block

            cout << "You encountered an orc! ";
            cout << "The orc's attack roll: " << orc_attack << endl;
            cout << "Your block roll: " << player_block << endl;

            if (player_block >= orc_attack) {
                cout << "You successfully blocked the orc's attack and escaped!" << endl;
                health--; // Lose one health point
                gold += rand() % 10 + 1; // Find random amount of gold
            } else {
                cout << "You failed to block the orc's attack and took damage!" << endl;
                health -= orc_attack; // Lose health equal to orc's attack
            }

            // Check if the player is dead
            if (health <= 0) {
                break; // Exit the loop if the player is dead
            }
        } else {
            // Player decided to stop adventuring
            break; // Exit the loop
        }

    } while (true); // Continue the adventure loop indefinitely

    // Output the result
    if (health > 0) {
        cout << "You survived for " << turns << " turns and found " << gold << " gold." << endl;
        if (health < 5) {
            cout << "Your health is low. You should visit a doctor." << endl;
        }
    } else {
        cout << "You died. There are " << gold << " gold left by your body." << endl;
    }

    return 0;
}