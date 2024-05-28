#include <iostream>
#include <vector>

using namespace std;

class SinhVien {
private:
    string maSV;
    string hoTen;
    vector<float> diemMonHoc;

public:
    void nhapThongTin() {
        cout << "Nhap ma sinh vien: ";
        cin >> maSV;
        cout << "Nhap ho ten: ";
        cin >> hoTen;
        cout << "Nhap diem cac mon hoc (cach nhau boi dau cach): ";
        for (float& diem : diemMonHoc) {
            cin >> diem;
        }
    }

    void hienThiThongTin() {
        cout << "Ma sinh vien: " << maSV << endl;
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
        cout << "\nMENU\n";
        cout << "1. Them moi sinh vien\n";
        cout << "2. Hien thi danh sach sinh vien\n";
        cout << "3. Sua thong tin sinh vien\n";
        cout << "4. Xoa sinh vien\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1: {
            SinhVien sinhVienMoi;
            sinhVienMoi.nhapThongTin();
            danhSachSinhVien.push_back(sinhVienMoi);
            break;
        }
        case 2: {
            if (danhSachSinhVien.empty()) {
                cout << "Danh sach sinh vien trong!\n";
            } else {
                for (SinhVien sinhVien : danhSachSinhVien) {
                    sinhVien.hienThiThongTin();
                }
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
        case 0:
            cout << "Thoat chuong trinh!\n";
            break;
        default:
            cout << "Lua chon sai!\n";
        }
    } while (luaChon != 0);

    return 0;
}