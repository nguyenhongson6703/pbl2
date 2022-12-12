#include "list.h"
#include "listsp.h"
#include "listhd.h"
#include "date.h"
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

int main(){
	List_sp E;
    E.doc_sp();
    sanpham a(12, "tuong" , 100000);
    E.them_cuoi(a);
    E.xoa_theo_ten("sua");
    E.ghi_sp();

    // List_hd F;

    // HoaDon a;
    // cin >> a;
    // a.tinhGiaTri(E);
    // F.them_cuoi(a);
    // F.ghi_hd();

    // HoaDon b;
    // cin >> b;
    // b.tinhGiaTri(E);
    // F.them_cuoi(b);
    // F.ghi_hd();

	return 0;
}