#include "list.h"
#include "listsp.h"
#include "listhd.h"
#include "date.h"
#include<bits/stdc++.h>

void xoakt(string &str);
string default_tensp(string& x); // chỉnh mặc định cho tên là chữ cái đầu viết hoa
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
                cout <<"--------------------------------------[ QUAN LY SAN PHAM ]--------------------------------------" <<endl ;
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
                        bool temp = true;
                        string str;
                        while (temp){
                            temp = false;
                            cout << "Nhap ten san pham can tim kiem: ";
                            fflush(stdin);
                            getline(cin,str);
                            xoakt(str);
                            str = default_tensp(str);
                            try {
                                if (E.check_ten(str) == 0) {
                                    temp = true;
                                    throw string ("Thong tin san pham khong hop le! Vui long nhap lai.");
                                }
                            }
                            catch (string &e){
                                cout << e << endl;
                            }
                        }
                        cout << "-->Thong tin san pham can tim<-- " << endl;
                        sanpham p;
                        p = E.tim_kiem_theo_ten(str);
                        cout << "\t#" << p;
                        fflush(stdin);
                        cout << "Ban co muon tim kiem tiep hay khong (0/1)?" << endl;
                        cin >> sl1;
                    }
                }
                else if(sl == 2){
                    try{
                        E.update_dssp();
                    } 
                    catch (string &s) {
                        cout << s << endl;
                    }
                }
                else{
                    break;
                }
            }
        }
        else if (check ==2){
            HoaDon a;
            cin >> a;
            //set lại tên theo mặc định , nên tạo thêm hai hàm trong hoadon.cpp
            // set_ten với get_ten
            for(int i=0;i<a.get_n(); i++){
                string str = a.get_TenSP(i);
                str = default_tensp(str);
                a.set_TenSP(i,str); 
            }
            // tại trong hoa don in ra có đơn giá , nên chúng ta cần set_dg của san phâmr trục tiếp trong hóa đơn luôn
            // vì trong hàm operator << chỉ chứa đc hai tham số , nên ko thể thêm list vào đc 
            // làm cai nay cx tiẹn hon cho viec tính giá trị
            a.set_dg(E);
            // vif đã có hàm tính đơn giá , nên trong hàm tính giá trị ko cần tham số lít_sp
            a.tinhGiaTri();
            cout << a;
            // hàm in hoadon cx tương tụ bỏ đi tham số list_sp
            a.in_hoa_don();
            F.them_cuoi(a);
            F.ghi_hd();
        }
        else if (check == 3){
            while (true){
                cout <<"-----------------------------------[ QUAN LY HOA DON ]-----------------------------------" <<endl ;
                cout << "1. Tra cuu cac hoa don."<< endl;
                cout << "2. Cap nhat thong tin danh sach hoa don."<< endl;
                cout << "3. Thoat!"<< endl;
                int sl2;
                cout << "Nhap vao lua chon cua ban: ";
                cin >> sl2;
                if(sl2 == 1){
                    cout << "-->Thong tin cua tat ca cac hoa don la:" <<endl;
                    F.in_list_hd();
                    int select = 1;
                    do{
                        int x;
                        cout << "\n-->Nhap vao ma id cua hoa don can tim kiem: " << endl;
                        cin >> x;
                        // sáng thấy có hàm bool tìm kiem id, nhưng nó lạp với hàm có sẵn nên đã xóa
                        if(F.check_hd(x) == false){
                            cout << "-->Khong ton tai hoa don nay!" << endl;
                            continue;
                        }
                        HoaDon A;
                        A = F.tim_kiem_theo_id(x);
                        cout << "-->Thong tin cua hoa don can tim kiem la: " <<endl;
                        cout << A;
                        cout << "-->Ban co muon truy cuu tiep khong (0/1)? ";
                        int k;
                        cin >> k;
                        select = k;
                    }while(select == 1);
                    


                }else if(sl2 == 2){
                    cout << "-->Nhap vao id cua hoa don ma ban muon thay doi:";
                    int x;
                    cin >> x;
                    cout << "\nBan muon thuc hien thao tac nao:";
                    cout << "\n1.Xoa";
                    cout << "\n2.Thay doi thong tin cua hoa don";
                    cout << "\nLua chon:";
                    int select;
                    cin >> select;
                    if(select == 1 ){
                        F.xoa_theo_id(x);
                        F.ghi_hd();
                    }else{
                        F.tim_kiem_theo_id(x).set_hoadon(E);
                        F.ghi_hd();
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