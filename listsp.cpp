#include "listsp.h"
#include <bits/stdc++.h>
#include <string>
#include <fstream>
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

void List_sp :: doc_sp(){
    char chtensp[100],chma[10],chgia[10];
    ifstream FileSP("sanpham_ip.txt");
    while (!FileSP.eof()){
        FileSP.getline(chma,10);
        int ma = atoi(chma);
        FileSP.getline(chtensp,10);
        string tensp = chtensp;
        FileSP.getline(chgia,10);
        long long gia = atof(chgia);
        sanpham S(ma,tensp,gia);
        this->them_cuoi(S);
    }
    FileSP.close();    
}

void List_sp::ghi_sp(){
    ofstream FileSP("sanpham_ip.txt");
    NODE<sanpham> *p = new NODE<sanpham>;
    p = gethead();
    do{
        if (p!=gettail())
            FileSP << (p->data).get_masp() << endl << (p->data).get_tensp() << endl << (p->data).get_dongiasp() << endl; 
        else 
            FileSP << (p->data).get_masp() << endl << (p->data).get_tensp() << endl << (p->data).get_dongiasp() ;
        p = p -> next;
    } while (p != NULL);
}

void List_sp :: in_sp(){
    string s;
    s = "sanpham_op.txt";
    this->xuat(s);
}

bool List_sp::tim_kiem_theo_ten(string value){ 
	NODE<sanpham> *p = new NODE<sanpham>;
    bool temp = false;
    p = this->gethead();
    do{
        if((p->data).get_tensp().compare(value) == 0) {
			temp= true;
            return temp;
		}
        p = p -> next;
    }while (p != NULL);
    return temp;
}

void List_sp::xoa_theo_ten(string value){
    if(tim_kiem_theo_ten(value) == true){
        NODE<sanpham>* p;
        p = gethead();
        while (p!= NULL && (p -> data).get_tensp()!= value)
        {
            p = p -> next;
        }
        if(p != NULL){
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
        p->prev = NULL; 
        p->next = NULL;
        delete p;
        }
    }else{
        cout << "\n Khong co san pham ten "<< value<< "trong danh sach san pham!";
        return;
    }
}