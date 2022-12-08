#include<bits/stdc++.h>
#include "HoaDon.h"
#include "listsp.h"
using namespace std;

int HoaDon::Ma_HD=0;

HoaDon::HoaDon(): date (){
    Ma_HD++;
    data = new muahang[100];
}

HoaDon::~HoaDon(){
    Ma_HD--;
    delete [] data;
}

void HoaDon::set_hoadon(){
    while(true){
        cout << "Menu"<< endl;
        cout << "1.Them loai san pham." << endl;
        cout << "2.Xoa loai san pham." << endl;
        cout << "3.Thay doi thong tin loai san pham." << endl;
        cout << "4.Thay doi ngay thang.";
        cout << "5.Thoat!." << endl;
        cout << "Moi ban chon tinh nang: " << endl;
        int check; cin >>check;
        if (check == 1) {
            string str;
            int n;
            cout << "Nhap ten san pham: "; 
            fflush(stdin);

        }
        else if (check == 2) {

        }
        else if ( check == 3) {

        }
        else if (check == 4) {

        }
        else if (check == 5){
            cout << "Ket thuc chinh sua hoa don!" << endl;
            break;
        }
    }
    
}
int HoaDon::get_MaHD(){
    return this->Ma_HD;
}

void HoaDon::TinhGiaTri(List_sp &x) {
    long long sum=0;
    for (int i=0; i<n; i++){
        this->data[i].GiaTri = this->data[i].SoLuong*(x.gia_theo_ten(this->data[i].TenSP));
        sum+= this->data[i].GiaTri;
    }
    this->tongtien = sum;
}

ostream& operator << (ostream &out, const HoaDon &x){
    for (int i=0; i<x.n; i++)
        out << i+1 << ". " << x.data[i].TenSP <<" "<< x.data[i].SoLuong <<" " << x.data[i].GiaTri << endl;
    out << "Tong tien : "<< x.tongtien;
    return out;
}

istream& operator >> (istream &in, HoaDon &x){ 
    int i=0;
    bool kt = true;
    while (kt) {
        cout << "   Nhap ten san pham: \n";
        cout << "--> ";fflush(stdin) ;getline(in,x.data[i].TenSP);
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