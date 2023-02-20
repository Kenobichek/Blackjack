#pragma once

#include "Deck.h"
#include "AbstractPlayer.h"

class Game;

#include "PlayerInterface.h"
#include <vector>
#include <memory>

class Game
{
public:
	Game();
	void cardsDistribution(const int numberCards);
	bool checkGameIsOver() const;
	void dealerMove();

private:
	void playersCardsDistribution(const int numberCards);
	void dealerCardsDistribution(const int numberCards);
	void findWinner() const; 
	void resetPlayerCharacteristic();

	int numberPlayers = 1;

	std::shared_ptr<Deck> deck;
	std::vector<std::shared_ptr<AbstractPlayer>> players;
	std::vector<std::shared_ptr<PlayerInterface>> playerInterface;
};