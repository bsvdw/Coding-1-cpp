#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "file_manager.h"

using namespace std;

void showMenu() {
    cout << "1. Add a favorite game\n";
    cout << "2. Edit a favorite game\n";
    cout << "3. Show favorite games\n";
    cout << "4. Clear the list of favorite games\n";
    cout << "5. Quit\n";
    cout << "Enter your choice: ";
}

int main() {
    vector<string> favoriteGames;
    const string filename = "favorite_games.txt";

    // Load favorite games from file
    load(favoriteGames, filename);

    int choice;
    string game;
    do {
        showMenu();
        while (!(cin >> choice) || choice < 1 || choice > 5) {
            cout << "Invalid choice! Please enter a number between 1 and 5: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        switch (choice) {
            case 1:
                cout << "Enter the name of the favorite game: ";
                getline(cin, game);
                favoriteGames.push_back(game);
                break;
            case 2:
                cout << "Enter the index of the game to edit: ";
                int index;
                cin >> index;
                while (cin.fail() || index < 0 || index >= favoriteGames.size()) {
                    cout << "Invalid index! Please enter a valid index: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                    cin >> index;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                cout << "Enter the new name of the game: ";
                getline(cin, game);
                favoriteGames[index] = game;
                break;
            case 3:
                cout << "Favorite games:\n";
                for (const string& favGame : favoriteGames) {
                    cout << favGame << endl;
                }
                break;
            case 4:
                favoriteGames.clear();
                cout << "Favorite games list cleared.\n";
                break;
            case 5:
                // Save favorite games to file before quitting
                save(favoriteGames, filename);
                cout << "Goodbye!\n";
                break;
        }
    } while (choice != 5);

    return 0;
}