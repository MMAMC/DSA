#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
  int left = 0;
  int right = n - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == key) {
      return mid;
    } else if (arr[mid] < key) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1; 
}

int main() {
  int arr[] = {2, 3, 4, 10, 40};
  int n = sizeof(arr) / sizeof(arr[0]);
  int key = 4;

  int index = binarySearch(arr, n, key);

  if (index != -1) {
    printf("Element %d found at index %d\n", key, index);
  } else {
    printf("Element %d not found\n", key);
  }

  return 0;
}
