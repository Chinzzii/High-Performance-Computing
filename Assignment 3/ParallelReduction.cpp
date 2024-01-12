#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    int arr[] = {5, 3, 8, 6, 7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min_val = arr[0];
    int max_val = arr[0];
    int sum = 0;

#pragma omp parallel for reduction(min:min_val) reduction(max:max_val) reduction(+: sum) 
    for(int i = 0; i < n; i++) {
        if (arr[i] < min_val)
        {
            min_val = arr[i];
        }
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
        sum += arr[i];
    }
    double average = (double)sum / n;
    
    cout << "Minimum: " << min_val << endl;
    cout << "Maximum: " << max_val << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    
    return 0;
}