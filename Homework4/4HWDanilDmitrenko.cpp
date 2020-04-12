#include <iostream>
#include <time.h>
#include <random> 
#include <cmath>

template <typename T>
void swap(T *x, T *y)  
{  
    T temp = *x;  
    *x = *y;  
    *y = temp;  
}  

template <typename T>   
void bubblesort(T arr[], T n, bool order)  
{  
    for (size_t i = 0; i < n-1; i++){        
        for (size_t j = 0; j < n-i-1; j++){  
            if(order){
                if (arr[j] > arr[j+1])  
                swap<T>(&arr[j], &arr[j+1]); 
            }
            else{
                if (arr[j] < arr[j+1])  
                swap<T>(&arr[j], &arr[j+1]);  
            }
        }             
    }
} 

template <typename T>
void selectionsort(T arr[], T n, bool order)  
{  
    size_t min_idx;  
    for (size_t i = 0; i < n-1; i++)  
    { 
        min_idx = i;  
        for (size_t j = i+1; j < n; j++) { 
            if(order){
                if (arr[j] < arr[min_idx])  
                    min_idx = j; 
            }
            else{
                if (arr[j] > arr[min_idx])  
                    min_idx = j;
            }
        }  
        swap<T>(&arr[min_idx], &arr[i]);  
    }  
} 

template <typename T>
void fillarray(T arr[], T size){
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<T> distribution(1,(std::numeric_limits<T>::max()));
    //T i{};
    for(size_t i=0;i<size;i++){
        arr[i]=distribution(generator);
    }
}

template <typename T>
void printarray(T arr[], T size){
    for(size_t i=0;i<size;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

int main(int argc, char const *argv[])
{
    int bintar[1000]{};
    //printarray<int>(bintar, 50);
    fillarray<int>(bintar, 1000);
    //printarray<double>(bintar, 10);
    double start=clock();
    bubblesort<int>(bintar, 1000, true);
    double end=clock();
    double binttime=round(((end-start)/CLOCKS_PER_SEC)*1000000)/1000000;
    std::cout<<"Bubble sort int array[1000]: "<<binttime<<" seconds"<<std::endl;
    //printarray<int>(bintar, 500);
    
    double bdblar[500]{};
    //printarray<int>(bintar, 50);
    fillarray<double>(bdblar, 500);
    //printarray<double>(bintar, 10);
    double startd=clock();
    bubblesort<double>(bdblar, 500, false);
    double endd=clock();
    double bdbltime=round(((endd-startd)/CLOCKS_PER_SEC)*1000000)/1000000;
    std::cout<<"Bubble sort double array[500]: "<<bdbltime<<" seconds"<<std::endl;
    //printarray<int>(bintar, 500);

    
    int sintar[1000]{};
    //printarray<int>(sintar, 500);
    fillarray<int>(sintar, 1000);
    //printarray<int>(sintar, 10);
    double starta=clock();
    selectionsort<int>(sintar, 1000, true);
    double enda=clock();
    double sinttime=round(((enda-starta)/CLOCKS_PER_SEC)*1000000)/1000000;
    std::cout<<"Selection sort int array[1000]: "<<sinttime<<" seconds"<<std::endl;
    //printarray<int>(sintar, 500);

    double sdblar[500]{};
    //printarray<int>(sintar, 500);
    fillarray<double>(sdblar, 500);
    //printarray<int>(sintar, 10);
    double startad=clock();
    selectionsort<double>(sdblar, 500, false);
    double endad=clock();
    double sdbltime=round(((endad-startad)/CLOCKS_PER_SEC)*1000000)/1000000;
    std::cout<<"Selection sort double array[500]: "<<sdbltime<<" seconds"<<std::endl;
    //printarray<int>(sintar, 500);
    return 0;
}
