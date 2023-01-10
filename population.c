#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int startSize, endSize;
    // TODO: Prompt for start size
    do
    {
        printf("Enter the starting population size: ");
        scanf("%d", &startSize);
    }
    while (startSize < 9);

    // TODO: Prompt for end size
    do
    {
        printf("Enter the ending population size: ");
        scanf("%d", &endSize);
    }
    while (endSize < startSize);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    while (startSize < endSize)
    {
        int births = startSize / 3;
        int deaths = startSize / 4;
        startSize += births - deaths;
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}
