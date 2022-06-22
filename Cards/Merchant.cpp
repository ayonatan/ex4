#include "Merchant.h"
#include "../utilities.h"

Merchant::Merchant() : Card("Merchant"){}

void Merchant::applyEncounter(Player &player) const 
{
    int payIndex = 0;
    std::string inputLine;
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    while (true) 
    {
        std::getline(std::cin,inputLine);
        try
        {
            payIndex = std::stoi(inputLine);
        }
        catch(const std::exception& e)
        {
            printInvalidInput();
            continue;
        }
        
      // if (payIndex != DONT_BUY && payIndex != BUY_HP && payIndex != BUY_FORCE)
       if (payIndex<0 || payIndex>2)
        {
            printInvalidInput();
            continue;
        }
        break;
    }

    if(payIndex == BUY_HP)
    {
        if(player.pay(5))
        {
            player.heal(1);
            printMerchantSummary(std::cout, player.getName(), payIndex, 5);
        }
        else
        {
            printMerchantInsufficientCoins(std::cout);
        }
        return;
    }

    if(payIndex == BUY_FORCE)
    {
        if(player.pay(10))
        {
            player.buff(1);
            printMerchantSummary(std::cout, player.getName(), payIndex, 10);
        }
        else
        {
            printMerchantInsufficientCoins(std::cout);
        }
        return;
    }
    
    printMerchantSummary(std::cout, player.getName(), payIndex, 0);
}

void Merchant::printInfo() const {
    printCardDetails(std::cout, "Merchant");
}

std::unique_ptr<Card> Merchant::clone() const {
    return std::unique_ptr<Merchant>(new Merchant());
}
