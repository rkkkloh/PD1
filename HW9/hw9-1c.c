#include <stdio.h>

typedef union {
	float f;
	struct {
	unsigned int mantissa : 23;
	unsigned int exponent : 8;
	unsigned int sign : 1;
	} parts;
} IEEE_754;

typedef union {
	double d;
	struct {
	unsigned long long mantissa : 52;
	unsigned int exponent : 11;
	unsigned int sign : 1;
	} parts;
} IEEE_754_double;

void printFloatBitPattern(float num) {
	IEEE_754 converter;
	converter.f = num;

	printf("Float Value: %f\n", converter.f);
	printf("Bit Pattern: %d", converter.parts.sign);

	for (int i = 8 - 1; i >= 0; --i) {
		printf("%d", (converter.parts.exponent >> i) & 1);
	}

	for (int i = 23 - 1; i >= 0; --i) {
		printf("%d", (converter.parts.mantissa >> i) & 1);
	}
	printf("\n");
}

float binaryToDecimal(char binary[]) {
	IEEE_754 ieee;

	ieee.parts.sign = binary[0] - '0';
	ieee.parts.exponent = 0;
	ieee.parts.mantissa = 0;

	for (int i = 1; i <= 8; ++i) {
		ieee.parts.exponent <<= 1;
		ieee.parts.exponent |= binary[i] - '0';
	}

	for (int i = 9; i <= 31; ++i) {
		ieee.parts.mantissa <<= 1;
		ieee.parts.mantissa |= binary[i] - '0';
	}

	int actualExponent = ieee.parts.exponent - 127;

	float value = 1.0;
	if (actualExponent >= -126 && actualExponent <= 127) {
		for (int i = 0; i < 23; ++i) {
			value += ((ieee.parts.mantissa >> (22 - i)) & 1) * (1.0 / (1 << (i + 1)));
		}
		value *= (1 << actualExponent);
	} else {
		value = 0.0;
	}

	if (ieee.parts.sign)
	value = -value;

	return value;
}

void printDoubleBitPattern(double num) {
	IEEE_754_double converter;
	converter.d = num;

	printf("Double Value: %lf\n", converter.d);
	printf("Bit Pattern: %d", converter.parts.sign);

	for (int i = 10; i >= 0; --i) {
		printf("%u", (converter.parts.exponent >> i) & 1);
	}

	for (int i = 51; i >= 0; --i) {
		printf("%llu", (converter.parts.mantissa >> i) & 1);
	}
	printf("\n");
}

double binaryToDecimalDouble(char binary[]) {
	IEEE_754_double ieee;

	ieee.parts.sign = binary[0] - '0';
	ieee.parts.exponent = 0;
	ieee.parts.mantissa = 0;

	for (int i = 1; i <= 11; ++i) {
		ieee.parts.exponent <<= 1;
		ieee.parts.exponent |= binary[i] - '0';
	}

	for (int i = 12; i <= 63; ++i) {
		ieee.parts.mantissa <<= 1;
		ieee.parts.mantissa |= binary[i] - '0';
	}

	int actualExponent = ieee.parts.exponent - 1023;

		double value = 1.0;
		double multiplier = 1.0;
	for (int i = 0; i < 52; ++i) {
		multiplier *= 0.5;
		value += ((ieee.parts.mantissa >> (51 - i)) & 1) * multiplier;
	}

	while (actualExponent > 0) {
		value *= 2.0;
		actualExponent--;
	}
	while (actualExponent < 0) {
		value *= 0.5;
		actualExponent++;
	}

	if (ieee.parts.sign)
		value = -value;

	return value;
}

int main() {
	float floatValue;
	double doubleValue;
	printf("Enter a float number: ");
	scanf("%f", &floatValue);

	printFloatBitPattern(floatValue);

	char fbinary[33];
	printf("Enter the IEEE-754 binary representation (32 bits): ");
	scanf("%32s", fbinary);

	float fdecimalValue = binaryToDecimal(fbinary);
	printf("Decimal value: %f\n", fdecimalValue);

	printf("Enter a double number: ");
	scanf("%lf", &doubleValue);
	printDoubleBitPattern(doubleValue);

	char dbinary[65];
	printf("Enter the IEEE-754 binary representation (64 bits): ");
	scanf("%64s", dbinary);

	double ddecimalValue = binaryToDecimalDouble(dbinary);
	printf("Decimal value: %lf\n", ddecimalValue);
	return 0;

}

