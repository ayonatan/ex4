#ifndef MTM_HW4_DRAGON_H
#define MTM_HW4_DRAGON_H

#include "Player.h"

class Dragon : public Player {
public:
    Dragon(const char* m_name);

    Dragon(const Dragon &dragon) = default;

    ~Dragon() = default override;

    operator=(const Dragon &dragon) = default;

    void printInfo() const override;

    void applyEncounter(Player &player) const override;


///private: add?


#endif //MTM_HW4_DRAGON_H
