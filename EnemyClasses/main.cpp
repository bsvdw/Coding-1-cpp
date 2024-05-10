#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Function to roll a die with 6 sides
int RollDie(int sides = 6) {
    return rand() % sides + 1;
}

// Class representing a player
class Player {
private:
    int health;
    int gold;
public:
    Player(int startHealth = 10) : health(startHealth), gold(0) {}
    int getHealth() const { return health; }
    int getGold() const { return gold; }
    void loseHealth(int amount) { health -= amount; }
    void gainGold(int amount) { gold += amount; }
    bool isAlive() const { return health > 0; }
};

// Class representing an enemy
class Enemy {
private:
    int health;
    int attack;
public:
    Enemy(int startHealth = 5, int attackValue = 2) : health(startHealth), attack(attackValue) {}
    int getHealth() const { return health; }
    int getAttack() const { return attack; }
    void loseHealth(int amount) { health -= amount; }
    bool isAlive() const { return health > 0; }
};

// Function to ask the player whether to use a weapon or consumable
string askWeaponOrConsumable() {
    string response;
    cout << "Do you want to use a weapon or consumable? (weapon/consumable): ";
    cin >> response;
    return response;
}

// Function to simulate a battle between the player and an enemy
void battle(Player& player, Enemy& enemy) {
    int playerBlock = RollDie(); // Player's block roll
    int enemyAttack = enemy.getAttack(); // Enemy's attack

    cout << "Enemy's attack: " << enemyAttack << endl;
    cout << "Your block roll: " << playerBlock << endl;

    if (playerBlock >= enemyAttack) {
        cout << "You successfully blocked the enemy's attack!" << endl;
    } else {
        cout << "You failed to block the enemy's attack and took damage!" << endl;
        player.loseHealth(enemyAttack); // Player takes damage equal to enemy's attack
    }
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

    Player player;
    int turns = 0;

    do {
        turns++;

        // Ask the player if they want to go adventuring
        string response = askYesNo("Do you want to go adventuring?");

        if (response == "yes") {
            // Encounter an enemy
            Enemy enemy;
            cout << "You encountered an enemy!" << endl;

            // Player chooses whether to use a weapon or consumable
            string action = askWeaponOrConsumable();

            if (action == "weapon") {
                // Simulate using a weapon
                cout << "You used a weapon to defeat the enemy!" << endl;
                player.gainGold(RollDie(10)); // Find random amount of gold
            } else if (action == "consumable") {
                // Simulate using a consumable
                cout << "You used a consumable to restore your health!" << endl;
                player.loseHealth(-RollDie(5)); // Restore random amount of health
            } else {
                cout << "Invalid action. You hesitated and the enemy attacks!" << endl;
                battle(player, enemy); // Player hesitates and enemy attacks
            }

            // Check if the player is dead
            if (!player.isAlive()) {
                break; // Exit the loop if the player is dead
            }
        } else {
            // Player decided to stop adventuring
            break; // Exit the loop
        }

    } while (true); // Continue the adventure loop indefinitely

    // Output the result
    if (player.isAlive()) {
        cout << "You survived for " << turns << " turns and found " << player.getGold() << " gold." << endl;
        if (player.getHealth() < 5) {
            cout << "Your health is low. You should visit a doctor." << endl;
        }
    } else {
        cout << "You died." << endl;
    }

    return 0;
}
