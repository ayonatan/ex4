//
// Created by yonat on 06/06/2022.
//

#include "Rouge.h"

void addCoins(int coinsToAdd)override
{
    if (coinsToAdd > 0) 
    {
        m_coins += 2*coinsToAdd;
    }
    else
    {
        //throw?
    }
}