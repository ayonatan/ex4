//
// Created by yonat on 06/06/2022.
//

#include "Wizard.h"
void heal(int pointsToHeal)override
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