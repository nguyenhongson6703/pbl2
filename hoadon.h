#ifndef hoa_don
#define hoa_don
#include "date.h"
#include "sanpham.h"
#include <iostream>
#include <string>

using namespace std;

struct SoLuongSP {
    string TenSP;
    int SoLuong;
};

class HoaDon : public date{
    private:
        static int Ma_HD;
        int n;
        SoLuongSP *data;
    public:
        HoaDon();
        ~HoaDon();
        void set_TenSoLuongSP(string, int, int );
        int get_MaHD();
        long long TongTien();
        friend ostream& operator << (ostream &, const HoaDon &);
        friend istream& operator >> (istream &, HoaDon &);
};
#endif
