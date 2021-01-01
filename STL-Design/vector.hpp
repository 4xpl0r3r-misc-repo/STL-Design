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
    vector(int l=0);
    //l为初始数组长度
    vector(const vector& tar);
    ~vector();
    void operator=(const vector& tar);
    T& operator[](int)const;
    
    T* begin()const;
    T* end()const;
    
    long size()const;
    
    void push_back(const T& tar);
    void pop_back();
    
    T& back()const;
private:
    T *data,*tail;//tail是空指针
};

/*-------------declearation above-------------*/

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
    while(data!=tail)
        delete data;
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
    return tail;
}

template<typename T>
long vector<T>::size()const{
    return tail-data;
}

template<typename T>
void vector<T>::push_back(const T& tar){
    tail=new T(tar);
    tail++;
}

template<typename T>
void vector<T>::pop_back(){
    delete tail--;
}

template<typename T>
T& vector<T>::back()const{
    return *tail;
}

template<typename T>
T& vector<T>::operator[](int steps)const{
    return *(data+steps);
}

}

#endif /* vector_hpp */
