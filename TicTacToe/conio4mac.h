#ifndef __CONIO4MAC_H
#define __CONIO4MAC_H

// $$ PATRICK included
#define printf  cprintf      // $$$ PATRICK 
#define gets    cgets        // $$$ PATRICK
//#define getsch  CURSgetch    // $$$ PATRICK
//#define getsche CURSgetche   // $$$ PATRICK

// $$ PATRICK begin of declaration
void inicjuj(void);
int  simple_strlen(char* str);
void cputs(char* str);
char* cgets(char* str);
void clreol(void);
void clrscr(void);
int  cprintf(char *fmt, ...);
int  cscanf(char *fmt, ...);
int  CURSgetch(void);
int  CURSgetche(void);
int  gotoxy(int x, int y);
int  kbhit(void);
int  putch(int znak);
void textbackground(short kolor);
void textcolor(short kolor);
int  wherex(void);
int  wherey(void);
void window(int xup, int yup, int xdown, int ydown);
// $$ PATRICK end of declaration

// Copyright (C) 2005  by Piotr He³ka (piotr.helka@nd.e-wro.pl)
// Linux C++ (not full) implementation of Borland's conio.h 
// v 1.01
// It uses Ncurses lib, so accept also its terms.

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

// ----------------------------- krotki opis ------------------

// Biblioteka obs³uguje mniej lub bardziej zgodnie:
//
//      cgets()
//      cputs()
//      clreol()
//      clrscr()
//      cprintf()
//      cscanf()
// getch()  (chyba nie wszystkie kody tak jak w conio.h)
//          (probably not all codes like in conio.h)
// getche()  
//      gotoxy()
//      kbhit()
//      putch()
//      textbackground()
//      textcolor()
//      wherex()
//      wherey()
//      window()


// kompatbyilno¶æ w kierunku Linux CONIO.H -> DOS CONIO.H
// bedzie zachowana

// Aby skompilowac
// $g++ nazwa_progsa.cpp -lncurses -o nazwa_progsa.o

// ------------------------------- define ---------------------

#ifndef __NCURSES_H
#include <ncurses.h>
#define __NCURSES_H
#endif /* __NCURSES_H */

#define MAX_OKIEN 256

/**
 * Colors which you can use in your application. $$ NOK
 */

#define BLACK       0
#define RED         1
#define GREEN       2
#define BROWN       3
#define BLUE        4
#define MAGENTA     5
#define CYAN        6
#define LIGHTGRAY   7

// below not quite ok ; -) same as above $$ PATRICK
#define DARKGRAY    0
#define LIGHTRED    1
#define LIGHTGREEN  2
#define YELLOW      3
#define LIGHTBLUE   4
#define PINK        5
#define LIGHTCYAN   6
#define WHITE       7

// -------------------------------- globalne ------------------

#undef getch
#define getch CURSgetch

#undef getche
#define getche CURSgetche


/* $ Patrick removed: it's not C ;-)
class Startuj   // konstruktor i destruktor klasy beda odpowiedzalni
{	public:     // za automagiczna inicjalizacje ustawien ;-)
	Startuj(){ inicjuj(); }
	~Startuj(){ endwin(); }
} Start;	    			// inicjuj!
*/







#endif /* __CONIO4MAC_H */
