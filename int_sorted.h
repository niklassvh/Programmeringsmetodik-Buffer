#pragma once
#include <cstdlib>
#include "int_buffer.h"

class int_sorted {
    
public :
int_sorted (const int * source,size_t size);
size_t size () const;
void insert (int value);
const int * begin () const;
const int * end () const ;
int_sorted merge (const int_sorted &merge_with) const;

private:

    int_sorted sort(const int* begin, const int* end);
    int_buffer buf;
};
