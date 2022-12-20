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
    long long dg;
    long long GiaTri;
};

class HoaDon{
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
        string get_TenSP(int );
        long long get_tongtien();
        void set_dg(List_sp&);
        void set_TenSP(int, string);
        muahang get_muahang(int);
        void tinhGiaTri();
        void in_hoa_don();
        
        friend void xoakt(string &str);
        friend string default_tensp(string& x);
        friend ostream& operator << (ostream &, HoaDon &);
        friend istream& operator >> (istream &, HoaDon &);
};
#endif
// vì thêm một biến là đơn giá nên sẽ có nhiều sự thay đổi trong hàm constructor, gán = , cout , in hóa đơn....