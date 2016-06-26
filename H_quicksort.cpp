// quick.cpp -- sort the sequence with the quicksort mothed.
#include <iostream>
#include <ctime>
#include <cstdlib>
const int L =2000000;    // the length of the array 
const int Max = 1000; // the biggest number of the array
void quicksort(int arr[],int,int);
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
  quicksort(rand_arr,0,L-1);
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

void quicksort(int arr[], int r,int s)
{
  int temp;
  int d = s-r;
  if (d == 1)
    {
      if (arr[r] > arr[s])
	{
	  temp = arr[r];
	  arr[r] = arr[s];
	  arr[s] = temp;
	}
    }
  else if ( d > 1)
    {
      int mid = rand()%(d+1)+r;
      temp = arr[r];
      arr[r] = arr[mid];
      arr[mid] = temp;
      int i = r;
      int j = s+1;
      while (i < j)
	{
	  while ((arr[--j] > arr[r]) && (i < j));
	  while ((arr[++i] < arr[r]) && (i < j));
	  if (i < j) 
	    {
	      temp = arr[i];
	      arr[i] = arr[j];
	      arr[j] = temp;
	    }
	}
      temp = arr[j];
      arr[j] = arr[r];
      arr[r] = temp;
      quicksort(arr,r,j-1);
      quicksort(arr,j+1,s);
    }
}
# sort
