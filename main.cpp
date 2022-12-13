#include "list.h"
#include "listsp.h"
#include "listhd.h"
#include "date.h"
#include<bits/stdc++.h>
int main(){

List_sp SP;
SP.doc_sp();
    while(true){
        system("cls");
        cout << "---------------------------------------MENU---------------------------------------" <<endl;
        cout << "1.Quan ly san pham." <<endl;
        cout << "2.Than toan hoa don."<<endl;
        cout << "3.Quan ly hoa don." << endl;
        cout << "4.Thoat!" <<endl;
        cout << "Moi ban chon tinh nang: ";
        int check; cin >> check;
        while (check){
            if(check == 1) {
                cout << endl << endl;
                cout << "1. Tra cuu cac loai san pham."<< endl;
                cout << "2. Chinh sua thong tin cua san pham."<< endl;
                cout << "3. Thoat!"<< endl;
                int luachon;
                cout << " Moi ban chon tinh nang:";
                cin >> luachon;
                if(luachon == 1){

                }else if(luachon == 2){

                }else{
                    break;
                }
            }
            else if (check ==2){

            }
            else if (check == 3){

            }
            else if (check == 4){
                cout << "Ket thuc chuong trinh!" << endl;
                cout << "----------------------------------------------------------------------------------" <<endl;
                break;
            }
        }
    }

	return 0;
}