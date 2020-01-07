#include<iostream>
#include<vector>
#include<array>
#include<map>
#include<unordered_map>
#include<queue>

int main(){

	int data[5]; //Old C style
	for(auto i =0; i<5; ++i)
		data[i] = i;

	std::array<int,5> a_data; //Adviced to use array than C style arrays

	std::vector<int> v_data; //Vectors powerfull containers specially when combined with iterators
	for(auto i =0; i<5; ++i)
		v_data.push_back(i);

	std::map<int, int> m_data;//role of a dictionnary
	m_data[5] = 1;
	m_data[3] = 3;
	const auto value = m_data[3];
	std::cout<<"Default value: "<<value<<std::endl;

	std::unordered_map<int, int> u_data;
	u_data[5] = 1;
	u_data[3] = 3;
	const auto u_value = u_data[5]; //Unordred map, kies are not ordered automatilcally, they follow the filling order
	std::cout<<"Default value: "<<u_value<<std::endl;

	std::queue<int> q_data; // Queue data structure FIFO, but this rule can be overrided
	q_data.push(5);
	q_data.push(3);
	q_data.push(6);
	std::cout<<"Queue front:"<<q_data.front()<<std::endl<<"Queue back: "<<q_data.back()<<std::endl;

}




