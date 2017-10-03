class HeapSort {
public:
	void MaxHeap(int* A, int i, int len){
		int temp = A[i];
		int lchild = 2 * i + 1;
		int rchild = 2 * i + 2;
		int max = i;
		if (i<len / 2){
			if (lchild<len&&A[max]<A[lchild]){
				max = lchild;
			}
			if (rchild<len&&A[max]<A[rchild]){
				max = rchild;
			}
			if (max != i){
				swap(A[i], A[max]);
				MaxHeap(A, max, len);
			}
		}
	}
	int* heapSort(int* A, int n) {
		if (n <= 1) return A;
		for (int i = n / 2; i >= 0; --i){
			MaxHeap(A, i, n);
		}
		for (int i = n; i>0; --i){
			swap(A[0], A[i - 1]);
			MaxHeap(A, 0, i - 1);
		}
		return A;
	}
private:
	void swap(int& a, int& b){
		int temp = a;
		a = b;
		b = temp;
	}
};