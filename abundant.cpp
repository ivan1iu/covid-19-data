/********************************************************
 * Description:
 *   Displays the top 3 most "abundant" (see writeup)
 *   numbers in the input sequence.  The input sequence
 *   is assumed to be valid natural numbers separated
 *   by spaces and ending with 0.
 *
 *   ABSOLUTELY NO ARRAY or `string`/`vector`/etc. usage
 *   is allowed!

 *   You may only declare: bool, int, or unsigned int
 *   No library functions (beyond cin/cout) are allowed.
 *
 *   You may NOT modify any of the given template code.
 *   This ensures our automated checkers can parse your
 *   output.  You MAY add functions, prototypes, etc.
 *   to aide your implementation. Failure to follow this 
 *   direction will lead to a score of 0 on this 
 *   part of the assignment.
 ********************************************************/

#include <iostream>
using namespace std;
// declare/define abundance function
int abundance(unsigned int x){
  int xx = x; //variable to get divided by divisors;
  int ab = 0; 
  int i = 1; //all starts with getting divided by 1;
  while(i<x){ 
    if(x % i == 0){
      xx = x / i;
      ab = ab + i;
      i = i + 1;
    }else{
      i = i + 1;
    }
    }
    
  if(ab > x){
    return ab; //return its abundance;
  }else{
    return 0;
  }
  
}

int main()
{
  // n1 is the number with the highest abundance, a1
  // n2 is the number with the 2nd-highest abundance, a2
  // n3 is the number with the 3rd-highest abundance, a3
  unsigned int n1 = 0, n2 = 0, n3 = 0;
  int a1 = 0, a2 = 0, a3 = 0;

  // num_abundant counts how many numbers in the input
  // sequence are abundant
  int num_abundant = 0;

  cout << "Enter a sequence of natural numbers, separated by spaces, ";
  cout << "and ending with 0."<< endl;

  /*====================*/
  /* Start of your code */
  

  while(true){
    unsigned int x; //unsigned since should be positive numbers;
    cin >> x;

    if(x == 0){ // to detect when to stop the function;
      break;
    }

    int abundancee = abundance(x);

    if(abundancee > a1){ //replace:
      n3 = n2; // 3rd most abundant number with the previous 2nd most;
      a3 = a2; 
      n2 = n1; // 2nd most abundant number with the previous most;
      a2 = a1;
      n1 = x;  // 1st most abundant number with the new one;
      a1 = abundancee;
    }else if(abundancee > a2){
      n3 = n2;
      a3 = a2;
      n2 = x;
      a2 = abundancee;
    }else if (abundancee > a3){
      n3 = x;
      a3 = abundancee;
    }

    if(abundancee > 0){
      num_abundant += 1;
    }
  }


  
  
  
  
  
  
  
  /* End of your code */
  /*==================*/
  
  
  cout << "Abundant number count: " << num_abundant << endl;
  cout << "Top 3 most abundant numbers: " << endl;
  cout << n1 << " : " << a1 << endl;
  cout << n2 << " : " << a2 << endl;
  cout << n3 << " : " << a3 << endl;


  return 0;

}
