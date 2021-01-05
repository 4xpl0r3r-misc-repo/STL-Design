//
//  multimap.hpp
//  STL-Design
//
//  Created by 张开楠 on 2021/1/5.
//

#ifndef multimap_hpp
#define multimap_hpp

#include <stdio.h>
#include "vector.hpp"

namespace istd{
template<typename keyT,typename valueT>
class pair{
public:
    keyT key;
    valueT value;
    pair(keyT key,valueT value){
        this->key=key;
        this->value=value;
    }
};

template<typename keyT,typename valueT>
class multimap{
    vector<pair<keyT, valueT>> data;
public:
    void insert(const pair<keyT,valueT>& newPair);
    valueT& find(keyT key);
    valueT& operator[](keyT key);
    //隐式声明拷贝函数和等于号函数
    void erase(pair<keyT, valueT>* it);
    
    pair<keyT, valueT>* begin();
    pair<keyT, valueT>* end(){return NULL;};
};

template<typename keyT,typename valueT>
void multimap<keyT,valueT>::insert(const pair<keyT,valueT>& newPair){
    data.push_back(newPair);
}

template<typename keyT,typename valueT>
valueT& multimap<keyT,valueT>::find(keyT key){
    auto it=data.begin();
    for (; it&&it->key!=key; it++);
    if (it) {
        return it->value;
    }else{
        throw "Can't find key!";
    }
}

template<typename keyT,typename valueT>
valueT& multimap<keyT,valueT>::operator[](keyT key){
    auto it=data.begin();
    for (; it&&it->key!=key; it++);
    if (it) {
        return it->value;
    }else{
        throw "Can't find key!";
    }
}

template<typename keyT,typename valueT>
pair<keyT, valueT>* multimap<keyT,valueT>::begin(){
    return data.begin();
}

template<typename keyT,typename valueT>
void multimap<keyT,valueT>::erase(pair<keyT, valueT>* it){
    data.erase(it);
}

}

#endif /* multimap_hpp */
