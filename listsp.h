#ifndef listsp_h
#define listsp_h
#include <string>
#include "list.h"
#include "sanpham.h"

class List_sp: public List<sanpham> {
    public:
        sanpham& tim_kiem_theo_ten(string value);
        bool check_ten(string value);
        void xoa_theo_ten(string value);
        void update_dssp();
        void doc_sp();
        void ghi_sp();
        void in_sp();
};
#endif
