/*
 * Copyright 2015 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at

 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Shihao Ji (Intel)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include "rnnlmlib.hpp"

int main(int argc, char **argv) {

    parameter param;

    if (int ret_code = param.read_arguments(argc, argv)) {
        return ret_code;
    }

    rnnlm model(param);

    cout << param;
    if (param.train_mode) {
        model.train();
    }

    if (param.test_mode) {
        model.test();
    }

    return 0;

}