#include <stdio.h>
#include <stdint.h>

#include "Array.h"

int main(void) {
  constexpr uint32_t myArraySize = 5;
  Array32_t* myArray = ArrayCreate(Type_i32, myArraySize);
  if (!myArray) {
    perror("malloc failed creating MyArray\n");
    return 1;
  }

  ArrayPrint(myArray);


  myArray = ArrayDestroy(myArray);
  return 0;
}
