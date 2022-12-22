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
// thêm hàm này
string default_tensp(string& x);

HoaDon::HoaDon(){
    Ma_HD++;
    id = Ma_HD;
    ngay = date();
}

HoaDon::HoaDon(int mahd, int n, muahang d[], long long tongtien, long long tientra, long long tienthoi, int day, int month, int year){
    this->id = mahd;
    this->tientra = tientra;
    this->tienthoi = tienthoi;
    this-> n= n;
    for(int i=0;i<n;i++){
        this->data[i].TenSP = default_tensp(d[i].TenSP);
        this->data[i].SoLuong = d[i].SoLuong;
        this->data[i].dg = d[i].dg;
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
    this->tientra = a.tientra;
    this->tienthoi = a.tienthoi;
    for(int i=0;i<n;i++){
        this->data[i].TenSP = a.data[i].TenSP;
        this->data[i].TenSP = default_tensp(this->data[i].TenSP);
        this->data[i].SoLuong = a.data[i].SoLuong;
        this->data[i].dg = a.data[i].dg;
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

string HoaDon :: get_TenSP(int i){
    return this->data[i].TenSP;
}

long long HoaDon::get_tongtien(){
    return tongtien;
}
long long HoaDon::get_tientra(){
    return tientra;
}
long long HoaDon::get_tienthoi(){
    return tienthoi;
}

muahang HoaDon :: get_muahang(int i){
    return data[i];
}

void HoaDon:: set_TenSP(int i, string x){
    this->data[i].TenSP = x;
}

void HoaDon :: set_hoadon(List_sp& A){
    while(true){
        system("cls");
        cout << "------------------------------[ CAP NHAT SAN PHAM TRONG HOA DON ]------------------------------"<< endl;
        cout << "1.Them loai san pham." << endl;
        cout << "2.Xoa loai san pham." << endl;
        cout << "3.Thay doi thong tin loai san pham." << endl;
        cout << "4.Thay doi ngay thang."<< endl;
        cout << "5.Thoat!." << endl;
        cout << "Moi ban chon tinh nang: " << endl;
        string check; cin >>check;
        if (check == "1"){
            string str;
            int index;
            bool temp = true;
            while(temp){
                temp = false;
                cout << "Nhap ten san pham: "; 
                fflush(stdin);
                getline(cin,str);
                xoakt(str);
                default_tensp(str);
                try {
                    if (A.check_ten(str) == 0){
                        temp = true;
                        throw string ("Thong tin san pham ton tai! Vui long nhap lai!");
                    }
                }
                catch (string& e){
                    cout << e << endl;
                }
            }
            cout << "Nhap vao so luong san pham: ";
            int x;
            cin >> x;
            this ->data[n].TenSP = str;
            this ->data[n].SoLuong= x;
            this -> n++;
            this ->tinhGiaTri();
        }
        else if (check == "2") {
            string str;
            cout << "\n Nhap vao ten san pham ma ban muon xoa di: ";
            fflush(stdin);
            getline(cin,str);
            xoakt(str);
            default_tensp(str);          
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
                this ->tinhGiaTri();
            }
            
        }
        else if ( check == "3") {
            string str;
            cout << "\n Nhap vao ten san pham ma ban muon thay doi thong tin: ";
            fflush(stdin);
            getline(cin,str);
            xoakt(str);
            default_tensp(str);  
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
                this ->tinhGiaTri();
            }


        }
        else if (check == "4") {
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
        else if (check == "5"){
            cout << "\n Ket thuc chinh sua hoa don!" << endl;
            break;
        }
    }
}

int HoaDon::get_id(){
    return this->id;
}
void HoaDon :: set_dg(List_sp& x) {
    for(int i=0;i<this->n;i++){
        string str = this->data[i].TenSP;
        if(x.check_ten(str) == 0) {
            throw string ( str  + " khong ton tai !!!");
        }
        this->data[i].dg = x.tim_kiem_theo_ten(this->data[i].TenSP).get_dongiasp();
    }
}

void HoaDon :: thanhtoan(){
    long long t;
    cout << "\nNhap so tien nhan: "; cin >> t;
    this->tientra = t;
    this->tienthoi = -this->tongtien + this->tientra;
}

void HoaDon :: tinhGiaTri (){
    long long sum = 0;
    for (int i=0;i <this->n; i++){
        this->data[i].GiaTri = this->data[i].SoLuong * this->data[i].dg;
        sum+= this->data[i].GiaTri;
    }
    this->tongtien = sum;
}

ostream& operator << (ostream &out, HoaDon &x){
    out << " Hoa don ngay "<< x.ngay.getday() << "/"<< x.ngay.getmonth()<<"/"<< x. ngay.getyear();
    out << "\n ID: "<< x. id << endl;
    out << " STT" << setw(15) << "Ten mon" << setw(15) << "SL" << setw(20) << "Don gia" << setw(15) << "T.Tien" << endl;
    for(int i=0 ;i < x.n ; i++){
        out << "\n "<< setw(2) << i + 1;
        out << setw(16) << x.data[i].TenSP << setw(15) << x.data[i].SoLuong << setw(20) << x.data[i].dg <<setw(15) << x.data[i].GiaTri << endl;
    }
    out <<  "-------------------------------------------------------------------------------------" << endl;
    out << setw(6)<< " TONG TIEN " << setw(58) <<  x.tongtien << endl;
    out << setw(6)<< " THANH TOAN"<< setw(58) <<  x.tientra << endl;
    out << setw(6)<< " TIEN THOI " << setw(58) <<  x.tienthoi << endl;
    return out;
}

istream& operator >> (istream &in, HoaDon &x){ 
    cin >> x.ngay;
    string check;
    int i = 0;
    do{
        cout << "-->Nhap ten san pham thu: "<< i+1 << endl;
        fflush(stdin);
        getline(in,x.data[i].TenSP);
        xoakt(x.data[i].TenSP);
        default_tensp(x.data[i].TenSP);  
        cout << "-->Nhap so luong san pham:"<< endl;
        in >> x.data[i].SoLuong;
        while (true) {
            cout << "-->Ban co muon nhap tiep khong (0: Dung lai / 1: Tiep tuc): " << endl;
            cin >> check;
            if (check=="0"||check=="1") break;
        }
        ++i;
    }while (check=="1");
    x.n = i;
    return in;
}
void HoaDon::in_hoa_don(){
    ofstream output("thanhtoan.txt");
    output << "\n Hoa don ngay "<< this ->ngay.getday() << "/"<< this ->ngay.getmonth()<<"/"<< this -> ngay.getyear();
    output << "\n ID: "<< this -> id << endl;
    output << " STT" << setw(15) << "Ten mon" << setw(15) << "SL" << setw(20) << "Don gia" << setw(15) << "T.Tien" << endl;
    for(int i=0 ;i < this ->n ; i++){
        output << "\n "<< setw(2) << i + 1;
        output << setw(16) << data[i].TenSP << setw(15) << data[i].SoLuong << setw(20) << data[i].dg <<setw(15) << data[i].GiaTri<< endl;
    }
    output <<  "-------------------------------------------------------------------------------------" << endl;
    output << setw(6)<< " TONG TIEN "<< setw(58) <<  this ->tongtien << endl;
    output << setw(6)<< " THANH TOAN"<< setw(58) <<  this->tientra << endl;
    output << setw(6)<< " TIEN THOI "<< setw(58) <<  this->tienthoi << endl;
    output.close();
}