#include <stdio.h>
#include <math.h>
typedef union {
	float floatValue;
	unsigned int bitPattern;
	} FloatUnion;

typedef union {
	double doubleValue;
	unsigned long long bitPattern;
	} DoubleUnion;

void printFloatBitPattern(float f) {
	FloatUnion unionData;
	unionData.floatValue = f;
	printf("Bit pattern of %f (float): ", f);

	for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; i--) {
		printf("%d", (unionData.bitPattern >> i) & 1);
		if (i % 8 == 0) {
		printf(" ");
		}
	}
	printf("\n");
}

void printFloatFromBits(char binary[])
{	int sign = binary[0] - '0';
	int exponent = 0;
	for (int i = 1; i <= 8; ++i) {
		exponent += (binary[i] - '0') * pow(2, 8 - i);
				    }
	int mantissa = 0;
	for (int i = 9; i <= 31; ++i) {
		mantissa += (binary[i] - '0') * pow(2, 31 - i);
	}

	int bias = 127;
	int actual_exponent = exponent - bias;
	float mantissa_value = 1.0f + (mantissa / pow(2, 23));
	float decimal_value = pow(-1, sign) * mantissa_value * pow(2, actual_exponent);

	printf("Decimal Value: %f\n", decimal_value);
}

void printDoubleBitPattern(double d) {
	DoubleUnion unionData;
	unionData.doubleValue = d;
	printf("Bit pattern of %lf (double): ", d);

	for (int i = sizeof(unsigned long long) * 8 - 1; i >= 0; i--) {
		printf("%lld", (unionData.bitPattern >> i) & 1);
		if (i % 8 == 0) {
			printf(" ");
		}
	}
	printf("\n");
}

void printDoubleFromBits(char binary[]) {
	int sign = binary[0] - '0';
	int exponent = 0;
	for (int i = 1; i <= 11; ++i) {
		exponent += (binary[i] - '0') * pow(2, 11 - i);
	}
	long long mantissa = 0;
	for (int i = 12; i <= 63; ++i) {
		mantissa += (binary[i] - '0') * pow(2, 63 - i);
	}

	int bias = 1023;
	int actual_exponent = exponent - bias;
	float mantissa_value = 1.0f + (mantissa / pow(2, 52));
	float decimal_value = pow(-1, sign) * mantissa_value * pow(2, actual_exponent);

	printf("Decimal Value: %f\n", decimal_value);
}

int main() {
	float floatNumber;
	double doubleNumber;

	printf("Enter a float number: ");
	scanf("%f", &floatNumber);
	printFloatBitPattern(floatNumber);

	printf("Enter a 32-bit pattern for float: ");
	char floatBits[33];
	scanf("%32s", floatBits);
	printFloatFromBits(floatBits);

	printf("Enter a double number: ");
	scanf("%lf", &doubleNumber);
	printDoubleBitPattern(doubleNumber);

	printf("Enter a 64-bit pattern for double: ");
	char doubleBits[65];
	scanf("%64s", doubleBits);
	printDoubleFromBits(doubleBits);

	return 0;
}

