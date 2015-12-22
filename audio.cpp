#include "audio.h"

#include <stdio.h>

Audio::Audio()      // Default Constructor
{
    if ( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("Error : Mixer could not be initialized");
    }
}

Audio::~Audio() {}

void Audio::loadSound(std::string filePath)
{
    if (this->_soundsLoaded.count(filePath) == 0)
    {
        Mix_Chunk* tmp = NULL;
        tmp=Mix_LoadWAV(filePath.c_str());
        if(tmp != NULL)
        {
            this->_soundsLoaded[filePath]=tmp;
        }
        else
        {
            printf("Cannot load sound file ");
        }
    }

}

void Audio::playSound(std::string name)
{
    if (this->_soundsLoaded.count(name) == 0)
    {
        printf("ERROR : Sound to played is not loaded");
    }
    else
    {
        Mix_PlayChannel(-1, this->_soundsLoaded[name],0);
    }
}
