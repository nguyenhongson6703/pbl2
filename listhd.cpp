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
    char chmahd[10];
    char chday[10],chmoth[10],chyear[10];
    char ch_tongtien[19];
    char chn[10];
    char chtensp[50],ch_soluong[10],ch_giatri[19];
    ifstream FileHD("hoadon_ip.txt");
    while (!FileHD.eof()){
        FileHD.getline(chmahd,10);
        int mahd = atoi(chmahd);
        FileHD.getline(chday,10);
        int day = atoi(chday);
        FileHD.getline(chmoth,10);
        int moth = atoi(chmoth);
        FileHD.getline(chyear,10);
        int year = atoi(chyear);
        FileHD.getline(ch_tongtien,19);
        long long tongtien = atof(ch_tongtien);
        FileHD.getline(chn,10);
        int n = atoi(chn);
        muahang data[100];
        for (int i=0;i<n;i++){
            FileHD.getline(chtensp,50);
            data[i].TenSP = chtensp;
            FileHD.getline(ch_soluong,10);
            data[i].SoLuong = atoi(ch_soluong);
            FileHD.getline(ch_giatri,19);
            data[i].GiaTri = atof(ch_giatri);
        }  

        HoaDon S(mahd ,n, data, tongtien, day, moth, year);
        cout << S;
        this->them_cuoi(S);
    }
    FileHD.close();
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