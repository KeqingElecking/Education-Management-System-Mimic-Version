#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sinhvien.h"

int main() {
	struct SinhVien dssv[100];
	int slsv = 0;
	int luaChon;
	
	// docFile(dssv, &slsv);
	printf("DANH SACH SINH VIEN HIEN TAI:\n");
	hienThiDSSV(dssv, slsv);
	int i;
				
	do {
		printf("=============== MENU ===============");
		printf("\n1. Them Sinh vien moi");
		printf("\n2. Hien thi danh sach");
		printf("\n3. Sap xep theo ten A-Z");
		printf("\n4. Sap xep theo diem giam dan");
		printf("\n5. Tim sinh vien theo ten");
		printf("\n6. Xuat danh sach ra file .txt");
		printf("\n\n0. Thoat");
		printf("\nOption: ");
		
		scanf("%d", &luaChon);
		struct SinhVien sv;
		
		switch(luaChon) {
			case 0:
				break;
				
			case 1:
				sv = nhapSV();
				dssv[slsv++] = sv;
				system("cls");
				break;
				
			case 2:
				system("cls");
				hienThiDSSV(dssv, slsv);
				break;
				
			case 3:
				sapXepTheoTen(dssv, slsv);
				printf("\nDanh sach sinh vien sau khi sap xep theo ten a-z:\n");
				hienThiDSSV(dssv, slsv);
				break;
				
			case 4:
				sapXepTheoDiem(dssv, slsv);
				printf("\nDanh sach sinh vien sau khi sap xep theo diem giam dan:\n");
				hienThiDSSV(dssv, slsv);
				break;
				
			case 5:
				timTheoTen(dssv, slsv);
				break;
				
			case 6:
				ghiFile(dssv, slsv);
				break;
				
			default:
				printf("Sai chuc nang, vui long chon lai!\n");
				break;
		}
		
	} while(luaChon);
	
	return 0;
}