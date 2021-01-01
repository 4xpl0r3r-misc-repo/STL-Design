//
//  list.hpp
//  STL-Design
//
//  Created by 张开楠 on 2020/12/30.
//

#ifndef list_hpp
#define list_hpp

#include <cstdio>

namespace istd {



template<typename T>
class list{
    class listNode;
    class iterator;
    listNode* head,tail;//head是空节点，不使用
public:
    list();
    list(const list& tar);
    ~list();
    void operator=(const list& tar);
    T& operator[](int index);
    
    void insert(const T&,const iterator& it);//插入到后面
    void erase(iterator& it);
    
    void push_back(const T&);
    
    iterator begin();
    iterator end();
    
    int size();
};

template<typename T>
class list<T>::listNode{
    T v;
public:
    listNode* forward=NULL,next=NULL;
    
    T& operator*()const;
    listNode(const T& v,listNode* forward=NULL,listNode* next=NULL);
    listNode(const listNode& tar,listNode* forward=NULL,listNode* next=NULL);
    //隐式析构,省略
    //隐式声明等于号=
};

template<typename T>
class list<T>::iterator{
private:
    list<T>::listNode* ptr;
public:
    iterator(list<T>::listNode* addr);
    iterator(const iterator& tar);
    void operator=(list<T>::listNode* addr);
    void operator=(const iterator& tar);
    
    T operator*()const;
    void operator++();
    void operator--();
    iterator operator+();
    iterator operator-();
};

/*-------------declearation above-------------*/

template<typename T>
list<T>::list(){
    tail=head=new list<T>::listNode();
}

template<typename T>
list<T>::list(const list& tar){
    tail=head=new list<T>::listNode();
    for (auto it=tar.begin(); it!=tar.end(); it++) {
        tail->next=new list<T>::listNode(*it,tail);
        tail=tail->next;
    }
}

template<typename T>
list<T>::~list(){
    for(auto tmp=this->tail;tmp!=this->head;tmp++){
        tmp=tmp->forward;
        delete tmp->next;
    }
    delete head;
}

template<typename T>
void list<T>::operator=(const list& tar){
    tail=head=new list<T>::listNode();
    for (auto it=tar.begin(); it!=tar.end(); it++) {
        tail->next=new list<T>::listNode(*it,tail);
        tail=tail->next;
    }
}

template<typename T>
T& list<T>::operator[](int index){
    return *(head+1+index);
}

template<typename T>
void list<T>::insert(const T& v,const iterator& it){
    (*it)->next=new list<T>::listNode(v,(*it),(*it)->next);
    if((*it)->next->next)
        (*it)->next->next->forward=(*it)->next;
}

template<typename T>
void list<T>::erase(iterator& it){
    auto toErase=*it;
    if(toErase->forward)
        toErase->forward->next=toErase->next;
    if(toErase->next)
        toErase->next->forward=toErase->forward;
    delete toErase;
}

template<typename T>
void list<T>::push_back(const T& v){
    insert(v, tail);
}

template<typename T>
typename list<T>::iterator list<T>::begin(){
    return head+1;
}

template<typename T>
typename list<T>::iterator list<T>::end(){
    return tail;
}

template<typename T>
int list<T>::size(){
    int i=0;
    for(iterator it=begin()+1;*it;it++,i++);
    return i;
}

template<typename T>
T& list<T>::listNode::operator*()const{
    return v;
}

template<typename T>
list<T>::listNode::listNode(const T& v,listNode* forward,listNode* next){
    this->v=v;
    this->forward=forward;
    this->next=next;
}

template<typename T>
list<T>::listNode::listNode(const listNode& tar,listNode* forward,listNode* next){
    this->v=tar.v;
    this->forward=forward;
    this->next=next;
}

template<typename T>
list<T>::iterator::iterator(list<T>::listNode* addr){
    ptr=addr;
}

template<typename T>
list<T>::iterator::iterator(const iterator& tar){
    ptr=tar.ptr;
}

template<typename T>
void list<T>::iterator::operator=(list<T>::listNode* addr){
    ptr=addr;
}

template<typename T>
void list<T>::iterator::operator=(const iterator& tar){
    ptr=tar.ptr;
}

template<typename T>
T list<T>::iterator::operator*()const{
    return **ptr;
}

template<typename T>
void list<T>::iterator::operator++(){
    
}

template<typename T>
void list<T>::iterator::operator--(){
    
}

template<typename T>
typename list<T>::iterator list<T>::iterator::operator+(){
    
}

template<typename T>
typename list<T>::iterator list<T>::iterator::operator-(){
    
}


}

#endif /* list_hpp */
