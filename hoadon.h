#ifndef hoadon_h
#define hoadon_h
#include "date.h"
#include "listsp.h"
#include <iostream>
#include <string>

using namespace std;

struct muahang {
    string TenSP;
    int SoLuong;
    long long GiaTri;
};

class HoaDon {
    private:
        static int Ma_HD;
        int id;
        int n;
        muahang data[100];
        long long tongtien;
        date ngay;
    public:
        HoaDon();
        HoaDon(int, int, muahang d[], long long, int, int, int);
        ~HoaDon();
        HoaDon& operator = (const HoaDon&);
        void set_hoadon(List_sp&);
        int get_id();
        int get_n();
        int get_day();
        int get_month();
        int get_year();
        long long get_tongtien();
        muahang get_muahang(int);
        void tinhGiaTri(List_sp&);
        void in_hoa_don(List_sp&);
        friend void xoakt(string &str);
        
        friend ostream& operator << (ostream &, HoaDon &);
        friend istream& operator >> (istream &, HoaDon &);
};
#endif