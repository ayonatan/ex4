//
// Created by yonat on 06/06/2022.
//

#include "Fighter.h"
int getAttackStrength() const override
{
    return (2 * m_force) + m_level;
}
