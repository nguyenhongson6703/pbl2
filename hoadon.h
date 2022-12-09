#ifndef hoa_don_h
#define hoa_don_h
#include "date.h"
#include "sanpham.h"
// #include "sanpham.h"
#include "listsp.h"
#include <iostream>
#include <string>

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
        long long TongTien();
        void TinhGiaTri(List_sp &);
        friend ostream& operator << (ostream &, const HoaDon &);
        friend istream& operator >> (istream &, HoaDon &);
};
#endif