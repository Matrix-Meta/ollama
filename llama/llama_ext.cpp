// Ollama extension functions for llama.cpp
#include "llama_ext.h"
#include "llama.h"
#include <cstddef>

extern "C" {

int llama_set_adapter_lora(struct llama_context *ctx, struct llama_adapter_lora *adapter, float scale) {
    if (ctx == nullptr || adapter == nullptr) {
        return -1;
    }

    struct llama_adapter_lora ** adapters = new struct llama_adapter_lora *;
    adapters[0] = adapter;

    float * scales = new float;
    scales[0] = scale;

    int32_t result = llama_set_adapters_lora(ctx, adapters, 1, scales);

    delete[] adapters;
    delete scales;

    return result;
}

} // extern "C"
