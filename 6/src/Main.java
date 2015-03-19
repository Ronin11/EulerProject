
/**
* The sum of the squares of the first ten natural numbers is,
*
* 1^2 + 2^2 + ... + 10^2 = 385
* The square of the sum of the first ten natural numbers is,
*
* (1 + 2 + ... + 10)^2 = 552 = 3025
* Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
*
* Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
**/

import java.util.ArrayList;

public class Main {
	//2 to 20, because 1 will go into anything and is a waste of computing.
	//Same could be said about other numbers, but that would make the code more messy.
	final static int low = 1;
	final static int high = 100;

	private static long sumOfSquares(){
		long num = 0;
		for(int i = low; i <= high; i++)
			num += Math.pow(i, 2);
		return num;
	}

	private static long squareOfSums(){
		long num = 0;
		for(int i = low; i <= high; i++)
			num += i;
		return (long)Math.pow(num, 2);
	}
	
	public static void main(String[] args){
		long num = (squareOfSums()-sumOfSquares());
		System.out.println("The difference is: " + num);
				
	}

}
