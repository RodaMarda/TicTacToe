//
//  keyboard.c
//  TicTacToe
//
//  Created by Rodaina Mardawy on 13.04.19.
//  Copyright © 2019 Rodaina Mardawy. All rights reserved.
//

#include "keyboard.h"

char readKey (void) {
    char ch;
    
    if(kbhit())
    {
        ch = getch();
        if(ch == '1');
        gotoxy (5,12); cprintf("%c",ch);
    } // conio4mac
     return (ch);
}

int getBoxNumber (void) {
    char c;
    c = getch();
    //c = readKey();
    return (c-'0');
}
