#include "Array.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/// private functions for ArrayCreate ///
bool private_ArrayCreate_i8(     Array_t* myArray, uint32_t size) {
  myArray->array = (i8_t*)malloc(size * sizeof(i8_t));
  if (!myArray->array) {
    perror("Failed to allocate memory for i8_t");
    return 0;
  }
  i8_t* ptr = (i8_t*)myArray->array;
  for (uint32_t i = 0; i < size; i++) {
    ptr->owner = myArray;
    ++ptr;
  }
  ptr = NULL;
  return 1;
}
bool private_ArrayCreate_i16(    Array_t* myArray, uint32_t size) {
  myArray->array = (i16_t*)malloc(size * sizeof(i16_t));
  if (!myArray->array) {
    perror("Failed to allocate memory for i16_t");
    return 0;
  }
  i16_t* ptr = (i16_t*)myArray->array;
  for (uint32_t i = 0; i < size; i++) {
    ptr->owner = myArray;
    ++ptr;
  }
  ptr = NULL;
  return 1;
}
bool private_ArrayCreate_i32(    Array_t* myArray, uint32_t size) {
  myArray->array = (i32_t*)malloc(size * sizeof(i32_t));
  if (!myArray->array) {
    perror("Failed to allocate memory for i32_t");
    return 0;
  }
  i32_t* ptr = (i32_t*)myArray->array;
  for (uint32_t i = 0; i < size; i++) {
    ptr->owner = myArray;
    ++ptr;
  }
  ptr = NULL;
  return 1;
}
bool private_ArrayCreate_u8(     Array_t* myArray, uint32_t size) {
  myArray->array = (u8_t*)malloc(size * sizeof(u8_t));
  if (!myArray->array) {
    perror("Failed to allocate memory for u8_t");
    return 0;
  }
  u8_t* ptr = (u8_t*)myArray->array;
  for (uint32_t i = 0; i < size; i++) {
    ptr->owner = myArray;
    ++ptr;
  }
  ptr = NULL;
  return 1;
}
bool private_ArrayCreate_u16(    Array_t* myArray, uint32_t size) {
  myArray->array = (u16_t*)malloc(size * sizeof(u16_t));
  if (!myArray->array) {
    perror("Failed to allocate memory for u16_t");
    return 0;
  }
  u16_t* ptr = (u16_t*)myArray->array;
  for (uint32_t i = 0; i < size; i++) {
    ptr->owner = myArray;
    ++ptr;
  }
  ptr = NULL;
  return 1;
}
bool private_ArrayCreate_u32(    Array_t* myArray, uint32_t size) {
  myArray->array = (u32_t*)malloc(size * sizeof(u32_t));
  if (!myArray->array) {
    perror("Failed to allocate memory for u32_t");
    return 0;
  }
  u32_t* ptr = (u32_t*)myArray->array;
  for (uint32_t i = 0; i < size; i++) {
    ptr->owner = myArray;
    ++ptr;
  }
  ptr = NULL;
  return 1;
}
bool private_ArrayCreate_float32(Array_t* myArray, uint32_t size) {
  myArray->array = (float32_t*)malloc(size * sizeof(float32_t));
  if (!myArray->array) {
    perror("Failed to allocate memory for float_t");
    return 0;
  }
  float32_t* ptr = (float32_t*)myArray->array;
  for (uint32_t i = 0; i < size; i++) {
    ptr->owner = myArray;
    ++ptr;
  }
  ptr = NULL;
  return 1;
}

/// public function ///
Array_t* ArrayCreate(Type_t T, uint32_t size) {
  Array_t* myArray = malloc(sizeof(Array_t));
  if (!myArray) return NULL;

  bool success = 0;
  if (T == Type_i8)           success = private_ArrayCreate_i8(     myArray, size);
  else if (T == Type_i16)     success = private_ArrayCreate_i16(    myArray, size);
  else if (T == Type_i32)     success = private_ArrayCreate_i32(    myArray, size);
  else if (T == Type_u8)      success = private_ArrayCreate_u8(     myArray, size);
  else if (T == Type_u16)     success = private_ArrayCreate_u16(    myArray, size);
  else if (T == Type_u32)     success = private_ArrayCreate_u32(    myArray, size);
  else if (T == Type_float32) success = private_ArrayCreate_float32(myArray, size);
  else perror("Type not found\n");

  if (!success) {
    perror("Failed to allocate memory for Array_t\n");
    free(myArray);
    myArray = NULL;
    return NULL;
  }
  myArray->size = size;
  myArray->type = T;
  return myArray;
}

/// private functions for ArrayDestroy ///
void private_ArrayDestroy_i8(     Array_t* myArray) {
  i8_t* ptr = (i8_t*)myArray->array;
  for (uint32_t i = 0; i < myArray->size; i++) {
    ptr->value = 0;
    ptr->owner = NULL;
    ++ptr;
  }
  ptr = NULL;
  free(myArray->array);
  myArray->array = NULL;
}
void private_ArrayDestroy_i16(    Array_t* myArray) {
  i16_t* ptr = (i16_t*)myArray->array;
  for (uint32_t i = 0; i < myArray->size; i++) {
    ptr->value = 0;
    ptr->owner = NULL;
    ++ptr;
  }
  ptr = NULL;
  free(myArray->array);
  myArray->array = NULL;
}
void private_ArrayDestroy_i32(    Array_t* myArray) {
  i32_t* ptr = (i32_t*)myArray->array;
  for (uint32_t i = 0; i < myArray->size; i++) {
    ptr->value = 0;
    ptr->owner = NULL;
    ++ptr;
  }
  ptr = NULL;
  free(myArray->array);
  myArray->array = NULL;
}
void private_ArrayDestroy_u8(     Array_t* myArray) {
  u8_t* ptr = (u8_t*)myArray->array;
  for (uint32_t i = 0; i < myArray->size; i++) {
    ptr->value = 0;
    ptr->owner = NULL;
    ++ptr;
  }
  ptr = NULL;
  free(myArray->array);
  myArray->array = NULL;
}
void private_ArrayDestroy_u16(    Array_t* myArray) {
  u16_t* ptr = (u16_t*)myArray->array;
  for (uint32_t i = 0; i < myArray->size; i++) {
    ptr->value = 0;
    ptr->owner = NULL;
    ++ptr;
  }
  ptr = NULL;
  free(myArray->array);
  myArray->array = NULL;
}
void private_ArrayDestroy_u32(    Array_t* myArray) {
  u32_t* ptr = (u32_t*)myArray->array;
  for (uint32_t i = 0; i < myArray->size; i++) {
    ptr->value = 0;
    ptr->owner = NULL;
    ++ptr;
  }
  ptr = NULL;
  free(myArray->array);
  myArray->array = NULL;
}
void private_ArrayDestroy_float32(Array_t* myArray) {
  float32_t* ptr = (float32_t*)myArray->array;
  for (uint32_t i = 0; i < myArray->size; i++) {
    ptr->value = 0;
    ptr->owner = NULL;
    ++ptr;
  }
  ptr = NULL;
  free(myArray->array);
  myArray->array = NULL;
}

/// public function ///
Array_t* ArrayDestroy(Array_t* myArray) {
  if (!myArray) return NULL;

  if (myArray->type      == Type_i8)      private_ArrayDestroy_i8(       myArray);
  else if (myArray->type == Type_i16)     private_ArrayDestroy_i16(      myArray);
  else if (myArray->type == Type_i32)     private_ArrayDestroy_i32(      myArray);
  else if (myArray->type == Type_u8)      private_ArrayDestroy_u8(       myArray);
  else if (myArray->type == Type_u16)     private_ArrayDestroy_u16(      myArray);
  else if (myArray->type == Type_u32)     private_ArrayDestroy_u32(      myArray);
  else if (myArray->type == Type_float32) private_ArrayDestroy_float32(myArray);
  else { 
    perror("Type not found\n");
    return myArray;
  }

  free(myArray->array);
  myArray->array = NULL;
  myArray->size = 0;
  myArray->type = Type_null;
  free(myArray);
  myArray = NULL;
  return myArray;
}
