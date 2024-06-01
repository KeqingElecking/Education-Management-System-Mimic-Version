#ifndef sinhvien 
#define sinhvien

#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

class SinhVien {
private:
    string mssv;
    string hoTen;
    unordered_map<string, float> grades;
    float diemMonHoc[2];

public:
    string getMSSV() {
        return mssv;
    }

    void nhapThongTin() {
        cout << "---Thong Tin Sinh vien---\n";
        cout << "Nhap mssv: ";
        cin >> mssv;
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        // Cần thêm thông tin điểm cho từng môn học sử dụng map
        cout << "Nhap diem qua trinh: ";
        cin >> diemMonHoc[0];
        cout << "Nhap diem cuoi ky: ";
        cin >> diemMonHoc[1];
    }

    void hienThiThongTin(vector<SinhVien>& danhSachSinhVien) {
        cout << "---Danh Sach Sinh vien---\n";
        for (auto sv : danhSachSinhVien) {
            cout << "Ma sinh vien: " << mssv << endl
                << "Ho ten: " << hoTen << endl
                << "Mon hoc: " << endl
                << "    QT: " << diemMonHoc[0] << endl
                << "    CK: " << diemMonHoc[1] << endl;
            cout << endl;
        }
        system("pause");
    }

    void suaThongTin(vector<SinhVien>& danhSachSinhVien) {
        //... them code sua thong tin sinh vien
    }


    void xoaThongTin(vector<SinhVien>& danhSachSinhVien) {
        //... them code xoa thong tin sinh vien
    }
};

#endif