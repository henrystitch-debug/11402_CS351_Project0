#include <stdio.h>
#include <stdlib.h>

// Two Sum - Loop Approach
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

// Two Sum - Hash Map Approach (korrigiert)
int *twoSumHashMap(int *nums, int numsSize, int target, int *returnSize)
{
    // Einfache Hash-Tabelle mit Offset für negative Zahlen
    int offset = 100000;
    int hashSize = 200001;
    int *hashMap = (int *)malloc(hashSize * sizeof(int));
    
    for (int i = 0; i < hashSize; i++)
        hashMap[i] = -1;

    for (int i = 0; i < numsSize; i++)
    {
        int complement = target - nums[i];
        int hashIndex = complement + offset;
        
        if (hashIndex >= 0 && hashIndex < hashSize && hashMap[hashIndex] != -1)
        {
            int *result = (int *)malloc(2 * sizeof(int));
            result[0] = hashMap[hashIndex];
            result[1] = i;
            *returnSize = 2;
            free(hashMap);
            return result;
        }
        hashMap[nums[i] + offset] = i;
    }

    *returnSize = 0;
    free(hashMap);
    return NULL;
}

int main()
{
    int numbers[] = {3, 7, 12, 19};
    int target = 19;
    int returnSize;  // <-- Separate Variable!

    int *result = twoSumLoop(numbers, 4, target, &returnSize);

    if (result != NULL)
    {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
        free(result);
    }
    else
    {
        printf("Keine Lösung gefunden.\n");
    }

     int *result2 = twoSumHashMap(numbers, 4, target, &returnSize);

    if (result2 != NULL)
    {
        printf("Indices: [%d, %d]\n", result2[0], result2[1]);
        free(result2);
    }
    else
    {
        printf("Keine Lösung gefunden.\n");
    }

    return 0;
}
