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
    void docHoaDonTuFile();

public:
    QLCongTy(string _fileSanPham, string _fileChiTietHD, string _fileHoaDon);
    void dongBoBanSao(string fileGoc, string fileBanSao);
    void sanPhamTop(int n);
    void khachHangTop(int n);
    // Hoadon
    void xemDSHoaDon();
    void themHoaDon();
    void ghiDSHoaDon();
    void xoaHoaDon();
    void capnhatHoaDon();
    void backupHoaDon();
    void khoiphucHoaDon();
    int tongTienKH(string _maKH);

    // end Hoadon
    // Sanpham
    void xemDSSanPham();
    void ghiDSSanPham();
    void themSanPham();
    void xoaSanPham();
    void capnhatSanPham();
    void backupSanPham();
    void khoiphucSanPham();

    // endsanpham
    //chitietHD
    void xemDSChiTietHD();
    void themChiTietHD();
    void ghiDSChiTietHD();
    void xoaChiTietHD();
    void capnhatChiTietHD();
    void backupChiTietHD();
    void khoiphucChiTietHD();
    int tongTienHD(string _soHD);
    int soluongSanPham(string _maSP);
    //endchitiethd

};

#endif