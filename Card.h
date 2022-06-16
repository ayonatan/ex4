#ifndef MTM_HW2_CARD_H
#define MTM_HW2_CARD_H

#include "Player.h"
#include "utilities.h"
#include <string>
#include <ostream>

/*
 *  CardType:
 *  Each card has an type:
 *  BATTLE - Battle against a monster.
 *  BUFF - Increase your player's force by 'm_force' points of CardStats.
 *  HEAL - Increase your player's HP by 'm_heal' points  of CardStats (no more than maxHP points).
 *  TREASURE - Get 'm_profit' coins of CardStats.
*/
//enum class CardType {Battle, Buff, Heal, Treasure}; // The type of the Card

class Card {
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */
    Card(std::string name) : m_cardName(name) {}


    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player &player) const = 0;


    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    virtual void printInfo() const = 0;




    /*
     * Here we are explicitly telling the compiler to use the default methods
    */

    ///check if needed
    Card(const Card &) = delete;

    virtual ~Card() {}

    ///check if needed
    Card &operator=(const Card &other) = delete;


protected:
    std::string m_cardName;
};

#endif //MTM_HW2_CARD_H
