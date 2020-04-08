#include <iostream>
#include <utility>

class Stack{
  public:
    bool push(int value){
        if (index==100)
            return false;
        array[index++]=value;
        return true;
    }
    std::pair<int, bool> pop(){
        if(index == 0)
            return {0, false};
        return {array[--index], true};
    }
    std::pair<int, bool> top(){
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
    static const int arrSize{1000};
    int array[arrSize]{};
    size_t index{};
};

int main(int argc, char const *argv[]){
    Stack st;
    std::cout<<st.getSize();
}