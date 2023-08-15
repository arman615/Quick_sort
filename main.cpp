#include <iostream>
#include <vector>
#include <ctime>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortFirst(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSortFirst(arr, low, pivotIndex - 1);
        quickSortFirst(arr, pivotIndex + 1, high);
    }
}

void quickSortLast(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = high;
        int pivotValue = arr[pivotIndex];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (arr[j] < pivotValue) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[pivotIndex]);
        pivotIndex = i + 1;
        quickSortLast(arr, low, pivotIndex - 1);
        quickSortLast(arr, pivotIndex + 1, high);
    }
}

void quickSortMedianOfThree(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < arr[low])
            std::swap(arr[mid], arr[low]);
        if (arr[high] < arr[low])
            std::swap(arr[high], arr[low]);
        if (arr[high] < arr[mid])
            std::swap(arr[high], arr[mid]);
        int pivotIndex = partition(arr, low, high);
        quickSortMedianOfThree(arr, low, pivotIndex - 1);
        quickSortMedianOfThree(arr, pivotIndex + 1, high);
    }
}

void quickSortRandomized(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int randomIndex = low + std::rand() % (high - low + 1);
        std::swap(arr[randomIndex], arr[high]);
        int pivotIndex = partition(arr, low, high);
        quickSortRandomized(arr, low, pivotIndex - 1);
        quickSortRandomized(arr, pivotIndex + 1, high);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int size = arr.size();
    std::cout << "Original array: ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
    std::srand(std::time(0));
    quickSortFirst(arr, 0, size - 1);
    // quickSortLast(arr, 0, size - 1);
    // quickSortMedianOfThree(arr, 0, size - 1);
    // quickSortRandomized(arr, 0, size - 1);
    std::cout << "Sorted array: ";
    for (int num : arr){
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
