//
//  main.c
//  cRecurrsion
//
//  Created by Aakash Chitroda on 4/8/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include <stdio.h>
#include "my_recurrsion.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    printf("Factorial of 7 is %d\n", my_recurrsion__calculate_factorial(7));
    printf("Reverse: %d\n", my_recurrsion__reverse_number(345));
    my_recurrsion__is_palindrome(123210) ? printf("Palindrome\n") : printf("Not Palindrome\n");
    
    my_recurrsion__is_armstrong(121) ? printf("Armstrong\n") : printf("Not Armstrong\n");
    
    my_recurrsion__print_fibonacci_series(10);
    
    printf("Power: %lu\n",my_recurrsion__get_power(10, 4));
    
    printf("Sum of digits: %d\n", my_recurrsion__sum_of_all_digits(456));
    return 0;
}
