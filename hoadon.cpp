#include<bits/stdc++.h>
#include "HoaDon.h"
using namespace std;

int HoaDon::Ma_HD=0;

HoaDon::HoaDon():date(1,1,2021){
    n = 0;
    Ma_HD++;
}

HoaDon::~HoaDon(){
    Ma_HD--;
    delete [] data;
}

void HoaDon::set_muahang(string ten, int soluong, int i ){
    this->data[i].TenSP = ten;
    this->data[i].SoLuong = soluong;
}

int HoaDon::get_MaHD(){
    return this->Ma_HD;
}

long long HoaDon::TongTien(){
    long long s=0;
    return 0;
}

ostream& operator << (ostream &out, const HoaDon &x){
    for (int i=0; i<x.n; i++)
        out << x.data[i].TenSP <<" "<< x.data[i].SoLuong << endl;
    return out;
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
