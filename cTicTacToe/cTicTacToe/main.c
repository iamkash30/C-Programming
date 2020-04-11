//
//  main.c
//  cTicTacToe
//
//  Created by Aakash Chitroda on 4/9/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#define ROW_SIZE    3
#define COL_SIZE    3
#define INITIAL_VALUE '_'

uint8_t matrix[ROW_SIZE][COL_SIZE] = {
    INITIAL_VALUE, INITIAL_VALUE, INITIAL_VALUE,
    INITIAL_VALUE, INITIAL_VALUE, INITIAL_VALUE,
    INITIAL_VALUE, INITIAL_VALUE, INITIAL_VALUE
};


bool user_turn = false;

void print_matrix(void) {
    for (int32_t row = 0; row < ROW_SIZE; row++) {
        for (int32_t col = 0; col < COL_SIZE; col++) {
            printf("[%2c ] ", matrix[row][col]);
        }
        printf("\n");
    }
}

void print_primary_diagonals(void) {
    for (int32_t row = 0; row < ROW_SIZE; row++)
        for (int32_t col = 0; col < COL_SIZE; col++) {
            if (row == col) {
                printf("[%2c ] ", matrix[row][col]);
        }
    }
    printf("\n");
}

void print_secondary_diagonals(void) {
    for (int32_t row = 0; row < ROW_SIZE; row++)
        for (int32_t col = 0; col < COL_SIZE; col++) {
            if (row+col == ROW_SIZE - 1) {
                printf("[%2c ] ", matrix[row][col]);
        }
    }
    printf("\n");
}

uint32_t game__get_sum_of_row(uint32_t row_num) {
    uint32_t sum = 0;
    for (int32_t col = 0; col < COL_SIZE; col++) {
        sum += matrix[row_num][col];
    }
    return sum;
}

uint32_t game__get_sum_of_col(uint32_t col_num) {
    uint32_t sum = 0;
    for (int32_t row = 0; row < ROW_SIZE; row++) {
        sum += matrix[row][col_num];
    }
    return sum;
}

uint32_t game__get_sum_primary_diagonal(void) {
    uint32_t sum = 0;
    for (int32_t row = 0; row < ROW_SIZE; row++) {
        for (int32_t col = 0; col < COL_SIZE; col++) {
            if (row == col) {
                sum += matrix[row][col];
            }
        }
    }
    return sum;
}

uint32_t game__get_sum_secondary_diagonal(void) {
    uint32_t sum = 0;
    for (int32_t row = 0; row < ROW_SIZE; row++) {
        for (int32_t col = 0; col < COL_SIZE; col++) {
            if ((row + col) == (ROW_SIZE - 1)) {
                sum += matrix[row][col];
            }
        }
    }
    return sum;
}

uint8_t game__is_winner(void) {
    uint32_t result = 0;
    // 'X' + 'X' + 'X' = 264
    // 'O' + 'O' + 'O' = 237
    // Case 1: When a particular row is XXX or OOO
    for (int row = 0; row < ROW_SIZE; row++) {
        result = 0;
        for (int col = 0; col < COL_SIZE; col++) {
            if (matrix[row][col] == '_') break;
            result += matrix[row][col];
            if (result == 264 || result == 237) return matrix[row][col];
        }
    }
    
    // Case 2: When a particular col is XXX or OOO
    for (int row = 0; row < ROW_SIZE; row++) {
        result = 0;
        for (int col = 0; col < COL_SIZE; col++) {
            if (matrix[col][row] == '_') break;
            result += matrix[col][row];
            if (result == 264 || result == 237) return matrix[col][row];
        }
    }
    
    // Case 3: When a primary diagonal is XXX or OOO
    result = 0;
    for (int row = 0; row < ROW_SIZE; row++) {
        for (int col = 0; col < COL_SIZE; col++) {
            if (row == col) {
                if (matrix[row][col] == '_') break;
                result += matrix[row][col];
                if (result == 264 || result == 237) return matrix[row][col];
            }
        }
    }
    
    // Case 4: When a secondary diagonal is XXX or OOO
    result = 0;
    for (int32_t row = 0; row < ROW_SIZE; row++) {
        for (int32_t col = 0; col < COL_SIZE; col++) {
            if ((row + col) == (ROW_SIZE - 1)) {
                if (matrix[row][col] == '_') break;
                result += matrix[row][col];
                if (result == 264 || result == 237) return matrix[row][col];
            }
        }
    }
    return 0;
}

bool game__is_full(void) {
    for (int32_t row = 0; row < ROW_SIZE; row++) {
        for (int32_t col = 0; col < COL_SIZE; col++) {
            if (matrix[row][col] == '_')
                return false;
        }
    }
    return true;
}

void game__insert(int row, int col, bool user) {
    matrix[row][col] = user ? 'O' : 'X';
}

int main(int argc, const char * argv[]) {
    // insert code here...
    uint8_t user1[32] = {'\0'}, user2[32] = {'\0'};
    uint8_t winner = '\0';
    uint8_t continue_playing = '\0';
    printf("Enter name of user 1: ");
    scanf("%s", user1);
    printf("User1: %s\n", user1);
    
    printf("Enter name of user 2: ");
    scanf("%s", user2);
    printf("User2: %s\n", user2);
    int row_in, col_in;
    do {
        do {
            print_matrix();
            fflush(stdin);
            printf("Continue Playing\n");
        REPEAT:
            printf("%s turn, Enter value [row col] (00 - 22) seperated by space : ", user_turn ? user2 : user1);
            scanf("%d%d", &row_in, &col_in);
            if ((row_in > 2) || (row_in < 0) || (col_in > 2) || (col_in < 0)) {
                printf("\n *** ERROR : Invalid index, try again !!!\n");
                goto REPEAT;
            }
            if (matrix[row_in][col_in] != '_') {
                printf("\n *** ERROR : Already filled,try again !!!\n");
                goto REPEAT;
            } else {
                game__insert(row_in, col_in, user_turn);
                user_turn = !user_turn;
            }
            winner = game__is_winner();
        } while (!game__is_full() && !winner);
        printf("\n *** Game Over *** \n");
        winner ?
        printf("Congratulations Dear %s,\n"
               "\tYou have won the game.!!!!\n", (winner == 'X') ? user1 : user2) :
        printf("Oops! Its a Tie\n");
        printf("Do you want to start a new game (Y/N): ");
//        scanf("%d", &continue_playing);
    } while (getc(stdin) == 'Y');
    printf("Game Stopped\n");
    return 0;
}
