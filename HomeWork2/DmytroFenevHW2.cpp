#include <cmath>
#include <iostream>
#include <string>

int main() 
{
    enum {FIRST_TASK=1, SECOND_TASK, THIRD_TASK, FOUR_TASK, FIVE_TASK};
    int task_choise;
    std::cout << "\tPath from ++C to C++(0x0421\'002B\'002B)\n";
    std::cout << "\tTask 1 - Sum of digits and average\n";
    std::cout << "\tTask 2 - Lucky ticket\n";
    std::cout << "\tTask 3 - Reversed number\n";
    std::cout << "\tTask 4 - Sum of odd number\n";
    std::cout << "\tTask 5 - Best divisor\n";
  
    std::cout << "\tEnter number of Task N1, N2, N3, N4, N5\n";
    std::cin >> task_choise;
    int x, n, tmp;
   
    switch (task_choise) 
    {
    case FIRST_TASK:
        n = 1; //число цифр
        std::cout << "\tEnter an integer" << std::endl;
        std::cin >> x;
        //xp = x; //сохранение х после подсчета количества цифр
        tmp = x;
        while ((tmp /= 10) > 0)
            n++;
        std::cout << "\tNumber of digits=" << n << std::endl;
        int sum;
        sum = 0;
        for (int ii = 0; ii < n; ii++) 
        {
            sum +=x % 10; //sum of digits
            x = x / 10;
        }
        std::cout << "\tsum=" << sum << std::endl;
        std::cout << "\tAverage number =" << sum / n << std::endl;
        break;
    case SECOND_TASK:
        int numberDigit;
        numberDigit = 6; //number of digits
        std::cout << "\tEnter six digits" << std::endl;
        std::cin >> x;
        int chisloDigits;
        chisloDigits = 1;
        tmp = x; //сохранение х после подсчета количества цифр
        while ((tmp /= 10) > 0)
            chisloDigits++;
        //std::cout << chisloDigits << std::endl;
        while ((chisloDigits < numberDigit) || (chisloDigits > numberDigit))
        {
            chisloDigits = 1;
            std::cout << "\tEnter not six  digits" << std::endl;
            std::cin >> x;
            tmp = x;
            while ((tmp /= 10) > 0)
                chisloDigits++;
        }
        int sum1, sum2;
        sum1 = 0;
        sum2 = 0;
        for (int ii = 0; ii < numberDigit;ii++)
        {
            if (ii < numberDigit / 2) 
             sum1 += x % 10; 
            else
                sum2 += x % 10;
            x = x / 10;
        }
        std::cout << sum1 << std::endl;
        std::cout << sum2 << std::endl;
        if (sum1 == sum2)
            std::cout << "\tAmount match" << std::endl;
        else
            std::cout << "\tAmounts do not match" << std::endl;
        break;
    case THIRD_TASK:
        int Chislo, reversedChislo, remainder;
        reversedChislo = 0;
        std::cout << "Enter Number" << std::endl;
        std::cin >> Chislo;
        while (Chislo != 0) 
        {
            remainder = Chislo % 10;
            reversedChislo = reversedChislo * 10 + remainder;
            Chislo /= 10;
        }
        std::cout << "reverse number=" << reversedChislo << std::endl;
        break;
    case FOUR_TASK:
        int Min, Max, cmin, cmax;
        Min = 1;
        Max = 50;
        cmin = -60;
        cmax = 90;
        int chislo;
        int nElement;
        sum = 0;
        std::cout << "\tEnter an integer in range...1...50" << std::endl;
        std::cin >> nElement;
        while ((nElement < Min) || (nElement > Max)) 
        {
            std::cout << "\tEnter an integer again in range 1...50" << std::endl;
            std::cin >> nElement;
        }
        for (int i = 0; i < nElement; i++) 
        {
            std::cout << "\tEnter an integer in range...-60...+90" << std::endl;
            std::cin >> chislo;
            while ((chislo < cmin) || (chislo > cmax)) 
            {
                std::cout << "\tEnter an integer again in range -60...+90" << std::endl;
                std::cin >> chislo;
            }
            if(chislo % 2 != 0) 
                sum += chislo;
        }
        std::cout << "\tSum of odd number=" << sum << std::endl;
        break;
    case FIVE_TASK:
        std::cout << "Enter x: ";
        std::cin >> x;
        int MaxDivider;
        int sumN;
        int sumDigitDivider; 
        sumDigitDivider = 0;//Max sum of divider
        for (int i = 1; i <= x; i++) 
        {
            if (x % i == 0) 
            {
                int n=1, tmp = i; //сохранение числа после подсчета количества цифр
                while ((tmp /= 10) > 0)
                    n++;
                int sumN = 0;
                tmp = i;
                for (int k = 0; k < n; k++) 
                {
                    sumN +=tmp % 10;
                    tmp = tmp / 10;
                }
                std::cout << "\ti=" << i << "\tn_Digit=" << n << "\tsumN=" << sumN << std::endl;
                if (sumN > sumDigitDivider) { sumDigitDivider = sumN; MaxDivider = i; }
                    
            }
        }
        std::cout << "MaxDivider=" << MaxDivider << std::endl;
        break;
        }
}
