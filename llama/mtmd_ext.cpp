// MTMD wrapper/adapter implementation
// Bridges old Ollama API to new third_party mtmd API

#include "mtmd_ext.h"
#include "mtmd.h"
#include "mtmd-helper.h"

extern "C" {

// Stub implementations - need to be adapted to new API
// The old API had mtmd_input_text as a separate object that's initialized
// The new API embeds text directly in mtmd_input_chunks

void* mtmd_input_text_init(const char* marker, bool param1, bool param2) {
    // In the new API, text is added to chunks directly
    // We return NULL to indicate this needs to be rewritten
    // The llama.go code needs to be updated to use the new API
    return nullptr;
}

void mtmd_input_text_free(void* input) {
    // In new API, text is managed through chunks
    // No-op for compatibility
}

// Wrapper for tokenize to handle the old calling convention
int32_t mtmd_tokenize_wrapper(void* ctx, void* chunks, void* text, void* bitmap, size_t n_bitmaps) {
    // Cast to third_party types
    mtmd_context* mtmd_ctx = static_cast<mtmd_context*>(ctx);
    mtmd_input_chunks* mtmd_chunks = static_cast<mtmd_input_chunks*>(chunks);
    
    // The text parameter is not used in new API - text is added to chunks differently
    // For now, return error to indicate this needs implementation
    (void)mtmd_ctx;
    (void)mtmd_chunks;
    (void)bitmap;
    (void)n_bitmaps;
    
    return -1; // Not implemented - needs new API adaptation
}

} // extern "C"
