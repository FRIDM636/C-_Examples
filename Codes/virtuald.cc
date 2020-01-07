#include<iostream>
#include<random>


int roll_dice(const int n_faces) {
	std::random_device random_device;
	std::default_random_engine random_engine(random_device());
	std::uniform_int_distribution<int> uniform_int_distribution(1,n_faces);

	return uniform_int_distribution(random_engine);
}

int main(int argc, char ** argv){
	
	int n_rolls = 10;
	int n_faces = 6;
	int Min, Max=0;
	double average = 0;

	std::cout<<"Enter your number of faces: ";
	std::cin>>n_faces;
	Min = n_faces;
	
	std::cout<<"Enter your number of rolls: ";
	std::cin>>n_rolls;
	for(auto i=0; i<n_rolls; i++){

		auto random_int = roll_dice(n_faces);
		printf("You rolled: %d\n",random_int);
		average += (double)random_int;
		Max = random_int > Max ? random_int : Max;
		Min = random_int < Min ? random_int : Min;
	}
	

	printf("Your average is: %f\n",average/(double)n_rolls);
	printf("Your Max roll is: %d\n",Max);
	printf("Your Min roll is: %d\n",Min);
	

	return 0;
}
