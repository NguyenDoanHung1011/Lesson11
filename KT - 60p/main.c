#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int checkIsPrime(int n) {
	int i, count = 0;
	
	if(n < 2) {
		return 0;
	} else {
		for(i = 2; i < n; i++) {
			if(n % i == 0) {
				count++;
			} 
		}
		if(count == 0) {
			return 1;
		} else {
			return 0;
		}
	}
} 

void checkIsPrimeArr(int n, int m) {
	int i, j, count = 0;
	
	for(i = n; i <= m; i++) {
		for(j = 2; j < i; j++) {
			if(i % j == 0) {
				count++;
			}
		}
		if(count == 0) {
			printf("\n%d", i);
		}
		count = 0;
	}
}

int main(int argc, char *argv[]) {
	//b1
	int n;
	
	printf("Nhap so kiem tra: ");
	scanf("%d", &n);
	
	checkIsPrime(n);
	printf("%d", checkIsPrime(n));
	
	//bai2
	int m;
	n = 0;
	
	fflush(stdin);fflush(stdout);
	printf("\nNhap n: ");
	scanf("%d", &n);
	
	fflush(stdin);fflush(stdout);
	printf("Nhap m: ");
	scanf("%d", &m);
	
	checkIsPrimeArr(n, m);
	return 0;
}
