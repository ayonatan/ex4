#include "Merchant.h"

Merchant::Merchant()
{
    m_cardName = "Merchant";
}

void Merchant::applyEncounter(Player &player) const {
    // bool flag = true;
    int payIndex;
    while (true) {
        printMerchantInitialMessageForInteractiveEncounter(std, player.getName(), player.getCoins());
        // can we use magic numbers
        std::cin >> payIndex;
        if (payIndex != 0 && payIndex != 1 && payIndex != 2) {
            printInvalidInput();
            continue;
        }
        if (!player.pay()) {
            return;
            printMerchantSummary(std, player.getName(), player.getCoins());
        }
    }
    printMerchantSummary(std, player.getName(), player.getCoins());
}

void printInfo() const {
    printCardDetails(std::cout, "Merchant");
}

Merchant *clone() const {
    return new Merchant(m_name);
}
