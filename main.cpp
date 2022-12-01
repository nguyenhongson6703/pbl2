#include "list.h"
#include "listsp.h"
#include "sanpham.cpp"
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

int main(){
	sanpham S(1,"sua",10000);
	sanpham K(2,"keo",12000);
	sanpham C(3,"ca rot",13000);
	sanpham T(4,"trung",11000);
	List_sp E;
	E.them_cuoi(S);
	E.them_cuoi(K);
	E.them_cuoi(C);
	E.them_cuoi(T);
    
    char chtensp[100],chma[10],chgia[10];

    ifstream FileSP("input.txt");
    while (!FileSP.eof()){
        FileSP.getline(chma,10);
        int ma = atoi(chma);
        FileSP.getline(chtensp,10);
        string tensp = chtensp;
        FileSP.getline(chgia,10);
        long long gia = atof(chgia);
        sanpham S(ma,tensp,gia);
        E.them_cuoi(S);
    }
    E.xuat();
    FileSP.close();
	return 0;
}
