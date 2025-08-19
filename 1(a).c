#include <stdio.h>

int linear_search(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {3, 7, 1, 9, 4};
    int target = 9;
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = linear_search(arr, size, target);
    printf("Index: %d\n", result);
    return 0;
}
