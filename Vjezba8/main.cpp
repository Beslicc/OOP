#include <iostream>
#include <vector>
#include "Warrior.h"
#include "Mage.h"
#include "Goblin.h"
#include "Dragon.h"

using namespace std;

int main() {
    cout << "=== KREIRANJE LIKOVA ===\n";

    Warrior* conan = new Warrior("Conan");
    Mage* merlin = new Mage("Merlin");
    Goblin* gobby = new Goblin("Gobby");
    Goblin* sneaky = new Goblin("Sneaky");
    Dragon* dragon = new Dragon("Dragon");

    cout << "\n";

    vector<GameCharacter*> characters;
    characters.push_back(conan);
    characters.push_back(merlin);
    characters.push_back(gobby);
    characters.push_back(sneaky);
    characters.push_back(dragon);

    cout << "=== SIMULACIJA BORBE ===\n\n";

    cout << "1. Conan napada Gobby:\n";
    conan->attackEnemy(gobby);
    cout << "---\n";

    cout << "2. Merlin napada Sneaky:\n";
    merlin->attackEnemy(sneaky);
    cout << "---\n";

    cout << "3. Gobby napada Conana:\n";
    gobby->attackPlayer(conan);
    cout << "---\n";

    cout << "4. Merlin napada Gobby:\n";
    merlin->attackEnemy(gobby);
    cout << "---\n";

    cout << "5. Dragon napada Merlina:\n";
    dragon->attackPlayer(merlin);
    cout << "---\n";

    cout << "6. Merlin napada Gobby:\n";
    merlin->attackEnemy(gobby);
    cout << "---\n";

    cout << "7. Conan napada Dragona:\n";
    conan->attackEnemy(dragon);
    cout << "---\n";

    cout << "8. Merlin napada Dragona:\n";
    merlin->attackEnemy(dragon);
    cout << "---\n";

    cout << "\n=== STATUS NAKON BORBE ===\n";
    for (auto character : characters) {
        character->displayStatus();
    }

    cout << "\n=== SPECIJALNE SPOSOBNOSTI ===\n";
    for (auto character : characters) {
        if (character->isAlive()) {
            cout << character->getName() << ": ";
            character->specialAbility();
        }
    }

    cout << "\n=== LIK S NAJVIŠE HEALTHA ===\n";
    GameCharacter* healthiest = nullptr;
    int maxHealth = -1;

    for (auto character : characters) {
        if (character->isAlive() && character->getHealth() > maxHealth) {
            maxHealth = character->getHealth();
            healthiest = character;
        }
    }

    if (healthiest) {
        cout << healthiest->getName() << " ima najvise healtha: "
            << maxHealth << "\n";
    }

    cout << "\n=== STATISTIKA ===\n";
    cout << "Preživjeli likovi:\n";
    for (auto character : characters) {
        if (character->isAlive()) {
            cout << "- " << character->getName()
                << " (" << character->getHealth() << " health)\n";
        }
        else {
            cout << "- " << character->getName() << " (Mrtav)\n";
        }
    }

    cout << "\n=== OSLOBADJANJE MEMORIJE ===\n";
    for (auto character : characters) {
        delete character;
    }
    characters.clear();
    return 0;
}