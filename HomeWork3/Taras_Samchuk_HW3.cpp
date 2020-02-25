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
/* int Revers()
{
    char InputStr[25]{};
    std::cout<<"input=";
    std::cin>>InputStr;
    size_t len{0};
    while(InputStr[len])len++;
    std::cout<<len;
    return 0;
} */
int Input(auto *input)
{
    return 0;
}
int main()
{

/*     char a='a';
    char b='b';
    std::cout<<a<<b<<std::endl;
    Swap(&a,&b);

    std::cout<<a<<b<<std::endl; */

    return 0;
}