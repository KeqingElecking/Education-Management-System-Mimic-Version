#include <stdio.h>
#include <string.h>

struct SinhVien;
void hienThiDSSV(struct SinhVien*, int);
void hienThiTenCot();

struct HoTen {
	char ho[20];
	char ten[40];
};

struct DiemMH {
	float QT;
	float CK;
	float DiemTB;
	char DiemHocPhan[2];
};

struct SinhVien {
	int mssv;
	struct HoTen hoVaTen;
	char Lop[10];
	char gioiTinh[10];
	struct DiemMH diem;
};

/**
 * @brief Nhap diem qua trinh va cuoi ky, tinh diem trung binh va diem hoc phan
 * 
 * @param diem 
 */
void nhapDiem(struct DiemMH* diem) {
	printf("QT: ");
	scanf("%f", &diem->QT);
	printf("CK: ");
	scanf("%f", &diem->CK);
	diem->DiemTB = (diem->QT*0.3 + diem->CK*0.7);
    if(diem->DiemTB >= 9) {
        strcpy(diem->DiemHocPhan, "A");
    } else if(diem->DiemTB >= 8) {
        strcpy(diem->DiemHocPhan, "B");
    } else if(diem->DiemTB >= 7) {
        strcpy(diem->DiemHocPhan, "C");
    } else if(diem->DiemTB >= 6) {
        strcpy(diem->DiemHocPhan, "D");
    } else if(diem->DiemTB >= 5) {
        strcpy(diem->DiemHocPhan, "E");
    } else {
        strcpy(diem->DiemHocPhan, "F");
    }
}

/**
 * @brief Nhap ho va ten sinh vien
 * 
 * @param ten 
 */
void nhapHoTen(struct HoTen* ten) {
	printf("Ho: ");
	scanf("%s", ten->ho);
	fflush(stdin);
	printf("Ten (VD:Viet_Tung): ");
	scanf("%s", ten->ten);
	fflush(stdin);
}

/**
 * @brief Nhap thong tin sinh vien
 * 
 * @return struct SinhVien 
 */
struct SinhVien nhapSV() {
	struct SinhVien sv;
	printf("Nhap mssv: ");
	scanf("%d", &sv.mssv);
	nhapHoTen(&sv.hoVaTen);
	printf("Lop (VD:ET-E9_01): ");
	scanf("%s", &sv.Lop);
	printf("Gioi tinh: ");
	scanf("%s", &sv.gioiTinh);
	nhapDiem(&sv.diem);
	printf("\nNhap sinh vien thanh cong!\n");
	system("pause");
	return sv;
}

/**
 * @brief Hien thi thong tin sinh vien
 * 
 * @param sv 
 */
void hienThiTTSV(struct SinhVien sv) {
	printf("%-10d %-10s %-20s %-10s %-10s %-10.2f %-10.2f %-10.2f %-10s\n",
	sv.mssv, sv.hoVaTen.ho, sv.hoVaTen.ten, sv.Lop, sv.gioiTinh,
	sv.diem.QT, sv.diem.CK, sv.diem.DiemTB, sv.diem.DiemHocPhan);
}

/**
 * @brief Sap xep danh sach sinh vien theo chu cai dau cua ten
 * 
 * @param ds 
 * @param slsv 
 */
void sapXepTheoTen(struct SinhVien* ds, int slsv) {
	int i, j;
	for(i = 0; i < slsv - 1; i++) {
		for(j = slsv - 1; j > i; j --) {
			if(strcmp(ds[j].hoVaTen.ten, ds[j-1].hoVaTen.ten) < 0) {
				struct SinhVien sv = ds[j];
				ds[j] = ds[j - 1];
				ds[j - 1] = sv;
			}
		}
	}
}

/**
 * @brief Sap xep danh sach sinh vien theo diem trung binh giam dan
 * 
 * @param ds 
 * @param slsv 
 */
void sapXepTheoDiem(struct SinhVien* ds, int slsv) {
	int i, j;
	for(i = 0; i < slsv - 1; i++) {
		for(j = slsv - 1; j > i; j --) {
			if(ds[j].diem.DiemTB > ds[j - 1].diem.DiemTB) {
				struct SinhVien sv = ds[j];
				ds[j] = ds[j - 1];
				ds[j - 1] = sv;
			}
		}
	}
}

/**
 * @brief Tim sinh vien theo ten
 * 
 * @param ds 
 * @param slsv 
 */
void timTheoTen(struct SinhVien* ds, int slsv) {
	char ten[20];
	printf("Nhap ten: ");
	scanf("%s", ten);
	hienThiTenCot();
	int i, timSV = 0;
	for(i = 0; i < slsv; i++) {
		if(strcmp(ten, ds[i].hoVaTen.ten) == 0) {
			hienThiTTSV(ds[i]);
			timSV = 1;
		}
	}
	if(timSV == 0) {
		printf("Khong co sinh vien %s trong danh sach!\n", ten);
	}
}

/**
 * @brief Ghi danh sach sinh vien ra file .txt
 * 
 * @param ds 
 * @param slsv 
 */
void ghiFile(struct SinhVien* ds, int slsv) {
	getchar();
	char fName[26];
	printf("Nhap ten file: ");
	gets(fName);
	FILE* fOut = fopen(fName, "a");
	int i;
	for(i = 0; i < slsv; i++) {
		struct SinhVien sv = ds[i];
		fprintf(fOut, "%-10d %-10s %-20s %-10s %-10s %-10.2f %-10.2f %-10.2f %-10s\n",
		sv.mssv, sv.hoVaTen.ho, sv.hoVaTen.ten, sv.Lop, sv.gioiTinh,
		sv.diem.QT, sv.diem.CK, sv.diem.DiemTB, sv.diem.DiemHocPhan);
	}
	fclose(fOut);
}

/**
 * @brief Doc danh sach sinh vien tu file .txt
 * 
 * @param ds 
 * @param slsv 
 */
void docFile(struct SinhVien* ds, int* slsv) {
	FILE* fOut = fopen("SV.txt", "r");
	int i = 0;
	if(fOut) {
		for(;;) {
			struct SinhVien sv;
			fscanf(fOut, "%10d %10s %20[^\n] %10s %10s %10f %10f %10f %10s\n",
			&sv.mssv, sv.hoVaTen.ho, sv.hoVaTen.ten, &sv.Lop, sv.gioiTinh,
			&sv.diem.QT, &sv.diem.CK, &sv.diem.DiemTB, sv.diem.DiemHocPhan);
			
			ds[i++] = sv;
			if(feof(fOut)) { // thoat chuong trinh
				break;
			}
		}
	}
	
	fclose(fOut);
	*slsv = i;
}

/**
 * @brief Hien thi hang dau tien cua bang danh sach sinh vien
 * 
 */
void hienThiTenCot() {
	printf("-----------------------------------------------------"
	"----------------------------------------------------------------------------\n");
	printf("%-10s %-10s %-20s %-10s %-10s %-10s %-10s %-10s %-12s \n", 
		"Mssv", "Ho", "Ten", "Lop", "Gioi Tinh", 
		"Diem QT", "Diem CK", "Diem TB", "DiemHocPhan");
}

/**
 * @brief Hien thi danh sach cua tat ca sinh vien hien tai
 * 
 * @param ds 
 * @param slsv 
 */
void hienThiDSSV(struct SinhVien* ds, int slsv) {
	hienThiTenCot();
	int i;
	for(i = 0; i < slsv; i++) {
		hienThiTTSV(ds[i]);
	}
	printf("-----------------------------------------------------"
	"----------------------------------------------------------------------------\n");
}