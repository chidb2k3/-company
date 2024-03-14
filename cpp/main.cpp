// #include "../header/NgayBan.h"
// #include "../header/HoaDon.h"
#include "NgayBan.cpp"
#include "HoaDon.cpp"
#include "ChiTietHD.cpp"
#include "SanPham.cpp"
#include "QLCongTy.cpp"
using namespace std;
int main(){
    // NgayBan n1(28,3,2003);
    // NgayBan n2(30,3,2003);

    // HoaDon hd1("HD001", n1,"KH004");
    // cout << hd1.getNgayBan().xemNgayBan();
    // hd1.setNgayBan(n2);
    // cout << hd1.getNgayBan().xemNgayBan();
    // cout << hd1.xemHoaDon();
    // ChiTietHD ct1("HD001","KP001",5,50000);
    // cout << ct1.xemChiTietHD();
    // SanPham sp1("KD001", "MiTom", 300, "VIP");
    // cout << sp1.xemSP();
    QLCongTy ql("../data/sanpham.csv", "../data/sanpham.csv");
    cout << "Danh sach san pham\n";
    ql.xemDSSanPham();
    cout << "\nDanh sach chi tiet san pham\n";
    ql.xemDSChiTietHD();







    return 0;
    


    
    
}
