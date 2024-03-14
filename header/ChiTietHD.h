#ifndef CHITIETHD_H
#define CHITIETHD_H
#include <iostream>
using namespace std;
class ChiTietHD
{
private:
    string soHD;
    string maSP;
    int soLuong;
    int giaBan;

    
public:
    ChiTietHD(string _soHD, string _maSP, int _soLuong, int _giaBan);
    string getSoHD();
    void setSoHD(string _soHD);
    string getMaSP();
    void setMaSP(string _maSP);
    int getSoLuong();
    void setSoLuong(int _soLuong);
    int getGiaBan();
    void setGiaBan(int _giaBan);
    string xemChiTietHD();
    
    

    
};
#endif
