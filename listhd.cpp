#include "listhd.h"
#include <bits/stdc++.h>
using namespace std;

// tim kiems va xoa theo id cua HOADON

bool List_hd::tim_kiem_theo_id(int value){ 
    NODE<HoaDon>* p  = this->gethead();
    for(p ; p != NULL; p = p -> next){
    	if((p->data).get_MaHD() == value){
    		return true;
		}
	}
    return false;
}
void List_hd :: doc_hd (){

}
void List_hd :: ghi_hd (){
    string s;
    s = "hoadon_op.txt";
    this->xuat(s);
}
void List_hd::xoa_theo_id(int value){
    if(tim_kiem_theo_id(value) == true){
        NODE<HoaDon>* p;
        p = gethead();
        while (p!= NULL && (p -> data).get_MaHD()!= value)
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
        cout << "\n Khong co ma id "<< value<< "trong danh sach hoa don!";
        return;
    }
}