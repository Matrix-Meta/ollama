// Ollama extension functions for llama.cpp
#ifndef LLAMA_EXT_H
#define LLAMA_EXT_H

#include "llama.h"

#ifdef __cplusplus
extern "C" {
#endif

    // LoRA adapter support - wrapper around upstream llama_set_adapters_lora
    // Returns 0 on success, -1 on error
    int llama_set_adapter_lora(struct llama_context *ctx, struct llama_adapter_lora *adapter, float scale);

#ifdef __cplusplus
}
#endif

#endif // LLAMA_EXT_H
