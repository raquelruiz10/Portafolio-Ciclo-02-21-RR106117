#include <iostream>
using namespace std;

int main(){
	
	int x ;
	int y ;
	
	cout << ( x <= y ) << " \n";  // returns 0 (false) because 5 is neither lees than or equal to 3
	cout << ( x >= y ) << " \n";  // returns 1 (true) because 5 is greater than, or equal to 3
	cout << ( x < y ) << " \n";  //  returns 0 (false) because 5 is not lees than  3
	cout << ( x > y ) << " \n";  // returns 1 (true) because 5 is greater than 3
	cout << ( x != y ) << " \n";  //returns 1 (true) because 5 is not equal to 3
	cout << ( x == y ) << " \n";  // returns 0 (false) because 5 is not equal to 3
	
	return 0;
	
		
}
	
