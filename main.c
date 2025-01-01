#include <stdio.h>
#include <stdint.h>
#include "Array.h"

#include <math.h>
#include <stdlib.h>

int main(void) {
  Array_t* myArray = ArrayCreate(Type_i8, 5);


  myArray = ArrayDestroy(myArray);
  return 0;
}
