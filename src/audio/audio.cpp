#include "audio/audio.h"

#include "globals.h"
#include "filesystem.h"

#include <vorbis/vorbisfile.h>
#include <SDL2/SDL_assert.h>

Audio::Audio() : Resource(ResType::AudioType), frequency(11025) {}

Audio::Audio(const Str& filename_) : Resource(filename_, ResType::AudioType),
                                        frequency(11025) {}

Audio::~Audio() {}

void Audio::removeContent()
{
    frequency = 11025;
    data.clear();
}

void Audio::_load()
{
    OggVorbis_File file;

    if (ov_fopen(fileSys->getAbsolutePath(getFilename().getData()).getData(), &file) < 0)
    {
        THROW(ResourceIOException, "audio", getFilename(), "Unable to open ogg vorbis file.");
    }

    vorbis_info *info = ov_info(&file, -1);

    if (info == nullptr)
    {
        ov_clear(&file);

        return;
    }

    SDL_assert_paranoid(info->rate >= 0);
    frequency = info->rate;

    ogg_int64_t numSamples = ov_pcm_total(&file, -1);
    SDL_assert_paranoid(numSamples >= 0);

    data = List<float>(numSamples*2);

    size_t samplesRead = 0;
    int stream = 0;

    while (samplesRead != (size_t)numSamples)
    {
        float **pcm;

        int result = ov_read_float(&file,
                                   &pcm,
                                   1024,
                                   &stream);

        if (result < 0)
        {
            THROW(ResourceIOException, "audio", getFilename(), Str::format("Unable to decode ogg vorbis file: %d", result));
        }

        if (info->channels == 2)
        {
            for (size_t i = 0; i < (size_t)result; ++i)
            {
                setSample(samplesRead+i, 0, pcm[0][i]);
                setSample(samplesRead+i, 1, pcm[1][i]);
            }
        } else
        {
            for (size_t i = 0; i < (size_t)result; ++i)
            {
                setMonoSample(samplesRead+i, pcm[0][i]);
            }
        }

        SDL_assert(result >= 0);
        samplesRead += result;
    }

    ov_clear(&file);
}

Resource *Audio::_copy() const
{
    Audio *audio = NEW(Audio);

    audio->frequency = frequency;
    audio->data = data.copy();

    return (Resource *)audio;
}
