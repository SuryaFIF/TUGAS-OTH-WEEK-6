#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* read_integers(int size) {
    int* arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

int twoStacks(int maxSum, int a_count, int* a, int b_count, int* b) {
    int i = 0, j = 0, count = 0, sum = 0;

    // Simulate removing elements from stack a
    while (i < a_count && sum + a[i] <= maxSum) {
        sum += a[i];
        i++;
        count++;
    }

    // Simulate removing elements from stack b, while adjusting sum
    while (j < b_count && i >= 0) {
        sum += b[j];
        j++;

        // If sum exceeds maxSum, remove elements from stack a until it's within limit
        while (sum > maxSum && i > 0) {
            i--;
            sum -= a[i];
        }

        // Update count if the current sum is within limit and greater than previous count
        if (sum <= maxSum && i + j > count) {
            count = i + j;
        }
    }

    return count;
}

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);

    for (int i = 0; i < numTestCases; i++) {
        int n, m, maxSum;
        scanf("%d %d %d", &n, &m, &maxSum);

        int* stackA = read_integers(n);
        int* stackB = read_integers(m);

        int result = twoStacks(maxSum, n, stackA, m, stackB);
        printf("%d\n", result);

        free(stackA);
        free(stackB);
    }

    return 0;
}