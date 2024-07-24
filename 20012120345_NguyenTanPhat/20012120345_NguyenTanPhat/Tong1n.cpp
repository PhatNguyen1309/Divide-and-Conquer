#include <stdio.h>

int tong1n(int n) {
	return n * (n + 1) / 2;
}

int tongdequy(int n) {
	if (n == 1)
		return 1;
	else
		return n + tongdequy(n - 1);
}

int main() {
	int choice, n, tong;
	while (1) {
		printf("Menu:\n");
		printf("1. Tinh tong 1 den n khong dung de quy\n");
		printf("2. Tinh tong 1 den n dung de quy\n");
		printf("3. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("Nhap n: ");
			scanf_s("%d", &n);
			tong = tong1n(n);
			printf("Tong 1 den %d la: %d\n", n, tong);
			break;
		case 2:
			printf("Nhap n: ");
			scanf_s("%d", &n);
			tong = tongdequy(n);
			printf("Tong de quy 1 den %d la: %d\n", n, tong);
			break;
		case 3:
			printf("Thoat\n");
			return 0;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
		}
	}
}
