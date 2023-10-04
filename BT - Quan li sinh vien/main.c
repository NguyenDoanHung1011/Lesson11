#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct studen_st {
	char name[30], province[30];
	int year;
} Student;

void showMenu();
void inputStd();
void sortStd();
void displayStd();
void findStdbyAge();
void findStdbyProvince();
void saveFileTxt();

int main(int argc, char *argv[]) {
	int choose;
	Student studentList[3];
	
	while(choose != 6) {
		showMenu(studentList);	
		scanf("%d", &choose);
		
		switch(choose) {
			case 1: {
				inputStd(studentList);
				break;
			}
			case 2: {
				sortStd(studentList);
				displayStd(studentList);
				break;
			}
			case 3: {
				findStdbyAge(studentList);
				break;
			}
			case 4: {
				findStdbyProvince(studentList);
				break;
			}
			case 5: {
				saveFileTxt(studentList);
				break;
			}
			case 6: {
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

void showMenu(Student *p) {
	printf("\n==========");
		
	printf("\n1. Nhap du lieu cua tung sinh vien");
	printf("\n2. Sap xep va hien thi thong tin chi tiet cua tung sinh vien theo thu tu tang dan cua ho ten");
	printf("\n3. Tim sinh vien co tuoi nho nhat");
	printf("\n4. Tim sinh vien theo tinh");
	printf("\n5. Luu thong tin vao file student.txt");
	printf("\n6. Thoat.");
	printf("\nChon: ");
}

void inputStd(Student *p) {		
	int i;
	
	for(i = 0; i < 3; i++) {
		printf("\n==========");
		printf("\nNhap du lieu sinh vien thu %d:", i+1);
		
		fflush(stdin);fflush(stdout);
		printf("\nNhap ten cua sinh vien: ");
		gets(p[i].name);
		
		fflush(stdin);fflush(stdout);
		printf("Nhap tinh: ");
		gets(p[i].province);
		
		fflush(stdin);fflush(stdout);
		printf("Nhap nam sinh: ");
		scanf("%d", &p[i].year);
	}
}

void sortStd(Student *p) {
	int i, j, cmp;
	
	for(i = 0; i < 2; i++) {
		for(j = i+1; j < 3; j++) {
			cmp = strcmp(p[i].name, p[j].name);
			if(cmp > 0) {
				Student tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}	
		}
	}
}

void displayStd(Student *p) {	
	int i;
	
	for(i = 0; i < 3; i++) {
		printf("\n==========");
		
		printf("\nSinh vien %d:", i+1);
		
		fflush(stdin);fflush(stdout);
		printf("\nHo Ten: ");
		puts(p[i].name);
		
		fflush(stdin);fflush(stdout);
		printf("Tinh thanh: ");
		puts(p[i].province);
		
		fflush(stdin);fflush(stdout);
		printf("Nam sinh: %d", p[i].year);
	}
}

void findStdbyAge(Student *p) {
	int i, j, max;
	
	max = p[0].year;
	
	for(i = 1; i < 3; i++) {
		if(p[i].year > max) {
			max = p[i].year;
		}
	}
	
	for(i = 0; i < 3; i++) {
		if(p[i].year == max) {	
			printf("\n==========");
			
			printf("\nSinh vien %d:", i+1);
			
			fflush(stdin);fflush(stdout);
			printf("\nHo Ten: ");
			puts(p[i].name);
			
			fflush(stdin);fflush(stdout);
			printf("Tinh thanh: ");
			puts(p[i].province);
			
			fflush(stdin);fflush(stdout);
			printf("Nam sinh: %d", p[i].year);
		}
	}	
}
void findStdbyProvince(Student *p) {	
	int i, count = 0;
	char find[30];
	
	fflush(stdin);fflush(stdout);
	printf("Nhap tinh thanh muon tim: ");
	gets(find);
	
	for(i = 0; i < 3; i++) {
		int cmp = strcmp(find, p[i].province);
		if(cmp == 0) {
			count++;
			
			printf("\n==========");
				
			printf("\nSinh vien %d:", i+1);
			
			fflush(stdin);fflush(stdout);
			printf("\nHo Ten: ");
			puts(p[i].name);
			
			fflush(stdin);fflush(stdout);
			printf("Tinh thanh: ");
			puts(p[i].province);
			
			fflush(stdin);fflush(stdout);
			printf("Nam sinh: %d", p[i].year);
		}
		if(count == 0) {
			printf("Khong co sinh vien o tinh nay");
		}
	}
	
	count = 0;
}
void saveFileTxt(Student *p) {
	printf("\n==========");
	
	int i;
	
	FILE *fp;
	
	fp = fopen("student.txt", "w");	
	
	if(ferror(fp)) {
		printf("Error!!");
	} else {
		for(i = 0; i < 3; i++) {
			fprintf(fp, "\nSinh vien %d:", i+1);

			fprintf(fp, "\nHo Ten: %s", p[i].name);

			fprintf(fp, "\nTinh thanh: %s", p[i].province);
			
			fprintf(fp, "\nNam sinh: %d", p[i].year);
		}
		printf("\nSaved!!");
	}
	
	fclose(fp);
}
