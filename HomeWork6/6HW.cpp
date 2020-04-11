#include <iostream>
#include <utility>

template <typename T, unsigned ARSZ>
class Stack{
  public:
    bool push(T value){
        if (index==100)
            return false;
        array[index++]=value;
        return true;
    }
    std::pair<T, bool> pop(){
        if(index == 0)
            return {0, false};
        return {array[--index], true};
    }
    std::pair<T, bool> top(){
        if(index == 0)
            return {0, false};
        return {array[index-1], true};
    }
    void clear(){
        if(index == 0)
            return;
        index = 0;
    }
    bool empty() const{
        return index == 0;
    }
    int getSize() const{
        return arrSize;
    }
  private: 
    static const int arrSize{ARSZ};
    T array[arrSize]{};
    size_t index{};
};

int main(int argc, char const *argv[]){
    Stack<double, 1000> st;
}
