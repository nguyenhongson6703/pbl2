#ifndef sanpham_h
#define sanpham_h
#include <iostream>
#include <string>
using namespace std;

class sanpham {
    private:
        string ten_sp;
        long long dongia_sp;
    public: 
        sanpham (string = "sp1", long long= 0);
        ~sanpham();
        friend istream &operator >> (istream &in, sanpham &sp);
        friend ostream &operator << (ostream &out, const sanpham &sp);
        string get_tensp();
        long long get_dongiasp();
        void set_tensp(string x);
        void set_dongiasp(long long x);
};
#endif
      
