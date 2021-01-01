//
//  vector.hpp
//  STL-Design
//
//  Created by 张开楠 on 2020/12/30.
//

#ifndef vector_hpp
#define vector_hpp
#include <iostream>
#include <cstdlib>

namespace istd {

template<typename T>
class vector{
    class iterator;
public:
    vector();
    vector(int l);
    //l为初始数组长度
    vector(const vector& tar);
    ~vector();
    void operator=(const vector& tar);
    
    T* begin()const;
    T* end()const;
    
    long size()const;
    
    void push_back(const T& tar);
    void pop_back();
    
    T& back()const;
private:
    T *data,*tail;
};

/*-------------declearation above-------------*/

template<typename T>
vector<T>::vector(){
    tail=data=NULL;
}

template<typename T>
vector<T>::vector(int l){
    data=new T[l];
    tail=data+l;
}

template<typename T>
vector<T>::vector(const vector& tar){
    data=new T[tar.size()];
    tail=data+tar.size();
}

template<typename T>
vector<T>::~vector(){
    delete[] data;
}

template<typename T>
void vector<T>::operator=(const vector& tar){
    data=new T[tar.size()];
    tail=data+tar.size();
}

template<typename T>
T* vector<T>::begin()const{
    return data;
}

template<typename T>
T* vector<T>::end()const{
    return tail+1;
}

template<typename T>
long vector<T>::size()const{
    return tail-data;
}

template<typename T>
void vector<T>::push_back(const T& tar){
    ++tail=new T(tar);
}

template<typename T>
void vector<T>::pop_back(){
    delete tail--;
}

template<typename T>
T& vector<T>::back()const{
    return *tail;
}

}

#endif /* vector_hpp */
