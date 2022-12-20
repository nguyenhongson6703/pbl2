#include "listsp.h"
#include <bits/stdc++.h>
#include <string>
#include <fstream>
using namespace std;


// điều chỉnh lại setw và them hàm friend dèault...
void xoakt(string &str);
string default_tensp(string& x) ;

sanpham& List_sp::tim_kiem_theo_ten(string value){ 
	NODE<sanpham> *p = new NODE<sanpham>;
    p = this->gethead();
    do{
        if((p->data).get_tensp().compare(value) == 0) {
			return (p->data);
		}
        p = p -> next;
    }while (p != NULL);
}

bool List_sp::check_ten(string value){ 
	NODE<sanpham> *p = new NODE<sanpham>;
    p = this->gethead();
    string str;
    do{
        str = (p->data).get_tensp();
        if(str == value) {
            return true;
		}
        p = p -> next;
    }while (p != NULL);
    return false;
}

void List_sp::xoa_theo_ten(string value){
    if(check_ten(value) == true){
        NODE<sanpham>* p;
        p = gethead();
        while (p!= NULL && (p -> data).get_tensp()!= value)
        {
            p = p -> next;
        }
        if(p != NULL){
            if( p -> prev == NULL){
                xoa_dau();
                return;
            }
            if(p -> next == NULL){
                xoa_cuoi();
                return;
            }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->prev = NULL; 
        p->next = NULL;
        delete p;
        }
    }else{
        cout << "\n Khong co san pham ten "<< value<< "trong danh sach san pham!";
        return;
    }
}

void List_sp :: update_dssp(){
    while(true){
        cout << "-----------------------------------[ CAP NHAT SAN PHAM ]-----------------------------------"<< endl;
        cout << "1.Them loai san pham." << endl;
        cout << "2.Xoa loai san pham." << endl;
        cout << "3.Cap nhat thong tin loai san pham." << endl;
        cout << "4.Thoat!" << endl;
        cout << "Moi ban chon tinh nang: " << endl;
        int check, index; cin >>check;
        if (check == 1) {
            do{
                bool temp = true;
                sanpham s;
                string str;
                while(temp){
                    temp = false;
                    cin >> s;
                    str = s.get_tensp();
                    xoakt(str);
                    str = default_tensp(str);
                    try {
                        if (this->check_ten(str)){
                            temp = true;
                            throw string("-->San pham da co trong danh sach! Moi nhap lai\n" );
                        }
                    }
                    catch (string& e) {
                        cout << e << endl; 
                    }
                }
                s.set_tensp(str);
                this->them_cuoi(s);
                this->ghi_sp();
                cout << "-->Danh sach sau khi khem san pham<--"<< endl;
                this->in_sp();
                cout << "Ban co muon tiep tuc them san pham khong (0/1)?" << endl;
                cin >> index;
            }while (index);
        }
        else if (check == 2) {
            string str;
            do{   
                bool temp = true;
                while(temp){
                    temp = false;
                    cout << "Nhap ten san pham can xoa: ";
                    fflush(stdin);
                    getline(cin,str);
                    xoakt(str);
                    str = default_tensp(str);
                    try {
                        if (this->check_ten(str) == 0){
                            temp = true;
                            throw string("-->San pham khong co trong danh sach! Moi nhap lai\n");
                        } 
                    }
                    catch (string& e) {
                        cout << e << endl; 
                    }
                }
                this->xoa_theo_ten(str);
                this->ghi_sp();
                cout << "-->Danh sach sau khi xoa san pham<--"<< endl;
                this->in_sp();
                cout << "Ban co muon tiep tuc xoa san pham khong (0/1)?" << endl;
                cin >> index;
            }while(index);
        }
        else if ( check == 3) {
            do{    
                string str;
                cout << "Nhap ten san pham can cap nhat: ";
                fflush(stdin);
                getline(cin,str);
                xoakt(str);
                str = default_tensp(str);
                if (this->check_ten(str)==0){
                    throw string("San pham khong co trong danh sach. Ban co the them loai san pham moi vao danh sach!");
                } 
                else {
                    sanpham p;
                    p = this->tim_kiem_theo_ten(str);
                    this->xoa_theo_ten(str);
                    cin >> p;
                    cout << "-->Thong tin san pham sau khi cap nhat<-- "<< endl;
                    cout << p;

                    this->them_cuoi(p);
                    this->ghi_sp();
                    cout << "-->Danh sach sau khi cap nhat san pham<--"<< endl;
                    this->in_sp();
                }
                cout << "Ban co muon tiep tuc cap nhat san pham khong (0/1)?" << endl;
                cin >> index;
            }while(index);
        }
        else{
            cout << "Ket thuc chinh sua danh sach san pham!" << endl;
            cout << "----------------------------------------------------------------------------------" << endl;
            break;
        }
    }   
}
void List_sp :: doc_sp(){
    char chtensp[50], chgia[19];
    ifstream FileSP("sanpham_ip.txt");
    while (!FileSP.eof()){
        FileSP.getline(chtensp,50);
        string tensp = chtensp;
        FileSP.getline(chgia,19);
        long long gia = atof(chgia);
        sanpham S(tensp,gia);
        this->them_cuoi(S);
    }
    FileSP.close();    
}

void List_sp::ghi_sp(){
    ofstream FileSP("sanpham_ip.txt");
    NODE<sanpham> *p = new NODE<sanpham>;
    p = gethead();
    do{
        if (p!=gettail())
            FileSP << (p->data).get_tensp() << endl << (p->data).get_dongiasp() << endl; 
        else 
            FileSP << (p->data).get_tensp() << endl << (p->data).get_dongiasp() ;
        p = p -> next;
    } while (p != NULL);
}

void List_sp :: in_sp(){
    ofstream output("sanpham_op.txt");
    output.clear();
    NODE<sanpham> *p = new NODE<sanpham>;
    p = this->gethead();
    int i=0;
    cout  << setw(3) <<  "STT" << setw(30) << "TEN SAN PHAM" << setw(30) << "DON GIA" << endl;
    output << setw(3) <<  "STT" << setw(30) << "TEN SAN PHAM" << setw(30) << "DON GIA" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    output << "------------------------------------------------------------------------------------" << endl;
    do{
        i++;
        cout << setw(3) << (i);
        output << setw(3) << (i);
        // in du lieu ra
        cout << (p -> data);
        cout << "------------------------------------------------------------------------------------" << endl;
        output << (p->data);
        output << "------------------------------------------------------------------------------------" << endl;
        p = p -> next;

    }while (p != NULL);
}