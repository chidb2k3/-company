#ifndef SANPHAM_H
#define SANPHAM_H
#include <iostream>
using namespace std;
class SanPham
{
private:
    string maSP;
    string tenSP;
    int trongLuong;
    string qcDongGoi;
public:
    SanPham(string _maSP, string _tenSP, int _trongLuong, string _qcDongGoi);
    string getMaSP();
    void setMaSP(string _maSP);
    string getTenSP();
    void setTenSP(string _tenSP);
    int getTrongLuong();
    void setTrongLuong(int _trongLuong);
    string getQCDongGoi();
    void setQCDongGoi(string _qcDongGoi);
    string xemSP();
};

#endif