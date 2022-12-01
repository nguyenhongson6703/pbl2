#ifndef hoa_don
#define hoa_don
#include "date.h"
#include "sanpham.h"
#include <iostream>
#include <string>

using namespace std;

//đổi tên struct , đổi string thành sanpham
// đổi tên hàm set_soluongsp thành set_muahang
// tạm thời đổi "string" qua "sanpham" sẽ ko chạy main đc, vì vướng lỗi MỘT SỐ HÀM trong hoadon.cpp
// HÀM ISTREAM, HÀM SET_MUAHANG , ... 
// nếu muốn chạy thử thì đổi lại string Tensp rồi chạy nghe
struct muahang {
    string TenSP;
    //sanpham Tensp;
    int SoLuong;
};

class HoaDon : public date{
    private:
        static int Ma_HD;
        int n;
        muahang *data;
    public:
        HoaDon();
        ~HoaDon();
        void set_muahang(string, int, int );
        int get_MaHD();
        long long TongTien();
        friend ostream& operator << (ostream &, const HoaDon &);
        friend istream& operator >> (istream &, HoaDon &);
};
#endif
