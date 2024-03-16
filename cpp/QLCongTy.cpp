#include <iostream>
#include "../header/QLCongTy.h"
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
QLCongTy::QLCongTy(string _fileSanPham, string _fileChiTietHD, string _fileHoaDon)
{
    this->fileSanPham = _fileSanPham;
    docSanPhamTuFile();
    this->fileChiTietHD = _fileChiTietHD;
    docChiTietHDTuFile();
    this->fileHoaDon = _fileHoaDon;
    docHoaDonTuFile();
}
void QLCongTy::dongBoBanSao(string tenfileGoc, string tenfileBanSao)
{
    // Mở tệp tin backup để đọc
    ifstream fileBackup(tenfileBanSao, ios::binary);
    if (!fileBackup.is_open())
    {
        cerr << "Khong the mo file backup de doc." << endl;
        return;
    }

    // Mở tệp tin gốc để ghi
    std::ofstream fileGoc(tenfileGoc, ios::binary);
    if (!fileGoc.is_open())
    {
        std::cerr << "Khong the mo file goc de ghi." << std::endl;
        return;
    }

    // Đọc từ tệp tin backup và ghi vào tệp tin gốc
    char buffer[1024];
    while (!fileBackup.eof())
    {
        fileBackup.read(buffer, sizeof(buffer));
        fileGoc.write(buffer, fileBackup.gcount());
    }

    // Đóng tệp tin
    fileBackup.close();
    fileGoc.close();

    cout << "Dong bo thanh cong." << endl;
}
void QLCongTy::sanPhamTop(int n){
    vector<SanPham> ds;
    ds = dsSanPham;
    for (int i = 0; i < ds.size()-1; i++)
    {
        for (int j = i+1; j<ds.size(); j++)
        {
            if (soluongSanPham(ds[i].getMaSP())<soluongSanPham(ds[j].getMaSP()))
            {
                swap(ds[i],ds[j]);
            }
            
        }
        
    }
    cout << "Top " << n << " san pham ban nhieu nhat\n";
    for (int i = 0; i < n; i++)
    {
        if (i<ds.size())
        {
            cout << "STT_"<<i+1<<" TenSP: " <<ds[i].getTenSP() << " So luong: "<< soluongSanPham(ds[i].getMaSP()) << endl;
        }else{
            break;
        }
        
        
    }
    
    
}
void QLCongTy::khachHangTop(int n){
    vector<string> dskh;
    for (int i = 0; i < dsHoaDon.size(); i++)
    {
        dskh.push_back(dsHoaDon[i].getMaKH());
    }
     // Sắp xếp mảng để đảm bảo các phần tử trùng lặp được liên tục
    sort(dskh.begin(), dskh.end());

    // Loại bỏ các phần tử trùng lặp để chỉ giữ lại 1 giá trị
    for (int i = 0; i < dskh.size() - 1; i++) {
        if (dskh[i] == dskh[i + 1]) {
            dskh.erase(dskh.begin() + i);
            i--;  // Giảm i để kiểm tra lại phần tử mới tại vị trí i
        }
    }
    for (int i = 0; i < dskh.size()-1; i++)
    {
        for (int j = i+1; j<dskh.size(); j++)
        {
            if (tongTienKH(dskh[i])<tongTienKH(dskh[j]))
            {
                swap(dskh[i], dskh[j]);
            }
            
            
        }
        
    }
    cout << "Top " << n << " khach hang mua nhieu nhat\n";
    for (int i = 0; i < n; i++)
    {
        if (i<dskh.size())
        {
             cout << "STT_"<<i+1<< " MaKH: " << dskh[i] << " Tong tien mua: " << tongTienKH(dskh[i]) << endl;
        }else
        {
            break;
        }
        
        
        
       
    }
    

    

}
// Start HoaDon
void QLCongTy::docHoaDonTuFile()
{
    ifstream file(fileHoaDon);
    if (!file.is_open())
    {
        cerr << "No open file HoaDon " << fileHoaDon << endl;
        return;
    }
    dsHoaDon.clear();
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, '|'))
        {
            tokens.push_back(token);
        }
        if (tokens.size() == 3)
        {
            string soHD = tokens[0];
            string ngayBan = tokens[1];
            string maKH = tokens[2];
            int ngay, thang, nam;
            char discard;
            stringstream ss(ngayBan);
            ss >> ngay >> discard >> thang >> discard >> nam;
            NgayBan nb(ngay, thang, nam);
            dsHoaDon.push_back(HoaDon(soHD, nb, maKH));
        }
    }
    file.close();
}
void QLCongTy::xemDSHoaDon()
{
    for (auto &hd : dsHoaDon)
    {
        cout << "ID: " << hd.xemHoaDon() << endl;
    }
}
void QLCongTy::ghiDSHoaDon()
{
    std::ofstream file(fileHoaDon);

    if (!file.is_open())
    {
        std::cerr << "No open file " << fileHoaDon << " write" << std::endl;
        return;
    }

    for (auto &hd : dsHoaDon)
    {
        file << hd.xemHoaDon() << std::endl;
    }

    file.close();
}
void QLCongTy::themHoaDon()
{
    HoaDon hd;
    dsHoaDon.push_back(hd.themHoaDon());
    ghiDSHoaDon();
    cout << "\nThem hoa don thanh cong\n";
}
void QLCongTy::xoaHoaDon()
{
    // xoa hoa don theo soHD
    string _soHD;
    int count = 0;
    cout << "Nhap soHD muon xoa: ";
    cin.ignore();
    getline(cin, _soHD);
    for (int i = 0; i < dsHoaDon.size(); i++)
    {
        if (dsHoaDon[i].getSoHD() == _soHD)
        {
            count++;
            dsHoaDon.erase(dsHoaDon.begin() + i);
        }
    }
    if (count == 0)
    {
        cout << "Khong tim thay soHD ban nhap!!!!!!\n";
    }
    else
    {
        cout << "Tim thay " << count << " Ket qua va da xoa\n";
    }

    ghiDSHoaDon();
}
void QLCongTy::capnhatHoaDon()
{
    string _soHD;
    cout << "Nhap soHD can cap nhat: ";
    cin.ignore();
    getline(cin, _soHD);
    int count = 0;
    for (int i = 0; i < dsHoaDon.size(); i++)
    {
        if (dsHoaDon[i].getSoHD() == _soHD)
        {
            count++;
            cout << "Tim thay ket qua: \n";
            cout << dsHoaDon[i].xemHoaDon() << endl;
            cout << "Nhap thong tin moi: \n";
            string new_soHD;
            string new_maKH;
            int ngay, thang, nam;
            cout << "New SoHD: ";
            getline(cin, new_soHD);
            cout << "Ngay: ";
            cin >> ngay;
            cout << "Thang: ";
            cin >> thang;
            cout << "Nam: ";
            cin >> nam;
            NgayBan new_ngayBan(ngay, thang, nam);
            cout << "New maKH: ";
            cin.ignore();
            getline(cin, new_maKH);
            dsHoaDon[i].setSoHD(new_soHD);
            dsHoaDon[i].setNgayBan(new_ngayBan);
            dsHoaDon[i].setMaKH(new_maKH);
            ghiDSHoaDon();
            cout << "Cap nhat thanh cong\n";
        }
    }
    if (count == 0)
    {
        cout << "Khong tim thay !!!!!!!!!!!\n";
    }
}
void QLCongTy::backupHoaDon()
{

    bool suDungNgayThang = true;
    // Tạo tên file sao lưu có chứa ngày tháng và thời gian (nếu được yêu cầu)
    string tenFileSaoLuu = "../backup/backup_danhba.csv";

    if (suDungNgayThang)
    {
        // Lấy thời gian hiện tại
        auto now = chrono::system_clock::now();
        time_t time = chrono::system_clock::to_time_t(now);

        // Định dạng thời gian thành chuỗi ngày tháng và thời gian
        stringstream ss;
        ss << put_time(localtime(&time), "%Y-%m-%d_%H-%M-%S");
        string ngayThangThoiGian = ss.str();

        // Thêm ngày tháng và thời gian vào tên file
        tenFileSaoLuu = "../data/backup/hoadon/hoadon_" + ngayThangThoiGian + ".csv";
    }

    std::ofstream fileBackup(tenFileSaoLuu);

    if (!fileBackup.is_open())
    {
        std::cerr << "Khong the mo file " << tenFileSaoLuu << " để sao lưu." << std::endl;
        return;
    }

    for (auto &hd : dsHoaDon)
    {
        fileBackup << hd.xemHoaDon() << endl;
    }

    fileBackup.close();
    cout << "Data dc sao luu vao file " << tenFileSaoLuu << "." << std::endl;
}
void QLCongTy::khoiphucHoaDon()
{
    string tenThuMuc = "../data/backup/hoadon";
    vector<string> list_backup;

    // Kiểm tra sự tồn tại của thư mục
    if (GetFileAttributesA(tenThuMuc.c_str()) != INVALID_FILE_ATTRIBUTES)
    {
        cout << "Folder ton tai." << std::endl;

        // Duyệt qua tất cả các tệp tin trong thư mục
        WIN32_FIND_DATAA findFileData;
        HANDLE hFind = FindFirstFileA((tenThuMuc + "\\*").c_str(), &findFileData);

        if (hFind != INVALID_HANDLE_VALUE)
        {
            do
            {
                if (strcmp(findFileData.cFileName, ".") != 0 && strcmp(findFileData.cFileName, "..") != 0)
                {
                    list_backup.push_back(findFileData.cFileName);
                }
            } while (FindNextFileA(hFind, &findFileData) != 0);

            FindClose(hFind);
        }
    }
    else
    {
        std::cerr << "Backup does not exits." << std::endl;
    }
    for (size_t i = 0; i < list_backup.size(); i++)
    {
        cout << i + 1 << "." << list_backup[i] << endl;
    }

    cout << "So luong filehoadon back_up " << list_backup.size();
    cout << "\nChon file hoa don back_up restore: ";
    int k;
    cin >> k;
    dongBoBanSao("../data/hoadon.csv", "../data/backup/hoadon/" + list_backup[k - 1]);
    docHoaDonTuFile();
}
int QLCongTy::tongTienKH(string _maKH){
    int sum=0;
    for (int i = 0; i < dsHoaDon.size(); i++)
    {
        if (dsHoaDon[i].getMaKH()==_maKH)
        {
            sum+=tongTienHD(dsHoaDon[i].getSoHD());
        }
        
    }
    return sum;
    
}
// end HoaDon
//  Start SanPham
void QLCongTy::docSanPhamTuFile()
{
    std::ifstream file(fileSanPham);

    if (!file.is_open())
    {
        std::cerr << "Không thể mở file " << fileSanPham << std::endl;
        return;
    }

    dsSanPham.clear(); // Xóa dữ liệu cũ trước khi đọc mới

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, '|'))
        {
            tokens.push_back(token);
        }

        if (tokens.size() == 4)
        {
            string maSP = tokens[0];
            string tenSP = tokens[1];
            int trongLuong = std::stoi(tokens[2]);
            string qcDongGoi = tokens[3];

            dsSanPham.push_back(SanPham(maSP, tenSP, trongLuong, qcDongGoi));
        }
    }

    file.close();
}
void QLCongTy::xemDSSanPham()
{
    for (auto &sp : dsSanPham)
    {
        std::cout << "ID: " << sp.xemSP() << std::endl;
    }
}
void QLCongTy::ghiDSSanPham()
{
    std::ofstream file(fileSanPham);

    if (!file.is_open())
    {
        std::cerr << "No open file " << fileSanPham << " write" << std::endl;
        return;
    }

    for (auto &sp : dsSanPham)
    {
        file << sp.xemSP() << std::endl;
    }

    file.close();
}
void QLCongTy::themSanPham()
{
    SanPham sp;
    dsSanPham.push_back(sp.themSP());
    ghiDSSanPham();
    cout << "\nThem san pham thanh cong\n";
}
void QLCongTy::xoaSanPham()
{
    string _maSP;
    cout << "Nhap maSP can xoa: ";
    cin.ignore();
    getline(cin, _maSP);
    int count = 0;
    for (int i = 0; i < dsSanPham.size(); i++)
    {
        if (dsSanPham[i].getMaSP() == _maSP)
        {
            count++;
            dsSanPham.erase(dsSanPham.begin() + i);
        }
    }
    if (count == 0)
    {
        cout << "Khong tim thay maSP de xoa!!!!\n";
    }
    else
    {
        cout << "Tim thay " << count << " ket qua va da xoa no!\n";
    }
    ghiDSSanPham();
}
void QLCongTy::capnhatSanPham()
{

    string _maSP;
    cout << "Nhap maSP can cap nhat: ";
    cin.ignore();
    getline(cin, _maSP);
    int count;
    for (int i = 0; i < dsSanPham.size(); i++)
    {
        if (dsSanPham[i].getMaSP() == _maSP)
        {
            string new_maSP;
            string new_tenSP;
            int new_trongLuong;
            string new_qcDongGoi;
            count++;
            cout << "Tim thay ket qua\n";
            cout << dsSanPham[i].xemSP() << endl;
            cout << "Nhap thong tin san pham: \n";
            cout << "new maSP: ";
            getline(cin, new_maSP);
            cout << "new tenSp: ";
            getline(cin, new_tenSP);
            cout << "new trong luong: ";
            cin >> new_trongLuong;
            cout << "new qcDongGoi: ";
            cin.ignore();
            getline(cin, new_qcDongGoi);
            dsSanPham[i].setMaSP(new_maSP);
            dsSanPham[i].setTenSP(new_tenSP);
            dsSanPham[i].setTrongLuong(new_trongLuong);
            dsSanPham[i].setQCDongGoi(new_qcDongGoi);
            ghiDSSanPham();
            cout << "Cap nhat thanh cong\n";
        }
    }

    if (count == 0)
    {
        cout << "Khong tim thay !!!!!!!!!!!\n";
    }
}
void QLCongTy::backupSanPham()
{

    bool suDungNgayThang = true;
    // Tạo tên file sao lưu có chứa ngày tháng và thời gian (nếu được yêu cầu)
    string tenFileSaoLuu = "../backup/backup_danhba.csv";

    if (suDungNgayThang)
    {
        // Lấy thời gian hiện tại
        auto now = chrono::system_clock::now();
        time_t time = chrono::system_clock::to_time_t(now);

        // Định dạng thời gian thành chuỗi ngày tháng và thời gian
        stringstream ss;
        ss << put_time(localtime(&time), "%Y-%m-%d_%H-%M-%S");
        string ngayThangThoiGian = ss.str();

        // Thêm ngày tháng và thời gian vào tên file
        tenFileSaoLuu = "../data/backup/sanpham/sanpham_" + ngayThangThoiGian + ".csv";
    }

    std::ofstream fileBackup(tenFileSaoLuu);

    if (!fileBackup.is_open())
    {
        std::cerr << "Khong the mo file " << tenFileSaoLuu << " để sao lưu." << std::endl;
        return;
    }

    for (auto &sp : dsSanPham)
    {
        fileBackup << sp.xemSP() << endl;
    }

    fileBackup.close();
    cout << "Data dc sao luu vao file " << tenFileSaoLuu << "." << std::endl;
}
void QLCongTy::khoiphucSanPham()
{
    string tenThuMuc = "../data/backup/sanpham";
    vector<string> list_backup;

    // Kiểm tra sự tồn tại của thư mục
    if (GetFileAttributesA(tenThuMuc.c_str()) != INVALID_FILE_ATTRIBUTES)
    {
        cout << "Folder ton tai." << std::endl;

        // Duyệt qua tất cả các tệp tin trong thư mục
        WIN32_FIND_DATAA findFileData;
        HANDLE hFind = FindFirstFileA((tenThuMuc + "\\*").c_str(), &findFileData);

        if (hFind != INVALID_HANDLE_VALUE)
        {
            do
            {
                if (strcmp(findFileData.cFileName, ".") != 0 && strcmp(findFileData.cFileName, "..") != 0)
                {
                    list_backup.push_back(findFileData.cFileName);
                }
            } while (FindNextFileA(hFind, &findFileData) != 0);

            FindClose(hFind);
        }
    }
    else
    {
        std::cerr << "Backup does not exits." << std::endl;
    }
    for (size_t i = 0; i < list_backup.size(); i++)
    {
        cout << i + 1 << "." << list_backup[i] << endl;
    }

    cout << "So luong file san pham back_up " << list_backup.size();
    cout << "\nChon file san pham back_up restore: ";
    int k;
    cin >> k;
    dongBoBanSao("../data/sanpham.csv", "../data/backup/sanpham/" + list_backup[k - 1]);
    docSanPhamTuFile();
}

// end sanpham

// start Chitiethoadon
void QLCongTy::docChiTietHDTuFile()
{
    ifstream file(fileChiTietHD);

    if (!file.is_open())
    {
        cerr << "Không thể mở file " << fileChiTietHD << std::endl;
        return;
    }

    dsChiTietHD.clear(); // Xóa dữ liệu cũ trước khi đọc mới

    string line;
    while (std::getline(file, line))
    {
        stringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, '|'))
        {
            tokens.push_back(token);
        }

        if (tokens.size() == 4)
        {
            string soHD = tokens[0];
            string maSP = tokens[1];
            try
            {
                int soLuong = std::stoi(tokens[2]);
                int giaBan = std::stoi(tokens[3]);
                dsChiTietHD.push_back(ChiTietHD(soHD, maSP, soLuong, giaBan));
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << "Error converting to integer: " << e.what() << std::endl;
                // Xử lý lỗi, ví dụ: bỏ qua hoặc đưa ra thông báo
            }
            catch (const std::out_of_range &e)
            {
                std::cerr << "Value out of range for integer: " << e.what() << std::endl;
                // Xử lý lỗi, ví dụ: bỏ qua hoặc đưa ra thông báo
            }
        }
    }

    file.close();
}
void QLCongTy::xemDSChiTietHD()
{
    for (auto &chitiet : dsChiTietHD)
    {
        std::cout << "ID: " << chitiet.xemChiTietHD() << std::endl;
    }
}
void QLCongTy::ghiDSChiTietHD()
{
    std::ofstream file(fileChiTietHD);

    if (!file.is_open())
    {
        std::cerr << "No open file " << fileChiTietHD << " write" << std::endl;
        return;
    }

    for (auto &ct : dsChiTietHD)
    {
        file << ct.xemChiTietHD() << std::endl;
    }

    file.close();
}
void QLCongTy::themChiTietHD()
{
    ChiTietHD c1;
    dsChiTietHD.push_back(c1.themChiTietHD());
    ghiDSChiTietHD();
    cout << "\n Them thanh cong\n";
}
void QLCongTy::xoaChiTietHD()
{
    string _soHD;
    cout << "Nhap soHD can xoa: ";
    cin.ignore();
    getline(cin, _soHD);
    int count = 0;
    for (int i = 0; i < dsChiTietHD.size(); i++)
    {
        if (dsChiTietHD[i].getSoHD() == _soHD)
        {
            count++;
            dsChiTietHD.erase(dsChiTietHD.begin() + i);
        }
    }
    if (count == 0)
    {
        cout << "Khong tim thay soHD de xoa!!!!\n";
    }
    else
    {
        cout << "Tim thay " << count << " ket qua va da xoa no!\n";
    }
    ghiDSChiTietHD();
}
void QLCongTy::capnhatChiTietHD()
{
    int count = 0;
    string _soHD;
    cout << "Nhap soHD can cap nhat: ";
    cin.ignore();
    getline(cin, _soHD);
    for (int i = 0; i < dsChiTietHD.size(); i++)
    {
        if (dsChiTietHD[i].getSoHD() == _soHD)
        {
            count++;
            cout << "Tim thay ket qua: \n";
            cout << dsChiTietHD[i].xemChiTietHD() << endl;
            string new_soHD;
            string new_maSP;
            int new_soLuong;
            int new_giaBan;
            cout << "Nhap thong tin cap nhat: \n";
            cout << "new soHD: ";
            getline(cin, new_soHD);
            cout << "new maSP: ";
            getline(cin, new_maSP);
            cout << "new soluong: ";
            cin >> new_soLuong;
            cout << "new giaban: ";
            cin >> new_giaBan;
            dsChiTietHD[i].setSoHD(new_soHD);
            dsChiTietHD[i].setMaSP(new_maSP);
            dsChiTietHD[i].setSoLuong(new_soLuong);
            dsChiTietHD[i].setGiaBan(new_giaBan);
            ghiDSChiTietHD();
            cout << "Cap nhat thanh cong\n";
        }
    }
    if (count == 0)
    {
        cout << "Khong tim thay!!!!!\n";
    }
}
void QLCongTy::backupChiTietHD()
{

    bool suDungNgayThang = true;
    // Tạo tên file sao lưu có chứa ngày tháng và thời gian (nếu được yêu cầu)
    string tenFileSaoLuu = "../backup/backup_danhba.csv";

    if (suDungNgayThang)
    {
        // Lấy thời gian hiện tại
        auto now = chrono::system_clock::now();
        time_t time = chrono::system_clock::to_time_t(now);

        // Định dạng thời gian thành chuỗi ngày tháng và thời gian
        stringstream ss;
        ss << put_time(localtime(&time), "%Y-%m-%d_%H-%M-%S");
        string ngayThangThoiGian = ss.str();

        // Thêm ngày tháng và thời gian vào tên file
        tenFileSaoLuu = "../data/backup/chitiethoadon/chitiethoadon_" + ngayThangThoiGian + ".csv";
    }

    std::ofstream fileBackup(tenFileSaoLuu);

    if (!fileBackup.is_open())
    {
        std::cerr << "Khong the mo file " << tenFileSaoLuu << " để sao lưu." << std::endl;
        return;
    }

    for (auto &ct : dsChiTietHD)
    {
        fileBackup << ct.xemChiTietHD() << endl;
    }

    fileBackup.close();
    cout << "Data dc sao luu vao file " << tenFileSaoLuu << "." << std::endl;
}
void QLCongTy::khoiphucChiTietHD()
{
    string tenThuMuc = "../data/backup/chitiethoadon";
    vector<string> list_backup;

    // Kiểm tra sự tồn tại của thư mục
    if (GetFileAttributesA(tenThuMuc.c_str()) != INVALID_FILE_ATTRIBUTES)
    {
        cout << "Folder ton tai." << std::endl;

        // Duyệt qua tất cả các tệp tin trong thư mục
        WIN32_FIND_DATAA findFileData;
        HANDLE hFind = FindFirstFileA((tenThuMuc + "\\*").c_str(), &findFileData);

        if (hFind != INVALID_HANDLE_VALUE)
        {
            do
            {
                if (strcmp(findFileData.cFileName, ".") != 0 && strcmp(findFileData.cFileName, "..") != 0)
                {
                    list_backup.push_back(findFileData.cFileName);
                }
            } while (FindNextFileA(hFind, &findFileData) != 0);

            FindClose(hFind);
        }
    }
    else
    {
        std::cerr << "Backup does not exits." << std::endl;
    }
    for (size_t i = 0; i < list_backup.size(); i++)
    {
        cout << i + 1 << "." << list_backup[i] << endl;
    }

    cout << "So luong file chitiethd back_up " << list_backup.size();
    cout << "\nChon file chitiethd back_up restore: ";
    int k;
    cin >> k;
    dongBoBanSao("../data/chitiethoadon.csv", "../data/backup/chitiethoadon/" + list_backup[k - 1]);
    docChiTietHDTuFile();
}
int QLCongTy::tongTienHD(string _soHD)
{
    int count = 0;
    int sum = 0;
    for (int i = 0; i < dsChiTietHD.size(); i++)
    {
        if (dsChiTietHD[i].getSoHD() == _soHD)
        {
            count++;
            sum = sum + dsChiTietHD[i].getSoLuong() * dsChiTietHD[i].getGiaBan();
        }
    }
    if (count == 0)
    {
        cout << "Khong tim thay " << _soHD << " . Vui long nhap lai!!!\n";
    }
    return sum;
}
int QLCongTy::soluongSanPham(string _maSP){
    int soLuong=0;
    for (int i = 0; i < dsChiTietHD.size(); i++)
    {
        if (dsChiTietHD[i].getMaSP()==_maSP)
        {
            soLuong += dsChiTietHD[i].getSoLuong();
        }
        
    }
    return soLuong;

    
}
// end chitiethd
