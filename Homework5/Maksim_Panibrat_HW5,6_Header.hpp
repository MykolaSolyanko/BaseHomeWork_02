#pragma once
#include <utility>
#include <iostream>

struct Pair {
	bool status;
	const char* msg;
};

class Stack {
public:
	Pair push(int value) {
		Pair pair{ true, " " };
		std::cout << "Push index: " << index << std::endl;
		if (index == 9) {
			pair.status = false;
			pair.msg = "Stack full";
			return pair;
		}
		std::cout << "Pushed: " << value << std::endl;
		array[++index] = value;
		pair.msg = "Push success";
		return pair;
	}
	Pair pop() {
		Pair pair{ true, " " };
		if (index == 0) {
			pair.status = false;
			pair.msg = "Stack clear";
			return pair;
		}
		std::cout << "Popped " << array[index] << std::endl;
		--index;
		pair.msg = "Pop success";
		return pair;
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

	unsigned long long GetSizeStack() {
		return kSize;
	}


private:
	static const unsigned long long kSize{ 10 };
	int array[kSize]{};
	unsigned long long index{};
};
