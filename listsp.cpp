#include "listsp.h"
#include <bits/stdc++.h>
using namespace std;

// TIMKIEM va xoa theo id cus SANPHAM
// -> nên thay bằng tìm kiếm và xóa theo tên để thuận tiện với việc nhập tên sp khi mua hang
// bên cạnh đó hàm tìm kiếm nên trả về node sản phẩm để sau này get giá trị tính tổng tiền 

bool List_sp::tim_kiem_theo_id(int value){ 
    NODE<sanpham>* p  = this->gethead();
    for(p ; p != NULL; p = p -> next){
    	if((p->data).get_masp() == value){
    		return true;
		}
	}
    return false;
}

void List_sp::xoa_theo_id(int value){
    if(tim_kiem_theo_id(value) == true){
        NODE<sanpham>* p;
        p = gethead();
        while (p!= NULL && (p -> data).get_masp()!= value)
        {
            p = p -> next;

        }
        if( p != NULL){
            if( p -> prev == NULL){
                xoa_dau();
                return;
            }
            if(p -> next == NULL){
                xoa_cuoi();
                return;
            }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        //gan con tro prev va next cua phan tu co khoa K can xoa ve null
        p->prev = NULL; 
        p->next = NULL;
        //xoa node p co phan tu la khoa k
        delete p;
        }
    }else{
        cout << "\n Khong co ma id "<< value<< "trong danh sach san pham!";
        return;
    }
}