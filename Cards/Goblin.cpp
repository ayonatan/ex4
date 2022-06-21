#include "Goblin.h"
#include "../utilities.h"

Goblin::Goblin() : Card("Goblin"), m_force(6), m_loot(2), m_damage(10) {}

void Goblin::applyEncounter(Player &player) const {
    if (player.getAttackStrength() >= m_force) {
        player.addCoins(m_loot);
        player.levelUp();

        printWinBattle(player.getName(),"Goblin");
    } 
    else 
    {
        player.damage(m_damage);
        printLossBattle(player.getName(),"Goblin");
    }
}


void Goblin::printInfo() const {
    printMonsterDetails(std::cout, m_force, m_damage, m_loot, false);
}

std::unique_ptr<Card> Goblin::clone() const {
    return std::unique_ptr<Goblin>(new Goblin(*this));
}
