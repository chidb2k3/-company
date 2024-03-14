#include <iostream>
#include "../header/QLCongTy.h"
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
QLCongTy::QLCongTy(string _fileSanPham, string _fileChiTietHD)
{
    this->fileSanPham = _fileSanPham;
    docSanPhamTuFile();
    this->fileChiTietHD = _fileChiTietHD;
    docChiTietHDTuFile();
}

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