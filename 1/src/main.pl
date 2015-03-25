# If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
#
# Find the sum of all the multiples of 3 or 5 below 1000.

use strict;
use warnings;

my $sum = 0;
for(my $a = 1; $a < 1000; $a = $a + 1){
	if(isMultipleOfThreeOrFive($a)){
		$sum = $sum + $a;
	}
}
print("The summation is: $sum");

#Subs
sub isMultipleOfThreeOrFive{
	my $num = $_[0];
	if($num % 3 == 0){
		return 1;
	}
	if($num % 5 == 0){
		return 1;
	}
	return 0;
}
