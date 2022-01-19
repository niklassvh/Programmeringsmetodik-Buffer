
#include <algorithm>
#include <cstddef>
#include <iostream>
#include "int_sorted.h"


int_sorted::int_sorted(const int *source, size_t size): buf(nullptr, 0) {
   if (size == 0){
     return;
   }
   if(size == 1){
       int_buffer one(source,1);
       buf = one;
       return;
   }

    buf = sort(source, source+size).buf;//move assign
}

size_t int_sorted::size() const {
    return buf.size();
}

 void int_sorted::insert(int value) {
    int_sorted add(&value,1);
    int_sorted inserted(merge(add));
    buf = inserted.buf;
}

const int *int_sorted::begin() const {
    return buf.begin();
}

const int *int_sorted::end() const {
    return buf.end();
}

int_sorted int_sorted::merge(const int_sorted &merge_with) const {
    const int* a = buf.begin();
  const int* b = merge_with.begin();
  int_buffer merged(buf.size() + merge_with.size());
  int* c = merged.begin();
  while(a != buf.end() && b !=merge_with.end()){

      if (*a < *b){
         *c = *a;
         a++;
      }
      else {
          *c = *b;
          b++;
      }
    c++;
  }
  std::copy(a,buf.end(),c);
  std::copy(b,merge_with.end(),c);
  int_sorted result(nullptr,0);
  result.buf = merged;
    return result;
}
//merge-sort
int_sorted int_sorted::sort(const int *begin, const int *end) {
    if ( begin == end ) {
        return int_sorted(nullptr, 0);
    }
    if ( begin == end -1 ) {
        return int_sorted(begin, 1);
    }
    ptrdiff_t half = ( end - begin ) /2;//pointer diff type
    const int * mid = begin + half ;
    return sort (begin,mid).merge(sort (mid , end )) ;
}
