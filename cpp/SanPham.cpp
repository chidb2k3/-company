#include "../header/SanPham.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
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
    ss << maSP << " | "<< tenSP << " | " << trongLuong << " | " << qcDongGoi;
    return ss.str();
}