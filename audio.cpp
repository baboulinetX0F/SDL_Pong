#include "audio.h"

#include <stdio.h>

// Default Construct : Initialize the audio mixer
Audio::Audio()
{
    if ( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("Error : Mixer could not be initialized");
    }
}

Audio::~Audio() {}


// loadSound : check if the sound was previously load, if not, load it into a map of Mix_Chunk pointer
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

// playSound : plays a sound previously load with loadSound
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
