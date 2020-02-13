#include <iostream>
//для переклaду повідомлень використвувався translate.google.com.ua
int main()
{
    //запрошення програми//


    //Програма для розвязання квадратного ріняння
    std::cout << "\tA program for solving a square swing" << std::endl;
    //Рівняння має вигляд
    std::cout << "\t The  equation  looks  like  this" << std::endl;
    //a * x ^ 2 + b * x + c = 0
    std::cout << "\t\ta*x^2+b*x+c=0" << std::endl;
    //,де
    std::cout << "\t,where" << std::endl;
    //a, b і c - коефієнти рівняння
    std::cout << "\t  a, b and c are the coefficients of\n\t    the equation" << std::endl;
    //х - корінь рівнняння
    std::cout << "\t  x is the root of the equation" << std::endl;
    int a, b, c, min_short, max_short;
    //Введіть коефіцієнти
    std::cout << "Enter the coefficients" << std::endl;
    //будемо перевіряти на правильність введення числа
    bool incorrect{true}; //true - неправильне число, false - правильне число

    //вводимо числа//

    min_short = -10; //std::numeric_limits<short>::min();
    max_short = 10;  //std::numeric_limits<short>::max();
    //Вводимо коефіцієнт а
    do
    {
        std::cout << "a=";
        std::cin >> a;
        std::cin.clear();
        incorrect = (a < min_short) || (a > max_short);
        if (incorrect)
        {
            std::cout << "\tYou entered an incorrect number." << std::endl;
            std::cout << "\tMust be between " << min_short << " and " << max_short << "!" << std::endl;
        }
        else if (a==0)
        {
            std::cout << "\tYou entered an incorrect number." << std::endl;
            std::cout << "\tCan't be zero" << std::endl;
            incorrect=true;
        }
    } while (incorrect);
    //вводимо коефіцієнт b
    do
    {
        std::cout << "b=";
        std::cin >> b;
        std::cin.clear();
        incorrect = (b < min_short) || (b > max_short);
        if (incorrect)
        {
            std::cout << "\tYou entered an incorrect number." << std::endl;
            std::cout << "\tMust be between " << min_short << " and " << max_short << "!" << std::endl;
        }
    } while (incorrect);
    //вводимо коефіцієнт с
    do
    {
        std::cout << "c=";
        std::cin >> c;
        std::cin.clear();
        incorrect = (c < min_short) || (c > max_short);
        if (incorrect)
        {
            std::cout << "\tYou entered an incorrect number." << std::endl;
            std::cout << "\tMust be between " << min_short << " and " << max_short << "!" << std::endl;
        }
    } while (incorrect);

    return 0;
}