#ifndef listsp_h
#define listsp_h
#include <string>
#include "list.h"
#include "sanpham.h"

class List_sp: public List<sanpham> {
    public:
		    long long gia_theo_ten(string value);
        void xoa_theo_ten(string value);
        bool tim_kiem_theo_ten(string value);
        void doc_sp();
        void ghi_sp();
};
#endif
