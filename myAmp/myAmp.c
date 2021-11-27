/* include libs */
#include "stddef.h"
#include "stdint.h"
#include "stdlib.h"
#include "lv2.h"

/* class definition */
typedef struct
{
    float *audio_in_ptr;
    float *audio_out_ptr;
    float *amp_ptr;
} MyAmp;

/* internal core methods */
static LV2_Handle instantiate(const LV2_Descriptor *descriptor, double sample_rate, const char *bundle_path, const LV2_Feature *const *features)
{
    MyAmp *m = (MyAmp *)calloc(1, sizeof(MyAmp));
    return m;
}

static void connect_port(LV2_Handle instance, uint32_t port, void *data_location)
{
    MyAmp *m = (MyAmp *)instance;
    if (!m)
        return;
    switch (port)
    {
    case 0:
        m->audio_in_ptr = (float *)data_location;
        break;
    case 1:
        m->audio_out_ptr = (float *)data_location;
        break;
    case 2:
        m->amp_ptr = (float *)data_location;
        break;
    default:
        break;
    }
}

static void activate(LV2_Handle instance)
{
    /* not need here */
}

static void run(LV2_Handle instance, uint32_t sample_count)
{
    MyAmp *m = (MyAmp *)instance;
    if (!m)
        return;
    if ((!m->audio_in_ptr) || (!m->audio_out_ptr) || (!m->amp_ptr))
        return;
    for (uint32_t i = 0; i < sample_count; i++)
    {
        m->audio_out_ptr[i] = m->audio_in_ptr[i] * *(m->amp_ptr);
    }
}

static void deactivate(LV2_Handle instance)
{
}

static void cleanup(LV2_Handle instance)
{
    MyAmp *m = (MyAmp *)instance;
    if (!m)
        return;
    free(m);
}

static const void *extension_data(const char *uri)
{
    return NULL;
}

/* descriptor */
static LV2_Descriptor const descriptor =
    {
        "https://github.com/rghvdberg/bmusic-lv2-programming/myAmp",
        instantiate,
        connect_port,
        activate,
        run,
        deactivate,
        cleanup,
        extension_data,
};
/* interface */
const LV2_SYMBOL_EXPORT LV2_Descriptor *lv2_descriptor(uint32_t index)
{
    if (index == 0)
        return &descriptor;
    else
        return NULL;
}