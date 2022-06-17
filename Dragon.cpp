#include "Dragon.h"

Dragon::Dragon() : Card("Dragon"), m_force(25), m_loot(1000), m_damage(100) {}

void printInfo() const {
    printMonsterDetails(std, m_force, m_damage, m_loot, true);
}

void Dragon::applyEncounter(Player &player) const 
{
    if (player.getAttackStrength() >= m_force) 
    {
        player.addCoins(m_loot);
        player.levelUp();
        printWinBattle(player.getName(), "Dragon");
    } 
    else 
    {
        player.damage(m_damage);
        printLossBattle(player.getName(), "Dragon");
    }
}

std::unique_ptr<Dragon> clone() const {
    return std::unique_ptr<Dragon>(new Dragon(m_name));
}
