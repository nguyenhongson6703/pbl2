#include "sanpham.h"
#include <bits/stdc++.h>
using namespace std;

sanpham :: sanpham(string ten , long long dg ){
    this->ten_sp = ten;
    this->dongia_sp = dg;
}

sanpham :: ~sanpham(){

}

sanpham& sanpham :: operator = (const sanpham& sp){
    this->id = sp.id;
    this->ten_sp = sp.ten_sp;
    this->dongia_sp = sp.dongia_sp;
    this->ma_sp--;
    return *this;
}

istream &operator >> (istream &in, sanpham &sp){
	fflush(stdin);
    cout << "Nhap ten san pham: "; getline(in,sp.ten_sp);
    cout << endl;
    cout << "Nhap don gia san pham: "; in >> sp.dongia_sp;
    return in;
}
ostream &operator << (ostream &out, const sanpham &sp){
    out << setw(30) << sp.ten_sp << setw(30) << sp.dongia_sp << endl;
    return out;
} 
string sanpham:: get_tensp(){
    return this->ten_sp;
}
long long sanpham:: get_dongiasp(){
    return this->dongia_sp;
}
void sanpham:: set_tensp(string x){
    this->ten_sp = x;
}
void sanpham:: set_dongiasp(long long x){
    this->dongia_sp = x;
}


