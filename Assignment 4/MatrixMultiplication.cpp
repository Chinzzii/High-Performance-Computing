#include <iostream>
#include <omp.h>

using namespace std;

const int N = 3;

int main()
{
    double A[N][N], B[N][N], C[N][N];
    int i, j, k;

    // Initialize matrices A and B
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            A[i][j] = i * j;
            B[i][j] = j * j;
        }
    }

// Parallelized matrix multiplication using OpenMP
#pragma omp parallel for private(j, k)
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < N; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Matrix A:\n";
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    cout<<endl;
    cout << "Matrix B:\n";
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            cout << B[i][j] << "\t";
        }
        cout << endl;
    }
    cout<<endl;
    // Print the result and execution time
    cout << "Result Matrix:\n";
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}