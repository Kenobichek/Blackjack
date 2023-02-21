#pragma once
#include <QtMultimedia>
#include <QSoundEffect>
#include <QMediaPlayer>

class Audio
{
public:

	void playSoundBackground();
	void playSoundButtonPress();
	void playSoundCardDistribution();
	void playSoundCardShuffle();

private:
	QMediaPlayer* player;
	QAudioOutput* audioOutput;
};