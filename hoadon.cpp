#include<bits/stdc++.h>
#include <string>
#include <iomanip>
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

void HoaDon :: set_hoadon(List_sp& A){
    while(true){
        system("cls");
        cout << "\n\t\t-----------Menu-----------"<< endl;
        cout << "1.Them loai san pham." << endl;
        cout << "2.Xoa loai san pham." << endl;
        cout << "3.Thay doi thong tin loai san pham." << endl;
        cout << "4.Thay doi ngay thang."<< endl;
        cout << "5.Thoat!." << endl;
        cout << "Moi ban chon tinh nang: " << endl;
        int check; cin >>check;
        if (check == 1){
            string str;
            int n;
            
            cout << "Nhap ten san pham: "; 
            fflush(stdin);
            getline(cin,str);
            cout << "\n Nhap vao so luong san pham: ";
            int x;
            cin >> x;
            this ->data[n].TenSP = str;
            this ->data[n].SoLuong= x;
            this -> n++;
            this ->tinhGiaTri(A);
        }
        else if (check == 2) {
            string str;
            cout << "\n Nhap vao ten san pham ma ban muon xoa di: ";
            fflush(stdin);
            getline(cin,str);
            int k;
            for(int i =0;i<=n;i++){
                if(this ->data[i].TenSP == str){
                    k = i;
                    break;

                }
                if(i == n){
                    cout << "\n San pham nay khong ton tai trong hoa don xin kiem tra lai!";
                    break;
                }
            }
            if(k != n){
                for(int i = k;i< n-1;i++){
                this ->data[i] = this ->data[i+1];

            }
            this -> n--;
            this ->tinhGiaTri(A);

            }
            
        }
        else if ( check == 3) {
            string str;
            cout << "\n Nhap vao ten san pham ma ban muon thay doi thong tin: ";
            fflush(stdin);
            getline(cin,str);
            int i=0;
            while (this ->data[i].TenSP != str)
            {
                i++;
                if(i == n){
                    cout << "\n San pham nay khong ton tai trong hoa don!";
                    break;
                }
            }
            if(i != n){
                cout << "\n Ban muon thay doi so luong san pham nay thanh bao nhieu: ";
                int x;
                cin >> x;
                this ->data[i].SoLuong= x;
                this ->tinhGiaTri(A);
            }


        }
        else if (check == 4) {
            cout << "\n Thay doi ngay thang nam: ";
            int x,y,z;
            cout << "\n Nhap vao ngay: ";
            cin >> x;
            cout << "\n Nhap vao thang: ";
            cin >> y;
            cout << "\n Nhap vao nam: ";
            cin >> z;
            this ->ngay.setday(x);
            this ->ngay.setmonth(y);
            this ->ngay.setyear(z);

        }
        else if (check == 5){
            cout << "\n Ket thuc chinh sua hoa don!" << endl;
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
        cout << "-->Nhap ten san pham thu: "<< i+1 << endl;
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
void HoaDon::in_hoa_don(List_sp& x){
    ofstream output("thanhtoan.txt");
    output << "\n Hoa don ngay "<< this ->ngay.getday() << "/"<< this ->ngay.getmonth()<<"/"<< this -> ngay.getyear();
    output << "\n ID: "<< this -> id << endl;
    output << " STT" << setw(10) << "Ten mon" << setw(15) << "SL" << setw(20) << "Don gia" << setw(15) << "T.Tien" << endl;
    for(int i=0 ;i < this ->n ; i++){
        output << "\n "<< i + 1;
        output << setw(10) << data[i].TenSP << setw(17) << data[i].SoLuong << setw(20) << x.tim_kiem_theo_ten(this->data[i].TenSP).get_dongiasp() <<setw(15) << data[i].GiaTri<< endl;
    }
    output <<  "-------------------------------------------------------------------------------------" << endl;
    output << setw(6)<< " TONG TIEN"<< setw(54) <<  this ->tongtien;
    output.close();
}