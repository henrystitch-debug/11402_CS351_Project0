// main program to call the two sum function

#include <stdio.h>
#include <two_sum.h>
#include <stdlib.h>

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int* result = twoSumLoop(nums, 4, target, &returnSize);
    printf("twosum: [%d, %d]\n", result[0], result[1]);
    free(result);
    result = twoSumHashMap(nums, 4, target, &returnSize);
    printf("twosumhashmap: [%d, %d]\n", result[0], result[1]);
    free(result);
    return 0;
} 
