#pragma once
#include<iostream>
using namespace std;

class date{
    protected:
        int day;
        int month;
        int year;
    public:
        date(int x =1, int y=1 , int z=2022);
        date(const date& x );
        ~date();
        void setday(int x);
        int getday();
        void setmonth(int x);
        int getmonth();
        void setyear(int x);
        int getyear();
        friend ostream& operator<<(ostream& output ,  date& x);
        friend istream& operator>>(istream& input, date& x);
    
};