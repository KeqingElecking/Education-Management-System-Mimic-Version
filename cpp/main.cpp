// Nhóm 13 - 
// Hệ thống quản lý đào tạo Hust - Phân hệ nhập điểm cho sinh viên
// Sinh viên:
// 1. Đặng Nhật Minh - 20224444
// 2. Đỗ Đặng Hoàng Linh - 2022
// 3. Phạm Việt Tùng - 2022
// 4. Trần Nhật Quang - 2022

#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

class SinhVien {
private:
    string mssv;
    string hoTen;
    vector<float> diemMonHoc;

public:
    void nhapThongTin() {
        cout << "Nhap ma sinh vien: ";
        cin >> mssv;
        cout << "Nhap ho ten: ";
        cin >> hoTen;
        cout << "Nhap diem cac mon hoc (cach nhau boi dau cach): ";
        for (float& diem : diemMonHoc) {
            cin >> diem;
        }
    }

    void hienThiThongTin() {
        cout << "Ma sinh vien: " << mssv << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Diem cac mon hoc: ";
        for (float diem : diemMonHoc) {
            cout << diem << " "; 
        }
        cout << endl;
    }

    // ... them cac phuong thuc sua, xoa thong tin sinh vien
};

int main() {
    vector<SinhVien> danhSachSinhVien;

    int luaChon;
    do {
        cout << "---------------------------------------------------------------\n";
        cout << "He thong quan ly dao tao Hust - Phan he nhap diem cho sinh vien\n";
        cout << "---------------------------------------------------------------\n";
        cout << "\nMENU:\n";
        cout << "1. Danh sach sinh vien\n";
        cout << "2. Nhap diem\n";
        cout << "3. Sua diem\n";
        cout << "4. Xoa diem\n";
        cout << "5. Xuat file diem theo dinh dang CSV\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1: {
            system("cls");
            if (danhSachSinhVien.empty()) {
                cout << "Danh sach sinh vien trong!\n";
            } else {
                for (SinhVien sinhVien : danhSachSinhVien) {
                    sinhVien.hienThiThongTin();
                }
            break;
        }
        case 2: {
            SinhVien sinhVienMoi;
            sinhVienMoi.nhapThongTin();
            danhSachSinhVien.push_back(sinhVienMoi);
            }
            break;
        }
        case 3: {
            // ... them code sua thong tin sinh vien
            break;
        }
        case 4: {
            // ... them code xoa thong tin sinh vien
            break;
        }
        case 5: {
            // ... them code xuat file diem theo dinh dang CSV
            break;
        }
        case 0:
            cout << "Tam biet!\n";
            break;
        default:
            cout << "Lua chon sai! Input using digit.\n";
        }
    } while (luaChon != 0);

    return 0;
}