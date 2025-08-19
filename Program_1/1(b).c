#include <stdio.h>

int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 4, 7, 9};
    int target = 7;
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = binary_search(arr, size, target);
    printf("Index: %d\n", result);
    return 0;
}
