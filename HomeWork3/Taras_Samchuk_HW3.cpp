//Working with pointers
#include <iostream>
void SwapChar(char *first_ptr, char *second_ptr)
{
    char tmp='\0';
    char *tmp_ptr=&tmp;
    *tmp_ptr=*first_ptr;
    *first_ptr=*second_ptr;
    *second_ptr=*tmp_ptr;

}
int main()
{
    char Test[]{"123456789"};
    size_t TestLength = sizeof(Test)-1;
    for (size_t i = 0; i < TestLength/2; i++)
    {
        SwapChar(&Test[i],&Test[TestLength-1-i]);
        std::cout<<Test<<std::endl;
    }

    


    return 0;
}