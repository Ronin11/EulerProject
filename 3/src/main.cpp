/**
* The prime factors of 13195 are 5, 7, 13 and 29.
*
* What is the largest prime factor of the number 600851475143 ?
**/

#include <iostream>
#include <vector>
#include <chrono>

const unsigned long int TARGET = 600851475143;

//Check if integer is prime.
bool is_Prime(unsigned long int *prime){
	if(*prime % 2 == 0)
		return false;
	for(int i = 3; i < *prime/2; i+=2){
		if(*prime % i == 0)
			return false;
	}
	return true;
}

//Find the Largest Prime Factor
unsigned long int get_Largest_Prime_Factor(){
	for(unsigned long int i = TARGET/2; i >= 3; i-=2){//We don't need to iterate through the even numbers.
		if(i % 2 == 0)
			--i; //Make sure we are iterating through odd numbers.
		if(TARGET % i == 0)
			if(is_Prime(&i))
				return i;
		}
}

int main(void){

	unsigned long int factor = get_Largest_Prime_Factor();
	std::cout << "The answer is: " << factor << std::endl;
	return 0;

}
