#include <stdio.h>
#include <string.h>

// Function to credit card valid or not using the Luhn algorithm
int is_valid(char *card)
{

    int n, sum, i;

    //sum the digits, taking them two at a time from the right
    for (i = strlen(card) - 1, sum = 0; i >= 0; i -= 2)
    {
        sum += (card[i] - '0');
    }

    //sum the digits, taking them two at a time from the right and multiplying by 2
    for (i = strlen(card) - 2; i >= 0; i -= 2)
    {
        n = 2 * (card[i] - '0');
        sum += (n / 10) + (n % 10);
    }

    // If %10==0 valid else not
    return sum % 10 == 0;
}

int main(void)
{
    char card[20];

    //get user input credit card number
    printf("Enter a credit card number: ");
    scanf("%s", card);

    //Check card is valid
    if (is_valid(card))
    {
        printf("Valid credit card just not AMEX/MC/VISA\n");
        //Check credit card type
        if (strlen(card) == 15 && (card[0] == '3' && (card[1] == '4' || card[1] == '7')))
        {
            printf("Type: AMEX\n");
        }
        else if (strlen(card) == 16 && (card[0] == '5' && (card[1] >= '1' && card[1] <= '5')))
        {
            printf("Type: MASTERCARD\n");
        }
        else if ((strlen(card) == 13 || strlen(card) == 16) && card[0] == '4')
        {
            printf("Type: VISA\n");
        }
        else
        {
            printf("Type: INVALID\n");
        }
    }
    else
    {
        printf("INVALID credit card\n");
    }

    return 0;
}
