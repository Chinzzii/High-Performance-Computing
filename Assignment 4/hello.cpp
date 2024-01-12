#include<iostream>
#include<omp.h>

using namespace std;

int main(){

    #pragma omp parallel num_threads(4)
    {
        std::cout<<"Number of available threads: " << omp_get_num_threads; 
        std::cout<<"Thread Num: " << omp_get_thread_num;
        std::cout<<"Hello World!";
    }
    return 0;
}