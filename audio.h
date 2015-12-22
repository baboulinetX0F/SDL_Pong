#ifndef AUDIO_H_INCLUDED
#define AUDIO_H_INCLUDED

#include <SDL.h>
#include <SDL_mixer.h>
#include <string>
#include <map>

class Audio
{
public:
    Audio();
    ~Audio();
    void loadSound(std::string filePath);
    void playSound(std::string name);


private:
    std::map<std::string,Mix_Chunk*> _soundsLoaded;
    std::map<std::string,Mix_Music*> _musicsloaded;
};

#endif // AUDIO_H_INCLUDED
