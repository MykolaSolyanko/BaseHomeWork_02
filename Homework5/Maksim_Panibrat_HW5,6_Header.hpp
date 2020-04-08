#pragma once
#include <utility>
#include <iostream>

struct Pair {
	bool status;
	const char* msg;
};

class Stack {
public:
	Pair push(int value, Pair pair) {
		std::cout << "Push index: " << index << std::endl;
		if (index == kSize) {
			return {false, "Stack full" };
		}
		std::cout << "Pushed: " << value << std::endl;
		array[++index] = value;
		return {true, "Push success" };
	}
	Pair pop(Pair pair) {
		if (index == 0) {
			return { false, "Stack clear" };
		}
		std::cout << "Popped " << array[index--] << std::endl;
		return {true, "Pop success"};
	}
	void clear() {
		if (index == 0) {
			return;
		}
		index = 0;
	}
	int top() const {
		if (index == 0) {
			return 0;
		}
		return array[index];
	}

	const unsigned long long GetSizeStack() {
		return kSize;
	}


private:
	static const unsigned long long kSize{ 10 };
	int array[kSize]{};
	unsigned long long index{};
};

