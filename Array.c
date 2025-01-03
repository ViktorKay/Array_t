#include "Array.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

Array32_t* ArrayCreate(const Type_t T, const uint32_t size) {
  if (size == 0) {
    fprintf(stderr, "ArrayCreate: Size cannot be zero.\n");
    return nullptr;
  }
  if (T != Type_i32 && T != Type_u32 && T != Type_f32) {
    fprintf(stderr, "ArrayCreate: Unsupported type.\n");
    return nullptr;
  }
  Array32_t* myArray = malloc(sizeof(Array32_t));
  if (!myArray) {
    fprintf(stderr, "ArrayCreate: Failed to allocate memory for array.\n");
    return nullptr;
  }
  myArray->ptrArray = (TypeData32_t*)malloc(size * sizeof(TypeData32_t));
  if (!myArray->ptrArray) {
    fprintf(stderr, "ArrayCreate: Failed to allocate memory for data array.\n");
    free(myArray);
    myArray = nullptr;
    return nullptr;
  }
  myArray->size = size;
  myArray->type = T;
  return myArray;
}

Array32_t* ArrayDestroy(Array32_t* myArray) {
  if (!myArray) {
    fprintf(stderr, "ArrayDestroy: Array is null.\n");
    return nullptr;
  }

  if (myArray->ptrArray) {
    memset(myArray->ptrArray, 0, myArray->size * sizeof(TypeData32_t));
    free(myArray->ptrArray);
    myArray->ptrArray = nullptr;
  }

  myArray->size = 0;
  myArray->type = 0;
  free(myArray);
  myArray = nullptr;
  return myArray;
}

void ArrayPrint(const Array32_t* myArray) {
  if (!myArray) {
    fprintf(stderr, "ArrayPrint: Array is null.\n");
    return;
  }

  switch (myArray->type) {
    case Type_i32: {
      for (uint32_t i = 0; i < myArray->size; i++) {
        printf("Index [%d] Value: %d\n", i, ((int32_t*)myArray->ptrArray)[i]);
      }
      break;
    }
    case Type_u32: {
      for (uint32_t i = 0; i < myArray->size; i++) {
        printf("Index [%d] value [%u]\n", i, ((uint32_t*)myArray->ptrArray)[i]);
      }
      break;
    }
    case Type_f32:{
      for (uint32_t i = 0; i < myArray->size; i++) {
        printf("Index [%d] value [%f]\n", i, ((float*)myArray->ptrArray)[i]);
      }
      break;
      }
    default: {
      perror("Type not found\n");
    }
  }
}

