#include "list.h"
#include "listsp.h"
#include "listhd.h"
#include "date.h"
#include<bits/stdc++.h>
int main(){
	List_sp E;
    E.doc_sp();
    List_hd F;
    F.doc_hd();
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
                cout << "Moi ban chon tinh nang: ";
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
                        getline(cin,str);
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
                    E.update_dssp();
                }
                else{
                    break;
                }
            }
        }
        else if (check ==2){
            HoaDon a;
            cin >> a;
            a.tinhGiaTri(E);
            a.in_hoa_don(E);
            F.them_cuoi(a);
            F.ghi_hd();
        }
        else if (check == 3){
            while (true){
                cout <<"--------------------------------------[ HOA DON ]--------------------------------------" <<endl ;
                cout << "1. Tra cuu cac hoa don."<< endl;
                cout << "2. Cap nhat thong tin danh sach hoa don."<< endl;
                cout << "3. Thoat!"<< endl;
                int sl2;
                cout << "\n Nhap vao lua chon cua ban:";
                cin >> sl2;
                if(sl2 == 1){
                    do{
                        int x;
                        cout << "\n Nhap vao ma id cua san pham can tim kiem";
                        HoaDon A;
                        A = F.tim_kiem_theo_id(x);
                        cout << "\n Thong tin cua hoa don can tim kiem la:";
                        cout << A;
                        cout << "\n Ban co muon truy cuu tiep khong (0/1)? ";
                        int select;
                        cin >> select;
                        if(select == 0){
                            break;
                    }

                    }while(true);
                    


                }else if(sl2 == 2){
                    cout << "\n Nhap vao id cua san pham ma ban muon thay doi:";
                    int x;
                    cin >> x;
                    cout << "\n Ban muon thuc hien thao tac nao:";
                    cout << "\n 1.Xoa";
                    cout << "\n 2.Thay doi thong tin cua hoa don:";
                    cout << "\n Lua chon:";
                    int select;
                    cin >> select;
                    if(select == 1 ){
                        F.xoa_theo_id(x);
                    }else{
                        // HoaDon A ;
                        // A = F.tim_kiem_theo_id(x);
                        // A.set_hoadon();
                        F.tim_kiem_theo_id(x).set_hoadon();
                    }

                }else{
                    break;
                }
            }

        }
        else if (check == 4){
            cout << "Ket thuc chuong trinh!" << endl;
            cout << "----------------------------------------------------------------------------------" <<endl;
            break;
        }
    }

return 0;
}
