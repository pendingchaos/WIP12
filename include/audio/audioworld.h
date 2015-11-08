#ifndef AUDIOWORLD_H
#define AUDIOWORLD_H

#include "audio/audio.h"
#include "math/t3.h"
#include "scripting/bindings.h"

#include <cmath>
#include <SDL2/SDL_assert.h>

class AudioDevice;

class AudioSource
{
    public:
        AudioSource(Audio *audio_) : is3d(true),
                                     referenceDistance(1.0f),
                                     rolloffFactor(1.0f),
                                     maxDistance(INFINITY),
                                     volume(1.0f),
                                     dopplerFactor(1.0f),
                                     offset(0),
                                     loop(false),
                                     playing(false),
                                     audio(audio_) {}
        ~AudioSource()
        {
            audio->release();
        }

        bool is3d;
        Position3D position;
        float referenceDistance;
        float rolloffFactor;
        float maxDistance;
        float volume;
        Vector3D velocity;
        float dopplerFactor;
        size_t offset;
        bool loop;
        bool playing;

        Audio *getAudio() const
        {
            return audio;
        }

        void setAudio(Audio *audio_)
        {
            audio->release();
            audio = audio_;
        }
    private:
        Audio *audio;
} BIND;

class AudioWorld
{
    public:
        AudioWorld();
        ~AudioWorld();

        Vector3D listenerVelocity;
        float dopplerFactor;
        Position3D listenerPosition;
        float speedOfSound;

        AudioSource *createSource(Audio *audio)
        {
            AudioSource *source = NEW(AudioSource, audio);

            sources.append(source);

            return source;
        }

        void destroySource(AudioSource *source)
        {
            int index = sources.find(source);

            if (index != -1)
            {
                SDL_assert_paranoid(index >= 0);

                DELETE(sources[index]);

                sources.remove(index);
            }
        }

        void clearSources()
        {
            for (auto source : sources)
            {
                DELETE(source);
            }

            sources.clear();
        }

        const List<AudioSource *>& getSources() const
        {
            return sources;
        }

        void addToAudioDevice(AudioDevice *device);
        void removeFromAudioDevice(AudioDevice *device);
    private:
        List<AudioSource *> sources;
} BIND;

#endif // AUDIOWORLD_H
