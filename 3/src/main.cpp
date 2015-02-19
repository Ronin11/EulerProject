/**
* The prime factors of 13195 are 5, 7, 13 and 29.
*
* What is the largest prime factor of the number 600851475143 ?
**/

#include <iostream>
#include <vector>
#include <chrono>

const unsigned long int TARGET = 600851475143;

//Check if integer is prime. Optimized with the list of primes,
//All non-prime numbers, must be divisible by a prime number, and 
// will always be divisible by a number less than itself.
bool is_Prime(unsigned long int *prime, std::vector<unsigned long int> *list){
	for(int i = 0; i < list->size(); i++){
		if(*prime % list->operator[](i) == 0)
			return false;
	}
	return true;
}

//Iterate until the target is met.
std::vector<unsigned long int> * generate_Primes(){
	static std::vector<unsigned long int> data = std::vector<unsigned long int>();
	data.reserve(TARGET/5);
	data.push_back(2);//Seed the vector with the first prime number.
	for(unsigned long int i = 3; i <= TARGET/2; i+=2)
		if(is_Prime(&i,&data))
			data.push_back(i);
	return &data;
}

//Find the Prime Factors
unsigned long int get_Prime_Factors(std::vector<unsigned long int> * primes){
	//std::vector<unsigned long int> factors = std::vector<unsigned long int>();
	for(int i = primes->size()-1; i >= 0; i--)
		if(TARGET % primes->operator[](i) == 0)
			return primes->operator[](i);
			//factors.push_back(primes[i]);
	//return factors;
}

int main(void){
	auto start = std::chrono::system_clock::now();
	std::vector<unsigned long int> *numbers = generate_Primes();
	unsigned long int factor = get_Prime_Factors(numbers);
	auto stop = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
	std::cout << "Time Taken: " << duration << " microseconds." << std::endl;
	//std::cout <<  "Factors of " << TARGET << ": ";
	//for(int i = 0; i < factors.size(); i++)
	//	std::cout <<  factors[i] << " ";
	//std::cout << std::endl;
	std::cout << "The answer is: " << factor << std::endl;
	return 0;

}
