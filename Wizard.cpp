//
// Created by yonat on 06/06/2022.
//

#include "Wizard.h"
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

void printInfo() const
{
    printPlayerDetails(os, m_name, "Wizard", m_level, m_force, m_HP, m_coins);
}

Wizard* clone() const
{
    return new Wizard(m_name);
}