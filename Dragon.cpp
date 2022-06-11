#include "Dragon.h"

Dragon::Dragon(std::string name) : Player(name), m_force(25), m_loot(1000), m_damage(100) {}

void printInfo() const {
    printMonsterDetails(std, m_force, m_damage, m_loot, true);
}

void Dragon::applyEncounter(Player &player) const {
    if (player.getAttackStrength() >= m_force) {
        player.addCoins(m_loot);
        player.levelUp();

        /// printBattleResult(true);
    } else {
        player.damage(m_damage);
        /// printBattleResult(false);
    }
}

Dragon *clone() const {
    return new Dragon(m_name);
}