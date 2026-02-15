// MTMD compatibility wrapper
// This provides bridge between old Ollama API and new third_party mtmd API

#ifndef MTMD_EXT_H
#define MTMD_EXT_H

#include "llama.h"
#include "mtmd.h"
#include "mtmd-helper.h"

#ifdef __cplusplus
#include <cstddef>
extern "C" {
#endif

// Old API compatibility wrappers

// Initialize text input - old API used this to create text prompts
// New API: text is handled differently, return NULL to indicate not implemented
static inline void* mtmd_input_text_init_compat(const char* marker, bool param1, bool param2) {
    (void)marker;
    (void)param1;
    (void)param2;
    return NULL;
}

// Free text input - no-op in new API
static inline void mtmd_input_text_free_compat(void* input) {
    (void)input;
}

// Tokenize wrapper - old signature: mtmd_tokenize(ctx, chunks, text, &bitmap, 1)
// New signature: mtmd_tokenize(ctx, chunks, text, bitmaps, n_bitmaps)
// This wrapper adapts the old calling convention
static inline int32_t mtmd_tokenize_compat(
    struct mtmd_context * ctx,
    struct mtmd_input_chunks * chunks,
    void * text,
    struct mtmd_bitmap ** bitmaps,
    size_t n_bitmaps) {
    
    // The new API expects text as a different type
    // For now, return error - this needs full migration
    (void)ctx;
    (void)chunks;
    (void)text;
    (void)bitmaps;
    (void)n_bitmaps;
    return -1;
}

#ifdef __cplusplus
}
#endif

#endif // MTMD_EXT_H
