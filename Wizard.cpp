//
// Created by yonat on 06/06/2022.
//

#include "Wizard.h"

Wizard::Wizard(std::string name) : Player(name) {}

void Wizard::heal(int pointsToHeal)
{
    if (pointsToHeal > 0) 
    {
        if (m_HP + pointsToHeal < MAX_HP) 
        {
            m_HP += pointsToHeal;
        } 
        else
        {
            m_HP = m_maxHP;
        }
    }
}

void Wizard::printInfo() const
{
    printPlayerDetails(os, m_name, "Wizard", m_level, m_force, m_HP, m_coins);
}

std::unique_ptr<Wizard> Wizard::clone() const
{
    return std::unique_ptr<Wizard>(new Wizard(m_name));
}