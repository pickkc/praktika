void saveArrayToFile(int arr[], int n, const char* filename) {
	FILE* file = fopen(filename, "w");
	if (file != NULL) {
		for (int i = 0; i < n; i++) {
			fprintf(file, "%d ", arr[i]);
		}
		fclose(file);
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	int n;
	printf("Введите количество элементов: ");
	scanf("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100001;
	}
	saveArrayToFile(arr, n, "input.txt");
	clock_t start_time = clock();
	shellSort(arr, n);
	clock_t end_time = clock();
	saveArrayToFile(arr, n, "sorted.txt");
	double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("Время выполнения сортировки: %.4f сек\n", execution_time);
	free(arr);
	return 0;
}
