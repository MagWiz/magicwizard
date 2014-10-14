#ifndef AUDIO_H
#define AUDIO_H

#include <SFML/Audio.hpp>

using namespace std;
namespace MWEngine
{
class Audio
{
public:
    sf::Music musicMenu;
    sf::Music musicStartLevel;
    sf::Music musicGame;
    sf::Music sfxJump;
    sf::Music sfxStab;
    sf::Music sfxStar;

public:
    Audio();

    void playMusicMenu();
    void stopMusicMenu();
    void playMusicGame();
    void stopMusicGame();
    void playMusicStartLevel();
    void stopMusicStartLevel();

    void restartLevel();
    void musicStab();
    void playJump();
    void playStab();
    void playStar();
};
}
#endif