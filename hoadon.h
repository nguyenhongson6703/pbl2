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

class HoaDon{
    private:
        static int Ma_HD;
        int n;
        muahang *data;
        long long tongtien;
        date ngay;
    public:
        HoaDon();
        HoaDon(int, int, muahang*, long long, int, int ,int);
        ~HoaDon();
        void set_hoadon();
        int get_MaHD();
        void tinhGiaTri(List_sp&);
        friend void xoakt(string &str);
        friend ostream& operator << (ostream &, HoaDon &);
        friend istream& operator >> (istream &, HoaDon &);
};
#endif