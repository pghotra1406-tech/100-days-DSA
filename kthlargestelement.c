#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int nums[], int left, int right) {
    int pivot = nums[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (nums[j] <= pivot) {
            swap(&nums[i], &nums[j]);
            i++;
        }
    }

    swap(&nums[i], &nums[right]);
    return i;
}

int quickSelect(int nums[], int left, int right, int kIndex) {
    if (left == right)
        return nums[left];

    int pivotIndex = partition(nums, left, right);

    if (pivotIndex == kIndex)
        return nums[pivotIndex];
    else if (pivotIndex < kIndex)
        return quickSelect(nums, pivotIndex + 1, right, kIndex);
    else
        return quickSelect(nums, left, pivotIndex - 1, kIndex);
}

int findKthLargest(int* nums, int numsSize, int k) {
    int target = numsSize - k;
    return quickSelect(nums, 0, numsSize - 1, target);
}
