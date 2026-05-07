#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ── Forward declarations ──────────────────────────────────────────────────────
int *twoSumLoop(int *nums, int numsSize, int target, int *returnSize);
int *twoSumHashMap(int *nums, int numsSize, int target, int *returnSize);

// ── Tiny test framework ───────────────────────────────────────────────────────
static int tests_run    = 0;
static int tests_passed = 0;

/* Check that result[0]==expA and result[1]==expB (or the swapped pair) */
static void check(const char *label, int *result, int returnSize,
                  int expA, int expB)
{
    tests_run++;
    int ok = (returnSize == 2) &&
             ((result[0] == expA && result[1] == expB) ||
              (result[0] == expB && result[1] == expA));
    if (ok) {
        printf("  PASS  %s\n", label);
        tests_passed++;
    } else {
        printf("  FAIL  %s", label);
        if (returnSize != 2)
            printf("  (returnSize=%d, expected 2)\n", returnSize);
        else
            printf("  (got [%d,%d], expected [%d,%d])\n",
                   result[0], result[1], expA, expB);
    }
    free(result);
}

/* Check that no solution is found */
static void check_null(const char *label, int *result, int returnSize)
{
    tests_run++;
    if (result == NULL && returnSize == 0) {
        printf("  PASS  %s\n", label);
        tests_passed++;
    } else {
        printf("  FAIL  %s  (expected NULL/0, got returnSize=%d)\n",
               label, returnSize);
        free(result);
    }
}

// ── Helper macros ─────────────────────────────────────────────────────────────
#define RUN_LOOP(label, arr, tgt, expA, expB) \
    do { \
        int rs = 0; \
        int *r = twoSumLoop(arr, sizeof(arr)/sizeof(arr[0]), tgt, &rs); \
        check(label " [Loop]", r, rs, expA, expB); \
    } while(0)

#define RUN_HASH(label, arr, tgt, expA, expB) \
    do { \
        int rs = 0; \
        int *r = twoSumHashMap(arr, sizeof(arr)/sizeof(arr[0]), tgt, &rs); \
        check(label " [Hash]", r, rs, expA, expB); \
    } while(0)

#define RUN_LOOP_NULL(label, arr, tgt) \
    do { \
        int rs = 0; \
        int *r = twoSumLoop(arr, sizeof(arr)/sizeof(arr[0]), tgt, &rs); \
        check_null(label " [Loop]", r, rs); \
    } while(0)

#define RUN_HASH_NULL(label, arr, tgt) \
    do { \
        int rs = 0; \
        int *r = twoSumHashMap(arr, sizeof(arr)/sizeof(arr[0]), tgt, &rs); \
        check_null(label " [Hash]", r, rs); \
    } while(0)

// ── Tests ─────────────────────────────────────────────────────────────────────
int main(void)
{
    printf("=== Two Sum – Test Suite ===\n\n");

    // ── 1. Basic / positive numbers ───────────────────────────────────────────
    printf("--- Basic (positive numbers) ---\n");
    {
        int a[] = {2, 7, 11, 15};
        RUN_LOOP("Basic [2,7]→9",  a, 9,  0, 1);
        RUN_HASH("Basic [2,7]→9",  a, 9,  0, 1);
        RUN_LOOP("Basic [2,15]→17",a, 17, 0, 3);
        RUN_HASH("Basic [2,15]→17",a, 17, 0, 3);
    }

    // ── 2. Negative numbers ───────────────────────────────────────────────────
    printf("\n--- Negative numbers ---\n");
    {
        int b[] = {-3, -1, 4, 8};
        RUN_LOOP("Neg [-3,-1]→-4", b, -4, 0, 1);
        RUN_HASH("Neg [-3,-1]→-4", b, -4, 0, 1);

        int c[] = {-6, 2, 10, -2};
        RUN_LOOP("Neg [-6,2]→-4",  c, -4, 0, 1);
        RUN_HASH("Neg [-6,2]→-4",  c, -4, 0, 1);

        int d[] = {-10, -20, -30, -40};
        RUN_LOOP("Neg [-10,-20]→-30", d, -30, 0, 1);
        RUN_HASH("Neg [-10,-20]→-30", d, -30, 0, 1);
    }

    // ── 3. Zero as part of the solution ──────────────────────────────────────
    printf("\n--- Zero as part of the solution ---\n");
    {
        int e[] = {0, 5, 3, 7};
        RUN_LOOP("Zero [0,5]→5",  e, 5, 0, 1);
        RUN_HASH("Zero [0,5]→5",  e, 5, 0, 1);

        int f[] = {0, 0, 1, 2};
        RUN_LOOP("Zero [0,0]→0",  f, 0, 0, 1);
        RUN_HASH("Zero [0,0]→0",  f, 0, 0, 1);

        int g[] = {-7, 0, 3, 9};
        RUN_LOOP("Zero [-7,0]→-7",g, -7, 0, 1);
        RUN_HASH("Zero [-7,0]→-7",g, -7, 0, 1);
    }

    // ── 4. Duplicate values ───────────────────────────────────────────────────
    printf("\n--- Duplicate values ---\n");
    {
        int h[] = {3, 3, 5, 7};
        RUN_LOOP("Dup [3,3]→6",   h, 6, 0, 1);
        RUN_HASH("Dup [3,3]→6",   h, 6, 0, 1);

        int i[] = {3, 5, 5, 9};
        RUN_LOOP("Dup [5,5]→10",  i, 10, 1, 2);
        RUN_HASH("Dup [5,5]→10",  i, 10, 1, 2);
    }

    // ── 5. No solution ────────────────────────────────────────────────────────
    printf("\n--- No solution ---\n");
    {
        int j[] = {1, 2, 3, 4};
        RUN_LOOP_NULL("NoSol target=100", j, 100);
        RUN_HASH_NULL("NoSol target=100", j, 100);
    }

    // ── 6. Performance comparison (large array, worst-case placement) ─────────────
printf("\n--- Performance comparison (n=50000, answer at end) ---\n");
{
    int size = 50000;
    int *big = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) big[i] = i + 1;
    int target = big[size - 2] + big[size - 1]; 

    struct timespec t0, t1;

    clock_gettime(CLOCK_MONOTONIC, &t0);
    int rs1 = 0;
    int *r1 = twoSumLoop(big, size, target, &rs1);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double loop_ms = (t1.tv_sec - t0.tv_sec) * 1000.0 + (t1.tv_nsec - t0.tv_nsec) / 1e6;
    printf("  twoSumLoop:    %.2f ms  (indices [%d, %d])\n", loop_ms, r1[0], r1[1]);
    free(r1);

    clock_gettime(CLOCK_MONOTONIC, &t0);
    int rs2 = 0;
    int *r2 = twoSumHashMap(big, size, target, &rs2);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double hash_ms = (t1.tv_sec - t0.tv_sec) * 1000.0 + (t1.tv_nsec - t0.tv_nsec) / 1e6;
    printf("  twoSumHashMap: %.2f ms  (indices [%d, %d])\n", hash_ms, r2[0], r2[1]);
    free(r2);

    printf("  --> Hash is %.1fx faster\n", loop_ms / hash_ms);
    free(big);
}

    // ── Summary ───────────────────────────────────────────────────────────────
    printf("\n=== Results: %d / %d passed ===\n", tests_passed, tests_run);
    return (tests_passed == tests_run) ? 0 : 1;
}