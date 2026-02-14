# Ollama SYCL Fork Plan (Experimental)

Goal: Maintain an experimental SYCL/XMX line for Intel Arc while keeping upstream compatibility.

## Scope
- Keep upstream Ollama runtime path intact.
- Add optional SYCL backend integration points for llama runner.
- Do not break Vulkan/CUDA/ROCm builds.

## Phase 1 (scaffold)
1. Add build flag: `OLLAMA_EXPERIMENTAL_SYCL`.
2. Add runtime env switch: `OLLAMA_SYCL=1`.
3. Add backend resolution log showing selected backend.

## Phase 2 (runner integration)
1. Vendor/attach an upstream `llama.cpp` build variant with `GGML_SYCL=ON`.
2. Wire runner selection to launch SYCL-built runner binary when enabled.
3. Add fallback to existing Vulkan/CPU runner if SYCL path fails.

## Phase 3 (validation)
1. Smoke test with tiny model.
2. Performance sanity on Arc B580.
3. Document constraints and known issues.

## Commands
```bash
source /opt/intel/oneapi/setvars.sh
# build + run scripts will be added in this branch
```
