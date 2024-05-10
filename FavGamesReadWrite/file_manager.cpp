#include "file_manager.h"
#include <fstream>

using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;

void load(vector<string>& favoriteGames, const string& filename) {
    ifstream file(filename);
    string game;
    while (getline(file, game)) {
        favoriteGames.push_back(game);
    }
    file.close();
}

void save(const vector<string>& favoriteGames, const string& filename) {
    ofstream file(filename);
    for (const string& game : favoriteGames) {
        file << game << std::endl;
    }
    file.close();
}