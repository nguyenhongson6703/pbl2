#include "list.h"
#include "listsp.h"
#include "listhd.h"
#include "date.h"
#include<bits/stdc++.h>
int main(){
	List_sp E;
    E.doc_sp();
    List_hd F;
    while(true){
        system("cls");
        cout << "--------------------------------------[ MENU ]--------------------------------------" <<endl;
        cout << "1.Quan ly san pham." <<endl;
        cout << "2.Thanh toan hoa don."<<endl;
        cout << "3.Quan ly hoa don." << endl;
        cout << "4.Thoat!" <<endl;
        cout << "Moi ban chon tinh nang: ";
        int check; cin >> check;
        if(check == 1) {
            while (true){
                cout <<"--------------------------------------[ SAN PHAM ]--------------------------------------" <<endl ;
                cout << "1. Tra cuu cac loai san pham."<< endl;
                cout << "2. Cap nhat thong tin danh sach san pham."<< endl;
                cout << "3. Thoat!"<< endl;
                int sl,sl1;
                cout << " Moi ban chon tinh nang: ";
                cin >> sl;
                if(sl == 1){
                    cout << "-----------------------------[ DANH SACH CAC SAN PHAM ]-----------------------------" << endl;
                    E.in_sp();
                    system("pause");
                    fflush(stdin);
                    cout << "Ban co muon xem noi dung cu the cua mot san pham (0/1) ? " << endl;
                    cin >> sl1;
                    while(sl1){
                        string str;
                        cout << "Nhap ten san pham can tim kiem: ";
                        fflush(stdin);
                        getline (cin , str);
                        cout << "-->Thong tin san pham can tim<-- " << endl;
                        sanpham p;
                        p = E.tim_kiem_theo_ten(str);
                        cout << p;
                        fflush(stdin);
                        cout << "Ban co muon tim kiem tiep hay khong (0/1)?" << endl;
                        cin >> sl1;
                    }
                }
                else if(sl == 2){
                    List_sp A;
                    A.update_dssp();
                    E = A;
                    E.ghi_sp();
                    E.in_sp();
                }
                else{
                    break;
                }
            }
        }
        else if (check == 2){

        }
        else if (check == 3){

        }
        else if (check == 4){
            cout << "Ket thuc chuong trinh!" << endl;
            cout << "----------------------------------------------------------------------------------" <<endl;
            break;
        }
    }
	return 0;
}
