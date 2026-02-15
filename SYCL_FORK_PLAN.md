# Ollama SYCL Fork Plan (Experimental)

Goal: Maintain an experimental SYCL/XMX line for Intel Arc while keeping upstream compatibility.

## Scope
- Keep upstream Ollama runtime path intact.
- Add optional SYCL backend integration points for llama runner.
- Do not break Vulkan/CUDA/ROCm builds.

## Phase 1 (scaffold) ✅ DONE
- [x] Add build flag: `OLLAMA_EXPERIMENTAL_SYCL` in CMakeLists.txt
- [x] Add runtime env switch: `OLLAMA_SYCL=1` in envconfig/config.go
- [x] Add backend resolution log showing selected backend in discover/runner.go

## Phase 2 (runner integration) ✅ DONE
- [x] Vendor/attach upstream llama.cpp with GGML_SYCL=ON (third_party/llama.cpp)
- [x] Add ggml-sycl backend to Ollama ggml
- [x] Fix API compatibility (graph_compute, GGML_TENSOR_FLAG_COMPUTE)
- [x] Add fallback warning when SYCL enabled but no devices found

## Phase 3 (validation) 🔄 IN PROGRESS
- [ ] Full binary build with SYCL support
- [ ] Smoke test with tiny model
- [ ] Performance sanity on Arc B580
- [ ] Document constraints and known issues

## Build Commands
```bash
# One-time setup
source /opt/intel/oneapi/setvars.sh

# Configure with SYCL
cmake -B build -DOLLAMA_EXPERIMENTAL_SYCL=ON -DGGML_SYCL=ON -DGGML_SYCL_TARGET=INTEL

# Build ggml libraries
cmake --build build --target ggml-sycl ggml-cpu
```

## Known Issues
- Full Go binary linking requires building llama.cpp as shared library
- Some multimodal features need stub implementations
