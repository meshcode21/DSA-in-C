#include<stdio.h>
#include<conio.h>

void Merge(int arr[], int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = start;
    int temp[end - start + 1];

    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= end) {
        temp[k++] = arr[j++];
    }

    for (int i = start; i <= end; i++) {
        arr[i] = temp[i];
    }
}

void MergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;

        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);

        Merge(arr, start, mid, end);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf(" %d", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = { 5,3,76,1,53 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sort:\n");
    printArray(arr, n);

    MergeSort(arr, 0, n - 1);

    printf("After Sort:\n");
    printArray(arr, n);
    return 0;
}