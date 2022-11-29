#include<bits/stdc++.h>
#include"list.h"
#include"list.cpp"
#include"sanpham.h"
class List_sp: public List<sanpham> {
    public:
		bool tim_kiem_theo_id(int value);
        void xoa_theo_id(int value);
};
bool List_sp::tim_kiem_theo_id(int value){ 
    NODE<sanpham>* p  = this->gethead();
    for(p ; p != NULL; p = p -> next){
    	if((p->data).get_masp() == value){
    		return true;
		}
	}
    return false;



}
void hoadon(){}
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


int main(){
//	List<int> T;
//	int x= 3;
//	T.them_cuoi(x);
//	
//	int y = 4;
//	T.them_cuoi(y);
//	y = 5;
//	T.them_cuoi(y);
//	y = 7;
//	T.them_cuoi(y);
//	
//	T.xuat();
//	T.xoa_dau();
//	cout << endl;
//	T.xuat();
//	T.xoa_cuoi();
//	cout << endl;
//	T.xuat();
	sanpham S(1,"sua",10000);
//	cout << S;
//	List<sanpham> T;
//	T.them_cuoi(S);
//	T.xuat();
	sanpham K(2,"keo",12000);
	sanpham C(3,"ca rot",13000);
	sanpham T(4,"trung",11000);
	
//	T.them_cuoi(K);
//	T.them_cuoi(C);
//	T.xuat();
//	sanpham I;
//	cin >> I;
//	cout << I;
	List_sp E;
	E.them_cuoi(S);
	E.them_cuoi(K);
	E.them_cuoi(C);
	E.them_cuoi(T);
	E.xuat();
	int x =2;
	if(E.tim_kiem_theo_id(x) == true){
		cout << "\n yes";
	}
	return 0;
}
