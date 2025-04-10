#include<stdio.h>
#include<conio.h>

void SelectionSort(int arr[], int n) {
    int i, j;
    int pos, least;

    for (i = 0;i < n - 1;i++) {
        pos = i;
        least = arr[pos];

        for (j = i + 1;j < n;j++) {
            if (least > arr[j]) {
                pos = j;
                least = arr[pos];
            }
        }

        if (pos != i) {
            int temp = arr[i];
            arr[i] = least;
            arr[pos] = temp;
        }
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

    SelectionSort(arr, n);

    printf("\nSorted Array:\n");
    printArray(arr, n);

    getch();
    return 0;
}