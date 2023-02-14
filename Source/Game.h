#pragma once

#include "Deck.h"
#include "AbstractPlayer.h"

class Game;

#include "PlayerInterface.h"
#include <vector>

class Game
{
public:
	Game();
	void cardsDistribution(const int numberCards);

private:
	int numberPlayers = 1;
	std::shared_ptr<Deck> deck;
	std::vector<std::shared_ptr<AbstractPlayer>> players;
	std::vector<std::shared_ptr<PlayerInterface>> playerInterface;
};