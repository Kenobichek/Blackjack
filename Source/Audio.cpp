#include "Audio.h"

void Audio::playSoundBackground()
{
	audioOutput = new QAudioOutput();
	audioOutput->setVolume(20);

	player = new QMediaPlayer();
	player->setAudioOutput(audioOutput);

	QUrl mediaUrl = QUrl::fromLocalFile("Content/Audio/background.mp3");
	player->setSource(mediaUrl);
	player->play();
}

void Audio::playSoundButtonPress()
{
	audioOutput = new QAudioOutput();
	audioOutput->setVolume(50);

	player = new QMediaPlayer();
	player->setAudioOutput(audioOutput);

	QUrl mediaUrl = QUrl::fromLocalFile("Content/Audio/button_press.mp3");
	player->setSource(mediaUrl);
	player->play();
}

void Audio::playSoundCardDistribution()
{
	audioOutput = new QAudioOutput();
	audioOutput->setVolume(50);

	player = new QMediaPlayer();
	player->setAudioOutput(audioOutput);

	QUrl mediaUrl = QUrl::fromLocalFile("Content/Audio/card_distribution.mp3");
	player->setSource(mediaUrl);
	player->play();
}

void Audio::playSoundCardShuffle()
{
	audioOutput = new QAudioOutput();
	audioOutput->setVolume(50);

	player = new QMediaPlayer();
	player->setAudioOutput(audioOutput);

	QUrl mediaUrl = QUrl::fromLocalFile("Content/Audio/card_shuffle.mp3");
	player->setSource(mediaUrl);
	player->play();
}
