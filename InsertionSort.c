#include<stdio.h>
#include<conio.h>

void InsertionSort(int arr[], int n) {
    int temp, i, j;

    for (i = 1;i < n;i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0;i < size;i++)
        printf(" %d", arr[i]);
    printf("\n");
}

int main() {
    int arr[100], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nUnsorted Array:\n");
    printArray(arr, n);

    InsertionSort(arr, n);

    printf("\nSorted Array:\n");
    printArray(arr, n);

    getch();
    return 0;
}