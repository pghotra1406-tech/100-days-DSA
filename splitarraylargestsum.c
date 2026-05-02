#include <stdio.h>

long long max(long long a, long long b) {
    return a > b ? a : b;
}

int canSplit(int* nums, int n, int k, long long limit) {
    int parts = 1;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] > limit) return 0;

        if (sum + nums[i] > limit) {
            parts++;
            sum = nums[i];
        } else {
            sum += nums[i];
        }
    }

    return parts <= k;
}

int splitArray(int* nums, int n, int k) {
    long long low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        low = max(low, nums[i]);
        high += nums[i];
    }

    long long ans = high;

    while (low <= high) {
        long long mid = (low + high) / 2;

        if (canSplit(nums, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return (int)ans;
}
