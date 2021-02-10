#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    
    long Card;

    do {
         Card = get_long ("Number : ");
    } while (Card <= 0);
    
    int card_length = (int)log10(Card)+1;
    int first_two = (int)(Card / pow(10, (int)log10(Card)-1));

    
    long card_number_copy = Card;
    int sum_double_digits = 0;
    int sum_other_digits = 0;
    
    // checksum : first part.
    while (card_number_copy >0)
    {
        //sum of the numbers not multiplied by 2.
        sum_other_digits += card_number_copy % 10;
        card_number_copy /= 10;
        
        //sum of the digits multiplied by 2.
        sum_double_digits += ((card_number_copy % 10) * 2) % 10;
        sum_double_digits += ((card_number_copy % 10) * 2) / 10;
        
        card_number_copy /= 10;

    }
    
    sum_double_digits += sum_other_digits;
    
    if (sum_double_digits % 10 != 0) 
    {
        printf("INVALID\n");
        return 0;
    }
    
    if ((first_two == 34 || first_two == 37) && card_length == 15){
        printf("AMEX\n");
    } else if ((first_two >=51 && first_two <= 55) && card_length == 16)
    {
        printf("MASTERCARD\n");
    }else if ((first_two/10 == 4 )&& (card_length == 13 || card_length == 16))
    {
        printf("VISA\n");
    } else {
        printf("INVALID\n");
    }
    
    
    
}