/*
 * Copyright (c) 2025 NorthernL1ghts. All rights reserved.
 *
 * This file is part of the Galilee.
 * Unauthorized copying, modification, or distribution of this file,
 * via any medium, is strictly prohibited except as permitted under
 * the terms outlined in the LICENSE file.
 *
 * For licensing details, contributions, or inquiries, refer to LICENSE
 * or contact:
 * NorthernL1ghts Software Division
 */

#include <iostream>
#include <windows.h>

#ifdef GL_PLATFORM_WINDOWS
#define COMMENT_STACK_SYMBOL '?'
#elif defined(GLFW_PLATFORM_LINUX)
#define COMMENT_STACK_SYMBOL '@'
#else
#define COMMENT_STACK_SYMBOL '#'
#endif

namespace ConsoleUtils {
	inline void EnableAnsi() {
#ifdef GL_PLATFORM_WINDOWS
		HANDLE h_Out = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD mode;
		GetConsoleMode(h_Out, &mode);
		mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		SetConsoleMode(h_Out, mode);
#endif
	}
}

void DrawSquare(int size, char symbol) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			std::cout << symbol << ' ';
		}
		std::cout << '\n';
	}
}

void DrawTriangle(int size, char symbol) {
	for (int i = 1; i <= size; ++i) {
		for (int j = 0; j < i; ++j) {
			std::cout << symbol << ' ';
		}
		std::cout << '\n';
	}
}

void DrawCircle(int radius, char symbol) {
	for (int y = -radius; y <= radius; ++y) {
		for (int x = -radius; x <= radius; ++x) {
			if (x * x + y * y <= radius * radius) {
				std::cout << symbol << ' ';
			}
			else {
				std::cout << "  ";
			}
		}
		std::cout << '\n';
	}
}

int main() {
	ConsoleUtils::EnableAnsi();

	std::cout << "Square:\n";
	DrawSquare(5, COMMENT_STACK_SYMBOL);

	std::cout << "\nTriangle:\n";
	DrawTriangle(5, COMMENT_STACK_SYMBOL);

	std::cout << "\nCircle:\n";
	DrawCircle(5, COMMENT_STACK_SYMBOL);

	return 0;
}