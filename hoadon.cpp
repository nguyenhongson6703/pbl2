#include<bits/stdc++.h>
#include "HoaDon.h"

int HoaDon::Ma_HD=0;

HoaDon::HoaDon(){
    Ma_HD++;
}

HoaDon::~HoaDon(){
    Ma_HD--;
    delete [] data;
}

void HoaDon::set_TenSoLuongSP(string ten, int soluong, int i ){
    this->data[i].TenSP = ten;
    this->data[i].SoLuong = soluong;
}

int HoaDon::get_MaHD(){
    return this->Ma_HD;
}

long long HoaDon::TongTien(){
    long long s=0;
}

ostream& operator << (ostream &out, const HoaDon &x){
    for (int i=0; i<x.n; i++)
        cout << x.data[i].TenSP <<" "<< x.data[i].SoLuong << endl;
}

istream& operator >> (istream &in, HoaDon &x){ 
    int i=0;
    bool kt = true;
    while (kt) {
        cout << "   Nhap ten san pham: \n";
        cout << "--> "; getline(in,x.data[i].TenSP);
        cout << "   Nhap so luong san pham: \n";
        cout << "--> ", in >> x.data[i].SoLuong;
        int k;
        cout << "   Nhan phim 1 de tiep tuc, phim 0 de dung!\n" ;
        cout << "--> ", in >> k;
        if (k==1) kt=true; else kt=false;
        i++;
    }
    x.n = i;
    return in;
}
