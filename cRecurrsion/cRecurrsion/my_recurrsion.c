//
//  my_recurrsion.c
//  cRecurrsion
//
//  Created by Aakash Chitroda on 4/8/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include "my_recurrsion.h"

uint32_t my_recurrsion__calculate_factorial(uint32_t num) {
    if (num <= 1) return 1;
    else return num * my_recurrsion__calculate_factorial(num-1);
}

static uint32_t my_recurrsion__reverse_util(uint32_t num, uint32_t result) {
    if (!num) return result;
    else {
        result = (result * 10) + (num % 10);
        return my_recurrsion__reverse_util(num / 10, result);
    }
}

uint32_t my_recurrsion__reverse_number(uint32_t num) {
    return my_recurrsion__reverse_util(num, 0);
}
#if 0
uint32_t result = 0;

while (num) {
    result = (result * 10) + (num % 10);
    num = num / 10;
}
return result;
#endif
bool my_recurrsion__is_palindrome(uint32_t num) {
    uint32_t result = my_recurrsion__reverse_number(num);
    
    return (result == num);
}

static uint32_t my_recurrsion__is_armstrong_util(uint32_t num, uint32_t result) {
    if (!num) return result;
    else {
        uint32_t rem = num % 10;
        result = result + (rem * rem * rem);
        return my_recurrsion__is_armstrong_util(num/10, result);
    }
}

bool my_recurrsion__is_armstrong(uint32_t num) {
    return (num == my_recurrsion__is_armstrong_util(num, 0));
}

static void my_recurrsion__print_fibonacci_series_util(uint32_t x, uint32_t y, uint32_t length) {
    if (length == 0) {
        printf("\n");
        return;
    }
    printf("%d ", x + y);
    my_recurrsion__print_fibonacci_series_util(y, x + y, length-1);
}

void my_recurrsion__print_fibonacci_series(uint32_t length) {
    uint32_t x = 0;
    uint32_t y = 1;
    printf("%d %d ", x, y);
    length = length - 2;
    if (length > 0)
        my_recurrsion__print_fibonacci_series_util(0,1,length);
}

long my_recurrsion__get_power(int32_t base, int32_t power) {
    if (power == 0) return 1;
    else return base * my_recurrsion__get_power(base, power - 1);
}

uint32_t my_recurrsion__sum_of_all_digits(uint32_t num) {
    if (!num) return 0;
    else return (num % 10) + my_recurrsion__sum_of_all_digits(num / 10);
}
