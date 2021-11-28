/* include libs */
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cmath>
#include "lv2.h"

/* class definition */
class MyTestTone
{
private:
    float *audio_out_ptr;
    float *freq_ptr;
    float *level_ptr;
    double samplerate;
    double phase;

public:
    MyTestTone(const double sr);
    void connectPort(const uint32_t port, void *data_location);
    void activate();
    void run(const uint32_t frames);
    void deactivate();
};

MyTestTone::MyTestTone(const double sr) : audio_out_ptr(nullptr),
                                          freq_ptr(nullptr),
                                          level_ptr(nullptr),
                                          samplerate(sr),
                                          phase(0.0)
{
}

void MyTestTone::connectPort(const uint32_t port, void *data_location)
{
    switch (port)
    {
    case 0:
        audio_out_ptr = (float *)data_location;
        break;
    case 1:
        freq_ptr = (float *)data_location;
        break;
    case 2:
        level_ptr = (float *)data_location;
    default:
        break;
    }
}

void MyTestTone::activate()
{
    phase = 0.0;
}

void MyTestTone::run(const uint32_t frames)
{
    if ((!audio_out_ptr) || (!freq_ptr) || (!level_ptr))
        return;

    for (uint32_t i = 0; i < frames; ++i)
    {
        audio_out_ptr[i] = sin(2.0 * M_PI * phase) * *level_ptr;
        phase += *freq_ptr / samplerate;
    }
}

/* internal core methods */
static LV2_Handle instantiate(const LV2_Descriptor *descriptor, double sample_rate, const char *bundle_path, const LV2_Feature *const *features)
{
    MyTestTone *m = new MyTestTone(sample_rate);
    return m;
}

static void connect_port(LV2_Handle instance, uint32_t port, void *data_location)
{
    MyTestTone *m = (MyTestTone *)instance;
    if (m)
        m->connectPort(port, data_location);
}

static void activate(LV2_Handle instance)
{
    MyTestTone *m = (MyTestTone *)instance;
    if (m)
        m->activate();
}

static void run(LV2_Handle instance, uint32_t sample_count)
{
    MyTestTone *m = (MyTestTone *)instance;
    if (m)
        m->run(sample_count);
}

static void deactivate(LV2_Handle instance)
{
    /* describe it */
}

static void cleanup(LV2_Handle instance)
{
    MyTestTone *m = (MyTestTone *)instance;
    if (m)
        delete m;
}

static const void *extension_data(const char *uri)
{
    return NULL;
}

/* descriptor */
static LV2_Descriptor const descriptor =
    {
        "https://github.com/rghvdberg/bmusic-lv2-programming/myTestTone",
        instantiate,
        connect_port,
        activate,
        run,
        deactivate,
        cleanup,
        extension_data,
};
/* interface */
extern "C" LV2_SYMBOL_EXPORT const LV2_Descriptor *lv2_descriptor(uint32_t index)
{
    if (index == 0)
        return &descriptor;
    else
        return NULL;
}