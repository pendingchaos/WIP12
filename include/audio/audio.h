#ifndef AUDIO_H
#define AUDIO_H

#include "containers/list.h"
#include "resource/resource.h"
#include "scripting/bindings.h"

class Audio : public Resource
{
    public:
        static const ResType resource_type = ResType::AudioType;

        Audio();
        Audio(const Str& filename);
        virtual ~Audio();

        virtual void removeContent();

        size_t frequency;
        List<float> data;

        static inline size_t changeSampleFrequency(size_t sample, size_t old, size_t new_)
        {
            return sample / (double)old * new_;
        }

        inline size_t getNumSamples() const
        {
            return data.getCount() / 2;
        }

        inline float getSample(size_t index, size_t channel) const
        {
            return data[index * 2 + channel];
        }

        inline float getMonoSample(size_t index)
        {
            return (getSample(index, 0) + getSample(index, 1)) / 2.0f;
        }

        inline void setSample(size_t index, size_t channel, float value)
        {
            data[index * 2 + channel] = value;
        }

        inline void setMonoSample(size_t index, float value)
        {
            setSample(index, 0, value);
            setSample(index, 1, value);
        }

        inline float getDuration() const
        {
            return (float)data.getCount() / frequency;
        }

        inline size_t getSampleIndex(float time)
        {
            return time * frequency;
        }

        inline size_t getSampleIndex(size_t time, size_t frequency_, float speed=1.0f)
        {
            return changeSampleFrequency(time, frequency_, frequency*speed);
        }
    protected:
        virtual void _load();
        virtual Resource *_copy() const;
} BIND DESTROY(obj->release());

#endif // AUDIO_H
