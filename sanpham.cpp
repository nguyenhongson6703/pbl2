#include "sanpham.h"
#include <bits/stdc++.h>
using namespace std;

void xoakt(string &str);
string default_tensp(string& x){
    string str = x;
    for (int i=0;i<str.length();i++){
        if (i==0){
            if (str[i] >=97 && str[i] <=122) str[i] = str[i] - 32;
        } 
        else str[i] = tolower(str[i]);
    }
    return str;
}
sanpham :: sanpham(string ten , long long dg ){
    ten = default_tensp(ten);
    this->ten_sp = ten;
    this->dongia_sp = dg;
}


sanpham :: ~sanpham(){

}

sanpham& sanpham :: operator = (const sanpham& sp){
    this->ten_sp = sp.ten_sp;
    this->ten_sp = default_tensp(this->ten_sp);
    this->dongia_sp = sp.dongia_sp;
    return *this;
}

istream &operator >> (istream &in, sanpham &sp){
	fflush(stdin);
    cout << "Nhap ten san pham: "; getline(in,sp.ten_sp);
    xoakt(sp.ten_sp);
    sp.ten_sp = default_tensp(sp.ten_sp);
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



