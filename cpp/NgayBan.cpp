#include "../header/NgayBan.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
NgayBan::NgayBan(){
    
}
NgayBan::NgayBan(int _ngay, int _thang, int _nam){
    this->ngay = _ngay;
    this->thang = _thang;
    this->nam = _nam;
}
int NgayBan::getNgay(){
    return this->ngay;
}
void NgayBan::setNgay(int _ngay){
    this->ngay = _ngay;
}
int NgayBan::getThang(){
    return this->thang;
}
void NgayBan::setThang(int _thang){
    this->thang = _thang;
}
int NgayBan::getNam(){
    return this->nam;
}
void NgayBan::setNam(int _nam){
    this->nam = _nam;
}
string NgayBan::xemNgayBan(){
    stringstream ss;
    ss << this->ngay << "/" << this->thang << "/" << this->nam;
    return ss.str();
}


