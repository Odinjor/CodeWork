// Program: Calculator 
// Author's name: Ugpchukwu Odinjor
// Purpose: The overall purpose of this program is to simulate an actual calculator. By inputting integer expressions the user will be able to perform simple arithmetic operations.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

	// ---- Addition Function ---- //
float add (float left,  float right) {
	return left + right;
}

	// ---- Subtraction Function ---- //
float subtr (float left, float right) {
	return left - right;
}

	// ---- Multiplication Function ---- //
float multi (float left, float right) {
	return left * right;
}

	// ---- Division Function ---- //
float divi (float left, float right) {
	return left / right;
}

	// ---- Power Function ---- //
float power (float left, float right) {
	float result = 1.0;
	for (int i = 0; i < right; i++) {
		result *= left;
	}
	return result;
}

	// ---- Floor Division Function ---- //
float flo_div (float left, float right) {
	return floor(left / right);
}

int main() {
	// Arithmetic Operator 
	char oper[3];
	// Operands
	float left, right;
	float result;
	
	printf("Please enter an expression:\n:> ");
	scanf("%f %s %f", &left, oper, &right);
	
	// Cases for Operator 
	if (strcmp(oper, "+") == 0) {
		result = add(left, right);
	}
	else if (strcmp(oper, "-") == 0) {
		result = subtr(left, right);
	}
	else if (strcmp(oper, "*") == 0) {
		result = multi(left, right);
	}
	else if (strcmp(oper, "/") == 0) {
		result = divi(left, right);
	}
	else if (strcmp(oper, "**") == 0) {
		result = power(left, right);
	}
	else if (strcmp(oper, "//") == 0) {
		result = flo_div(left, right);
	}
	else {
		printf("Error: Invalid Operator (%s)\n", oper);
		return 0;
	}
	// Print Statement 
	printf("%.2f %s %.2f = %.2f\n", left, oper, right, result);
	return 0;
}

