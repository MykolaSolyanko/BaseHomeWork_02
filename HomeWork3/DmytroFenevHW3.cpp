#include <iostream> 
#include<ctime>

int main()
{
    setlocale(LC_ALL, "Russian");
    int z;
    int const SIZE = 10;
    std::cout << "Задача №1 или 2\n";
    std::cin >> z;
    char arrL[]{ "HelloWorld" };
    switch (z)
    {
    case 1:
        std::cout << "\tИсходный текст ---\n" << "\t";;
        for (int i = 0; i < 10; i++) 
        {
            std::cout << arrL[i];
        }
        std::cout << "\n";
        srand(time(NULL));
        int arrp[SIZE];
        bool alreadyThere;
        for (int i = 0; i < SIZE; )
        {
            alreadyThere = false;
            int newRandom = rand() % 10;
            for (int j = 0; j < i; j++)
            {
                if (arrp[j] == newRandom)
                {
                    alreadyThere = true;
                    break;
                }
            }
            if (!alreadyThere)
            {
                arrp[i] = newRandom;
                i++;
            }
        }
        std::cout << "\tИндексы для перестановки ---\n" << "\t";
        for (int i = 0; i < 10; i++)
        {
            std::cout <<arrp[i];
        }
        std::cout << "\n";
        std::cout << "\tТекст со случайной перестановкой ---\n" << "\t";
        for (int i = 0; i < 10; i++) {
            std::cout << arrL[arrp[i]];
        }
        break;
    case 2:
        int size = 10; // размер массива // Ввод количества элементов массива 
        //int size1;
        std::cout << "Число точок n =10\n";
        std::cout << "Введіть число=\n";
        int a;
        int arr[10]{ 0,0,0,0,0,0,0,0,0,0 };
        int arr1[10];
        for (int i = 0; i < size; i++)
        {
            std::cin >> a;
            arr[i] = a;
            for (int ii = 0; ii < 10; ii++)
            {
                std::cout << arr[ii];
            }
            std::cout << "\n";
            for (int ik = 0; ik < 10; ik++)
            {
                arr1[ik] = arr[ik];
            }
            for (int j = 0; j < size - 1; j++)
            {
                for (int jj = 0; jj < size - j - 1; jj++)
                {
                    if (arr1[jj] > arr1[jj + 1])
                    { // меняем элементы местами 
                        int temp = arr1[jj];
                        arr1[jj] = arr1[jj + 1];
                        arr1[jj + 1] = temp;
                    }
                }
            }

            for (int k = 0; k < size; k++)
            {
                std::cout << arr1[k];
            }
            std::cout << "\n";
        }
        break;
    }
}
