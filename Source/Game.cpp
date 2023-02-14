#include "Game.h"
#include "Player.h"
#include "Dealer.h"
#include <memory>
#include <iostream>

Game::Game()
{
	players.push_back(std::make_shared<Dealer>());

	for (int i = 0; i < numberPlayers; i++)
	{
		std::shared_ptr<Player> newPlayer = std::make_shared<Player>();
		players.push_back(newPlayer);
		playerInterface.push_back(std::make_shared<PlayerInterface>());
		playerInterface[i]->setPlayer(newPlayer);		
		playerInterface[i]->setGame(this);
	}

	deck = std::make_shared<Deck>();
	deck->shuffler();
}

void Game::cardsDistribution(const int numberCards)
{
	for (int i = 0; i < players.size(); i++)
	{
		for (int j = 0; j < numberCards; j++)
		{
			std::shared_ptr<Card> card = deck->getCard();
			std::cout << card->getValue() << " ";
			//players[i]->increasePoints(card->getValue());
		}
	}
}
