/**
* The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
*
* Find the sum of all the primes below two million.
**/

#include <iostream>
#include <vector>
#include <numeric>

const int TARGET = 2000000;

//Check if integer is prime. Optimized with the list of primes,
//All non-prime numbers, must be divisible by a prime number, and 
// will always be divisible by a number less than itself.
bool is_Prime(long long int *prime, std::vector<unsigned long long int> *list){
	for(long int i = 0; i < list->size(); i++){
		if(*prime % list->operator[](i) == 0)
			return false;
	}
	return true;
}

//Iterate until the target is met.
std::vector<unsigned long long int> generate_Primes(){
	std::vector<unsigned long long int> data = std::vector<unsigned long long int>();
	data.push_back(2);//Seed the vector with the first prime number.
	for(long long int i = 3; i <= TARGET; i++)
		if(is_Prime(&i,&data))
			data.push_back(i);
	return data;
}

int main(void){
	std::vector<unsigned long long int> numbers = generate_Primes();
	unsigned long long int init = 0;
	std::cout << "The summation is: " << std::accumulate(numbers.begin(), numbers.end(), init) << std::endl;
	return 0;

}
