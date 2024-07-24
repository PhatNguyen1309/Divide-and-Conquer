#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int PhanHoach(int arr[], int left, int right) {
	int pivot = arr[right];
	int i = left - 1;
	for (int j = left; j < right; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]); //đổi chổ i với j
		}
	}
	swap(&arr[i + 1], &arr[right]);
	return i + 1;
}

void Quicksort(int arr[], int left, int right) {
	if (left < right) {
		int pi = PhanHoach(arr, left, right); // Phân hoạch mảng và lấy vị trí của pivot
		Quicksort(arr, left, pi - 1);
		Quicksort(arr, pi + 1, right);
	}
}

int main() {
	int arr[] = { 6, 2, 8, 1, 5, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Mang ban dau:");
	for (int i = 0; i < n; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");

	Quicksort(arr, 0, n - 1);

	printf("Mang da duoc xu ly:");
	for (int i = 0; i < n; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");

	getchar();
	return 0;
}
