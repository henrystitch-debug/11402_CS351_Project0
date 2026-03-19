#include <stdio.h>
#include <stdlib.h>

// ── Two Sum – Loop Approach ───────────────────────────────────────────────────
int *twoSumLoop(int *nums, int numsSize, int target, int *returnSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                int *result = (int *)malloc(2 * sizeof(int));
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

// ── Two Sum – Hash Map Approach ───────────────────────────────────────────────
int *twoSumHashMap(int *nums, int numsSize, int target, int *returnSize)
{
    // Simple hash table with offset to handle negative numbers
    int offset   = 100000;
    int hashSize = 200001;
    int *hashMap = (int *)malloc(hashSize * sizeof(int));

    for (int i = 0; i < hashSize; i++)
        hashMap[i] = -1;

    for (int i = 0; i < numsSize; i++)
    {
        int complement = target - nums[i];
        int hashIndex  = complement + offset;

        if (hashIndex >= 0 && hashIndex < hashSize && hashMap[hashIndex] != -1)
        {
            int *result = (int *)malloc(2 * sizeof(int));
            result[0]   = hashMap[hashIndex];
            result[1]   = i;
            *returnSize = 2;
            free(hashMap);
            return result;
        }
        int storeIndex = nums[i] + offset;
        if (storeIndex >= 0 && storeIndex < hashSize)
            hashMap[storeIndex] = i;
    }

    *returnSize = 0;
    free(hashMap);
    return NULL;
}

// ── main (skipped when building the test binary) ─────────────────────────────
#ifndef TESTING
int main(void)
{
    int numbers[] = {3, 7, 12, 19};
    int target    = 19;
    int returnSize;

    // Loop approach
    int *result = twoSumLoop(numbers, 4, target, &returnSize);
    if (result != NULL) {
        printf("Loop  – Indices: [%d, %d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("Loop  – Keine Lösung gefunden.\n");
    }

    // Hash map approach
    int *result2 = twoSumHashMap(numbers, 4, target, &returnSize);
    if (result2 != NULL) {
        printf("Hash  – Indices: [%d, %d]\n", result2[0], result2[1]);
        free(result2);
    } else {
        printf("Hash  – Keine Lösung gefunden.\n");
    }

    return 0;
}
#endif