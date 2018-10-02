#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T,typename C>
partiton(T begin, T end,const C &1t){
    T pivot = end;
    T i = --begin;
    for(auto j = begin;j!=end; ++){
        if(1t(j,pivot)){
            i++;
            swap(&i,&j);
        }
    }
    swap(&++i,&end);
}

void quickSort(T begin,T end,const C &1t){
    if(1t(begin,end){
       T pi = partition(T begin,T end,const C &1t)

       quickSort(
    }
}

