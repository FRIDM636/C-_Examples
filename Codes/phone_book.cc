#include<iostream>
#include<vector>
#include<algorithm>
#include<ostream>
#include<array>
#include<iterator>
#include<string>
#include<tuple>


//using contact = std::pair<std::string, std::string>;
using contact = std::tuple<std::string, std::string, std::string>; //any combination of types may be used with tuple
using contacts = std::vector<contact>;


//Compare functions to use with std::sort "<" is the default comparaison
bool  compare_first_name(const contact& person1, const contact& person2) {

		return std::get<0>(person1) < std::get<0>(person2) ;
}

bool  compare_last_name(const contact& person1, const contact& person2) {

		return std::get<1>(person1) < std::get<1>(person2) ;
}

bool  compare_phone_number(const contact& person1, const contact& person2) {

		return std::get<2>(person1) < std::get<2>(person2) ;
}


//Some contacs data
contacts demo_contacts =
{	
	{"Anast","Vict","542-569-8412"},
	{"Farid","MIHOUB","371-256-4589"},
	{"Omar","WITTG","555-889-4578"},
	{"Johan","GOKU","455-858-5625"},
	{"Monkey","D_LUFFY","154-458-1254"},
	{"Law","D_TRAW","965-856-4522"},
	{"Conan","Obrien","758-548-5865"},
	{"Khawz","ALGEBRE","124-458-9875"},
	{"James","arno","125-458-9854"},
	{"Canada","FAIL","356-589-2458"},
	{"Brazil","FOOT","125-586-5982"},
	{"Europe","EAST","335-856-9124"},
	{"Neptune","SYSTEM","524-532-6587"},
	{"China","LIVE","425-852-7561"}
};

//Printing contact using oveloafing method
inline std::ostream& operator << (std::ostream& o,const contact & person) {
		//return o << person.first << ":" <<person.second; // used with pair
		return o <<std::get<0>(person)<<"		"<<std::get<1>(person)<<"		"<<std::get<2>(person);
}

//Printing the whole contacts elements
void print_contacts(const contacts& list) {

	
	printf("Name:		Surname:	Phone:		\n");
	std::for_each(list.begin(), list.end(), [](const contact & person) 
			{	
				std::cout<<person<<std::endl;
			});
	std::cout<<std::endl;
}

void contacts_filter(const contacts& list, const char c='A') {
	std::vector<contact> filter;
	std::copy_if(list.begin(), list.end(), std::back_inserter(filter), [c](const contact& person) 
			{	
				auto first_name = std::get<0>(person);
				return first_name.find(c) != std::string::npos;
			});
	
	std::cout<<"*****Sorting by conctacts contain \""<<c<<"\" in the name****************"<<std::endl;
	print_contacts(filter);
}

//The main function
int main(int argc, char ** argv){

	std::sort(demo_contacts.begin(), demo_contacts.end(), compare_first_name); //Sorting using comapre helper
	std::cout<<"********************Sorting by first name*******************************"<<std::endl;
	print_contacts(demo_contacts);
	std::sort(demo_contacts.begin(), demo_contacts.end(), compare_last_name); //Sorting using comapre helper
	std::cout<<"********************Sorting by last name*******************************"<<std::endl;
	print_contacts(demo_contacts);
	std::sort(demo_contacts.begin(), demo_contacts.end(), compare_phone_number); //Sorting using comapre helper
	//std::sort(demo_contacts.begin(), demo_contacts.end()); //standar sorting
	/*std::sort(demo_contacts.begin(), demo_contacts.end(), [](const  contact& person1, const contact& person2) -> bool
			{
				//return person1.first > person2.second; //used with pair 
				return std::get<1>(person1) > std::get<1>(person2);
			});
	*/
	std::cout<<"********************Sorting by phone number****************************"<<std::endl;
	print_contacts(demo_contacts);
	contacts_filter(demo_contacts,'F');
	return 0;
}






