//
//  main.c
//  TicTacToe
//
//  Created by Rodaina Mardawy on 13.04.19.
//  Copyright © 2019 Rodaina Mardawy. All rights reserved.
//

#include <stdio.h>
#include "keyboard.h"
#include "player.h"
#include "display.h"
#include "storage.h"
#include "conio4mac.h" // conio4mac
// set flag -lncurses in PROJECT -> build settings -> other linker flags to avoid linker issues

int main(int argc, const char * argv[]) {
    
    printf ("\ntest");
    
//setUp
printf ("\nsetUp");
    inicjuj(); // conio4mac
    textbackground (WHITE); textcolor (BLACK); clrscr();
    setUp_display();
    
//loop
    printf ("\nloop");
   //int a=0;
    //int i=1;
    char key;
    do{
        key = readKey();
        playGame();
        
    } while (key != '0');
    
    endwin(); // conio4mac
    return 0;
}
