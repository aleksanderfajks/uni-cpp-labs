#pragma once

#include <limits>

enum class Operation : unsigned int {
	ADD = 0,
	SUBTRACT = 1,
	MULTIPLY = 2,
	DIVIDE = 3,
	INVALID = std::numeric_limits<unsigned int>::max()
};

float add(float x, float y);
float subtract(float x, float y);
float multiply(float x, float y);
float divide(float x, float y);

float calculate(Operation operation, float x, float y);
