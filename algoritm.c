void shellSort(int arr[], int n) {
// Определяем расстояние между элементами, начиная с максимального
	int gap;
	for (gap = n / 2; gap > 0; gap /= 2) {
// Выполняем сортировку вставкой с заданным расстоянием
		for (int i = gap; i < n; i++) {
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
				arr[j] = arr[j - gap];
			}
	arr[j] = temp;
		}
	}
}