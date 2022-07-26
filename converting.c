#include "math.h"
#include "constants.c"

#define BIN_MACHINE_CODE_LENGTH 10
#define ONLY1 1023


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
    decimal_number = decimal_number ^ ONLY1;
    
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


/* Revers the string */
char* reverstr(char str[], int index){
	int index;
	char *rstr;
	
  index = 0;
  rstr = malloc(BIN_MACHINE_CODE_LENGTH * sizeof(char));

	/* Ignore the '\0' */
	index -= 1;
	while(index > -1){
		*(rstr + index) = str[index--];
		index++;
	}
	return rstr;
}


/* Converts decimal number to base32 */
char* convertDtoB32(int decimal_number) {
  int remainder, index;
  char str[BIN_MACHINE_CODE_LENGTH];
  char *revers_str;

  index = 0;

  while (decimal_number > 0) {
    remainder = decimal_number % 32;
    str[index] = (base32[remainder]);
    decimal_number /= 32;
	  index++;
  }
  
  revers_str = reverstr(str, index);
  return revers_str;
}