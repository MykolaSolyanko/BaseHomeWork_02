#pragma once
#include <utility>
#include <iostream>

struct Pair {
	bool status;
	const char* msg;
};

template <typename T>
struct Value {
	bool status;
	T msg;
};

template <typename T, const long long kSize = 5>
class Stack {
public:
	Pair push(T value, Pair pair) {
		std::cout << "Index: " << index << std::endl;
		if (index == kSize) {
			return { false, "Stack full" };
		}
		array[++index] = value;
		return { true, "Push success" };
	}
	Pair pop(Pair pair) {
		if (index == 0) {
			return { false, "Stack clear" };
		}
		array[index--];
		return { true, "Pop success" };
	}
	void clear() {
		if (index == 0) {
			return;
		}
		index = 0;
	}
	
	template <typename T>
	Value <T> top() const {
		Value <T> topy{ false, 0 };
		if (index == 0) {
			return topy;
		}
		topy.status = true;
		topy.msg = array[index];
		return topy;
	}

	const unsigned long long GetSizeStack() {
		return kSize;
	}


private:
	T array[kSize]{};
	unsigned long long index{};
};
