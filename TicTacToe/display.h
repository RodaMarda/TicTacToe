//
//  display.h 
//  TicTacToe
//
//  Created by Rodaina Mardawy on 13.04.19.
//  Copyright © 2019 Rodaina Mardawy. All rights reserved.
//

#ifndef display_h
#define display_h

#include <stdio.h>
#include "conio4mac.h" // conio4mac 
// set flag -lncurses in PROJECT -> build settings -> other linker flags to avoid linker issues

void setUp_display (void);
void displayBox (int boxNumber, char playerValue);


#endif /* display_h */
