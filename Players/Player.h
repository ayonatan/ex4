#ifndef MTM_HW4_PLAYER_H
#define MTM_HW4_PLAYER_H

#include<string>
#include <memory>

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
    Player(std::string m_name);

public:   

    Player(const Player &player) = default;

    Player &operator=(const Player &player) = default;

    virtual ~Player() = default;

    virtual std::unique_ptr<Player> clone() const = 0;

    virtual void printInfo() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Player &player);

    void levelUp();

    int getLevel() const;

    int getHP() const;

    int getCoins() const;

    /*
    *  add points to the player's force
    */
    void buff(int pointsToAdd);

    virtual void heal(int pointsToHeal);

    void damage(int damagePoints);

    bool isKnockedOut() const;

    virtual void addCoins(int coinsToAdd);

    bool pay(int coinsToPay);

    virtual int getAttackStrength() const;
    const std::string getName() const;
};

#endif //MTM_HW2_PLAYER_H
