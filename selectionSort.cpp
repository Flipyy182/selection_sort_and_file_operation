#include <iostream>
#include<ctime>
#include<fstream>

using namespace std;

void printArray(int arr[], int n){
	for(int i=0; i<n; i++){
		cout << arr[i] << ", ";
	}
	cout << endl;
}


void swap(int *x, int *y)
{
	int temp   = *x;
    *x   = *y;
    *y   =  temp;
}
int getMinIndex(int arr[], int n, int startIdx){
	int minIdx = startIdx;
	for(int i=startIdx; i<n; i++){
		if(arr[i] < arr[minIdx]){
			minIdx = i;
		}
	}
	return minIdx;
}
void selectionSort(int arr[], int n){
	for(int left=0; left<n-1; left++){
		int minIdx = getMinIndex(arr, n, left);
		swap(&arr[left], &arr[minIdx]);
	}
}

int main()
{
  int t;
  cin >> t;
  ofstream file;
  file.open("Output.txt");

  while (t--) {
    cout<<"Input size and then array: "<<endl;
    int n;
    int arr[n];
    cin>>n;
    for(int i=0; i<n; i++)
    {
      cin>>arr[i];
    }
  
    long t1, t2;
    t1 = time(NULL);
    selectionSort(arr,n);
    t2 = time(NULL);

    cout<<"Elapsed time "<<(t2-t1)<<"s"<<endl;
  
    printArray(arr,n);

    file<<"Case file #"<<t+1<<" ," ;
    file<<"Inputs "<<n<<", ";
    file<<"Elapsed time "<<(t2-t1)<<"s"<<endl;
  }

}
