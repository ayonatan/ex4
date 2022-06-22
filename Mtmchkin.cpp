#include "Mtmchkin.h"

bool static isNameValid(const std::string playerName) {
    int length = playerName.size();
    if (length > MAX_NAME_SIZE) {
        return false;
    }
    for (int i = 0; i < length; i++) {
        if (!((playerName.at(i) >= 'a' && playerName.at(i) <= 'z') || (playerName.at(i) >= 'A' && playerName.at(i) <= 'Z'))) {
            return false;
        }
    }
    return true;
}

void static initializePlayers(deque<unique_ptr<Player>> &currentPlayersQueue) {
    printEnterTeamSizeMessage();
    std::string teamSize;
    int teamSizeInt;
    std::cin >> teamSize;
    do {
        try {
            std::stoi(teamSize, nullptr, 10);
        }
        catch (std::invalid_argument &e) {
            printInvalidInput();
            continue;
        }
        teamSizeInt = std::stoi(teamSize, nullptr, 10);
        if (teamSizeInt > MAX_TEAM_SIZE || teamSizeInt < MIN_TEAM_SIZE) {
            printInvalidInput();
            continue;
        }
        break;
    } while (std::cin >> teamSize);
////////////////////////
    std::string playerName, playerClass;
    bool isCorrectFormat = false;
    for (int i = 0; i < teamSizeInt; i++) {
        isCorrectFormat=false;
        printInsertPlayerMessage();
        while (!isCorrectFormat) {
            std::cin >> playerName;
            if (!isNameValid(playerName)) {
                printInvalidName();
            } else {
                isCorrectFormat = true;
            }
        }
        isCorrectFormat = false;
        while (!isCorrectFormat) {
            std::cin >> playerClass;
            if (playerClass == "Wizard") 
            {
                currentPlayersQueue.push_back(unique_ptr<Wizard>(new Wizard(playerName)));
                isCorrectFormat = true;
            } 
            else if (playerClass == "Fighter") 
            {
                currentPlayersQueue.push_back(unique_ptr<Fighter>(new Fighter(playerName)));
                isCorrectFormat = true;
            } 
            else if (playerClass == "Rogue") 
            {
                currentPlayersQueue.push_back(unique_ptr<Rogue>(new Rogue(playerName)));
                isCorrectFormat = true;
            } 
            else 
            {
                printInvalidClass();
            }
        }
    }
}

Mtmchkin::Mtmchkin(const std::string fileName) : m_numOfRounds(0)
{
    printStartGameMessage();
    ifstream source(fileName);
    if (!source) 
    {
        throw DeckFileNotFound();
    }
    int numLine = 0;
    std::string cardName;
    while (std::getline(source, cardName)) 
    {
        numLine++;
        if (cardName == "Fairy") 
        {
            m_cardsDeck.push_back(unique_ptr<Fairy>(new Fairy()));
        }
        else if (cardName == "Goblin") 
        {
            m_cardsDeck.push_back(unique_ptr<Goblin>(new Goblin()));
        }
        else if (cardName == "Vampire") 
        {
            m_cardsDeck.push_back(unique_ptr<Vampire>(new Vampire()));
        }
        else if (cardName == "Barfight") 
        {
            m_cardsDeck.push_back(unique_ptr<Barfight>(new Barfight()));
        }
        else if (cardName == "Dragon")
        {
            m_cardsDeck.push_back(unique_ptr<Dragon>(new Dragon()));
        }
        else if (cardName == "Treasure") 
        {
            m_cardsDeck.push_back(unique_ptr<Treasure>(new Treasure()));
        }
        else if (cardName == "Merchant") 
        {
            m_cardsDeck.push_back(unique_ptr<Merchant>(new Merchant()));
        } 
        else if (cardName == "Pitfall") 
        {
            m_cardsDeck.push_back(unique_ptr<Pitfall>(new Pitfall()));
        }
        else
        {
            throw DeckFileFormatError(numLine);
        }
    }
    if (m_cardsDeck.size() < 5) 
    {
        throw DeckFileInvalidSize();
    }
    initializePlayers(m_currentPlayersQueue);
}

void Mtmchkin::playRound() {
    int queueSize = m_currentPlayersQueue.size();
    printRoundStartMessage(m_numOfRounds + 1);
    for (int i = 0; i < queueSize; i++) {
        printTurnStartMessage(m_currentPlayersQueue.front()->getName());
        unique_ptr<Card> currentCard = m_cardsDeck.front()->clone();
        unique_ptr<Player> currentPlayer = m_currentPlayersQueue.front()->clone();
        m_cardsDeck.pop_front();
        m_currentPlayersQueue.pop_front();
        currentCard->applyEncounter(*currentPlayer);
        m_cardsDeck.push_back(std::move(currentCard));
        if (currentPlayer->getLevel() == 10) {
            m_winnersDeck.push_back(std::move(currentPlayer));
        } else if (currentPlayer->getHP() == 0) {
            m_losersDeck.push_front(std::move(currentPlayer));
        } else {
            m_currentPlayersQueue.push_back(std::move(currentPlayer));
        }
        if (this->isGameOver()) {
            printGameEndMessage();
            return;
        }
    }
    m_numOfRounds++;
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    int rank = 0;
    for (const unique_ptr<Player> &player: m_winnersDeck) {
        printPlayerLeaderBoard(++rank, *player);
    }
    for (const unique_ptr<Player> &player: m_currentPlayersQueue) {
        printPlayerLeaderBoard(++rank, *player);
    }
    for (const unique_ptr<Player> &player: m_losersDeck) {
        printPlayerLeaderBoard(++rank, *player);
    }
}

bool Mtmchkin::isGameOver() const {
    return m_currentPlayersQueue.empty();
}

int Mtmchkin::getNumberOfRounds() const {
    return m_numOfRounds;
}