/*
Exponentiation
Time Limit: 500MS		Memory Limit: 10000K
Total Submissions: 122885		Accepted: 29996
Description

Problems involving the computation of exact values of very large magnitude and precision are common. For example, the computation of the national debt is a taxing experience for many computer systems.

This problem requires that you write a program to compute the exact value of Rn where R is a real number ( 0.0 < R < 99.999 ) and n is an integer such that 0 < n <= 25.
Input

The input will consist of a set of pairs of values for R and n. The R value will occupy columns 1 through 6, and the n value will be in columns 8 and 9.
Output

The output will consist of one line for each line of input giving the exact value of R^n. Leading zeros should be suppressed in the output. Insignificant trailing zeros must not be printed. Don't print the decimal point if the result is an integer.
Sample Input

95.123 12
0.4321 20
5.1234 15
6.7592  9
98.999 10
1.0100 12
Sample Output

548815620517731830194541.899025343415715973535967221869852721
.00000005148554641076956121994511276767154838481760200726351203835429763013462401
43992025569.928573701266488041146654993318703707511666295476720493953024
29448126.764121021618164430206909037173276672
90429072743629540498.107596019456651774561044010001
1.126825030131969720661201
Hint

If you don't know how to determine wheather encounted the end of input:
s is a string and n is an integer
C++

while(cin>>s>>n)

{

...

}

c

while(scanf("%s%d",s,&n)==2) //to  see if the scanf read in as many items as you want

//while(scanf(%s%d",s,&n)!=EOF) //this also work
{

...

}
*/


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#define debugoff
using namespace std;

string pow(string s, int index);
string mul(string s1,string s2); // multiply two number
string trimtoDisplay(string s);  // in case of the one order number that will not be process by mul(string,string) 

int main()
{
    string s;
    int n;
    while(cin>>s>>n)
    {
        string result=pow(s,n);
        cout<<trimtoDisplay(result)<<endl;

    }
    return 0;
}

string pow(string s,int index)
{
    if(index==1)return s;

    if(index>2)
    {

        int i=index/2; // in order to reduce the multiply ,divide the index to two half
        int j=index%2;
        if (j==1)
            return mul(pow(pow(s,i),2),s);
        else
            return pow(pow(s,i),2);
    }

    return mul(s,s);
}


string mul(string s1,string s2)
{
    int pos1=s1.find('.');
    int pos2=s2.find('.');

    if(pos1!=std::string::npos)
        s1.erase(pos1,1);
    else pos1=0;

    if(pos2!=std::string::npos)
        s2.erase(pos2,1);
    else pos2=0;

    int pos=pos1+pos2;  //remember the result dot position

    vector<int> pre(s1.length());
    vector<int> back(s2.length());
    vector<int> re(pre.size()+back.size());

    for(int i1=0;i1<s1.length();i1++)
    {
         pre.at (s1.size()-i1-1)=s1.at (i1)-'0';
    }

    for(int i2=0;i2<s2.length();i2++)
    {
         back.at (s2.size()-i2-1)=s2.at (i2)-'0';
    }
	
#ifdef debug
	cout<<"pre:";
	for(vector<int>::iterator it=pre.begin();it!=pre.end();it++)
		cout<<*it;
	cout<<endl;
	
	cout<<"back:";
	for(vector<int>::iterator it=back.begin();it!=back.end();it++)
		cout<<*it;
	cout<<endl;
#endif
	

    for(int p=0;p!=pre.size();p++)
    {
        for(int b=0;b!=back.size();b++)
        {
            re[p+b]+=pre[p]*back[b]; //accumulate
#ifdef debug
			cout<<"re["<<p+b<<"]:"<<re[p+b]<<endl;
#endif

        }
    }
	
	vector<int>::iterator itr=re.begin();
	while(itr!=re.end())
	{
		if(*itr>9)
		{   
			*(itr+1)+=*itr/10;
			*itr=*itr%10;
		}
#ifdef debug
		cout<<*itr;
#endif		
		itr++;

	}
	
	if(pos!=0)
	re.insert(re.end()-pos,-1); //let -1 to denote the dot
#ifdef debug
	cout<<endl<<"result after insert dot:";
	for(vector<int>::iterator it=re.begin();it!=re.end();it++)
		cout<<*it;
		cout<<endl;
#endif    
	ostringstream out;
    vector<int>::reverse_iterator it=re.rbegin(),end=re.rend()-1;
#ifdef debug
	cout<<endl<<"result after remove dot&zeros:";
	for(vector<int>::iterator it=re.begin();it!=re.end();it++)
		cout<<*it;
		cout<<endl;
#endif  
	
    while(it!=end+1)
    {
		if(*it!=-1)
			out<<*it;
		else out<<'.';
#ifdef debug
		cout<<*it;
#endif 
        it++;
    }
    return out.str();

}


string trimtoDisplay(string s)
{
	
	int it=0,end=s.size()-1;
	while(s.at(it)=='0')it++;
	if(s.find('.')!=string::npos)  // delete the zeros at last only if there is a dot'.'
	{
		while(s.at(end)=='0')
			end--; //delete zeros
		if(s.at(end)=='.')end--;//delete the dot
		
	}	
	return s.substr(it,end-it+1);	
	
}