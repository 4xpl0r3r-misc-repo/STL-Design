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
public:
    class listNode;
    class iterator;
    
    list();
    list(const list& tar);
    ~list();
    void operator=(const list& tar);
    T& operator[](int index);
    
    list<T>::listNode* insert(const T&,iterator& it);//插入到后面
    void erase(iterator& it);
    
    void push_back(const T&);
    
    iterator begin()const;
    iterator end()const;
    
    int size();
protected:
    listNode *head,*tail;//head是空节点，不使用
};

template<typename T>
class list<T>::listNode{
    T v;
public:
    listNode *forward=NULL,*next=NULL;
    
    T& operator*();
    listNode(const T& v=0,listNode* forward=NULL,listNode* next=NULL);
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
    
    bool operator==(const iterator& tar)const;
    bool operator!=(const iterator& tar)const;
    
    T operator*();
    void operator++();
    void operator--();
    iterator operator+(int steps)const;
    iterator operator-(int steps)const;
    list<T>::listNode* getPtr();
};

/*-------------declearation above-------------*/

template<typename T>
list<T>::list(){
    tail=head=new list<T>::listNode();
}

template<typename T>
list<T>::list(const list& tar){
    tail=head=new list<T>::listNode();
    for (auto it=tar.begin(); it!=tar.end(); ++it) {
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
    return *(list<T>::iterator(head)+1+index);
}

template<typename T>
typename list<T>::listNode* list<T>::insert(const T& v,iterator& it){
    it.getPtr()->next=new list<T>::listNode(v,it.getPtr(),it.getPtr()->next);
    if(it.getPtr()->next->next)
        it.getPtr()->next->next->forward=it.getPtr()->next;
    return it.getPtr()->next;
}

template<typename T>
void list<T>::erase(iterator& it){
    auto toErase=it.getPtr();
    if(toErase->forward)
        toErase->forward->next=toErase->next;
    if(toErase->next)
        toErase->next->forward=toErase->forward;
    delete toErase;
}

template<typename T>
void list<T>::push_back(const T& v){
    auto tmp=list<T>::iterator(tail);
    tail=insert(v, tmp);
}

template<typename T>
typename list<T>::iterator list<T>::begin()const{
    return head->next;
}

template<typename T>
typename list<T>::iterator list<T>::end()const{
    return list<T>::iterator(NULL);
}

template<typename T>
int list<T>::size(){
    int i=0;
    for(iterator it=begin()+1;*it;it++,i++);
    return i;
}

template<typename T>
T& list<T>::listNode::operator*(){
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
T list<T>::iterator::operator*(){
    return **ptr;
}

template<typename T>
void list<T>::iterator::operator++(){
    ptr=ptr->next;
}

template<typename T>
void list<T>::iterator::operator--(){
    ptr=ptr->forward;
}

template<typename T>
typename list<T>::iterator list<T>::iterator::operator+(int steps)const{
    auto tmp=ptr;
    for(;steps>0;steps--)ptr=ptr->next;
    return list<T>::iterator(tmp);
}

template<typename T>
typename list<T>::iterator list<T>::iterator::operator-(int steps)const{
    auto tmp=ptr;
    for(;steps>0;steps--)ptr=ptr->forward;
    return list<T>::iterator(tmp);
}

template<typename T>
bool list<T>::iterator::operator==(const iterator& tar)const{
    return ptr==tar.ptr;
}

template<typename T>
bool list<T>::iterator::operator!=(const iterator& tar)const{
    return ptr!=tar.ptr;
}

template<typename T>
typename list<T>::listNode* list<T>::iterator::getPtr(){
    return ptr;
}

}

#endif /* list_hpp */
