// insertion_sort.cpp
#include <iostream>
#include <ctime>
#include <cstdlib>
const int L = 10;    // the length of the array 
const int Max = 100; // the biggest number of the array
int insertion_sort(int arr[],const int);
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
      cout << rand_arr[i] << "  ";
      if ((i%10) == 9)
	cout << endl;
    }
  cout << endl;
  int count = insertion_sort(rand_arr,L);
  cout << "\nThe sequence after sorting is: " << endl;
  for (i = 0; i < L; i++)
    {   
      cout << rand_arr[i] << "  ";
      if ((i%10) == 9)
	cout << endl;
    }
  cout << endl;
  cout << "\nThere have been experienced " << count 
           << " exchange.\n\n";
  return 0;
}

int insertion_sort(int arr[],const int L)
{
  int key,count = 0;
  for (int j = 1;j < L;j++)
    {
      key = arr[j];
      int i = j-1;
      while ((i >= 0)&&(arr[i]>key))
	{
	  arr[i+1]=arr[i];
	  --i;
	  ++ count;
	}
      arr[i+1] =key;
    }
  return count;
}
# sort
