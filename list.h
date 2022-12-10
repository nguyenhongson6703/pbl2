#ifndef list_h
#define list_h
#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct NODE{
    T data;
    struct NODE* next;
    struct NODE* prev;

};

template<typename T>
class List{
    private:
        NODE<T>* head;
        NODE<T>* tail;
    public:
        List();
        ~List();
        NODE<T>* gethead();
        NODE<T>* gettail();
        bool kiem_tra_rong();
        void them_cuoi(T& value);
        void xuat(string s);
        void xoa_dau();
        void xoa_cuoi();
};

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
        output << (p->data);
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
#endif
