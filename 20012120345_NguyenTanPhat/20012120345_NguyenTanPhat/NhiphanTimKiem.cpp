#include <stdio.h>

int timKiemNhiPhan(int arr[], int n, int x) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] == x)
			return mid; // Trả về chỉ số nếu tìm thấy x
		else if (arr[mid] < x)
			left = mid + 1; // Nếu x lớn hơn arr[mid], loại bỏ nửa bên trái
		else
			right = mid - 1; // Nếu x nhỏ hơn arr[mid], loại bỏ nửa bên phải
	}
	return -1;
}

int timKiemNhiPhanDeQuy(int arr[], int left, int right, int x) {
	if (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] == x)
			return mid; // Trả về chỉ số nếu tìm thấy x
		else if (arr[mid] < x)
			return timKiemNhiPhanDeQuy(arr, mid + 1, right, x); // Tìm kiếm bên phải của mid
		else
			return timKiemNhiPhanDeQuy(arr, left, mid - 1, x); // Tìm kiếm bên trái của mid
	}
	return -1;
}

int main() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x;
	int chon;
	int ketQua;

	do {
		printf("=======================Menu=================\n");
		printf("Mang = { 1 , 2, 3, 4, 5, 6, 7, 8, 9}\n");
		printf("1. Tim kiem nhi phan\n");
		printf("2. Tim kiem nhi phan bang de quy\n");
		printf("3. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf_s("%d", &chon);

		switch (chon) {
		case 1:
			printf("Nhap gia tri can tim: ");
			scanf_s("%d", &x);
			ketQua = timKiemNhiPhan(arr, n, x);
			if (ketQua != -1)
				printf("Phan tu %d duoc tim thay tai vi tri %d.\n", x, ketQua);
			else
				printf("Phan tu %d khong tim thay trong mang.\n", x);
			break;
		case 2:
			printf("Nhap gia tri can tim: ");
			scanf_s("%d", &x);
			ketQua = timKiemNhiPhanDeQuy(arr, 0, n - 1, x);
			if (ketQua != -1)
				printf("Phan tu %d duoc tim thay tai vi tri %d.\n", x, ketQua);
			else
				printf("Phan tu %d khong tim thay trong mang.\n", x);
			break;
		case 3:
			printf("Thoat!\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
		}
	} while (chon != 3);

	return 0;
}
