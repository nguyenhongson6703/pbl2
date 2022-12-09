#include "date.h"
#include <bits/stdc++.h>
using namespace std;
date::date(int x, int y, int z){
    this -> day = x;
    this -> month = y;
    this -> year = z;

}
date::date(const date& x){
    this -> day = x.day;
    this -> month = x.month;
    this -> year = x.year;

}
date::~date(){

}
void date::setday(int x){
    this -> day = x;

}
int date::getday(){
    return this -> day;


}
void date::setmonth(int x){
    this -> month = x;
}
int date::getmonth(){
    return this -> month;

}
void date::setyear(int x){
    this -> year = x;

}
int date::getyear(){
    return this -> year;

}
ostream&  operator<<(ostream& output, date& x){
    output << "Date:  "<< x.getday() <<"/  "<< x.getmonth() <<"/  "<< x.getyear() <<endl;
    return output;

}
istream& operator>>(istream& input, date& x){
    // nhap vao nam
    int day,month,year;
    do{
        cout << "\n Nhap vao nam:";
        input >> year;
        if(year > 2022){
            cout << "\n Hay nhap lai gia tri cua nam:";
        }

    }while(year > 2022);

    // nhap vao thang
    do{
        cout << "\n Nhap vao thang:";
        input >> month;
        if(month < 1 || month > 12){
            cout << "\n Hay nhap lai gia tri cua thang:";
        }

    }while (month < 1 || month > 12);
    // nhap vao ngay
    if( month == 1 || month == 3 || month ==5 || month ==7 || month == 8|| month == 10 || month == 12){
        do{
        cout << "\n Nhap vao ngay:";
        input >> day;
        if(day < 1 || day > 31){
            cout << "\n Hay nhap lai gia tri cua ngay!";

        }
        

        }while (day < 1 || day > 31);

        
        
    }else if(month == 4 || month == 6|| month ==9 || month == 11){

        do{
        cout << "\n Nhap vao ngay:";
        input >> day;
        if(day < 1 || day > 30){
            cout << "\n Hay nhap lai gia tri cua ngay!";

        }
        

        }while (day < 1 || day > 30);
    }else{
        if(( year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
            do{
                cout << "\n Nhap vao ngay:";
                input >> day;
                if( day < 1 || day > 29){
                    cout << "\n Nhap lai ngay!";

                }

            }while(day < 1 || day > 29);

        }else{
            do{
                cout << "\n Nhap vao ngay:";
                input >> day;
                if( day < 1 || day > 28){
                    cout << "\n Nhap lai ngay!";

                }

            }while(day < 1 || day > 28);
            

        }
    }
    x.setday(day);
    x.setmonth(month);
    x.setyear(year);
    return input;
}

