#ifndef hoa_don
#define hoa_don
#include "date.h"
// #include "sanpham.h"
#include "listsp.h"
#include <iostream>
#include <string>

using namespace std;

struct muahang {
    string TenSP;
    int SoLuong;
    long long GiaTri;
};

class HoaDon : public date{
    private:
        static int Ma_HD;
        int n;
        muahang *data;
        long long tongtien;
    public:
        HoaDon();
        ~HoaDon();
        void set_hoadon();
        int get_MaHD();
        void TinhGiaTri(List_sp &);
        friend ostream& operator << (ostream &, const HoaDon &);
        friend istream& operator >> (istream &, HoaDon &);
};
#endif
