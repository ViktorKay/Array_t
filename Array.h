#ifndef ARRAY_H
#define ARRAY_H

typedef enum {
  Type_null,
  Type_u8,
  Type_i8,
  Type_i16,
  Type_u16,
  Type_i32,
  Type_u32,
  Type_float32,
} Type_t;

#include <stdint.h>
typedef struct Array {
  Type_t type;
  uint32_t size;
  void* array;
} Array_t;

typedef struct {
  int8_t value;
  Array_t* owner;
} i8_t;
typedef struct {
  uint8_t value;
  Array_t* owner;
} u8_t;
typedef struct {
  int16_t value;
  Array_t* owner;
} i16_t;
typedef struct {
  uint16_t value;
  Array_t* owner;
} u16_t;
typedef struct {
  int32_t value;
  Array_t* owner;
} i32_t;
typedef struct {
  uint32_t value;
  Array_t* owner;
} u32_t;
typedef struct {
  float value;
  Array_t* owner;
} float32_t;


/// public function declarations ///
void* ArrayInsert(Array_t*, void*);
void* ArrayRemove(void*);

typedef enum {
  // alphabetically,
  low_to_high,
  high_to_low
} ArraySort_t;
Array_t* ArraySort(Array_t*, ArraySort_t);

Array_t* ArrayCreate(Type_t, uint32_t);
Array_t* ArrayDestroy(Array_t*);
Array_t* ArrayGrow(Array_t*, uint32_t);
Array_t* ArrayShrink(Array_t*);
Array_t* ArrayDefrag(Array_t*);

Array_t* ArrayCopy(Array_t*, Array_t*);

#include <stdarg.h>
Array_t* ArrayAppend(Array_t*, void*, ...);

#endif //ARRAY_H
