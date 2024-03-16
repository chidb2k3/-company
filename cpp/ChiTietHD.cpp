#include "../header/ChiTietHD.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
ChiTietHD::ChiTietHD(){
    
}
ChiTietHD::ChiTietHD(string _soHD, string _maSP, int _soLuong, int _giaBan){
    this->soHD = _soHD;
    this->maSP = _maSP;
    this->soLuong = _soLuong;
    this->giaBan = _giaBan;
}
string ChiTietHD::getSoHD(){
    return this->soHD;
}
void ChiTietHD::setSoHD(string _soHD){
    this->soHD = _soHD;
}
string ChiTietHD::getMaSP(){
    return this->maSP;
}
void ChiTietHD::setMaSP(string _maSP){
    this->maSP = _maSP;
}
int ChiTietHD::getSoLuong(){
    return this->soLuong;
}
void ChiTietHD::setSoLuong(int _soLuong){
    this->soLuong = _soLuong;
}
int ChiTietHD::getGiaBan(){
    return this->giaBan;
}
void ChiTietHD::setGiaBan(int _giaBan){
    this->giaBan = _giaBan;
}
string ChiTietHD::xemChiTietHD(){
    stringstream ss;
    ss << soHD << "|" << maSP << "|" << soLuong << "|" << giaBan;
    return ss.str();
}
ChiTietHD ChiTietHD::themChiTietHD(){
    string _soHD;
    string _maSP;
    int _soLuong;
    int _giaBan;
    cout << "\nNhap thong tin chi tiet hoa don: \n";
    cout << "Nhap SoHD: ";cin.ignore(); getline(cin, _soHD);
    cout << "Nhap MaSP: "; getline(cin, _maSP);
    cout << "Nhap SoLuong: "; cin >> _soLuong;
    cout << "Nhap Gia Ban: "; cin >> _giaBan;
    return ChiTietHD(_soHD, _maSP, _soLuong, _giaBan);
    


}
    
