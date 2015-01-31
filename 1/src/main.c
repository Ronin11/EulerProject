/** Main for Problem 1 **/
#include <stdio.h>
#include <stdlib.h>

//Make an array of multiples that are with the multiple base, and a max range.
int * make_array(int multiple, int max){
	int* arr = malloc((multiple/max)*sizeof(int));
	int i;
	for(i = 0; multiple <= max; i++){
		arr[i] = multiple;
		multiple += multiple; 
	}
	arr[++i] = -1;
	return arr;
}

//Get the array size, as long as it is terminated with -1
int get_size(int * arr){
	int arr_size;
	for(arr_size = 0; ; arr_size++){
		if(arr[arr_size] == -1)
			break;
	}
	return arr_size;
}

//There will be a set of doubles in the array, Create a negative array to counter the doubles.
int * make_negative_doubles(int first, int second, int max){
	int multiple = first*second;
	int * arr = make_array(multiple, max);
	int i = 0;
	while(arr[i++] != -1){
		arr[i] = -arr[i];
	}
	return arr;
}

//Add the arrays together, and return the result.
int * add_arrays(int * arr1, int * arr2, int * arr3){
	int arr1_size = get_size(arr1);
	int arr2_size = get_size(arr2);
	int arr3_size = get_size(arr3);
	int* result = malloc(arr1_size + arr2_size + arr3_size);

	int i,j,k;
	for(i = 0; ; i++){
		if(arr1[i] == -1)
			for(j = 0; ; i++,j++){
				if(arr2[j] == -1)
					for(k = 0; ; i++,k++){
						if(arr3[k] == -1)
							break;
						else
							result[i] = arr3[k];
					}
				else
					result[i] = arr2[j];
			}
		else
			result[i] = arr1[i];
	}
	result[++i] = -1;
	return result;
}

//Sum all values in the array and return the result.
int summation(int * arr){
	int sum = 0;
	for(int i = 0; ; i++){
		if(arr[i] == -1)
			break;
		else
			arr[i] += sum;
	}
	return sum;

}

int main(){
	printf("Program Begin\n");
	//Declare Variables
	int three = 3;
	int five = 5;
	int max = 1000;

	//Zhu Li do the thing!
	int * threes_arr = make_array(three,max); 
	int * fives_arr = make_array(five,max);
	int * negatives = make_negative_doubles(three,five,max);
	int * result = add_arrays(threes_arr,fives_arr,negatives);
	int answer = summation(result);

	printf("The sum of all the multiples of %d or %d below %d is: %d\n", three, five, max, answer);

	//Release memory, even though the OS will reclaim it once the program finishes.
	free(threes_arr);
	free(fives_arr);
	free(result);

	return 0;	
}

