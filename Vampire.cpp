#include "Vampire.h"

Vampire::Vampire(const char *m_name) : Player(

const char *m_name
),m_force(10), m_loot(2), m_damage(10) {
}


void Vampire::applyEncounter(Player &player) const {
    if (player.getAttackStrength() >= m_force) {
        player.addCoins(m_loot);
        player.levelUp();

        /// printBattleResult(true);
    } else {
        player.damage(m_damage);
        /// printBattleResult(false);
    }
}

void printInfo() const {
    printMonsterDetails(std, m_force, m_damage, m_loot, false);
}

Vampire *clone() const {
    return new Vampire(m_name);
}