#include "Header.h"

int main()
{
    std::cout << "This program realize Stack by using template. \n";

    {
        Stack <int> st_int;
        std::cout << "Stack size: " << st_int.GetSizeStack() << std::endl;
        {
            std::cout << "Int Stack\n";
            Pair pair{ true , "" };
            while (pair.status == true) {
                int value;
                std::cin >> value;
                pair = st_int.push(value, pair);
                std::cout << "Pushed: " << st_int.top() <<std::endl;
            }
            std::cout << pair.msg << std::endl;
        }
        {
            for (Pair pair{ true , "" };pair.status == true;pair = st_int.pop(pair)) {
                std::cout << "Popped: " << st_int.top() << std::endl;
            }
        }
        st_int.clear();
        std::cout << "new top after clear: " << st_int.top() << std::endl;
    }

    {
        Stack <float> st_float;
        {
            std::cout << "float Stack\n";
            Pair pair{ true , "" };
            while (pair.status == true) {
                float value;
                std::cin >> value;
                pair = st_float.push(value, pair);
                std::cout << "Pushed: " << st_float.top() << std::endl;
            }
            std::cout << pair.msg << std::endl;
        }
        {
            for (Pair pair{ true , "" };pair.status == true;pair = st_float.pop(pair)) {
                std::cout << "Popped: " << st_float.top() << std::endl;
            }
        }
    }

    {
        Stack <char> st_char;
        {
            std::cout << "char Stack\n";
            Pair pair{ true , "" };
            while (pair.status == true) {
                char value;
                std::cin >> value;
                pair = st_char.push(value, pair);
                std::cout << "Pushed: " << st_char.top() << std::endl;
            }
            std::cout << pair.msg << std::endl;
        }
        {
            for (Pair pair{ true , "" };pair.status == true;pair = st_char.pop(pair)) {
                std::cout << "Popped: " << st_char.top() << std::endl;
            }
        }
    }

    return 0;
}
