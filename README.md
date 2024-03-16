[Đề 1 - QL công ty bánh kẹo ABC.pdf](https://github.com/chidb2k3/company/files/14622470/D.1.-.QL.cong.ty.banh.k.o.ABC.pdf)
Đặng Bá Chí _ 21IT468
Chis_master
ĐỀ 1.
Công ty Bánh kẹo ABC cần xây dựng phần mềm quản lý bán hàng. Sau khi thu thập thông
tin nhóm BA đã xây dựng được đặc tả như sau:
Về sản phẩm, công ty cần lưu thông tin về mã sản phẩm, tên sản phẩm, trọng lượng và quy
cách đóng gói.
Khi khách hàng mua hàng, Công ty sẽ cấp một hoá đơn. Trong hóa đơn có số hóa đơn,
ngày bán, mã khách hàng và các chi tiết về các sản phẩm đã mua.
Để thực hiện giao hàng và xử lý sự cố (nếu có), Công ty cần lưu thông tin khách hàng gồm
mã khách hàng, tên khách hàng, địa chỉ, số điện thoại.
Từ việc phân tích người ta đã thiết kế một số bảng trong cơ sở dữ liệu quản lý bán hàng
như sau:
HoaDon(SoHD, NgayBan, MaKH)
ChiTietHD(SoHD, MaSP, SoLuong, GiaBan)
SanPham(MaSP, TenSP, TrongLuong, QCDongGoi)
Bảng HoaDon
SoHD NgayBan MaKH
HD001 2020-10-11 KH004
HD002 2020-12-15 KH002
HD003 2020-06-15 KH005
HD004 2020-08-15 KH004
HD005 2020-12-17 KH002
Bảng ChiTietHD
SoHD MaSP SoLuong GiaBan
HD001 KD001 5 50000
HD001 KD006 3 30000
HD002 KD001 2 50000
HD003 KD002 7 30000
HD003 KD003 8 35000
HD003 KD005 2 40000
HD004 KD006 10 30000
HD005 KD004 5 80000
HD005 KD001 7 50000
Bảng SanPhamMaSP TenSP TrongLuong QCDongGoi
KD001 Banh Kinh do Ruoc 300 Hộp VIP
KD002 Banh Kinh do Solite 200 Hộp BT
KD003 Banh Kinh do Cosy 100 Bao
KD004 Banh Kinh do Trang vang 200 Hộp VIP
KD005 Banh Kinh do Bo sua 250 Bao
KD006 Banh Kinh do Socola 100 Hộp BT
Ngữ cảnh: các bạn cần phải xây dựng một chương trình quản lý bán hàng cho Công ty
Bánh kẹo ABC. Từ các bảng như hình trên, hãy xây dựng chương trình có các chức năng
sau.
Câu 1: Xây dựng 4 tính năng (gồm: thêm, sửa, xóa và đọc) cho mỗi bảng dữ liệu.
Câu 2: Xây dựng tính năng sao lưu và khôi phục dữ liệu
Câu 3: Để hoàn thành giao dịch với khách hàng, công ty cần thông tin về tổng tiền của một
hóa đơn cụ thể. Hãy xây dựng tính năng tính Tổng tiền của một hóa đơn với số hóa đơn
được nhập vào từ bàn phím.
Câu 4: Để cơ cấu lại hoạt động sản xuất trong năm mới, công ty cần thông tin về số lượng
bán của từng sản phẩm. Hãy xây dựng tính năng thống kê N sản phẩm có số lượng bán
nhiều nhất, với N được nhập vào từ bàn phím. Ví dụ: N = 5 nghĩa là hiển thị ra tên của 5
sản phẩm được bán với số lượng nhiều nhất.
Câu 5: Công ty cần chuẩn bị dữ liệu cho chương trình tri ân khách hàng cuối năm. Hãy xây
dựng tính năng thống kê N khách hàng đã mua hàng với tổng tiền nhiều nhất, với N được
nhập vào từ bàn phím.
Chú ý:
1. Tất cả các hàm và phương thức đều phải có ghi chú (comment).
2. Thời gian để ở dạng chuỗi
3. Tất cả dữ liệu đều là tiếng Việt không dấu và không có ký tự đặc biệt, nên có thể sử
dụng ký tự đặc biệt trong chức năng sao lưu và khôi phục dữ liệu.

Các bạn tải code và biên dịch theo cú pháp:
g++ NgayBan.cpp HoaDon.cpp ChiTietHoaDon.cpp SanPham.cpp main.cpp -o main
.\main
Kết quả demo:
![image](https://github.com/chidb2k3/company/assets/106579016/d0cee347-f73e-49f9-a533-2ba2f7e5fe83)
![image](https://github.com/chidb2k3/company/assets/106579016/34936eed-a3b3-4a4d-8725-80b8297e7b98)
..... Code đầy đủ các yêu cầu đề bài
Đóng góp ý kiến và follow tui Đặng Bá Chí
zalo: 0375534047
Nhận support đồ án/bài tập C++/PHP/Java mysql
Code thuê đồ án Website(PHP laravel, spring boot)



