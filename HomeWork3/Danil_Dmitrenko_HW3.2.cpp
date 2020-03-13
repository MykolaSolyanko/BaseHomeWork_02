#include <iostream>
using namespace std;

void qwerty(int numbers[], int count);

int main(){
	int array_size;
	cout<<"Enter size of your array: "<<endl;
	cin>>array_size;
	int arr[array_size]{};
	arr[array_size-1] = 0;
	cout<<"Enter int values to fill your array\n";
	int h=0;
	while(arr[array_size-1]==0){
		cin>>arr[h];
		h++;
	}
	qwerty(arr,array_size);
	for(int l=0;l<array_size;l++){
		cout<<arr[l]<<" ";
	}
	cout<<endl;
}
void qwerty(int numbers[], int count)
{
    for(int i = 0; i < count - 1; i++)
    {
        int currentMin = numbers[i];
        int currentMinIndex = i;

        for(int j = i + 1; j < count; j++)
        {
            if(currentMin > numbers[j])
            {
                currentMin = numbers[j];
                currentMinIndex = j;
            }
        }
           
            if(currentMinIndex != i){
                numbers[currentMinIndex] = numbers[i];
                numbers[i] = currentMin;

            }
        }
}

 
