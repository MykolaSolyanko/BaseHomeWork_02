#pragma once
#include <utility>
#include <iostream>

struct Pair {
	bool status;
	const char* msg;
};

template <typename T>
class Stack {
public:
	Pair push(T value, Pair pair) {
		std::cout << "Index: " << index << std::endl;
		if (index == kSize) {
			return {false, "Stack full" };
		}
		array[++index] = value;
		return {true, "Push success" };
	}
	Pair pop(Pair pair) {
		if (index == 0) {
			return { false, "Stack clear" };
		}
		array[index--];
		return {true, "Pop success"};
	}
	void clear() {
		if (index == 0) {
			return;
		}
		index = 0;
	}
	T top() const {
		if (index == 0) {
			return 0;
		}
		return array[index];
	}

	const unsigned long long GetSizeStack() {
		return kSize;
	}


private:
	static const unsigned long long kSize{ 5 };
	T array[kSize]{};
	unsigned long long index{};
};
