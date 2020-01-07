#include<iostream>
#include<random>



typedef struct{
	unsigned long money=0;
	unsigned long bet = 0;
	int choice = 1;
}Player;


class Bet {
	private:
	static bool guess;
	unsigned int result = 1;
	bool game = true;
	Player player;

	void roller();	
	void set_guess();
	void set_money();
	public:
		Bet(unsigned long initial_money){player.money = initial_money;}
		bool get_guess() const{ return guess;}
		unsigned int get_result() const{return result;}
		void set_bet(const unsigned long bet) { player.bet = bet;}
		void set_choice(const unsigned int choice) { player.choice = choice; set_guess(); set_money();}
		unsigned long get_money() const{ return player.money;}
		unsigned long get_bet(){ return player.bet;}
		bool game_over() const{ return game;}
};

bool Bet::guess = false;
void Bet::roller() {
	std::random_device random_device;
	std::default_random_engine random_engine(random_device());
	std::uniform_int_distribution<int> uniform_int_distribution(1,10);

	result = uniform_int_distribution(random_engine);
}
void Bet::set_guess(){
	roller();
	guess = (result == player.choice);
}

void Bet::set_money(){
       	if(guess)
		player.money += 10 * player.bet;
	else
		player.money -= player.bet;	
	if(player.money)
		game = false;
}


void make_bet(Bet &b){
	unsigned long bet;
	unsigned int choice;
//	printf("%p\n",&b);

	std::cout<<"Set your bet"<<std::endl;
	std::cin>>bet;
	while(bet > b.get_money()) {
		std::cout<<"You bet an incorrect amount, try again!"<<std::endl;
		std::cin>>bet;
	}

	b.set_bet(bet);
	std::cout<<"Choose a number"<<std::endl;
	std::cin>>choice;
	b.set_choice(choice);

}

int main() {

	unsigned long money, bet;
	unsigned int choice;
	char c = 'y';
	printf("Enter your amount of money\n");
	std::cin>>money;
	Bet b = Bet(money);

//	printf("%p\n",&b);

	while(c != 'n' && c != 'N') {
	
	make_bet(b);

	if(b.get_guess()){
		std::cout<<"You win 10x"<<b.get_bet()<<" dollars"<<std::endl;
		std::cout<<"You have now "<<b.get_money()<<" dollars"<<std::endl;
	}
	else{
		std::cout<<"You lose "<<b.get_bet()<<" dollars"<<std::endl;
		std::cout<<"Guess is "<<b.get_result()<<std::endl;
		std::cout<<"You have now "<<b.get_money()<<" dollars"<<std::endl;
	}
	if(b.game_over())
		{ 
			std::cout<<"Go home!"<<std::endl;
			break;
		}
	if(b.get_money() <= 50){
		std::cout<<"Just "<<b.get_money();
		std::cout<<" dollars continue playing?! Y/N"<<std::endl;
		std::cin>>c;
	}
	}
	return 0;
}	
