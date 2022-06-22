#include "Card.h"
#include "../utilities.h"

std::ostream& operator<<(std::ostream& os, const Card &card)
{
    card.printInfo();
    printEndOfCardDetails(std::cout);
    return os;
}