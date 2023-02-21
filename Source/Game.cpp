#include "Game.h"
#include "Player.h"
#include "Dealer.h"
#include <memory>

Game::Game()
{
	for (int i = 0; i < numberPlayers; i++)
	{
		std::shared_ptr<Player> newPlayer = std::make_shared<Player>();
		players.push_back(newPlayer);
		playerInterface.push_back(std::make_shared<PlayerInterface>());
		playerInterface[i]->setPlayer(newPlayer);		
		playerInterface[i]->setGame(this);
	}

	players.push_back(std::make_shared<Dealer>());

	deck = std::make_shared<Deck>();
	deck->shuffle();
}

void Game::cardsDistribution(const int numberCards)
{
	dealerMove();

	if (checkGameIsOver())
	{
		findWinner();
		resetPlayerCharacteristic();
		Card::setMoreThanOneCardFromDealer(false);
	}
	else
	{
		playersCardsDistribution(numberCards);
		dealerCardsDistribution(numberCards);
	}
}

bool Game::checkGameIsOver() const
{
	for (int i = 0; i < players.size(); i++)
	{
		if (!players[i]->isStand()) return false;
	}
	return true;
}

void Game::findWinner() const
{
	for (int i = 0; i < numberPlayers; i++)
	{
		if (players[numberPlayers]->getPoints() > 21 && players[i]->getPoints() <= 21)
		{
			playerInterface[i]->finishMove(true);
		}
		else if (players[i]->getPoints() > players[numberPlayers]->getPoints() && players[i]->getPoints() <= 21)
		{
			playerInterface[i]->finishMove(true);
		}
		else
		{
			playerInterface[i]->finishMove(false);
		}
	}
}

void Game::resetPlayerCharacteristic()
{
	for (int i = 0; i < players.size(); i++)
	{
		players[i]->resetBet();
		players[i]->resetPoints();
		players[i]->resetStand();
	}
}

void Game::playersCardsDistribution(const int numberCards)
{
	for (int i = 0; i < numberPlayers; i++)
	{
		if (players[i]->isStand()) continue;

		for (int j = 0; j < numberCards; j++)
		{
			std::shared_ptr<Card> card = deck->getCard();

			players[i]->increasePoints(card->getValue());
			card->setPlayer(true);
			playerInterface[i]->displayCard(card);
			Card::changeEndPointPlayer();
		}
	}
}

void Game::dealerCardsDistribution(const int numberCards)
{
	if (players[numberPlayers]->isStand()) return;

	for (int i = 0; i < numberCards; i++)
	{
		std::shared_ptr<Card> card = deck->getCard();

		if (Card::isMoreThanOneCardFromDealer()) card->setHide();
		else Card::setMoreThanOneCardFromDealer(true);

		players[numberPlayers]->increasePoints(card->getValue());

		for (int j = 0; j < numberPlayers; j++)
		{
			playerInterface[j]->displayCard(card);
			Card::changeEndPointDealer();
		}
	}
}

void Game::dealerMove()
{
	if (players[numberPlayers]->shouldStand())
	{
		players[numberPlayers]->setStand(true);
	}
}
