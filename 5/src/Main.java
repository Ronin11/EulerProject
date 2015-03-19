
/**
* 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
* 
* What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
**/

import java.util.ArrayList;

public class Main {
	//2 to 20, because 1 will go into anything and is a waste of computing.
	//Same could be said about other numbers, but that would make the code more messy.
	final static int low = 2;
	final static int high = 20;

	private static boolean isEvenlyDivisible(int num){
		for(int i = high; i >= low; i--)
			if(num % i != 0)
				return false;
		return true;
	}
	
	public static void main(String[] args){
		//Iterate through the value of the high number, because it's the largest common denominator of the group.
		for(int i = high;; i += high)
			if(isEvenlyDivisible(i)){
				System.out.println("The smallest number is: " + i);
				break;
			}
				
	}

}
