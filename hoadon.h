#ifndef hoa_don
#define hoa_don
#include "date.h"
#include "sanpham.h"
#include <iostream>
#include <string>

using namespace std;

struct muahang {
    string TenSP;
    int SoLuong;
};

class HoaDon : public date{
    private:
        int Ma_HD;
        int n;
        muahang *data;
    public:
        HoaDon(int count = 10, int ma = 1);
        ~HoaDon();
        void set_hoadon();
        int get_MaHD();
        long long TongTien();
        friend ostream& operator << (ostream &, const HoaDon &);
        friend istream& operator >> (istream &, HoaDon &);
};
#endif
