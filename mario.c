#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_pyramid(int height);

int main(void)
{
    //get size of pyramid
    int n = get_height();

    //print pyramid
    print_pyramid(n);
}


//method for getting height of pyramid
int get_height(void)
{
    //loop until given right parameter value
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8);
    return height;
}




//here's where we will build mario pyramid
//   #  #
//  ##  ##
// ###  ###
//####  ####
void print_pyramid(int height)
{
    int row;
    int spacer;
    int block;
    int rightBlock;

    //print each line of the pyramid as a new row
    for (row = 0; row < height; row++)
    {

        //print left spaces need to decrement since we are putting spaces on a negative side (or adding spaces)
        for (spacer = height - row - 1; spacer > 0; spacer--)
        {
            printf(" ");
        }
        //print left hashes
        for (block = 0; block < row + 1 > 0; block++)
        {
            printf("#");
        }
        //print gap
        printf("  ");

        //print right hashes
        for (rightBlock = 0; rightBlock < row + 1; rightBlock++)
        {
            printf("#");
        }
        printf("\n");
    }
}
