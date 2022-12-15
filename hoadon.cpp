#include<bits/stdc++.h>
#include <string>
#include "hoadon.h"
using namespace std;

int HoaDon :: Ma_HD=0;

void xoakt(string &str)
{
    for(int i=0;i<str.length();i++)
    if(str[i]==' '&& str[i+1]==' ')
    {
      str.erase(str.begin() + i);
      i--;
    }
    if(str[0]==' ')
    str.erase(str.begin());
    if(str[str.length()-1]==' ')
    str.erase(str.begin() +str.length()-1 );
}
HoaDon::HoaDon(){
    Ma_HD++;
    id = Ma_HD;
    ngay = date();
}

HoaDon::HoaDon(int mahd, int n, muahang d[], long long tongtien, int day, int month, int year){
    this->id = mahd;
    this-> n= n;
    for(int i=0;i<n;i++){
        this->data[i].TenSP = d[i].TenSP;
        this->data[i].SoLuong = d[i].SoLuong;
        this->data[i].GiaTri = d[i].GiaTri;
    }
    this->tongtien = tongtien;
    this->ngay = date(day, month, year);
    this->Ma_HD = mahd;
}

HoaDon::~HoaDon(){
}

HoaDon& HoaDon:: operator = (const HoaDon& a) {
    this->id = a.id;
    this->n = a.n;
    for(int i=0;i<n;i++){
        this->data[i].TenSP = a.data[i].TenSP;
        this->data[i].SoLuong = a.data[i].SoLuong;
        this->data[i].GiaTri = a.data[i].GiaTri;
    }
    this->tongtien = a.tongtien;
    this->ngay = a.ngay;
    this->Ma_HD--;
    return *this;
}
int HoaDon::get_n(){
    return n;
}

int HoaDon::get_day(){
    return ngay.getday();
}

int HoaDon::get_month(){
    return ngay.getmonth();
}

int HoaDon::get_year(){
    return ngay.getyear();
}

long long HoaDon::get_tongtien(){
    return tongtien;
}

muahang HoaDon::get_muahang(int i){
    return data[i];
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

int HoaDon::get_id(){
    return this->id;
}

void HoaDon :: tinhGiaTri (List_sp &x){
    long long sum = 0;
    for (int i=0;i <this->n; i++){
        this->data[i].GiaTri = this->data[i].SoLuong * (x.tim_kiem_theo_ten(this->data[i].TenSP).get_dongiasp());
        sum+= this->data[i].GiaTri;
    }
    this->tongtien = sum;
}

ostream& operator << (ostream &out, HoaDon &x){
    out << "Hoa don " << x.id << endl;
    out << x.ngay;
    for (int i=0; i<x.n; i++)
        out << i + 1 << ". " << x.data[i].TenSP <<" "<< x.data[i].SoLuong << " " << x.data[i].GiaTri << endl;
    out << "Tong tien: " << x.tongtien <<endl;
    return out;
}

istream& operator >> (istream &in, HoaDon &x){ 
    cin >> x.ngay;
    int check;
    int i = 0;
    do{
        cout << "-->Nhap ten san pham thu "<< i+1<< endl;
        fflush(stdin);
        getline(in,x.data[i].TenSP);
        xoakt(x.data[i].TenSP);
        cout << "-->Nhap so luong san pham:"<< endl;
        in >> x.data[i].SoLuong;
        cout << "-->Ban co muon nhap tiep khong (0/1): " << endl;
        cin >> check;
        ++i;
    }while (check);
    x.n = i;
    return in;
}