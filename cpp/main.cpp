// #include "../header/NgayBan.h"
// #include "../header/HoaDon.h"
#include "NgayBan.cpp"
#include "HoaDon.cpp"
#include "ChiTietHD.cpp"
#include "SanPham.cpp"
#include "QLCongTy.cpp"
using namespace std;
int main()
{

    QLCongTy ql("../data/sanpham.csv", "../data/chitiethoadon.csv", "../data/hoadon.csv");
    int luaChon;
    do
    {
        cout << "-------------Trang chu-----------\n";
        cout << "1.HoaDon\n";
        cout << "2.ChiTietHoaDon\n";
        cout << "3.SanPham\n";
        cout << "4.All\n";
        cout << "5.TinhtienHoaDon\n";
        cout << "6.SanPhamTop\n";
        cout << "7.KhachHangTop\n";
        cout << "0.Thoat\n";
        cout << "--------------end-----------------\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        switch (luaChon)
        {
        case 1:
            int lc1;
            do
            {

                cout << "----------------HoaDon--------------\n";
                cout << "1.Xem\n";
                cout << "2.Them\n";
                cout << "3.Xoa\n";
                cout << "4.Capnhat\n";
                cout << "5.Saoluu\n";
                cout << "6.Khoiphuc\n";
                cout << "0.Trang Chu\n";
                cout << "--------------end----------------------\n";
                cout << "Nhap lua chon: ";
                cin >> lc1;
                switch (lc1)
                {
                case 1:
                    cout << "Danh sach Hoa Don: \n";
                    ql.xemDSHoaDon();

                    break;
                case 2:
                    ql.themHoaDon();
                    break;
                case 3:
                    ql.xoaHoaDon();
                    break;
                case 4:
                    ql.capnhatHoaDon();
                    break;
                case 5:
                    ql.backupHoaDon();
                    break;
                case 6:
                    ql.khoiphucHoaDon();
                case 0:

                    break;

                default:
                    break;
                }
            } while (lc1 != 0);

            break;
        case 2:
            int lc2;
            do
            {
                cout << "----------------ChiTietHD------------\n";
                cout << "1.Xem\n";
                cout << "2.Them\n";
                cout << "3.Xoa\n";
                cout << "4.Capnhat\n";
                cout << "5.Saoluu\n";
                cout << "6.Khoiphuc\n";
                cout << "0.Trang Chu\n";
                cout << "--------------end----------------------\n";
                cout << "Nhap lua chon: ";
                cin >> lc2;
                switch (lc2)
                {
                case 1:
                    cout << "Danh sach Chi Tiet Hoa Don: \n";
                    ql.xemDSChiTietHD();

                    break;
                case 2:
                    ql.themChiTietHD();
                    break;
                case 3:
                    ql.xoaChiTietHD();
                    break;
                case 4:
                    ql.capnhatChiTietHD();
                    break;
                case 5:
                    ql.backupChiTietHD();
                    break;
                case 6:
                    ql.khoiphucChiTietHD();
                case 0:
                    break;
                default:
                    break;
                }
            } while (lc2 != 0);
            break;
        case 3:
            int lc3;
            do
            {
                cout << "----------------SanPham------------\n";
                cout << "1.Xem\n";
                cout << "2.Them\n";
                cout << "3.Xoa\n";
                cout << "4.Capnhat\n";
                cout << "5.Saoluu\n";
                cout << "6.Khoiphuc\n";
                cout << "0.Trang Chu\n";
                cout << "--------------end----------------------\n";
                cout << "Nhap lua chon: ";
                cin >> lc3;
                switch (lc3)
                {
                case 1:
                    cout << "Danh sach San Pham: \n";
                    ql.xemDSSanPham();

                    break;
                case 2:
                    ql.themSanPham();
                    break;
                case 3:
                    ql.xoaSanPham();
                    break;
                case 4:
                    ql.capnhatSanPham();
                    break;
                case 5:
                    ql.backupSanPham();
                    break;
                case 6:
                    ql.khoiphucSanPham();
                case 0:
                    break;
                default:
                    break;
                }
            } while (lc3 != 0);
            break;
        case 4:
            cout << "Danh sach hoa don: \n";
            ql.xemDSHoaDon();
            cout << "\nDanh sach san pham: \n";
            ql.xemDSSanPham();
            cout << "\nDanh sach chi tiet hoa don: \n";
            ql.xemDSChiTietHD();
            break;
        case 5:
        {
            string inputsoHD;
            cout << "Nhap soHD can tinh tong tien:  ";
            cin.ignore();
            getline(cin, inputsoHD);
            cout << "Tong tien: " << ql.tongTienHD(inputsoHD) << endl;
        }

        break;
        case 6:
        {
            int n;
            cout << "Top: ";
            cin >> n;
            ql.sanPhamTop(n);
        }
        break;
        case 7:
        {
            int n;
            cout << "Top: ";
            cin >> n;
            ql.khachHangTop(n);

        }
        break;
        case 0:
            cout << "Thoat\n";
            break;
        default:
            break;
        }

    } while (luaChon != 0);

    return 0;
}
