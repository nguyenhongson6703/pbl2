#include "sanpham.h"
#include <iostream>
#include <string>
#include<bits/stdc++.h>

using namespace std;


sanpham :: sanpham(int ma, string ten , long long dg ){
    this -> ma_sp = ma;
    this->ten_sp = ten;
    this->dongia_sp = dg;
}

sanpham :: ~sanpham(){

}
istream &operator >> (istream &in, sanpham &sp){
	cout << "\n Nhap ma san pham:";
	in>> sp.ma_sp;
////	in.ignore();
	fflush(stdin);
    cout << "Nhap ten san pham: "; getline(in,sp.ten_sp);
    cout << endl;
    cout << "Nhap don gia san pham: "; in >> sp.dongia_sp;
    
    return in;
}
ostream &operator << (ostream &out, const sanpham &sp){
    out << setw(6) << sp.ma_sp << setw(10) << sp.ten_sp << setw(10) << sp.dongia_sp << endl;
} 
void sanpham::output(){
    cout << "\n Ma san pham:"<< ma_sp;
    cout << "\n Ten san pham:"<< ten_sp;
    cout << "\n Don gia :"<< dongia_sp;
}
int sanpham:: get_masp(){
    return this->ma_sp;
}
string sanpham:: get_tensp(){
    return this->ten_sp;
}
long long sanpham:: get_dongiasp(){
    return this->dongia_sp;
}
void sanpham:: set_masp(int x){
    this->ma_sp = x;
}
void sanpham:: set_tensp(string x){
    this->ten_sp = x;
}
void sanpham:: set_dongiasp(long long x){
    this->dongia_sp = x;
}


