#include "audio/audioworld.h"

#include "audio/audiodevice.h"
#include "globals.h"
#include "resource/resourcemanager.h"

void audioWorldCallback(float *data, size_t numSamples, void *userdata, AudioDevice *device)
{
    double duration = (double)numSamples / (double)device->getFrequency();

    AudioWorld *world = (AudioWorld *)userdata;

    for (size_t i = 0; i < world->getSources().getCount(); ++i)
    {
        AudioSource *source = world->getSources()[i];

        if (source->playing)
        {
            ResPtr<Audio> audio = source->audio;

            float distance = world->listenerPosition.distance(source->position);

            distance = std::max(distance, source->referenceDistance);
            distance = std::min(distance, source->maxDistance);

            float gain = source->volume;

            float doppler = 1.0f;

            if (source->is3d)
            {
                //Attenuation
                gain *= source->referenceDistance /
                        (source->referenceDistance +
                         source->rolloffFactor *
                         (distance - source->referenceDistance));

                //Doppler
                //Disabled because it causes popping noises.
                /*float dopplerFactor = world->dopplerFactor * source->dopplerFactor;
                Vector3D sl = world->listenerPosition - source->position;
                Vector3D sv = source->velocity;
                Vector3D lv = world->listenerVelocity;
                float vls = sl.dot(lv) / sl.length();
                float vss = sl.dot(sv) / sl.length();
                vss = std::min(vss, world->speedOfSound / dopplerFactor);
                vls = std::min(vls, world->speedOfSound / dopplerFactor);
                doppler = (world->speedOfSound - dopplerFactor * vls) /
                                (world->speedOfSound - dopplerFactor * vss);*/
            }

            if (gain >= 0.00001f)
            {
                if (source->loop)
                {
                    for (size_t j = 0; j < numSamples; ++j)
                    {
                        size_t index = audio->getSampleIndex(j, device->getFrequency(), doppler)+source->offset;

                        index %= audio->getNumSamples();

                        if (source->is3d)
                        {
                            float sample = audio->getMonoSample(index) * gain;

                            data[j*2] += sample;
                            data[j*2+1] += sample;
                        } else
                        {
                            data[j*2] += audio->getSample(index, 0) * gain;
                            data[j*2+1] += audio->getSample(index, 1) * gain;
                        }
                    }
                } else
                {
                    size_t samplesToPlay = audio->getNumSamples()-source->offset;
                    samplesToPlay = Audio::changeSampleFrequency(samplesToPlay,
                                                                 audio->frequency,
                                                                 device->getFrequency());

                    for (size_t j = 0; j < std::min(numSamples, samplesToPlay); ++j)
                    {
                        size_t index = audio->getSampleIndex(j, device->getFrequency(), doppler)+source->offset;

                        if (index < audio->getNumSamples())
                        {
                        if (source->is3d)
                        {
                            float sample = audio->getMonoSample(index) * gain;

                            data[j*2] += sample;
                            data[j*2+1] += sample;
                        } else
                        {
                            data[j*2] += audio->getSample(index, 0) * gain;
                            data[j*2+1] += audio->getSample(index, 1) * gain;
                        }
                        }
                    }
                }
            }

            source->offset += duration * audio->frequency;

            if (source->offset > audio->getNumSamples() and not source->loop)
            {
                source->offset = 0;
                source->playing = source->loop;
            }

            if (source->loop)
            {
                source->offset %= audio->getNumSamples();
            }
        }
    }
}

AudioWorld::AudioWorld() : dopplerFactor(1.0f),
                           speedOfSound(343.3f) {}

AudioWorld::~AudioWorld()
{
    clearSources();
}

void AudioWorld::addToAudioDevice(AudioDevice *device)
{
    AudioDevice::Callback callback;

    callback.function = audioWorldCallback;
    callback.data = this;

    device->callbacks.set(this, callback);
}

void AudioWorld::removeFromAudioDevice(AudioDevice *device)
{
    device->callbacks.remove(this);
}
