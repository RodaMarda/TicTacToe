//
//  main.c
//  Lesson2
// 
//  Created by Rodaina Mardawy on 04.09.18.
//  Copyright © 2018 Rodaina Mardawy. All rights reserved.
//

//
//  roda_patrick_tictactoe.c
//  ncurses_Patrick
//
//  Created by Patrick Workspace on 23.02.19.
//  Copyright © 2019 Patrick Workspace. All rights reserved.
//

#include "roda_patrick_tictactoe.h"
/*
 Hallo Roda, il faut écrire:
 scanf("%c %c%c", &line, &column, &lf); // Patrick
 
 Au lieu de
 scanf("%c %c%c", &line, &column); // Patrick
 Avec les initializations nécessaires.
*/

#include <stdio.h>

char toto [3][3];

//definitions

void displayGame (void)
{
    printf ("  1 2 3\n");
    for (int line = 0; line<3; line++)
    {
        if (line == 0) printf("A ");
        if (line == 1) printf("B ");
        if (line == 2) printf("C ");
        for (int column =0; column<3; column++)
        {
            printf ("%c ", toto[line][column]);
        }
        printf("\n");
    }
    printf("\n");
    
} /*displayGame*/

void initGame ()
{
    toto[0][0]='-';
    toto[0][1]='o';
    toto[0][2]='-';
    toto[1][0]='x';
    toto[1][1]='-';
    toto[1][2]='-';
    toto[2][0]='o';
    toto[2][1]='-';
    toto[2][2]='x';
} /*initGame*/

void iPlay (void)
{
    char line, column, lf; // Patrick
    printf("hello!\nveuillez rentrer vos caractères: ");
    scanf("%c %c%c", &line, &column, &lf); // Patrick
    printf("\nligne %c \ncolonne %c \n\n", line, column);
    int i = 0,j = 0; // Patrick
    switch(line)
    {
        case'A':
            i=0;
            break;
        case'B':
            i=1;
            break;
        case'C':
            i=2;
            break;
        default:
            printf("c'est n'importe quoi! %c", line);
    }
    switch(column)
    {
        case'1':
            j=0;
            break;
        case'2':
            j=1;
            break;
        case'3':
            j=2;
            break;
        default:
            printf("c'est n'importe quoi! %c", column);
    }
    printf("i est égal à %d\nj est égal à %d\n\n",i,j);
    toto[i][j]='x';
} /*iPlay*/

int endOfGame (void)
{
    if(toto[0][0]=='x')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int roda_patrick_tictactoe (void)
{
    initGame();
    displayGame();
    while (!endOfGame()) // Patrick
    {
        iPlay();
        displayGame();
        // iPlay(); Patrick
        // displayGame(); Patrick
    }
    return 0;
}

