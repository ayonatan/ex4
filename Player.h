#ifndef MTM_HW4_PLAYER_H
#define MTM_HW4_PLAYER_H

#include<string>
#include "utilities.h"

const int INITIAL_FORCE = 5;
const int INITIAL_COINS = 10;
const int MAX_HP = 100;

class Player {
protected:
    std::string m_name;
    int m_level;
    int m_force;
    int m_HP;
    int m_coins;

public:
    /*
     * C'tor Player:
     *
     * @param m_name - The name of the player.
     * @param m_maxHP - max HP for the player.
     * @param force - the starting force rate.
     * @result
     *      An instance of Player
    */
    explicit Player(const char* m_name);

    Player(const Player &player) = delete;

    Player &operator=(const Player &player) = delete;

    virtual ~Player() = default;

    /*
     *  prints the player's attributes
     *
     *  @return
     *          void
     */
    void printInfo() const;

    /*
    *  promotes the player to the next level, unless its max level
    *
    *  @return
    *          void
    */
    void levelUp();

    /*
    *  return player's level
    *
    *  @return
    *          player's level - int
    */
    int getLevel() const;

    /*
    *  add points to the player's force
    *
    *  @return
    *          void
    */
    void buff(int pointsToAdd);

    /*
    *  heals the player according to pointsToHeal
    *
    *  @return
    *          void
    */
    virtual void heal(int pointsToHeal);

    /*
    *  reduces damagePoints to the player's (not less than 0)
    *
    *  @return
    *          void
    */
    void damage(int damagePoints);


    /*
    *  checks id player has lost
    *
    *  @return
    *          true - if player has 0 HP
    *          false - Player's HP >0
    */
    bool isKnockedOut() const;

    /*
    *  add coins to the player
    *
    *  @return
    *          void
    */
    virtual void addCoins(int coinsToAdd);

    /*
    *  pay the coins if player has enough money
    *
    *  @return
    *          true - payment went successfully , false otherwise
    */
    bool pay(int coinsToPay);

    /*
    *  return Strength, calculated according to force and level
    *
    *  @return
    *          player Strength attribute - int
    */
    virtual int getAttackStrength() const;
};

#endif //MTM_HW2_PLAYER_H