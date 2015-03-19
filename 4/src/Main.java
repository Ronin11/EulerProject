
/**
* A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
* 
* Find the largest palindrome made from the product of two 3-digit numbers.
**/

import java.util.ArrayList;

public class Main {
	
	//Factors for the bounds to find the palindromic number
	final static int min = 100;
	final static int max = 999;
	
	static Integer pop(ArrayList<Integer> list){
		Integer temp = list.get(0);
		list.remove(0);
		return temp;
	}
	static Integer popBack(ArrayList<Integer> list){
		Integer temp = list.get(list.size()-1);
		list.remove(list.size()-1);
		return temp;
	}
	static boolean isPalindrome(int num){
		ArrayList<Integer> data = new ArrayList<Integer>();
		//Divide each by a log10 to get each number-character separately
		for(int i = 0; i < Math.log10(num); i++){
			int temp = (int)(num / Math.pow(10,i));
			data.add(temp % 10);
		}
		
		//+1 because if the size is odd, it will loop for the single,
		// but if it's even it wont, because of integer division.
		int iterationMax = (data.size()+1)/2;
		
		//Check if it's a palindrome
		for(int j = 0; j < iterationMax; j++){ 
			if(data.size() == 1)
				break; //We don't care what the last number is, if it's in the exact middle.
			else
				if(pop(data) != popBack(data))
					return false;
	
		}
		return true; //If it falls through, it passed the test.
	}
	
	
	
	public static void main(String[] args){
		//Using this loop does not guarantee we find the largest first unfortunately.
		int largest = 0;
		for(int i = max; i >= min; i--)
			for(int j = max; j >= min; j--)
				if(i*j > largest && isPalindrome(i*j))//Don't bother checking for palindromimity if the product is smaller than the current largest.
					largest = i*j;
		System.out.println("The palindrome is: " + largest);
				
	}

}
