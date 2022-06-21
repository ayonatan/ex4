#include "Player.h"

Player::Player(std::string name) :
        m_name(name),
        m_level(1),
        m_force(INITIAL_FORCE),
        m_HP(MAX_HP),
        m_coins(INITIAL_COINS) {}

std::ostream& operator<<(std::ostream& os, const Player &player)
{
    player.printInfo();
    return os;
}

void Player::levelUp()
{
    if (m_level < 10) 
    {
        m_level++;
    }
}

int Player::getLevel() const
{
    return m_level;
}

int Player::getHP() const
{
    return m_HP;
}

int Player::getCoins() const
{
    return m_coins;
}

void Player::buff(int pointsToAdd)
{
    if (pointsToAdd > 0) {
        m_force += pointsToAdd;
    }
}


void Player::heal(int pointsToHeal)
{
    if (pointsToHeal > 0) {
        if (m_HP + pointsToHeal < MAX_HP) {
            m_HP += pointsToHeal;
        } else {
            m_HP = MAX_HP;
        }
    }
}

void Player::damage(int damagePoints)
{
    if (damagePoints > 0) {
        if (damagePoints < 0) {
            return;
        }
        if (m_HP - damagePoints > 0) {
            m_HP -= damagePoints;
        } else {
            m_HP = 0;
        }
    }
}

bool Player::isKnockedOut()const
{
    if (m_HP <= 0) {
        return true;
    }
    return false;
}

void Player::addCoins(int coinsToAdd)
{
    if (coinsToAdd > 0) {
        m_coins += coinsToAdd;
    }
}

bool Player::pay(int coinsToPay)
{
    if (coinsToPay > 0) 
    {
        if (m_coins - coinsToPay < 0) 
        {
            return false;
        }
        m_coins -= coinsToPay;
        return true;
    }
    return true;
}

int Player::getAttackStrength()const
{
    return m_level + m_force;
}

const std::string Player::getName()const
{
    return m_name;
}