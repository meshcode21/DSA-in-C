#include<stdio.h>
#include<conio.h>

// int partition(int arr[], int start, int end) {
//     int p = arr[end], index = start - 1;
//     int temp; 

//     for (int j = start; j < end; j++) {
//         if (arr[j] <= p) {
//             index++;
//             temp = arr[index];
//             arr[index] = arr[j];
//             arr[j] = temp;
//         }
//     }
//     index++;
//     temp = arr[index];
//     arr[index] = arr[end];
//     arr[end] = temp;

//     return index;
// }

int partition(int arr[], int start, int end){
    int l = start, r = end;
    int p = arr[start];

    while (l < r){
        while(arr[l] <= p) l++;
        while(arr[r] >= p) r--;
        if(l<r){
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
        }
    }
    arr[start] = arr[r];
    arr[r] = p;
    return r;
}

void QuickSort(int arr[], int start, int end) {
    if (start < end)
    {
        int pi = partition(arr, start, end);
        QuickSort(arr, start, pi - 1);
        QuickSort(arr, pi + 1, end);
    }
}

void printArray(int arr[], int size){
    for(int i = 0; i<size; i++)
        printf(" %d",arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {4,1,5,7,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Before Sort:\n");
    printArray(arr,n);

    QuickSort(arr,0,n-1);

    printf("After Sort:\n");
    printArray(arr,n);
    return 0;
}