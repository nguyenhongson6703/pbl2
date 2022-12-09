#include<bits/stdc++.h>
#include "HoaDon.h"
using namespace std;

int HoaDon :: Ma_HD = 0;
HoaDon::HoaDon(){
    Ma_HD++;
    data = new muahang[100];
    ngay = date();
}

HoaDon::~HoaDon(){
    Ma_HD--;
    delete [] data;
}

void set_hoadon(){
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

void HoaDon :: tinhGiaTri (List_sp &x){
    long long sum = 0;
    for (int i=0;i <this->n; i++){
        this->data[i].GiaTri = this->data[i].SoLuong * (x.gia_theo_ten(this->data[i].TenSP));
        sum+= this->data[i].GiaTri;
    }
    this->tongtien = sum;
}
ostream& operator << (ostream &out, HoaDon &x){
    out << "Hoa don " << x.Ma_HD << endl;
    out << x.ngay;
    for (int i=0; i<x.n; i++)
        out << i + 1 << ". " << x.data[i].TenSP <<" "<< x.data[i].SoLuong << " " << x.data[i].GiaTri << endl;
    out << "Tong tien: " << x.tongtien;
    return out;
}

istream& operator >> (istream &in, HoaDon &x){ 
    in >> x.ngay;
    int check;
    int i = 0;
    do{
        cout << "-->Nhap ten san pham thu "<< i+1<< endl;
        fflush(stdin);
        getline(in,x.data[i].TenSP);
        cout << "-->Nhap so luong san pham:"<< endl;
        in >> x.data[i].SoLuong;
        cout << "-->Ban co muon nhap tiep khong (0/1): " << endl;
        cin >> check;
        ++i;
    }while (check);
    x.n = i;
    return in;
}