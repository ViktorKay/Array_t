#ifndef ARRAY_H
#define ARRAY_H

#include <stdint.h>

typedef enum {
  Type_null,
  Type_i32,
  Type_u32,
  Type_f32
  // ... other types
} Type_t;
typedef union  {
  int32_t  i32;
  uint32_t u32;
  float    f32;
  // ... other types
} TypeData32_t;
typedef struct Array {
  Type_t type;
  uint32_t size;
  TypeData32_t* ptrArray;
} Array32_t;

typedef struct {
  int32_t value;
  Array32_t* owner;
} i32_t;
typedef struct {
  uint32_t value;
  Array32_t* owner;
} u32_t;
typedef struct {
  float value;
  Array32_t* owner;
} f32_t;

/// public function declarations ///
Array32_t* ArrayCreate(const Type_t, const uint32_t);
Array32_t* ArrayDestroy(Array32_t*);

void ArrayPrint(const Array32_t*);

typedef enum {
  // alphabetically,
  low_to_high,
  high_to_low
} ArraySort_t;
Array32_t* ArraySort(Array32_t*, ArraySort_t);

//#include <stdarg.h>
//Array32_t* ArrayAppend(Array32_t*, void*, ...);

//void* ArrayInsert(Array32_t*, void*);
//void* ArrayRemove(void*);
//Array32_t* ArrayGrow(Array32_t*, uint32_t);
//Array32_t* ArrayShrink(Array32_t*);
//Array32_t* ArrayDefrag(Array32_t*);
//Array32_t* ArrayCopy(Array32_t*, Array32_t*);

#endif //ARRAY_H
