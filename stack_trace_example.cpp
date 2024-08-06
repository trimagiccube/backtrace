#include <iostream>
#include <execinfo.h>
#include <cstdlib>
#include <cxxabi.h>

void printStackTrace() {
	void *array[10];
	size_t size;

	// 获取调用栈的地址
	size = backtrace(array, 10);

	// 打印调用栈
	std::cerr << "Stack trace:\n";
	char **symbols = backtrace_symbols(array, size);
	for (size_t i = 0; i < size; ++i) {
		// 解码符号名称
		std::cerr << symbols[i] << std::endl;
	}
	free(symbols);
}

void functionC() {
	printStackTrace();
}

void functionB() {
	functionC();
}

void functionA() {
	functionB();
}

int main() {
	functionA();
	return 0;
}
