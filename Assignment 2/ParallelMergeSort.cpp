#include <iostream>
#include <vector>
#include <algorithm>
#include <omp.h>

using namespace std;

void merge(vector<int> &arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

#pragma omp parallel sections
        {
#pragma omp section
            {
                merge_sort(arr, l, m);
            }
#pragma omp section
            {
                merge_sort(arr, m + 1, r);
            }
        }

        merge(arr, l, m, r);
    }
}

int main()
{
    vector<int> arr = {4, 3, 6, 1, 9, 2, 7, 8, 5};
    int n = arr.size();

    cout << "Original Array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    merge_sort(arr, 0, n - 1);

    cout << "\nSorted Array Using Parallel Merge Sort:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
