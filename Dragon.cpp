#include "Dragon.h"

Dragon::Dragon(const char* m_name) : Player(const char* m_name),m_force(25), m_loot(1000), m_damage(100) {}


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

std::ostream &operator<<(std::ostream &os, const Goblin &goblin) {
    printMonsterDetails(std, m_force, m_damage, m_loot, true);
    return os;
}
