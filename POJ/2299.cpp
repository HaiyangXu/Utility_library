/*
Ultra-QuickSort
Time Limit: 7000MS  Memory Limit: 65536K 
Total Submissions: 35321  Accepted: 12703 

Description

In this problem, you have to analyze a particular sorting algorithm. The algorithm processes a sequence of n distinct integers by swapping two adjacent sequence elements until the sequence is sorted in ascending order. For the input sequence 

9 1 0 5 4 , 

Ultra-QuickSort produces the output 

0 1 4 5 9 . 

Your task is to determine how many swap operations Ultra-QuickSort needs to perform in order to sort a given input sequence. 
Input

The input contains several test cases. Every test case begins with a line that contains a single integer n < 500,000 -- the length of the input sequence. Each of the the following n lines contains a single integer 0 ≤ a[i] ≤ 999,999,999, the i-th input sequence element. Input is terminated by a sequence of length n = 0. This sequence must not be processed.
Output

For every input sequence, your program prints a single line containing an integer number op, the minimum number of swap operations necessary to sort the given input sequence.
Sample Input

5
9
1
0
5
4
3
1
2
3
0

Sample Output

6
0

Source

Waterloo local 2005.02.05 
*/





#define debugoff
#include <iostream>
#define Max_Sequence_Len 500001
using namespace std;
/**
 * @brief merge_sort
 *
 * @param sequence ,the sequence will be ordered.
 * @param begin , the begin index of the sequence.
 * @param end ,the end index of the sequence.
 */
void merge_sort(int* sequence,int begin,int end);
/**
 * @brief merge ,merge the subset.
 *
 * @param sequence
 * @param begin
 * @param mid  the middle of the two sub set 
 * @param end
 */
void merge(int* sequence, int begin,int mid,int end);

long long int count=0;//count the Inverse number  开始的时候因为使用int 一直不能accept ，long int 也不行 只能 long long int 
int larray[Max_Sequence_Len];
int rarray[Max_Sequence_Len];
int main()
{
	int sequence[Max_Sequence_Len];
	int i=0;
	cin>>i;
	while(i!=0)
	{
		count=0;
		for(int index=1;index<=i;index++)
			cin>>sequence[index];
		merge_sort(sequence,1,i);
		cout<<count<<endl;
		cin>>i;
	}
	 
	return 0;
}

void merge_sort(int* sequence ,int begin,int end)
{
	if(begin<end)
	{
		int m=(begin+end)/2;
		merge_sort(sequence,begin,m);
		merge_sort(sequence,m+1,end);
		merge(sequence,begin,m,end);
	}
}
void merge(int* sequence, int begin,int mid,int end)
{
	int nl=mid-begin+1;
	int nr=end-mid;
//	int* larray=new int[nl+2];//开始使用动态内存分配，时间耗费较多 改用全局数组
//	int* rarray=new int[nr+2];



	for(int il=1;il<=nl;il++)
	{
		larray[il]=sequence[begin+il-1];
	}
	for(int ir=1;ir<=nr;ir++)
	{
		rarray[ir]=sequence[mid+ir];
	}

	int infinity=~(1<<8*sizeof(int)-1);//let the last element as the infinity.

	larray[nl+1]=rarray[nr+1]=infinity;
	
	int r=1,l=1;

	for(int is=begin;is<=end;is++)
	{
		
		if(larray[l]>rarray[r])
		{
			sequence[is]=rarray[r];
			r++;

			count=count+nl-l+1;//count the invert number
		}
		else 
		{
			
			sequence[is]=larray[l];
			l++;		
			
		}		

	}
//	delete [] rarray;
//	delete [] larray;
}

