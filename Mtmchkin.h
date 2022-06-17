#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include "Player.h"
#include "Card.h"
#include <fstream>
#include <deque>
#include <memory>

using std::ifstream;
using std::ofstream;
using std::cerr;
using std::endl;
using std::deque;
using std::unique_ptr;


class Mtmchkin {
    int m_numberOfRounds;
    deque<unique_ptr<Player>> m_winnersDeck;
    deque<unique_ptr<Player>> m_losersDeck;
    deque<unique_ptr<Card>> m_cardsDeck;
    deque<unique_ptr<Player>> m_currentPlayersQueue;
public:
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

    Mtmchkin(const Mtmchkin& mtmchkin) = delete;
    Mtmchkin& operator=(const Mtmchkin& mtmchkin) = delete;
    ~Mtmchkin() = default;
};


#endif /* MTMCHKIN_H_ */
