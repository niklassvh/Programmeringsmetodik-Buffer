#include "int_buffer.h"
#include<iostream>
#include<algorithm>

int_buffer::int_buffer (size_t size): first(new int[size]),last(first + size){

}
int_buffer::int_buffer(const int * source, size_t size): int_buffer(size){

    std::copy(source,source+size,first);
}

int_buffer::int_buffer( const int_buffer & rhs ): int_buffer(rhs.first,rhs.size()){
}
int_buffer::int_buffer(int_buffer && rhs){
    swap(rhs);
}

int_buffer &int_buffer::operator =(const int_buffer &rhs){
     int_buffer copy(rhs);
     swap(copy);
     return *this;
}

int_buffer &int_buffer::operator=(int_buffer &&rhs) {
    swap(rhs);
    return *this;
}

size_t int_buffer::size() const {
    return last-first;
}

int* int_buffer::begin(){
    return first;
}

int* int_buffer::end(){
    return last;
}

const int* int_buffer::begin() const{
    return first;
}

const int* int_buffer::end() const{
    return last;
}

int_buffer::~int_buffer (){
 delete []first;
}

int &int_buffer::operator[](size_t index) {
   return first[index];

}

const int &int_buffer::operator[](size_t index) const {
    return first[index];
}

void int_buffer::swap(int_buffer& rhs) {

    std::swap(first,rhs.first);
    std::swap(last,rhs.last);

}

