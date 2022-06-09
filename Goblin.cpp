#include "Goblin.h"

Goblin::Goblin(const char* m_name) : Player(const char* m_name),m_force(6), m_loot(2), m_damage(10) {}


void Goblin::applyEncounter(Player &player) const {
    if (player.getAttackStrength() >= m_force) {
        player.addCoins(m_loot);
        player.levelUp();

      ///  printBattleResult(true);
    } else {
        player.damage(m_damage);
      ///  printBattleResult(false);
    }
}

std::ostream &operator<<(std::ostream &os, const Goblin &goblin) {
    printMonsterDetails(std, m_force, m_damage, m_loot, false);
    return os;
}