#include <cs50.h>
#include <stdio.h>

void print_hashes(int l);
void build_pyramid(int h);
int height;

int main(void)
{
    do
    {
        printf("Height: ");
        height = get_int();
    }
    while (height < 0 || height > 23);
    build_pyramid(height);
}

void build_pyramid(int h)
{
    for (int i = 0; i < h; i++)
    {
        
        //print spaces
        for (int s = 0; s < h - i - 1; s++)
        {
            printf(" ");
        }
        
        //print hashes
        print_hashes(i + 1);
        
        //gap
        printf("  ");
        
        //print hashes
        print_hashes(i + 1);
        
        //new line
        printf("\n");
    }
}

void print_hashes(int l)
{
    for (int i = 0; i < l; i++)
    {
        printf("#");
    }
}