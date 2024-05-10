#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

vector<string> favGames;

int main() {
    vector<string> favGames; // Vector to store names

    cout << "Enter names (type 'exit' to stop):\n";

    while (true) {
        string game;
        cout << "Enter a name: ";

        // Use getline to read the entire line
        getline(cin, game);

        if (game == "exit") {
            break; // Exit the loop if 'exit' is entered
        }

        favGames.push_back(game); // Add the name to the vector
    }

    // Display the list of names
    cout << "\nList of names:\n";
    for (const auto& game : favGames) {
        cout << game << "\n";
    }

    return 0;
}
