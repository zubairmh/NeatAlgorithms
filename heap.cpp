#include <any>
#include <bits/stdc++.h>
#include <math.h>
#include <valarray>

using namespace std;

// Methods

// MaxHeapify: restore heap
// BuildMaxHeap: create from unsorted array
// HeapSort: Sort an array



void MaxHeapify(int heap[], int size, int i) {
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<size && heap[left]>heap[largest]) {
        largest=left;
    }
    if(right<size && heap[right]>heap[largest]) {
        largest=right;
    }
    if(largest!=i) {
        swap(heap[i],heap[largest]);
        MaxHeapify(heap, size, largest);
    }
    

}

void BuildMaxHeap(int heap[],int size)
{
    for(int i=size/2-1;i>=0;i--)
    {
        MaxHeapify(heap,size,i);
    }
}

void Disp(int heap[], int size) {
    for(int i=0; i<size; i++) {
        cout<<heap[i] <<" ";
    }
    cout<<endl;
}

void HeapSort(int heap[], int size) {
    BuildMaxHeap(heap, size);
    for(int i=size-1; i>=0; i--) {
        swap(heap[0],heap[i]);
        MaxHeapify(heap, i, 0);
    }
}


// Priority queue

// – INSERT(S, x): inserts element x into set S
// – EXTRACT-MAX(S): removes and returns element of S with
// the largest key
// – MAXIMUM(S): returns element of S with the largest key
// – INCREASE-KEY(S, x, k): increases value of element x’s key
// to k (Assume k ≥ x’s current key value)

int HeapMaximum(int heap[]) {
    return heap[0];
}

int HeapExtractMax(int heap[], int size) {
  if(size < 1)
    return 0;
  int max = heap[0];
  heap[0] = heap[size-1];
  size=size-1;
  MaxHeapify(heap, size, 0);
  return max;
}

int main() {
    int heap[]={4,8,3,1,2};
    int n=sizeof(heap)/sizeof(heap[0]);
    BuildMaxHeap(heap, n);
    Disp(heap, n);
    // HeapSort(heap, n);
    // Disp(heap, n);
    cout<<HeapExtractMax(heap, n)<<endl;
}