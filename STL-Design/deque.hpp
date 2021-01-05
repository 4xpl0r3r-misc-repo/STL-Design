//
//  deque.hpp
//  STL-Design
//
//  Created by 张开楠 on 2021/1/4.
//

#ifndef deque_hpp
#define deque_hpp

#include <stdio.h>
#include "list.hpp"
using namespace std;

namespace istd {

template<typename T>
class deque:public list<T>{
public:
    void push_back(const T& tar);
    void pop_back();
    void push_front(const T& tar);
    void pop_front();
    T& front();
    T& back();
};

template<typename T>
void deque<T>::push_back(const T& tar){
    list<T>::push_back(tar);
}

template<typename T>
void deque<T>::push_front(const T& tar){
    typename list<T>::iterator tmp(this->head);
    list<T>::insert(tar, tmp);
}

template<typename T>
void deque<T>::pop_back(){
    typename list<T>::iterator tmp(this->tail);
    list<T>::erase(tmp);
}

template<typename T>
void deque<T>::pop_front(){
    typename list<T>::iterator tmp(this->head->next);
    list<T>::erase(tmp);
}

template<typename T>
T& deque<T>::front(){
    return **this->head->next;
}

template<typename T>
T& deque<T>::back(){
    return **this->tail;
}

}

#endif /* deque_hpp */
