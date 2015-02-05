/**
* By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
*
* What is the 10 001st prime number?
**/

#include <iostream>
#include <vector>

const int TARGET = 10000;

//Check if integer is prime. Optimized with the list of primes,
//All non-prime numbers, must be divisible by a prime number, and 
// will always be divisible by a number less than itself.
bool is_Prime(int *prime, std::vector<unsigned long int> *list){
	for(int i = 0; i < list->size(); i++){
		if(*prime % list->operator[](i) == 0)
			return false;
	}
	return true;
}

//Iterate until the target is met.
std::vector<unsigned long int> generate_Primes(){
	std::vector<unsigned long int> data = std::vector<unsigned long int>();
	data.push_back(2);//Seed the vector with the first prime number.
	for(int i = 3; data.size() <= TARGET; i++)
		if(is_Prime(&i,&data))
			data.push_back(i);
	return data;
}

int main(void){
	std::vector<unsigned long int> numbers = generate_Primes();
	std::cout << "The answer is: " << numbers[TARGET] << std::endl;
	return 0;

}
