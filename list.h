#ifndef list_h
#define list_h
#include"sanpham.h"
#include"hoadon.h"
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
        void xuat();
        void xoa_dau();
        void xoa_cuoi();
};
#endif
