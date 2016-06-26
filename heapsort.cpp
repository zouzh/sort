//heapsort.cpp -- the heapsort algorithm
#include <iostream>
#include <ctime>
#include <cstdlib>
const int L = 1000000;    // the length of the array 
const int Max = 10; // the biggest number of the array
void Max_heapify(int arr[],int,int);
void Build_Max_Heap(int arr[],int);
void Heapsort(int arr[],int);
int main()
{
  using namespace std;
  cout << "The original sequence is: " << endl;
  srand(time(0));
  int rand_arr[L];
  int i;
  for ( i = 0; i < L; i++)
    {   
      rand_arr[i] = rand()%Max + 1;
      // rand_arr[i] = 1;
      cout << rand_arr[i] << "  ";
      if ((i%10) == 9)
	cout << endl;
    }
  cout << endl;
  Heapsort(rand_arr,L);
  cout << "\nThe sequence after sorting is: " << endl;
  for (i = 0; i < L; i++)
    {   
      cout << rand_arr[i] << "  ";
      if ((i%10) == 9)
	cout << endl;
    }
  cout << endl; 
  // cout << "\nThere have been experienced " << count 
  //     << " exchange.\n\n";
  return 0;
}

void Max_Heapify(int arr[],int n,int s)
{
  int l=s,r; // l is the left child of s,and r is the right child of s;
  l <<= 1;
  r = l + 1;
  int largest;
  if (l<=n)
    {
      if(arr[l] > arr[s])
	largest = l;
      else 
	largest = s;
      if ((r<=n) && (arr[r] > arr[largest]))
	largest = r;
      if  (largest != s )
	{
	  int temp = arr[s];
	  arr[s] = arr[largest];
	  arr[largest] = temp;
	  Max_Heapify(arr,n,largest);
	}
    }
}

void Build_Max_Heap(int arr[],int n)
{
  int i = n/2;
  for (;i > 0; i--)
    Max_Heapify(arr,n,i);
}

void Heapsort (int arr[],int n)
{
  Build_Max_Heap(arr-1,n);
  int i = n - 1;
  int temp;
  for (;i>0;i--)
    {
      temp = arr[i];
      arr[i] = arr[0];
      arr[0] = temp;
      Max_Heapify(arr-1,i,1);
    }
}
# sort
