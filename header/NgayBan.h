#ifndef NgayBan_H
#define NgayBan_H
#include <iostream>
using namespace std;

class NgayBan
{
private:
    int ngay;
    int thang;
    int nam;


public:
    NgayBan();
    NgayBan(int _ngay, int _thang, int _nam);
    string xemNgayBan();
    int getNgay();
    void setNgay(int _ngay);
    int getThang();
    void setThang(int _thang);
    int getNam();
    void setNam(int _nam);

  

   
};
#endif

