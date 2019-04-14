//
//  display.c
//  TicTacToe
//
//  Created by Rodaina Mardawy on 13.04.19.
//  Copyright © 2019 Rodaina Mardawy. All rights reserved.
//

#include "display.h" 

int x_pos [9];
int y_pos [9];

void setUp_display (void) {
    for (int i = 0; i <9; i++) {
        int x, y;
        x=5+(i%3);
        y=5+(i/3);
        x_pos [i] = x;
        y_pos [i] = y;
    };
}

void displayBox (int boxNumber, char playerValue) {
    gotoxy(x_pos[boxNumber], y_pos[boxNumber]);
        cprintf("%c", playerValue);
};
