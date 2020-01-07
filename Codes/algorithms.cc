#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<numeric>
#include<random>
//#include<execution>

//Helper functions

template<typename T>
void print_data(std::vector<T> data, std::string s = " "){
	std::cout<<s<<std::endl;
	std::copy(data.begin(), data.end(), std::ostream_iterator<T>(std::cout, " "));
	std::cout<<std::endl;
}


void generate_random_data(std::vector<int> &data){
	std::random_device random_device;
	std::default_random_engine random_engine(random_device());
	std::uniform_int_distribution<int> uniform_int_distribution(1,10);

	for(auto i = data.begin(); i != data.end(); i++)
		*i = uniform_int_distribution(random_engine);
}


void fill_example() {
	std::vector<int> data(10);
	std::fill(data.begin(), data.end(), 0);
	print_data(data, "Filling function:");	

}

void find_example(){
	std::vector<int> data(10);
	std::iota(data.begin(), data.end(), 1);
	print_data(data, "Finding function:");

	std::cout<<"Looking for 9"<<std::endl;
	auto result = find(data.begin(), data.end(), 9);
	
	if(result != data.end())
		std::cout<<"Element "<<*result<<" is found at index "<<distance(data.begin(), result)<<std::endl;
	else
		std::cout<<"Element not found !"<<std::endl;
	
	std::cout<<"Looking for 5"<<std::endl;
	result = find(data.begin(), data.end(), 55);
	
	if(result != data.end())
		std::cout<<"Element "<<*result<<" is found at index "<<distance(data.begin(), result)<<std::endl;
	else
		std::cout<<"Element 55 not found !"<<std::endl;


}

void accumulate_example(){
	std::vector<int> data(5);
	generate_random_data(data);

	auto sum = std::accumulate(data.begin(), data.end(), 0);
	print_data(data, "Accumulate function:");
	std::cout<<"The sum of vector's elements is: "<<sum<<std::endl;
	
}

void copy_example(){
	std::vector<int> data(10);
	generate_random_data(data);
	std::vector<int> copy;
	std::copy(data.begin(), data.end(), std::back_inserter(copy));
	
	std::cout<<"Copy function:"<<std::endl;
	print_data(data, "Original copy");
	print_data(copy, "Copy version");

}
//This function requiries Visual studio, std::execution is not implemented or supported in GCC
/*  
void reduce_example() {
	std::vector<double> data(1e4, 0.5);
	const auto result = std::reduce(std::execution::par, data.begin(), data.end());
	print_data(data, "Reduce function");
	std::cout<<"Sum with reduce operation is "<<result<<std::endl;


}
*/
int main(){

	fill_example();
	find_example();
	//reduce_example(); //Needs c++17 and threading building block library TBB
	accumulate_example();
	copy_example();
}
