#include "list.h"
#include "listsp.h"
#include "listhd.h"
#include "hoadon.h"
#include "sanpham.h"
#include "date.h"
// #include "date.cpp"
#include <fstream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
	List_sp E;
    E.doc_sp();
    E.ghi_sp();

    List_hd F;

    HoaDon a;
    cin >> a;
    a.tinhGiaTri(E);
    F.them_cuoi(a);
    F.ghi_hd();

    HoaDon b;
    cin >> b;
    b.tinhGiaTri(E);
    F.them_cuoi(b);
    F.ghi_hd();

	return 0;
}
