#include<iostream>
#include<vector>
#include<array>
#include<numeric>
#include<iterator>
template<typename T>
void Print(std::vector<T> data,bool with_end_line = true) {

	std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout," "));
	if(with_end_line)
		std::cout<<std::endl;
}


int main() {
	
	//Ways to decalre and initialize
	//std::vector<int> data;
	std::vector<int> data(5,1); //initialize with 5 elements with 1
	std::cout<<"Initialize using std::vector<int> data(5,1):"<<std::endl;
	Print(data);

	//Normal filling before initializing
	/*for(auto i=0; i<5; i++)
		data.push_back(i);
	std::cout<<"Using normal filling with for and push_back before initializing:"<<std::endl;
	Print(data);*/

	//Filling after initializing 
	for(auto i=0; i<5; i++)
		data[i] = i;
	std::cout<<"Using normal filling after initializing:"<<std::endl;
	Print(data);


	//Using std::fill
	std::fill(data.begin(), data.end(), 0);
	std::cout<<"Using std::fill for zero filling:"<<std::endl;
	Print(data);

	//Filling with sequential values using std::iota
	std::iota(data.begin(), data.end(), 1);
	std::cout<<"Using std::iota for sequential filling:"<<std::endl;
	Print(data);


	return 0;
}
