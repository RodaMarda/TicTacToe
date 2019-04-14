//
//  player.c 
//  TicTacToe
//
//  Created by Rodaina Mardawy on 13.04.19.
//  Copyright © 2019 Rodaina Mardawy. All rights reserved.
//

#include "player.h"

char game [3][3];
char player;
// char gamePosition[]="-.-.+....";
char* gamePosition="-.-.+....";

void playGame (void){
    /*for (int i=0; i<9; i++) {
        displayBox(i, *(gamePosition+i));
    };*/
    int bnr;
    bnr = getBoxNumber();
    displayBox(bnr, '*');
}

