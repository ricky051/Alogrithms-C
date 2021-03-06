#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void swap(int*,int*);
int partition(int*,int,int);
void quicksort(int*,int,int);
int main(){
	int size,*A,i;
	clock_t start, end;
	printf("Enter the size of the aray: ");
	scanf("%d",&size);
	A = (int*) malloc(size*sizeof(int));
	for(i=0;i<size;i++){
		A[i]=random();
	}
	start = clock();
	quicksort(A,0,size-1);
	end = clock();
	printf("%f\n",(float)(end-start)/1000);
}

void quicksort(int A[],int low, int high){
	if(low<high){
		int mid = partition(A, low, high);
		quicksort(A,low,mid-1);
		quicksort(A,mid+1,high);
	}	
}

int partition(int A[], int low, int high){
	int i = low+1, j = high, key = A[low];
	while(i<j){
		while(key>=A[i]&&i<high)i++;
		while(key<=A[j])j--;
		if(i>=j){
			swap(&A[low],&A[j]);
			return j;
		}
		swap(&A[i],&A[j]);
	}
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
