#ifndef hoa_don
#define hoa_don
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
        ~HoaDon();
        void set_hoadon();
        int get_MaHD();
        void xoa (string&, int);
        void xoakt (string&);
        void tinhGiaTri(List_sp&);
        friend ostream& operator << (ostream &, HoaDon &);
        friend istream& operator >> (istream &, HoaDon &);
};
#endif
