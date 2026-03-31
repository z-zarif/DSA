#include <bits/stdc++.h>
using namespace std;

// Fast I/O
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
// take the array, build a maxheap, then continously push min at the front and reduce size;
void heapify(vector<int> &arr, int i, int n)
{
    int leftChild = (2 * i) + 1;
    int rightChild = (2 * i) + 2;
    int largest = i;
    if (leftChild < n && arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }
    if (rightChild < n && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}
void heapSort(vector<int> &arr)
{
    int n = arr.size();
    int startidx = (n / 2) - 1;
    for (int i = startidx; i >= 0; i--)
    {
        heapify(arr, i, n);
    }
    vector<int> sortedArr(n);
    int n2 = arr.size();
    // for (int i = 0; i < n; i++)
    // {
    //     sortedArr[i] = arr[0];
    //     arr[0] = arr[n2 - 1];
    //     n2--;
    //     heapify(arr, 0, n2);
    // }
    //! inPlace
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[i], arr[0]);
        heapify(arr, 0, i);
    }

    //! using extra vector;
    int idx = n - 1;
    while (n > 0)
    {
        sortedArr[idx--] = arr[0];
        swap(arr[0], arr[n - 1]);
        n--;
        heapify(arr, 0, n);
    }
}

int main()
{
    vector<int> arr = {9, 4, 3, 8, 10, 2, 5};

    heapSort(arr);

    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
}
// Sorted array is
// 2 3 4 5 8 9 10