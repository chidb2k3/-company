#include "../header/HoaDon.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
HoaDon::HoaDon(string _soHD, NgayBan _ngayBan, string _maKH){
    this->soHD = _soHD;
    this->ngayBan = _ngayBan;
    this->maKH = _maKH;
}
string HoaDon::getSoHD(){
    return this->soHD;
}
void HoaDon::setSoHD(string _soHD){
    this->soHD = _soHD;
}
NgayBan HoaDon::getNgayBan(){
    return this->ngayBan;
}
void HoaDon::setNgayBan(NgayBan _ngayBan){
    this->ngayBan = _ngayBan;
}
string HoaDon::getMaKH(){
    return this->maKH;
}
void HoaDon::setMaKH(string _maKH){
    this->maKH = _maKH;
}
string HoaDon::xemHoaDon(){
    stringstream ss;
    ss << soHD << " | " << ngayBan.xemNgayBan() << " | " << maKH;
    return ss.str();
}

       