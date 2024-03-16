#include "../header/SanPham.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
SanPham::SanPham(){
    this->maSP = "";
    this->tenSP = "";
    this->trongLuong = 0;
    this->qcDongGoi = "";

}
SanPham::SanPham(string _maSP, string _tenSP, int _trongLuong, string _qcDongGoi){
    this->maSP = _maSP;
    this->tenSP = _tenSP;
    this->trongLuong = _trongLuong;
    this->qcDongGoi = _qcDongGoi;

}
string SanPham::getMaSP(){
    return this->maSP;
}
void SanPham::setMaSP(string _maSP){
    this->maSP = _maSP;
}
string SanPham::getTenSP(){
    return this->tenSP;
}
void SanPham::setTenSP(string _tenSP){
    this->tenSP = _tenSP;
}
int SanPham::getTrongLuong(){
    return this->trongLuong;
}
void SanPham::setTrongLuong(int _trongLuong){
    this->trongLuong = _trongLuong;
}
string SanPham::getQCDongGoi(){
    return this->qcDongGoi;
}
void SanPham::setQCDongGoi(string _qcDongGoi){
    this->qcDongGoi = _qcDongGoi;
}
string SanPham::xemSP(){
    stringstream ss;
    ss << maSP << "|"<< tenSP << "|" << trongLuong << "|" << qcDongGoi;
    return ss.str();
}
SanPham SanPham::themSP(){
    string _maSP;
    string _tenSP;
    int _trongLuong;
    string _qcDongGoi;
    cout << "\nNhap thong tin san pham: \n";
    cin.ignore();
    cout << "MaSP: "; getline(cin, _maSP);
    cout << "TenSP: "; getline(cin, _tenSP);
    cout << "Trong luong: "; cin >> _trongLuong;
    cin.ignore();
    cout << "QCDongGoi: "; getline(cin, _qcDongGoi);
    return SanPham(_maSP,_tenSP,_trongLuong,_qcDongGoi);
}
