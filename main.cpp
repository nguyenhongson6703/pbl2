#include "list.h"
#include "listsp.h"
// #include "sanpham.h"
#include "listhd.h"
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    //ndasdadasgit 
	List_sp E;
    List_hd F;
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
