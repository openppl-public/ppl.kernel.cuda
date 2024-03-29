// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#ifndef PPLCUDAKERNEL_INCLUDE_CHECK_COMMON_H_
#define PPLCUDAKERNEL_INCLUDE_CHECK_COMMON_H_
#include <iostream>

#define NVRTC_SAFE_CALL(x)                                    \
    do {                                                      \
        nvrtcResult result = x;                               \
        if (result != NVRTC_SUCCESS) {                        \
            std::cerr << "\nerror: " #x " failed with error " \
                      << nvrtcGetErrorString(result) << '\n'; \
            exit(1);                                          \
        }                                                     \
    } while (0)

#define CUDA_SAFE_CALL(x)                                     \
    do {                                                      \
        CUresult result = x;                                  \
        if (result != CUDA_SUCCESS) {                         \
            const char *msg;                                  \
            cuGetErrorName(result, &msg);                     \
            std::cerr << "\nerror: " #x " failed with error " \
                      << msg << '\n';                         \
            exit(1);                                          \
        }                                                     \
    } while (0)

#define PPL_CHECK(COND, ERR)                                    \
    if(!(COND)) {                                               \
        std::cerr << "'" #COND "' failed: " << ERR << "\n";     \
        exit(1);                                                \
    }

#endif