#ifndef AUDIODEVICE_H
#define AUDIODEVICE_H

#include "containers/string.h"
#include "containers/hashmap.h"
#include "scripting/bindings.h"

#include <SDL2/SDL_audio.h>

class AudioDevice
{
    public:
        struct Callback
        {
            void (*function)(float *, size_t, void *, AudioDevice *);
            void *data;
        };

        AudioDevice(size_t index, size_t frequency, size_t samples);
        ~AudioDevice();

        Str getName();
        static Str getName(size_t index);
        static size_t getDeviceCount();

        void setIndex(size_t index);
        void setFrequency(size_t frequency);
        void setSamples(size_t samples);

        inline size_t getIndex()
        {
            return index;
        }

        inline size_t getFrequency() const
        {
            return spec.freq;
        }

        inline size_t getSamples() const
        {
            return samples;
        }

        inline size_t getNumQueuedSamples() const
        {
            size_t sampleSize = SDL_AUDIO_BITSIZE(spec.format) / 8 * spec.channels;

            SDL_LockAudioDevice(id);

            size_t count = queued.getCount() / sampleSize;

            SDL_UnlockAudioDevice(id);

            return count;
        }

        void pause();
        void play();
        bool getPaused();

        NO_BIND HashMap<void *, Callback> callbacks;

        void runCallbacks(size_t numSamples);

        float volume;
    private:
        size_t index;
        SDL_AudioDeviceID id;
        SDL_AudioSpec spec;
        List<Uint8> queued;
        size_t frequency;
        size_t samples;

        static void audioDeviceCallback(void *userdata, Uint8 *data, int len);
} BIND;

#endif // AUDIODEVICE_H
