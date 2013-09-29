/*

Servicing DVD Requests
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 1577		Accepted: 476
Description

You are running a DVD library. Suppose that you have k DVD drives, through which the users can access the contents of the requested DVDs.A DVD drive can only access the content of one DVD at the same time. When a DVD request arrives, if the DVD is already in a DVD drive, then nothing needs to be done. Otherwise, you are supposed to insert the requested DVD into an empty drive. If all k drives are occupied, you have to remove a DVD out of the drive before having the requested DVD inserted into the drive. The objective is to minimize the number of DVD insertions required for serving the whole sequence of requests. 

To make things interesting, we assume that you are given the whole sequence x1, x2, . . . , xn in advance. Also, you have to service request xi before servicing xi+1, for each i = 1, 2, . . . , n - 1. You want to carefully plan how to service each request such that the overall number of DVD insertions is minimized. Clearly, the difficulty lies in determining which DVD should be removed from its drive when you receive a request to a DVD not in any drive and all drives are occupied. 

For example, let k = 2, and let the sequence of requests be 1, 2, 3, 1, 3, 1, 3. For the first two requests, one can simply put DVDs 1 and 2 into the drives. When the third request (i.e., DVD 3) arrives, you have to either remove DVD 1 or DVD 2 out of its drive so that DVD 3 can be inserted to a drive. 

If you choose the first option (i.e., removing DVD 1), then the remaining requests (i.e., requests 4-7) need at least one more DVD insertions. 
If you choose the second option (i.e., removing DVD 2), then the remaining requests (i.e., requests 4-7) need no more DVD insertions.

It is not difficult to verify that the second option results in an optimal way to service the above sequence of requests which needs only three DVD insertions.
Input

The first line contains the number m of test cases. Each test case starts with a line containing two numbers k and n, where 1 <= k <= 10 is the number of DVD drives and 1 <= n <= 100 is the number of requests. In the following n lines, the i-th line contains the i-th request xi.
Output

For each test case, your program has to output the minimum number of DVD insertions required to service the whole sequence of requests in one line.
Sample Input

2
2 7
1
2
3
1
3
1
3
3 9
1
2
3
4
1
2
1
2
4
Sample Output

3
4
Source

Taiwan 2004

*/

#define debugoff
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
int arrange(int k,std::vector<int> &sequence);// arrange the sequence of request with k DVD drives and return the minimun number of insertions

int main()
{
	int num_of_request=0;
	std::cin>>num_of_request;
	int k=0,num=0;

	while(num_of_request>0)
	{
		num_of_request--;
		std::cin>>k>>num;
		std::vector<int> sequence(num);
		std::vector<int>::iterator it=sequence.begin();
		while(it!=sequence.end())
		{
			std::cin>>*it;
			it++;
		}
		std::cout<<arrange(k,sequence)<<std::endl;		
	}					
}

int arrange(int k,std::vector<int> &sequence)
{
	int insertion_count=0;
	std::map<int,std::vector<int>::const_iterator> drives_map;
	std::set<int> drives_ons;
	
	for(std::vector<int>::iterator it=sequence.begin();it!=sequence.end();it++)
	{
		if(drives_ons.size()<k)
		{
			std::pair<std::set<int>::iterator,bool> ret=drives_ons.insert(*it);
			if(ret.second==true)
				insertion_count++;			
		}
		else
		{
			if(drives_ons.find(*it)==drives_ons.end()) //not in the drives on set
			{
				std::vector<std::vector<int>::iterator> itset;// save the iterator of dvds which are in drives on set in sequence,so that later i can find 
				int temp=-110;
				for(std::set<int>::iterator its=drives_ons.begin();its!=drives_ons.end();its++)
				{
					std::vector<int>::iterator pos=std::find(it,sequence.end(),*its);
					if(pos!=sequence.end())
						itset.push_back(pos);
					else temp=*its;
					
#ifdef debug
					std::cout<<"set:"<<*its;
#endif
				}
				
				
				if(temp==-110)
				{
					std::sort(itset.begin(),itset.end());// near to further
#ifdef debug
					std::cout<<"Areplace:"<<*(itset.back())<<"with"<<*it<<std::endl;
#endif
					drives_ons.erase(*(itset.back())  );
					drives_ons.insert(*it);
				}
				else 
				{
					drives_ons.erase(temp);
					drives_ons.insert(*it);
#ifdef debug
					std::cout<<"Breplace:"<<temp<<"with"<<*it<<std::endl;
#endif
				}
					
				
				insertion_count++;
			}
			
			else ;//the dvd is in the drives on set. so, do nothing	
		}
	}

	
	return insertion_count;
}

