#ifndef sanpham_h
#define sanpham_h
#include <iostream>
#include <string>
using namespace std;

class sanpham {
    private:
        int id;
        static int ma_sp;
        string ten_sp;
        long long dongia_sp;
    public: 
        sanpham();
        sanpham (int, string, long long );
        ~sanpham();
        sanpham& operator = (const sanpham&);
        friend istream &operator >> (istream &in, sanpham &sp);
        friend ostream &operator << (ostream &out, const sanpham &sp);
        int get_id();
        string get_tensp();
        long long get_dongiasp();
        void set_id(int x);
        void set_tensp(string x);
        void set_dongiasp(long long x);
};
#endif
      
