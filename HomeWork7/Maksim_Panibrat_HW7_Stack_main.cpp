#include "Header.h"

int main()
{
    std::cout << "This program realize Stack by using template. \n";

    {
        Stack <int> st_int;
        std::cout << "Stack size: " << st_int.GetSizeStack() << std::endl;
        Pair pair{ true , "" };
        Value <int> topy;
        {
            std::cout << "Int Stack\n";
            while (pair.status == true) {
                int value;
                std::cin >> value;
                pair = st_int.push(value, pair);
                topy = st_int.top<int>();
                std::cout << "Pushed: " << topy.msg << std::endl;
            }
            std::cout << pair.msg << std::endl;
        }
        pair.status = true;
        pair.msg = " ";
        {
            for (;pair.status == true;pair = st_int.pop(pair)) {
                topy = st_int.top<int>();
                std::cout << "Popped: " << topy.msg << std::endl;
            }
        }
        st_int.clear();
        topy = st_int.top<int>();
        std::cout << "new top after clear: " << topy.msg << std::endl;
    }

    {
        Stack <float> st_float;
        Pair pair{ true , "" };
        Value <float> topy;
        {
            std::cout << "float Stack\n";
            while (pair.status == true) {
                float value;
                std::cin >> value;
                pair = st_float.push(value, pair);
                topy = st_float.top<float>();
                std::cout << "Pushed: " << topy.msg << std::endl;
            }
            std::cout << pair.msg << std::endl;
        }
        pair.status = true;
        pair.msg = " ";
        {
            for (;pair.status == true;pair = st_float.pop(pair)) {
                topy = st_float.top<float>();
                std::cout << "Popped: " << topy.msg << std::endl;
            }
        }
    }

    {
        Stack <char> st_char;
        Pair pair{ true , "" };
        Value <char> topy;
        {
            std::cout << "char Stack\n";
            while (pair.status == true) {
                char value;
                std::cin >> value;
                pair = st_char.push(value, pair);
                topy = st_char.top<char>();
                std::cout << "Pushed: " << topy.msg << std::endl;
            }
            std::cout << pair.msg << std::endl;
        }
        pair.status = true;
        pair.msg = " ";
        {
            for (;pair.status == true;pair = st_char.pop(pair)) {
                topy = st_char.top<char>();
                std::cout << "Popped: " << topy.msg << std::endl;
            }
        }
    }

    return 0;
}
