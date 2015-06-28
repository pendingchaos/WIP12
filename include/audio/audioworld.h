#ifndef AUDIOWORLD_H
#define AUDIOWORLD_H

#include "audio/audio.h"
#include "math/t3.h"

#include <cmath>

class AudioDevice;

class AudioSource
{
    public:
        AudioSource(ResPtr<Audio> audio_) : is3d(true),
                                            audio(audio_),
                                            referenceDistance(1.0f),
                                            rolloffFactor(1.0f),
                                            maxDistance(INFINITY),
                                            volume(1.0f),
                                            dopplerFactor(1.0f),
                                            offset(0),
                                            loop(false),
                                            playing(false) {}

        bool is3d;
        ResPtr<Audio> audio;
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
};

class AudioWorld
{
    public:
        AudioWorld();
        ~AudioWorld();

        Vector3D listenerVelocity;
        float dopplerFactor;
        Position3D listenerPosition;
        float speedOfSound;

        inline AudioSource *createSource(ResPtr<Audio> audio)
        {
            AudioSource *source = NEW(AudioSource, audio);

            sources.append(source);

            return source;
        }

        inline void destroySource(AudioSource *source)
        {
            int index = sources.find(source);

            if (index != -1)
            {
                DELETE(AudioSource, sources[index]);

                sources.remove(index);
            }
        }

        inline void clearSources()
        {
            for (size_t i = 0; i < sources.getCount(); ++i)
            {
                DELETE(AudioSource, sources[i]);
            }

            sources.clear();
        }

        inline const List<AudioSource *>& getSources() const
        {
            return sources;
        }

        void addToAudioDevice(AudioDevice *device);
        void removeFromAudioDevice(AudioDevice *device);
    private:
        List<AudioSource *> sources;
};

#endif // AUDIOWORLD_H
