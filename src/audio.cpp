#include "audio.h"
#include <SFML/Audio.hpp>

namespace MWEngine
{
Audio::Audio()
{
    musicMenu.openFromFile("assets/audio/menu00.ogg");
    musicStartLevel.openFromFile("assets/audio/magic-wizard-before-level.ogg");
    musicGame.openFromFile("assets/audio/Magic Wizard - Game 02.ogg");
    musicGame.setVolume(30);
    sfxJump.openFromFile("assets/audio/jump.flac");
    sfxJump.setVolume(30);
    sfxStar.openFromFile("assets/audio/coin.wav");
    sfxStab.openFromFile("assets/audio/blood-stab.flac");
}

void Audio::playMusicMenu()
{
    musicMenu.play();
    musicMenu.setLoop(true);
}
void Audio::stopMusicMenu()
{
    musicMenu.stop();
}

void Audio::playMusicStartLevel()
{
    musicStartLevel.play();
    musicStartLevel.setLoop(true);
}

void Audio::stopMusicStartLevel()
{
    musicStartLevel.stop();
}

void Audio::restartLevel()
{
    musicGame.setPitch(1);
    musicGame.setVolume(35);
}

void Audio::musicStab()
{
    musicGame.setPitch(0.5);
    musicGame.setVolume(10);

}

void Audio::playMusicGame()
{
    musicGame.play();
    musicGame.setLoop(true);
    musicGame.setPitch(1);
}
void Audio::stopMusicGame()
{
    musicGame.stop();
}

void Audio::playJump()
{
    sfxJump.play();
}
void Audio::playStab()
{
    sfxStab.play();
}
void Audio::playStar()
{
    sfxStar.play();
}
}
