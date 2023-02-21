#pragma once
#include <QtMultimedia>
#include <QSoundEffect>
#include <QMediaPlayer>

class Audio
{
public:
	~Audio();

	void playSoundBackground();
	void playSoundButtonPress();
	void playSoundCardDistribution();
	void playSoundCardShuffle();

private:
	QMediaPlayer* player;
	QAudioOutput* audioOutput;
};