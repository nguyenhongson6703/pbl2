#include "listsp.h"
#include <bits/stdc++.h>
#include <string>
using namespace std;

long long List_sp::gia_theo_ten(string value){ 
	NODE<sanpham> *p = new NODE<sanpham>;
    p = this->gethead();
    do{
        if((p->data).get_tensp().compare(value) == 0) {
			return (p->data).get_dongiasp();
		}
        p = p -> next;
    }while (p != NULL);
}

// void List_sp::xoa_theo_id(string value){
//     if(gia_theo_ten(value) == true){
//         NODE<sanpham>* p;
//         p = gethead();
//         while (p!= NULL && (p -> data).get_tensp()!= value)
//         {
//             p = p -> next;

//         }
//         if( p != NULL){
//             if( p -> prev == NULL){
//                 xoa_dau();
//                 return;
//             }
//             if(p -> next == NULL){
//                 xoa_cuoi();
//                 return;
//             }
//         p->prev->next = p->next;
//         p->next->prev = p->prev;
//         //gan con tro prev va next cua phan tu co khoa K can xoa ve null
//         p->prev = NULL; 
//         p->next = NULL;
//         //xoa node p co phan tu la khoa k
//         delete p;
//         }
//     }else{
//         cout << "\n Khong co ma id "<< value<< "trong danh sach san pham!";
//         return;
//     }
// }