#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

int32_t most_frequent(int32_t *nums, size_t nums_size, int32_t key)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_LEN(nums_size);

    int32_t rom[2] = {0};
    int32_t max_freq = -1, freq[2] = {1};
    for (size_t i = 0; i < nums_size - 1; i ++) {
        rom[0] = nums[i];
        rom[1] = nums[i + 1];
        for (size_t j = i + 2; j < nums_size - 1; j ++) {
            if (rom[0] == nums[j] && rom[1] == nums[j + 1]) {
                freq[0] ++;
                if (max_freq <= freq[0]) {
                    max_freq = freq[0];
                    freq[1] = nums[j + 1];
                }
            }
        }
        freq[0] = 1;
    }

    ret = freq[1];

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {1,100,200,1,100};
    int32_t array2[] = {2,2,2,2,3};
    int32_t out;

    ret = most_frequent(array1, ARRAY_SIZE(array1), 1);
    assert(ret == 100);

    ret = most_frequent(array2, ARRAY_SIZE(array2), 2);
    assert(ret == 2);


    LOG("All tests have passed!\n");

finish:
    return ret;
}