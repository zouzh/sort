// merge_sort.cpp -- sort the sequence with the merge_sort mothed.
#include <iostream>
#include <ctime>
#include <cstdlib>
const int L = 1000000;    // the length of the array 
const int Max = 10; // the biggest number of the array
void merge_sort(int arr[],int,int,int);
void merge(int arr[],int,int);
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
      //rand_arr[i] = 1;
      cout << rand_arr[i] << "  ";
      if ((i%10) == 9)
	cout << endl;
    }
  cout << endl;
  merge(rand_arr,0,L-1);
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

void merge_sort(int arr[],int p ,int q, int r)
{
  int n1 = q -p + 1;
  int n2 = r - q;
  int * pl = new int [n1];
  int * pr = new int [n2];
  int i,j=0,k=0;
  for (i = p;i <= q;i++)
    pl[i-p] = arr[i];
  for (i = q + 1;i <= r;i++)
    pr[i-q-1] = arr[i];
  i = p;
  while (1)
    {
      // for (i = p;i <= r;i++)
      // {
      if (pl[j] < pr[k])
	{
	  arr[i] = pl[j];
	  ++j;
	}
      else
	{
	  arr[i] = pr[k];
	  ++k;
	}
      if (j == n1)
	{
	  while (k < n2)
	    arr[++i] = pr[k++];
	  break;
	}
      else if (k == n2)
	{
	while (j < n1)
	  arr[++i] = pl[j++];
	break;
	}
      ++i;
    }
  delete [] pl;
  delete [] pr;
}

void merge(int arr[],int r,int s)
{
  int d = s -r;
  if (d == 1)
    {
    if (arr[r] > arr[s])
      {
	int temp = arr[r];
	arr[r] = arr[s];
	arr[s] = temp;
      }
    }
  else if (d > 1)
    {
      int q = (r + s) / 2;
      merge(arr,r,q);
      merge(arr,q+1,s);
      merge_sort(arr,r,q,s);
    }
}
# sort
