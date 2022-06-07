#ifndef MTM_HW4_HEALTH_POINTS_H
#define MTM_HW4_HEALTH_POINTS_H

#include <iostream>
#include <fstream>

const int MAX_HP_DEFAULT = 100;

class HealthPoints
{
public:
    HealthPoints(int max_hp = MAX_HP_DEFAULT);

    HealthPoints(const HealthPoints &otherHp) = default;

    HealthPoints &operator=(const HealthPoints &otherHp) = default;

    ~HealthPoints() = default;

    HealthPoints &operator+=(const int hp);

    HealthPoints &operator-=(const int hp);

    class InvalidArgument {};


private:
    int m_maxHp;
    int m_currentHp;

    friend std::ostream &operator<<(std::ostream &, const HealthPoints &hp); //use: ...<< hp ...

    friend bool operator<=(const HealthPoints &hp1, const HealthPoints &hp2); //use: hp1 <= hp2
};

HealthPoints operator+(const int hp, const HealthPoints &otherHp); //use: 7+hp

HealthPoints operator+(const HealthPoints &otherHp, const int hp); //use: hp+7

HealthPoints operator-(const HealthPoints &otherHp, const int hp); //use: hp -7

bool operator==(const HealthPoints &hp1, const HealthPoints &hp2); //use: hp1 == hp2

bool operator!=(const HealthPoints &hp1, const HealthPoints &hp2); //use: hp1 != hp2

bool operator<(const HealthPoints &hp1, const HealthPoints &hp2); //use: hp1 < hp2

bool operator>(const HealthPoints &hp1, const HealthPoints &hp2); //use: hp1 > hp2

bool operator>=(const HealthPoints &hp1, const HealthPoints &hp2); //use: hp1 >= hp2

#endif