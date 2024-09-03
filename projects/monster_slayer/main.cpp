#include <iostream>
#include <cstdlib>
#include <ctime>

// Character class definition
class Character {
public:
    std::string name;
    int health;
    int maxHealth;
    int attackPower;
    int defensePower;
    int potions;

    Character(std::string name, int health, int attackPower, int defensePower, int potions)
        : name(name), health(health), maxHealth(health), attackPower(attackPower), defensePower(defensePower), potions(potions) {}

    void attack(Character& target) {
        int damage = attackPower - target.defensePower;
        if (damage < 0) damage = 0;
        target.health -= damage;
        std::cout << name << " attacks " << target.name << " for " << damage << " damage!" << std::endl;
    }

    void defend() {
        defensePower += 5;
        std::cout << name << " raises defense!" << std::endl;
    }

    void usePotion() {
        if (potions > 0) {
            health += 20;
            if (health > maxHealth) health = maxHealth;
            potions--;
            std::cout << name << " uses a potion and recovers 20 health points!" << std::endl;
        } else {
            std::cout << "No potions left!" << std::endl;
        }
    }

    bool isAlive() const {
        return health > 0;
    }
};

// Monster class derived from Character
class Monster : public Character {
public:
    Monster(std::string name, int health, int attackPower, int defensePower)
        : Character(name, health, attackPower, defensePower, 0) {}
};

// Function to display health bars
void displayHealthBar(const std::string& name, int health, int maxHealth) {
    std::cout << name << " [";
    int barWidth = 20;
    int healthBar = (health * barWidth) / maxHealth;
    for (int i = 0; i < barWidth; i++) {
        if (i < healthBar)
            std::cout << "=";
        else
            std::cout << " ";
    }
    std::cout << "] " << health << "/" << maxHealth << std::endl;
}

// Player's turn function
void playerTurn(Character& player, Monster& monster) {
    std::cout << "\nIt's " << player.name << "'s turn." << std::endl;
    std::cout << "1. Attack" << std::endl;
    std::cout << "2. Defend" << std::endl;
    std::cout << "3. Use Potion" << std::endl;
    std::cout << "Choose an action: ";

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        player.attack(monster);
        break;
    case 2:
        player.defend();
        break;
    case 3:
        player.usePotion();
        break;
    default:
        std::cout << "Invalid choice!" << std::endl;
        break;
    }
}

// Monster's turn function
void monsterTurn(Monster& monster, Character& player) {
    std::cout << "\nIt's " << monster.name << "'s turn." << std::endl;
    monster.attack(player);
}

// Main game function
int main() {
    std::srand(std::time(0));

    // Initialize player and monsters
    Character player("Hero", 100, 20, 10, 3);
    Monster monsters[] = {
        Monster("Goblin", 30, 10, 5),
        Monster("Orc", 50, 15, 7),
        Monster("Dragon", 100, 25, 10)
    };
    int numberOfMonsters = sizeof(monsters) / sizeof(monsters[0]);

    std::cout << "Welcome to the Monster Slayer Game!" << std::endl;

    // Loop through each monster
    for (int i = 0; i < numberOfMonsters; ++i) {
        Monster& currentMonster = monsters[i];
        std::cout << "\nA wild " << currentMonster.name << " appears!" << std::endl;

        // Fight loop
        while (player.isAlive() && currentMonster.isAlive()) {
            displayHealthBar(player.name, player.health, player.maxHealth);
            displayHealthBar(currentMonster.name, currentMonster.health, currentMonster.maxHealth);
            
            playerTurn(player, currentMonster);

            if (currentMonster.isAlive()) {
                monsterTurn(currentMonster, player);
            }
        }

        if (!player.isAlive()) {
            std::cout << "\n" << player.name << " has been defeated! Game Over." << std::endl;
            return 0;
        } else {
            std::cout << "\nYou defeated the " << currentMonster.name << "!" << std::endl;
        }
    }

    std::cout << "\nCongratulations! You defeated all the monsters!" << std::endl;
    return 0;
}
