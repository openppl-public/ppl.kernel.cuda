#ifndef PPLCUDA_KERNEL_INCLUDE_GLOBAL_POOLING_POOLING_AVE_H_
#define PPLCUDA_KERNEL_INCLUDE_GLOBAL_POOLING_POOLING_AVE_H_
#include "ppl/nn/common/tensor_shape.h"
#include "ppl/common/retcode.h"

ppl::common::RetCode PPLCUDAGlobalAvePoolingForwardImp(
    cudaStream_t stream,
    ppl::nn::TensorShape* input_shape,
    const void* input,
    ppl::nn::TensorShape* output_shape,
    void* output);

#endif //PPLCUDA_KERNEL_INCLUDE_GLOBAL_POOLING_POOLING_AVE_H_
