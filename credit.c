// This program uses the Luhn Algorithm for credit card verification

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void    card_id_checker(long long int card_id, long long int card_number);
void    verify_card_checker(long long int card_verify, int which);
void    verify_calculator(int sum1, int sum2);

// This determines what the number is. For example AMEX or VISA or MASTERCARD or INVALID number.
void    card_id_checker(long long int card_id, long long int card_number)
{
    int digit_count = 2;

    // This cuts off the digits for identification.
    while (!(card_id >= 10 && card_id <= 99))
    {
        card_id = card_id / 10;
        digit_count++;
    }

    // For AMEX
    if ((card_id == 34 || card_id == 37) && digit_count == 15)
    {
        // Function call for card validation process.
        verify_card_checker(card_number, 1);
    }

    // For MASTERCARD
    if ((card_id == 51 || card_id == 52 || card_id == 53 || card_id == 54 || card_id == 55) && digit_count == 16)
    {
        // Function call for card validation process.
        verify_card_checker(card_number, 2);
    }

    // For VISA
    if ((card_id >= 40 && card_id <= 49) && (digit_count == 13 || digit_count == 16))
    {
        // Function call for card validation process.
        verify_card_checker(card_number, 3);
    }

    // Prints "INVALID" if number identification fails.
    if (!((card_id == 34 || card_id == 37 || card_id == 51 || card_id == 52 || card_id == 53 || card_id == 54 || card_id == 55
           || (card_id >= 40 && card_id <= 49)) && (digit_count == 16 || digit_count == 13 || digit_count == 15)))
    {
        printf("INVALID\n");
        exit(0);
    }
}

// This is a special function for credit card verification with the Luhn Algorithm. This function was calculated and designed by me.
void    verify_card_checker(long long int card_verify, int which)
{
    // ----------------------------------------Each digit of the entered number is processed according to the algorithm rules.---------------From Start
    int digit_1 = card_verify % 10;
    long mem1 = card_verify / 10;
    int digit_2 = mem1 % 10;
    long mem2 = mem1 / 10;
    int digit_3 = mem2 % 10;
    long mem3 = mem2 / 10;
    int digit_4 = mem3 % 10;
    long mem4 = mem3 / 10;
    int digit_5 = mem4 % 10;
    long mem5 = mem4 / 10;
    int digit_6 = mem5 % 10;
    long mem6 = mem5 / 10;
    int digit_7 = mem6 % 10;
    long mem7 = mem6 / 10;
    int digit_8 = mem7 % 10;
    long mem8 = mem7 / 10;
    int digit_9 = mem8 % 10;
    long mem9 = mem8 / 10;
    int digit_10 = mem9 % 10;
    long mem10 = mem9 / 10;
    int digit_11 = mem10 % 10;
    long mem11 = mem10 / 10;
    int digit_12 = mem11 % 10;
    long mem12 = mem11 / 10;
    int digit_13 = mem12 % 10;
    long mem13 = mem12 / 10;
    int digit_14 = mem13 % 10;
    long mem14 = mem13 / 10;
    int digit_15 = mem14 % 10;
    long mem15 = mem14 / 10;
    int digit_16 = mem15 % 10;

    int digit_2_v2 = digit_2 * 2;
    int digit_2_v3 = digit_2_v2 % 9;
    if (digit_2_v3 == 0 && digit_2_v2 != 0)
    {
        digit_2_v3 += 9;
    }
    int digit_4_v2 = digit_4 * 2;
    int digit_4_v3 = digit_4_v2 % 9;
    if (digit_4_v3 == 0 && digit_4_v2 != 0)
    {
        digit_4_v3 += 9;
    }
    int digit_6_v2 = digit_6 * 2;
    int digit_6_v3 = digit_6_v2 % 9;
    if (digit_6_v3 == 0 && digit_6_v2 != 0)
    {
        digit_6_v3 += 9;
    }
    int digit_8_v2 = digit_8 * 2;
    int digit_8_v3 = digit_8_v2 % 9;
    if (digit_8_v3 == 0 && digit_8_v2 != 0)
    {
        digit_8_v3 += 9;
    }
    int digit_10_v2 = digit_10 * 2;
    int digit_10_v3 = digit_10_v2 % 9;
    if (digit_10_v3 == 0 && digit_10_v2 != 0)
    {
        digit_10_v3 += 9;
    }
    int digit_12_v2 = digit_12 * 2;
    int digit_12_v3 = digit_12_v2 % 9;
    if (digit_12_v3 == 0 && digit_12_v2 != 0)
    {
        digit_12_v3 += 9;
    }
    int digit_14_v2 = digit_14 * 2;
    int digit_14_v3 = digit_14_v2 % 9;
    if (digit_14_v3 == 0 && digit_14_v2 != 0)
    {
        digit_14_v3 += 9;
    }
    int digit_16_v2 = digit_16 * 2;
    int digit_16_v3 = digit_16_v2 % 9;
    if (digit_16_v3 == 0 && digit_16_v2 != 0)
    {
        digit_16_v3 += 9;
    }

    int first_sum = digit_2_v3 + digit_4_v3 + digit_6_v3 + digit_8_v3 + digit_10_v3 + digit_12_v3 + digit_14_v3 + digit_16_v3;
    int second_sum = digit_1 + digit_3 + digit_5 + digit_7 + digit_9 + digit_11 + digit_13 + digit_15;

    int final_sum = first_sum + second_sum;
    // ----------------------------------------Each digit of the entered number is processed according to the algorithm rules.---------------To Finish

    // ----------------------------------------According to the operation result, it decides the final result of the program with if statements combined with logical comparisons.---------------From Start
    if (which == 1 && final_sum % 10 == 0)
    {
        printf("AMEX\n");
        exit(0);
    }
    if (which == 2 && final_sum % 10 == 0)
    {
        printf("MASTERCARD\n");
        exit(0);
    }
    if (which == 3 && final_sum % 10 == 0)
    {
        printf("VISA\n");
        exit(0);
    }
    if (!(which == 1 && final_sum % 10 == 0) || !(which == 2 && final_sum % 10 == 0) || !(which == 3 && final_sum % 10 == 0))
    {
        printf("INVALID\n");
        exit(0);
    }
    // ----------------------------------------According to the operation result, it decides the final result of the program with if statements combined with logical comparisons.---------------To Finish
}

#define MAX_CARD_LENGTH 16

int main() {

    long long int    card_number = 5555555555554444;
    printf("%li\n", card_number);
    card_id_checker(card_number, card_number);


    return 0;
}



