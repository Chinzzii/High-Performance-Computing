#include <iostream>
#include <cstdlib>
#include <ctime>
#include <omp.h>

using namespace std;

void parallelBubbleSort(int arr[], int n)
{
    int i, j, temp;

#pragma omp parallel for default(none) shared(arr, n) private(i, j, temp)
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n = 10;
    int arr[n];

    srand(time(NULL));
    cout << "Original Array: \n";
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 + 1;
        cout << arr[i] << " ";
    }

    cout << endl;

    parallelBubbleSort(arr, n);

    cout << "\nSorted Array Using Parallel Bubble Sort: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
