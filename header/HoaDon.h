#ifndef HOADON_H
#define HOADON_H
#include "NgayBan.h"
#include <iostream>
using namespace std;


class HoaDon
{
private:
    string soHD;
    NgayBan ngayBan;
    string maKH;


public:
    HoaDon(string _soHD, NgayBan _ngayBan, string _maKH);
    string getSoHD();
    void setSoHD(string _sHD);
    NgayBan getNgayBan();
    void setNgayBan(NgayBan _ngayBan);
    string getMaKH();
    void setMaKH(string _maKH);
    string xemHoaDon();


   
};
#endif

