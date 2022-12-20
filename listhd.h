#ifndef listhd_h
#define listhd_h
#include "list.h"
#include "hoadon.h"
// đã bỏ hàm bool tìm kiếm id vì trùng hàm bool check_hd
class List_hd: public List<HoaDon> {
    public:
	    HoaDon& tim_kiem_theo_id(int );
        bool check_hd(int );
        void xoa_theo_id(int );
        void doc_hd();
        void ghi_hd();
        void in_list_hd();
        void in_ra_file();
};

#endif
