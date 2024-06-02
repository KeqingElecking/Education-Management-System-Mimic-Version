// Nhóm 13 - 
// Hệ thống quản lý đào tạo Hust - Phân hệ nhập điểm cho sinh viên
// Sinh viên:
// 1. Đặng Nhật Minh - 20224444
// 2. Đỗ Đặng Hoàng Linh - 2022
// 3. Phạm Việt Tùng - 20224415
// 4. Trần Nhật Quang - 2022

#include <iostream>
#include <vector>
#include "sinhvien.hpp"
using namespace std;

int main() {
    vector<SinhVien> danhSachSinhVien;

    int luaChon;
    do {
        system("cls");
        cout << "---------------------------------------------------------------\n"
        << "He thong quan ly dao tao Hust - Phan he nhap diem cho sinh vien\n"
        << "---------------------------------------------------------------\n"
        << "\nMENU:\n"
        << "1. Danh sach sinh vien\n"
        << "2. Nhap diem\n"
        << "3. Sua diem\n"
        << "4. Xoa diem\n"
        << "5. Xuat file diem theo dinh dang CSV\n"
        << "0. Thoat\n"
        << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1: {
            system("cls");
            if (danhSachSinhVien.empty()) {
                cout << "Danh sach sinh vien trong!\n";
                system("pause");
            } else {
                danhSachSinhVien[0].hienThiThongTin(danhSachSinhVien);
            break;
            }
        }
        case 2: {
            system("cls");
            SinhVien sinhVienMoi;
            cout<<"---Nhap thong tin sinh vien moi---\n";
            sinhVienMoi.nhapThongTin();
            danhSachSinhVien.push_back(sinhVienMoi);
            cout<<"Xong!\n";
            system("pause");
            break;
        }
        case 3: {
            void suaThongTin(vector<SinhVien>& danhSachSinhVien) {
            // Tim sinh vien theo ma so
            system("cls");
            string mssvCanSua;
            cout << "Nhap ma sinh vien can sua: ";
            cin >> mssvCanSua;

            int indexSinhVien = -1;
            for (int i = 0; i < danhSachSinhVien.size(); i++) {
            if (danhSachSinhVien[i].getMSSV() == mssvCanSua) {
                indexSinhVien = i;
                break;
            }
            }
        system("cls");
        if (indexSinhVien != -1) {
            cout << "Thong tin hien tai cua sinh vien:\n";
            danhSachSinhVien[indexSinhVien].hienThiThongTin(danhSachSinhVien);

            cout << "\nNhap thong tin moi:\n";
            danhSachSinhVien[indexSinhVien].nhapThongTin();

            cout << "Sua thong tin sinh vien thanh cong!\n";
            system("pause");
        }
        else {
            cout << "Khong tim thay sinh vien co ma so " << mssvCanSua << "!\n";
        }
    }
            break;
        }
        case 4: {
            // danhSachSinhVien[0].xoaThongTin(danhSachSinhVien);
            break;
        }
        case 5: {
            // ... them code xuat file diem theo dinh dang CSV
            break;
        }
        case 0:
            system("cls");
            cout << "Tam biet!\n";
            break;
        default:
            cout << "Lua chon sai! Input using digit.\n";
        }
    } while (luaChon != 0);

    return 0;
}