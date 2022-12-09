#ifndef listhd_h
#define listhd_h
#include "list.h"
#include "hoadon.h"

class List_hd: public List<HoaDon> {
    public:
	    bool tim_kiem_theo_id(int value);
        void xoa_theo_id(int value);
        void doc_hd();
        void ghi_hd();
};

#endif
