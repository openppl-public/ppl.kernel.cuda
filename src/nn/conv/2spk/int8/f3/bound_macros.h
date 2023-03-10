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

#define SET_BOUND_FLT3(_in_hw_mask, _in_n_id, _in_h_id, _in_w_id) \
        { \
            if(_in_n_id < in_num) \
            { \
                _in_hw_mask = 0xffffffff; \
                if(_in_h_id < 0 || _in_h_id >= in_height) _in_hw_mask = _in_hw_mask & 0xfffffff8; \
                if(_in_w_id < 0 || _in_w_id >= in_width)  _in_hw_mask = _in_hw_mask & 0xffffffb6; \
                \
                _in_h_id += hole_height; \
                _in_w_id += hole_width; \
                \
                if(_in_h_id < 0 || _in_h_id >= in_height) _in_hw_mask = _in_hw_mask & 0xffffffc7; \
                if(_in_w_id < 0 || _in_w_id >= in_width)  _in_hw_mask = _in_hw_mask & 0xffffff6d; \
                \
                _in_h_id += hole_height; \
                _in_w_id += hole_width; \
                \
                if(_in_h_id < 0 || _in_h_id >= in_height)  _in_hw_mask = _in_hw_mask & 0xfffffe3f; \
                if(_in_w_id < 0 || _in_w_id >= in_width)   _in_hw_mask = _in_hw_mask & 0xfffffedb; \
            } else { \
                _in_hw_mask = 0x0; \
            } \
        }

#define FWD_FLT3(_flt_hw_id, _flt_hw_bid, _flt_c_v16_id, _flt_c_v16_valid) \
        { \
            if(_flt_hw_id == 8) \
            { \
                _flt_hw_id = 0; \
                _flt_c_v16_id += TILE_K_V16_PER_CTA; \
                \
                _flt_c_v16_valid = _flt_c_v16_id < flt_c_v16_end; \
            } else { \
                _flt_hw_id = _flt_hw_id + 1; \
            } \
            \
            _flt_hw_bid = (0x1 << _flt_hw_id); \
        }

#define FWD_FLT(_flt_hw_id, _flt_hw_bid, _flt_c_v16_id, _flt_c_v16_valid) FWD_FLT3(_flt_hw_id, _flt_hw_bid, _flt_c_v16_id, _flt_c_v16_valid)
