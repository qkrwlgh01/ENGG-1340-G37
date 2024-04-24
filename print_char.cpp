#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void correct_position(char correct_character) //printing right characters with right position, indicated by green colour
{
    printf("\033[32m[ "); 
    printf("\033[32m%c", correct_character);
    printf("\033[32m ]\033[0m");
}
void wrong_position(char wrong_position) //printing right characters with wrong position, indicated by yellow colour
{
    printf("\033[33m[ ");
    printf("\033[33m%c", wrong_position);
    printf("\033[33m ]\033[0m");
}
void wrong_character(char wrong_character) // printing normal tries
{
    printf("\033[0m[ ");
    printf("\033[0m%c", wrong_character);
    printf("\033[0m ]\033[0m");
}
