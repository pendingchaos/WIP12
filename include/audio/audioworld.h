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

        inline ResPtr<Audio> getAudio() const
        {
            return audio;
        }

        inline void setAudio(ResPtr<Audio> audio_)
        {
            audio->release();
            audio = audio_;
        }
    private:
        ResPtr<Audio> audio;
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
