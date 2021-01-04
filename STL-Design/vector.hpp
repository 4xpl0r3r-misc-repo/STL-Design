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
    vector(int l=100);
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
    T *data,*tail,*spaceTail;//tail是空数据指针，spaceTail是空指针
    int baseLength,multiplier=1;
    void reAllocate();
};

/*-------------declearation above-------------*/

template<typename T>
vector<T>::vector(int l){
    baseLength=l;
    tail=data=new T[baseLength];
    spaceTail=data+baseLength;
}

template<typename T>
vector<T>::vector(const vector& tar){
    baseLength=tar.baseLength;
    multiplier=tar.multiplier;
    data=new T[baseLength*multiplier];
    memcpy(data, tar.data, (int)sizeof(data));
    tail=data+tar.size();
    spaceTail=data+baseLength*multiplier;
}

template<typename T>
vector<T>::~vector(){
    delete [] data;
}

template<typename T>
void vector<T>::operator=(const vector& tar){
    if(data)delete [] data;
    baseLength=tar.baseLength;
    multiplier=tar.multiplier;
    data=new T[baseLength*multiplier];
    memcpy(data, tar.data, (int)sizeof(data));
    tail=data+tar.size();
    spaceTail=data+baseLength*multiplier;
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
    if(tail==spaceTail)reAllocate();
    (*tail)=tar;
    tail++;
}

template<typename T>
void vector<T>::pop_back(){
    tail--;
}

template<typename T>
T& vector<T>::back()const{
    return *(tail-1);
}

template<typename T>
T& vector<T>::operator[](int steps)const{
    return *(data+steps);
}

template<typename T>
void vector<T>::reAllocate(){
    multiplier+=1;
    T *newData=new T[baseLength*multiplier];
    memcpy(newData, data, (int)sizeof(data));
    delete[] data;
    data=newData;
    spaceTail=data+baseLength*multiplier;
    tail=data+baseLength*(multiplier-1);
}

}

#endif /* vector_hpp */
