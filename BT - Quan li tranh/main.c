#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct st_tranhtheu {
	char ten[30], tacgia[30];
	int chieudai, chieurong, giaban;
} TranhTheu;

void showMenu();
void seperateLine();
void inputGallery(TranhTheu *p);
void sortGallery(TranhTheu *p);
void displayGallery(TranhTheu *p);
void galleryStatistic(TranhTheu *p);
void findGallerybyPrice(TranhTheu *p);
void saveFile(TranhTheu *p);

int main(int argc, char *argv[]) {
	TranhTheu dsTranh[3];
	
	int choose;
	
	while(choose != 5) {
		showMenu(dsTranh);
		scanf("%d", &choose);
		
		switch(choose) {
			case 1: {
				inputGallery(dsTranh);
				break;
			}
			case 2: {
//				sortGallery(dsTranh);
				displayGallery(dsTranh);
				galleryStatistic(dsTranh);	
				break;
			}
			case 3: {
				findGallerybyPrice(dsTranh);
				break;
			}
			case 4: {
				saveFile(dsTranh);
				break;
			}
			case 5: {
				printf("Thoat!!");
				break;
			}
			default: {
				printf("Nhap sai!!");
				break;
			}
		}
	}
	return 0;
}

void seperateLine() {
	int i;
	
	for(i = 0; i < 100; i++) {
		printf("=");
	}
}

void showMenu() {
	seperateLine();
	
	printf("\n1. Nhap danh sach cac buc tranh");
	printf("\n2. Sap xep, thong ke va hien thi thong tin chi tiet cua tung buc tranh theo dien tich giam dan");
	printf("\n3. Tim buc tranh co theo gia ban");
	printf("\n4. Ghi vao tap tin nhi phan tranhtheu.dat");
	printf("\n5. Thoat");
	printf("\nChon: ");
}

void inputGallery(TranhTheu *p) {
	int i;
	
	for(i = 0; i < 3; i++) {
		seperateLine();
		
		printf("\n Nhap thong tin cho buc tranh so %d: ", i+1);
		
		fflush(stdin);fflush(stdout);
		printf("\n Ten: ");
		gets(p[i].ten);
		
		fflush(stdin);fflush(stdout);
		printf("\n Tac gia: ");
		gets(p[i].tacgia);
		
		fflush(stdin);fflush(stdout);
		printf("\n Chieu dai: ");
		scanf("%d", &p[i].chieudai);
		
		fflush(stdin);fflush(stdout);
		printf("\n Chieu rong: ");
		scanf("%d", &p[i].chieurong);
			
		fflush(stdin);fflush(stdout);
		printf("\n Gia ban (USD): ");
		scanf("%d", &p[i].giaban);
	}
}

void sortGallery(TranhTheu *p) {
	int i, j, dientich[3];
	
	for(i = 0; i < 3; i++) {
		dientich[i] = p[i].chieudai * p[i].chieurong;
	}	
	
	for(i = 0; i < 2; i++) {
		for(j = 1; j < 3; j++) {
			if(dientich[i] < dientich[j]) {
				TranhTheu tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;	
			}
		}
	}
}

void displayGallery(TranhTheu *p) {
	seperateLine();
	
	printf("\nDanh sach tranh");
	printf("\n");
	
	seperateLine();
	
	printf("\n%-3s||%-30s||%-20s||%-5s||%-5s||%-10s||%-15s", "STT", "Ten", "Tac gia", "Dai", "Rong", "Gia", "Kho");
	
	int i, dientich[3];
	
	for(i = 0; i < 3; i++) {
		dientich[i] = p[i].chieudai * p[i].chieurong;
	}
	
	for(i = 0; i < 3; i++) {
		if(dientich[i] < 2000) {
			printf("\n%03d||%-30s||%-20s||%-5d||%-5d||%-10d||%-15s", i+1, p[i].ten, p[i].tacgia, p[i].chieudai, p[i].chieurong, p[i].giaban, "Nho");
		}

		if(dientich[i] < 10000 && dientich[i] >= 2000) {
			printf("\n%03d||%-30s||%-20s||%-5d||%-5d||%-10d||%-15s", i+1, p[i].ten, p[i].tacgia, p[i].chieudai, p[i].chieurong, p[i].giaban, "Trung binh");
		}
		
		if(dientich[i] >= 10000) {
			printf("\n%03d||%-30s||%-20s||%-5d||%-5d||%-10d||%-15s", i+1, p[i].ten, p[i].tacgia, p[i].chieudai, p[i].chieurong, p[i].giaban, "Lon");
		}
	}
	printf("\n");
}

void galleryStatistic(TranhTheu *p) {
	seperateLine();
	
	printf("\nThong ke: ");
		
	int i, dientich[3], count=0;
	
	for(i = 0; i < 3; i++) {
		dientich[i] = p[i].chieudai * p[i].chieurong;
	}	
	
	for(i = 0; i < 3; i++) {
		if(dientich[i] < 2000) {
			count++;
		}
	}
	if(count != 0) {
		printf("\nKho Nho co %d buc tranh", count);
	}
	
	count = 0;
	
	for(i = 0; i < 3; i++) {
		if(dientich[i] < 10000 && dientich[i] >= 2000) {
			count++;
		}
	}
	if(count != 0) {
		printf("\nKho Trung binh co %d buc tranh", count);
	}
	
	count = 0;
	
	for(i = 0; i < 3; i++) {
		if(dientich[i] >= 10000) {
			count++;
		}
	}
	if(count != 0) {
		printf("\nKho Lon co %d buc tranh", count);
	}
	
	printf("\n");
}

void findGallerybyPrice(TranhTheu *p) {
	seperateLine();
	
	int price;
	
	fflush(stdin);fflush(stdout);
	printf("\nNhap gia ban toi da: ");
	scanf("%d", &price);

	seperateLine();

	int i, count;
	char kho[3];
	
	for(i = 0; i < 3; i++) {
		if(p[i].giaban < price) {
			count++;
		}
	}
	if(count != 0) {
		printf("\n%-3s||%-30s||%-20s||%-5s||%-5s||%-10s||%-15s", "STT", "Ten", "Tac gia", "Dai", "Rong", "Gia", "Kho");
	}
	
	int dientich[3];
	
	for(i = 0; i < 3; i++) {
		dientich[i] = p[i].chieudai * p[i].chieurong;
	}
	
	for(i = 0; i < 3; i++) {
		if(p[i].giaban <= price) {
			if(dientich[i] < 2000) {
				printf("\n%03d||%-30s||%-20s||%-5d||%-5d||%-10d||%-15s", i+1, p[i].ten, p[i].tacgia, p[i].chieudai, p[i].chieurong, p[i].giaban, "Nho");
			}
	
			if(dientich[i] < 10000 && dientich[i] >= 2000) {
				printf("\n%03d||%-30s||%-20s||%-5d||%-5d||%-10d||%-15s", i+1, p[i].ten, p[i].tacgia, p[i].chieudai, p[i].chieurong, p[i].giaban, "Trung binh");
			}
			
			if(dientich[i] >= 10000) {
				printf("\n%03d||%-30s||%-20s||%-5d||%-5d||%-10d||%-15s", i+1, p[i].ten, p[i].tacgia, p[i].chieudai, p[i].chieurong, p[i].giaban, "Lon");
			}
		}
	}
	
	if(count == 0) {
		printf("\nKhong co buc tranh nao ban voi gia nhu vay");
	}
	
	printf("\n");
}

void saveFile(TranhTheu *p) {
	seperateLine();
	
	FILE *fp;
	
	fp = fopen("tranhthue.dat", "wb");
	
	if(ferror(fp)) {
		printf("\nMo file loi!!");
	} else {
		fwrite(p, sizeof(TranhTheu), 3, fp);
		printf("\nLuu thang cong!!");
	}
	
	fclose(fp);
	
	printf("\n");
}
