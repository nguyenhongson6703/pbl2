#include"list.h"
#include<bits/stdc++.h>

using namespace std;
template<typename T>
NODE<T>* Tao_node(T& value){
    NODE<T>* p;
    p = new NODE<T>;
    if(p == NULL){
        cout << "\n Khong du bo nho !";

    }
    p -> data = value;
    p -> next = NULL;
    p -> prev = NULL;
    return p;

}
template<typename T>
List<T>::List(){
    head = NULL;
    tail = NULL;

}
template<typename T>
List<T>::~List(){
    delete head;
    delete tail;

}
template<typename T>
bool List<T>::kiem_tra_rong(){
    if( head == NULL){
        return true;
    }
    return false;


}
template<typename T>
void List<T>::them_cuoi(T& value){
    NODE<T>* p = Tao_node(value);

    if(head == NULL){
        head = p;
        tail = p;


    }else{
        tail -> next = p;
        p -> prev = tail;
        tail = p;

    }

}
template<typename T>

void List<T>::xuat(){
    NODE<T> *p = new NODE<T>;
    p = head;
    do{
        // in du lieu ra
        cout << (p -> data);
        p = p -> next;


    }while (p != NULL);
   
    

}
template<typename T>
void List<T>::xoa_dau(){
    NODE<T> *p = head;
    head = head -> next;
    head -> prev = NULL;
    if( head == NULL){
        tail = NULL;

    }
    p -> next = NULL;
    delete p;


}
template<typename T>
void List<T>::xoa_cuoi(){
    NODE<T>* p = tail;
    tail = tail -> prev;
    tail -> next = NULL;
    if( tail == NULL){
        head = NULL;

    }
    p -> prev = NULL;
    delete p;


}

template <typename T>
NODE<T>* List<T>::gethead(){
    return head;
}

template <typename T>
NODE<T>* List<T>::gettail(){
    return tail;
}


