#ifndef listsp_h
#define listsp_h
#include "list.h"
#include "list.cpp"
#include "sanpham.h"

class List_sp: public List<sanpham> {
    public:
		  bool tim_kiem_theo_id(int value);
      void xoa_theo_id(int value);
};

#endif
