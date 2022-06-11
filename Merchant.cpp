#include "Merchant.h"

void Merchant::applyEncounter(Player &player) const {
    // bool flag = true;
    int payIndex;
    while (true) {
        printMerchantInitialMessageForInteractiveEncounter(std, player.getName(), player.getCoins());
        // can we use magic numbers
        if (std::cin >> payIndex != 0 && std::cin >> payIndex != 1 && std::cin >> payIndex != 2) {
            printInvalidInput();
            continue;
        }
        if (!player.pay()) {
            return;
            printMerchantSummary(std,player.getName(),player.getCoins());
        }
    }
    printMerchantSummary(std,player.getName(),player.getCoins());
}
void printInfo() const {
    printCardDetails(std::cout,"Merchant");
}

Merchant *clone() const {
    return new Merchant(m_name);
}