#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    long Card_Number;
    int Digit_Number = 0, Current_Digit = 0, Even_x2_Product = 0, Even_Digits = 0, Odd_Digits = 0,
        Total_Digit_Sum = 0;
    bool is_even = false;

// Prompt User for Credit Card Number

    do
    {
        Card_Number = get_long("Card Number: ");
    }
    while (Card_Number < 0);

// Check First Digits of Number

    int Digits_MstrCrd = Card_Number / pow(10, 14);
    int Digits_Visa_16 = Card_Number / pow(10, 15);
    int Digits_AmEx = Card_Number / pow(10, 13);
    int Digits_Visa_13 = Card_Number / (pow(10, 12));

// Loop to determine identity of each digit
   while (Card_Number != 0)
    {
        // Get Last Digit of Number

        Current_Digit = (Card_Number % 10);

        // Increase Digit Number by 1

        Digit_Number += 1;

        // Check if Current Digit is at Odd or Even Position in Card Number

        if (is_even == true)
        {
            // Multiply Digit by 2

            Even_x2_Product = Current_Digit * 2;

            // Add Digits of Multiplication Product

            while (Even_x2_Product != 0)
            {
                Even_Digits += Even_x2_Product % 10;
                Even_x2_Product /= 10;
            }

            // Tell Program Next Digit is Odd

            is_even = false;
        }
        else
        {
            // Add Odd Digits

            Odd_Digits += Current_Digit;

            // Tell Program Next Number is Even

            is_even = true;
        }

        // Remove Last Digit and Repeat

        Card_Number /= 10;
    }

    // Add Odd and Even Digits Together

    Total_Digit_Sum = Even_Digits + Odd_Digits;

// Loop to Check if Card Number is Valid

    if (Total_Digit_Sum % 10 == 0)
     {
        // Check Mastercard

        if (Digit_Number == 16)
        {
            if (Digits_MstrCrd <= 55 && Digits_MstrCrd >= 51)
            {
                printf("MASTERCARD\n");
            }

            // Check Visa 16

            else if (Digits_Visa_16 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        // Check American Express

        else if (Digit_Number == 15)
        {
            if (Digits_AmEx == 34 || Digits_AmEx == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        // Check Visa 13

        else if (Digit_Number == 13)
        {
            if (Digits_Visa_13 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
}