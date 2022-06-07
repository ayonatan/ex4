#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :
        m_player(playerName),
        m_cards_array(new Card[numOfCards]),
        m_num_of_cards(numOfCards),
        m_game_status(GameStatus::MidGame),
        m_round(0)
{
    for(int i = 0; i < numOfCards; i++)
    {
        m_cards_array[i] = cardsArray[i];
    }
}

Mtmchkin::~Mtmchkin()
{
    delete[] m_cards_array;
}

Mtmchkin::Mtmchkin(const Mtmchkin &game):
        m_player(game.m_player),
        m_cards_array(new Card[game.m_num_of_cards]),
        m_num_of_cards(game.m_num_of_cards),
        m_game_status(game.m_game_status),
        m_round(game.m_round)
{
    for(int i = 0; i < m_num_of_cards; i++)
    {
        m_cards_array[i] = game.m_cards_array[i];
    }
}

Mtmchkin& Mtmchkin::operator=(const Mtmchkin &game)
{
    if (this == &game)
    {
        return *this;
    }
    m_player = game.m_player;
    delete[] m_cards_array;
    m_cards_array = new Card[game.m_num_of_cards];
    for(int i = 0; i < m_num_of_cards; i++)
    {
        m_cards_array[i] = game.m_cards_array[i];
    }
    m_num_of_cards = game.m_num_of_cards;
    m_game_status = game.m_game_status;
    m_round=game.m_round;
    return *this;
}

void Mtmchkin::playNextCard()
{
    if (m_game_status != GameStatus::MidGame)
    {
        return;
    }
    m_cards_array[m_round].printInfo();
    m_cards_array[m_round].applyEncounter(m_player);
    m_player.printInfo();
    m_round++;
    if (m_round == m_num_of_cards)
    {
        m_round = 0;
    }
    if (m_player.getLevel() == 10)
    {
        m_game_status=GameStatus::Win;
        return;
    }
    if (m_player.isKnockedOut())
    {
        m_game_status=GameStatus::Loss;
        return;
    }
}

GameStatus Mtmchkin::getGameStatus()const
{
    return m_game_status;
}

bool Mtmchkin::isOver()const
{
    return m_game_status!=GameStatus::MidGame;
}