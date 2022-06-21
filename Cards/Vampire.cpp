#include "Vampire.h"
#include "../utilities.h"

Vampire::Vampire() : Card("Vampire"), m_force(10), m_loot(2), m_damage(10) {}


void Vampire::applyEncounter(Player &player) const {
    if (player.getAttackStrength() >= m_force) {
        player.addCoins(m_loot);
        player.levelUp();
        printWinBattle(player.getName(), "Vampire");
    } 
    else 
    {
        player.damage(m_damage);
        printLossBattle(player.getName(), "Vampire");
    }
}

void Vampire::printInfo() const {
    printMonsterDetails(std::cout, m_force, m_damage, m_loot, false);
}

std::unique_ptr<Card> Vampire::clone() const {
    return std::unique_ptr<Vampire>(new Vampire(*this));
}