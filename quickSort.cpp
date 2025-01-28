#include <iostream>
using namespace std;
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int slowIndex = low - 1;
    for (int fastIndex = low; fastIndex <= high; fastIndex++) {
        if (arr[fastIndex]<=pivot) {
            slowIndex++;
	    if(arr[slowIndex]>arr[fastIndex])
		{
            	swap(arr[slowIndex], arr[fastIndex]);
		}
        }
    }
    return slowIndex;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}