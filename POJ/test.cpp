#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int arg, char** argv)
{
	std::vector<int> sint;
	sint.push_back(2);
	sint.push_back(234);
	std::ostringstream ouu;
	for(std::vector<int>::iterator it=sint.begin();it!=sint.end();it++)
		ouu<<*it;
	ouu<<"1"<<"2"<<3<<45;
	std::cout<<ouu.str();
	
	std::string ss="0.1";
	std::cout<<" "<<ss<<" "<<ss.find('.')<<ss.size();
	
	ss.erase(ss.find('.'),1);
	std::cout<<std::endl<<ss<<" "<<ss.size();
	
	
	return 0;
	
}