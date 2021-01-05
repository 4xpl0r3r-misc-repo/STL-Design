//
//  algorithm.hpp
//  STL-Design
//
//  Created by 张开楠 on 2021/1/5.
//

#ifndef algorithm_hpp
#define algorithm_hpp

#include <stdio.h>

namespace istd {

template<typename T>
void greater(T it1,T it2){
    return *it1>*it2;
}

template<typename T>
void less(T it1,T it2){
    return *it1<*it2;
}

template<typename T>
void swap(T& v1,T& v2){
    T tmp=v1;
    v1=v2;
    v2=v1;
}


template<typename RandomIterator,typename Compare>
void sort(RandomIterator start,RandomIterator end,Compare cmp=greater){
    for (RandomIterator i=start; i!=end; i++) {
        RandomIterator tmp=i;
        for (RandomIterator j=start+1; j!=end; j++) {
            if(cmp(*j,*tmp)){
                tmp=j;
            }
        }
        swap(*tmp,*i);
    }
}

template<typename RandomIterator,typename valueT>
RandomIterator find(RandomIterator start,RandomIterator end,valueT toFind){
    RandomIterator i=start;
    for (; i!=end; i++) {
        if(*i==toFind){
            return i;
        }
    }
    return end;
}

}


#endif /* algorithm_hpp */
