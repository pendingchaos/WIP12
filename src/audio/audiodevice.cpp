#include "audio/audiodevice.h"

#include "memory.h"
#include "endian_utils.h"
#include "logging.h"

inline uint32_t floatToUint32(float f)
{
    union
    {
        float f;
        uint32_t i;
    } u;

    u.f = f;

    return u.i;
}

//Audio disabled because SDL_CloseAudioDevice does not return (audio thread not joining?)
AudioDevice::AudioDevice(size_t index_, size_t frequency_, size_t samples_) : volume(1.0f),
                                                                              index(index_),
                                                                              frequency(frequency_),
                                                                              samples(samples_)
{
    SDL_AudioSpec format;

    format.channels = 2;
    format.format = AUDIO_F32SYS;
    format.freq = frequency;
    format.samples = samples;
    format.callback = audioDeviceCallback;
    format.userdata = this;

    /*id = SDL_OpenAudioDevice(SDL_GetAudioDeviceName(index, false),
                             false,
                             &format,
                             &spec,
                             SDL_AUDIO_ALLOW_FORMAT_CHANGE |
                             SDL_AUDIO_ALLOW_FREQUENCY_CHANGE);*/
}

AudioDevice::~AudioDevice()
{
    //SDL_CloseAudioDevice(id);
}

Str AudioDevice::getName()
{
    return SDL_GetAudioDeviceName(index, false);
}

Str AudioDevice::getName(size_t index)
{
    return SDL_GetAudioDeviceName(index, false);
}

size_t AudioDevice::getDeviceCount()
{
    return SDL_GetNumAudioDevices(false);
}

void AudioDevice::setIndex(size_t index_)
{
    this->~AudioDevice();
    queued.clear();

    new (this) AudioDevice(index_, frequency, samples);
}

void AudioDevice::setFrequency(size_t frequency_)
{
    this->~AudioDevice();
    queued.clear();

    new (this) AudioDevice(index, frequency_, samples);
}

void AudioDevice::setSamples(size_t samples_)
{
    this->~AudioDevice();
    queued.clear();

    new (this) AudioDevice(index, frequency, samples_);
}

void AudioDevice::pause()
{
    //SDL_PauseAudioDevice(id, 1);
}

void AudioDevice::play()
{
    //SDL_PauseAudioDevice(id, 0);
}

bool AudioDevice::getPaused()
{
    return false;
    //return SDL_GetAudioDeviceStatus(id) == SDL_AUDIO_PAUSED;
}

void AudioDevice::runCallbacks(size_t numSamples)
{
    float *result = (float *)ALLOCATE(numSamples * sizeof(float) * 2);

    for (size_t i = 0; i < numSamples*2; ++i)
    {
        result[i] = 0.0f;
    }

    for (auto kv : callbacks)
    {
        const Callback& callback = kv.second;

        callback.function(result, numSamples, callback.data, this);
    }

    for (size_t i = 0; i < numSamples*2; ++i)
    {
        result[i] *= volume;
    }

    size_t sampleSize = SDL_AUDIO_BITSIZE(spec.format) / 8 * spec.channels;

    void *converted = ALLOCATE(sampleSize * numSamples);

    switch (spec.format)
    {
    case AUDIO_S8:
    {
        for (size_t i = 0; i < numSamples*2; ++i)
        {
            ((int8_t *)converted)[i] = std::max(std::min((double)result[i], 1.0), -1.0) * 127.0;
        }
        break;
    }
    case AUDIO_U8:
    {
        for (size_t i = 0; i < numSamples*2; ++i)
        {
            ((uint8_t *)converted)[i] = (std::max(std::min((double)result[i], 1.0), -1.0) + 1.0f) * 127.0;
        }
        break;
    }
    case AUDIO_S16LSB:
    {
        for (size_t i = 0; i < numSamples*2; ++i)
        {
            ((int16_t *)converted)[i] = TO_LE_S16(std::max(std::min((double)result[i], 1.0), -1.0) * 32767.0);
        }
        break;
    }
    case AUDIO_S16MSB:
    {
        for (size_t i = 0; i < numSamples*2; ++i)
        {
            ((int16_t *)converted)[i] = TO_BE_S16(std::max(std::min((double)result[i], 1.0), -1.0) * 32767.0);
        }
        break;
    }
    case AUDIO_U16LSB:
    {
        for (size_t i = 0; i < numSamples*2; ++i)
        {
            ((uint16_t *)converted)[i] = TO_LE_U16((std::max(std::min((double)result[i], 1.0), -1.0) + 1.0) * 32767.0);
        }
        break;
    }
    case AUDIO_U16MSB:
    {
        for (size_t i = 0; i < numSamples*2; ++i)
        {
            ((uint16_t *)converted)[i] = TO_BE_U16((std::max(std::min((double)result[i], 1.0), -1.0) + 1.0) * 32767.0);
        }
        break;
    }
    case AUDIO_S32LSB:
    {
        for (size_t i = 0; i < numSamples*2; ++i)
        {
            ((int32_t *)converted)[i] = TO_LE_S32(std::max(std::min((double)result[i], 1.0), -1.0) * 2147483647.0);
        }
        break;
    }
    case AUDIO_S32MSB:
    {
        for (size_t i = 0; i < numSamples*2; ++i)
        {
            ((int32_t *)converted)[i] = TO_BE_S32(std::max(std::min((double)result[i], 1.0), -1.0) * 2147483647.0);
        }
        break;
    }
    #if IS_LITTLE_ENDIAN
    case AUDIO_F32LSB:
    {
        std::memcpy(converted, result, numSamples * 2 * sizeof(float));
        break;
    }
    #else
    case AUDIO_F32LSB:
    {
        for (size_t i = 0; i < numSamples*2; ++i)
        {
            ((uint32_t *)converted)[i] = TO_LE_U32(floatToUint32(result[i]));
        }
        break;
    }
    #endif
    #if IS_BIG_ENDIAN
    case AUDIO_F32MSB:
    {
        std::memcpy(converted, result, numSamples * 2 * sizeof(float));
        break;
    }
    #else
    case AUDIO_F32MSB:
    {
        for (size_t i = 0; i < numSamples*2; ++i)
        {
            ((uint32_t *)converted)[i] = TO_BE_U32(floatToUint32(result[i]));
        }
        break;
    }
    #endif
    }

    DEALLOCATE(result);

    //SDL_LockAudioDevice(id);

    queued.append(sampleSize * numSamples, (uint8_t *)converted);

    //SDL_UnlockAudioDevice(id);

    DEALLOCATE(converted);
}

void AudioDevice::audioDeviceCallback(void *userdata, Uint8 *data, int len)
{
    List<Uint8>& queued = ((AudioDevice *)userdata)->queued;

    if (queued.getCount() < (size_t)len)
    {
        std::memcpy(data, queued.getData(), queued.getCount());

        INFO(CATEGORY_AUDIO, "Too little data for audio! %d bytes missing.", (size_t)len - queued.getCount())();

        queued.clear();
    } else
    {
        std::memcpy(data, queued.getData(), len);

        queued.remove(0, len);
    }
}
