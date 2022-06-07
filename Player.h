#ifndef MTM_HW4_PLAYER_H
#define MTM_HW4_PLAYER_H

#include<string>
#include "utilities.h"

const int DEFAULT_FORCE = 5;
const int DEFAULT_MAX_HP = 100;

class Player {
private:
    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
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
    explicit Player(const char* m_name, int m_maxHP = 100, int force = 5);

    Player(const Player &player) = default;

    ~Player() = default;

    Player &operator=(const Player &player) = default;

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
    void heal(int pointsToHeal);

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
    void addCoins(int coinsToAdd);

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
    int getAttackStrength() const;
};

#endif //MTM_HW2_PLAYER_H