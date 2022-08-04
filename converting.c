#include "constants.h"
#include "constants.c"
#include "converting.h"
#include "utils.h"

#define BIN_MACHINE_CODE_LENGTH 10
#define TEN_BITS_OF_ONE 1023


/* Converts decimal number to binary with the Two's complement method */
unsigned long convertDtoB(int decimal_number){
    unsigned long bin_number;
    int remainder, index, num_of_bits;

    bin_number = 0;
    index = 1;
    num_of_bits = 0;

    if(decimal_number < 0){
    decimal_number = -decimal_number;
    
    /* Bit conversion */
    decimal_number = decimal_number ^ TEN_BITS_OF_ONE;
    
    while (decimal_number != 0){
        num_of_bits++;
        remainder = decimal_number % 2;
        decimal_number /= 2;
        bin_number += remainder * index;
        index *= BIN_MACHINE_CODE_LENGTH;
        }
        bin_number += 1;
    }

    /* If the decimal number is positive. */
    else while (decimal_number != 0) {
        remainder = decimal_number % 2;
        decimal_number /= 2;
        bin_number += remainder * index;
        index *= BIN_MACHINE_CODE_LENGTH;
    }

    return bin_number;
}


/* Converts binary number to decimal */
int convertBtoD(unsigned long bin_number){
    int decimal_number, remainder, index;

    decimal_number = 0;
    index = 1;

    while(bin_number > 0){
        remainder = bin_number % BIN_MACHINE_CODE_LENGTH;
        bin_number /= BIN_MACHINE_CODE_LENGTH;
        decimal_number += remainder * index;
        index *= 2;
    }

    return decimal_number;
}


/* Converts decimal number to base32 */
char *convertDtoB32(int decimal_number) {
    int remainder, index;
    char str[LENGTH_OF_32_ITEM];
    
    index = 0;
    reset_array(str);

    while (decimal_number > 0) {
        remainder = decimal_number % 32;
        str[index] = (base32[remainder]);
        decimal_number /= 32;
        index++;
    }

    return reverstr(str);
}

/* Converts binary number to base32 */
char* convertBtoB32(unsigned long binary_number) {
    int remainder, index;
    int decimal_number;
    char str[LENGTH_OF_32_ITEM];
    
    index = 0;
    reset_array(str);
    decimal_number = convertBtoD(binary_number);

    while (decimal_number > 0) {
        remainder = decimal_number % 32;
        str[index] = (base32[remainder]);
        decimal_number /= 32;
        index++;
    }

    return reverstr(str);
}


/* Revers the string */
char *reverstr(char str[]){
	char temp;
	
    temp = str[0];
    str[0] = str[1];
    str[1] = temp;

	return str;
}

