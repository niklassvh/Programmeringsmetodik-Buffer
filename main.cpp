#include <iostream>
#include <ctime>
#include <algorithm>
#include "int_buffer.h"
#include "int_sorted.h"
#include <chrono>
#include <unistd.h>

void f ( int_buffer buf);
void selection_sort(int* begin, int* end);
bool cmp();
int main(){
    
    //Uppgift 1--------------
    f(int_buffer(10));
    // explicit int_buffer()-kontrueraren körs.
    // båda for kör icke konst. förmodligen för objektet inte är const.
    //tar bort first last i slutet av funktionen pga den går ur scope.
    // for(auto e:buf){} funkar.
    //------------------------------------------------
    // Uppgift 2
   /* int_buffer buffen(10);
    int count = 1;
    for(int* i = buffen.begin(); i != buffen.end(); i++){
        *i = count++;
    }


    int_sorted test(buffen.begin(),buffen.size());
    srand (time(NULL));
   for (int i = 0; i < 300; i++){
       test.insert(rand() % 300);
   }

    int l = 0;
    for (auto i = test.begin(); i != test.end(); i++){
        std::cout << *i<< " ";
        l++;
        if (l % 300 == 0)
        {std::cout<<std::endl;}

    }
    */
    /*Uppgift 3*/
    //sel sort
    int_buffer sortBuff(400000);
    srand (time(NULL));
    for (auto i = sortBuff.begin(); i != sortBuff.end(); i++){
        *i = rand();
    }
    auto begin = std::chrono::high_resolution_clock::now();
    //selection_sort(sortBuff.begin(),sortBuff.end());
    //19009, 19491, 18967 ms.
   int_sorted test(sortBuff.begin(), sortBuff.size());
    // 100ms;
   // std::sort(sortBuff.begin(),sortBuff.end()); // 18ms
    auto end = std::chrono::high_resolution_clock::now();
    std::cout<< std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    //merge sort



    return 0;
}




void f ( int_buffer buf){
    int count = 1;
    std::cout<< "Function f: ";
    for(int* i = buf.begin(); i != buf.end(); i++){
        *i = count++;
    }
    int_buffer bufferbroder(buf.begin(),buf.size());
    for (const int* i = buf.begin(); i != buf.end(); i++ ){

        std::cout<<*i<<" ";
    }
    std::cout << std::endl << std::endl;
}

void selection_sort(int* begin, int* end){

    for ( auto it = begin; it != end; it++){
        auto const selection = std::min_element(it, end);
        std::iter_swap(selection,it);
    }
    std::cout<<"sel sort"<< std::endl;


}

bool cmp(int* first, int *last){
    return (*first < *last);



}

