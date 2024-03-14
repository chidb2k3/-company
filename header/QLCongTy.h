#ifndef CONGTY_H
#define CONGTY_H
#include "HoaDon.h"
#include "ChiTietHD.h"
#include "SanPham.h"
#include <vector>
using namespace std;
class QLCongTy
{
private:
    vector<HoaDon> dsHoaDon;
    vector<SanPham> dsSanPham;
    vector<ChiTietHD> dsChiTietHD;
    string fileHoaDon, fileSanPham, fileChiTietHD;
    void docSanPhamTuFile();
    void docChiTietHDTuFile();

    
public:
    QLCongTy(string _fileSanPham, string _fileChiTietHD);
    void xemDSSanPham();
    void xemDSChiTietHD();
    // void themHoaDon();
    
};

#endif