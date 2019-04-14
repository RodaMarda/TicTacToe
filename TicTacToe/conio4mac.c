//
//  conio4mac.c 
//  ncurses_Patrick
//
//  Created by Patrick Workspace on 21.02.19.
//  Copyright © 2019 Patrick Workspace. All rights reserved.
//


#include <stdio.h>
#include "conio4mac.h"

typedef struct
{
    int     xup;
    int     yup;
    int     xdown;
    int     ydown;
    WINDOW*    okno;
} Okno;

bool    zainicjowane = FALSE; //czy juz po initscr() ?
int    znakSpecjalny = -1; //potrzebne do getch'a
int    n = 0; //liczba uzytych okienek

short    kolorTekstu = COLOR_WHITE;
short    kolorTla = COLOR_BLACK;
short    biezacaPara;

Okno    okienka[MAX_OKIEN];    //tablica struktur aktywnych okienek
WINDOW*    aktywneOkno = NULL;    //wsk na aktywne okno


int (* wsk_f)(void) = getch;

// ----------------------------- koniec globalnych ------------

void inicjuj()
{
    initscr();
    start_color(); //wlaczmy kolorki
    cbreak(); //wylaczmy buforowanie wejscia
    noecho(); //bez wyswietlania na ekran
    //raw(); //nadpisywane i tak przez noecho
    keypad(stdscr, TRUE);
    scrollok(stdscr, TRUE);
    
    //domyslne okno
    aktywneOkno = stdscr;
    zainicjowane = TRUE;
    
    //utworzmy macierz 8x8 kolorow tla i tekstu
    short kolor = 1;
    for(short i=0; i<8; i++)
    {
        for(short j=0; j<8; j++, kolor++)
        {
            init_pair(kolor,i,j);
            if(i == COLOR_WHITE && j == COLOR_BLACK)
                //ustawmy czarne tlo i bialey tekst jako standard
            {
                biezacaPara = kolor;
            }
        }
    }
    
    wrefresh(aktywneOkno);
}

int simple_strlen(char* str)
{
    char* p;
    for(p = str; *p != 0; p++);
    return (int) (p-str);
}

void cputs(char* str)
{
    waddstr(aktywneOkno, str);
    wrefresh(aktywneOkno);
}

char* cgets(char* str)
{
    // nie wiem dokladnie jak dziala orginalna f. cgets bo nie mam do niej referencji..
    // I do not know exactly how the original f. cgets works because I do not have references to it ...
    if(str == NULL || *str == 0)
    {
        *(str+1) = 0;
        return NULL;
    }
    
    int max = (int)(*str);
    
    echo();
    
    if(wgetnstr(aktywneOkno, (str + 2), max) == ERR)
    {
        *(str+1) = 0;
        return NULL;
    }
    
    noecho();
    
    *(str+1) = (char)simple_strlen(str+2);
    
    return str+2;
}

void clreol()
{
    wclrtoeol(aktywneOkno);
    wrefresh(aktywneOkno);
}

void clrscr()
{
    if(!zainicjowane) inicjuj();
    wbkgd(aktywneOkno, COLOR_PAIR(biezacaPara));
    //trzeba przesunac kursor? chyba nie...
    wclear(aktywneOkno);
}

int cprintf(char *fmt, ...)
// czysty hardcore ;-)
{
    if(!zainicjowane) inicjuj();
    
    va_list ap;
    va_start(ap, fmt);
    
    int i = vwprintw(aktywneOkno,fmt, ap);    //jakie proste ;-)
    
    va_end(ap);
    
    wrefresh(aktywneOkno);
    
    return i;
}

int cscanf(char *fmt, ...)
{
    if(!zainicjowane) inicjuj();
    
    echo();
    
    va_list ap;
    va_start(ap, fmt);
    
    int i = vwscanw(aktywneOkno, fmt, ap);
    
    va_end(ap);
    
    wrefresh(aktywneOkno);
    noecho();
    
    return i;
}

int CURSgetch()
{
    if(!zainicjowane) inicjuj();
    
    int znak;
    
    if(znakSpecjalny>0) //drugi czlon znaku specjalnego 0x00 i 0x??
    {
        //zamieniamy znak na kod DOSowy - conio.h
        znak = znakSpecjalny;
        znakSpecjalny = -1;
        
        return znak-265+59;
    }
    
    znak = wgetch(aktywneOkno);
    
    if(znak > 255) //to mamy znak specjalny 0x00
    {
        znakSpecjalny = znak;
        return 0;
    }
    
    return znak;
}

int CURSgetche()
{
    echo();
    int znak = getch();
    noecho();
    return znak;
}

int gotoxy(int x, int y)
{
    if(!zainicjowane) inicjuj();
    wmove(aktywneOkno, y - 1, x - 1);
    return 0;
}

int kbhit()
{
    int znak;
    wtimeout(aktywneOkno, 0);
    znak = wgetch(aktywneOkno);
    //wtimeout(aktywneOkno, -1);
    nodelay(aktywneOkno, FALSE);
    if (znak == ERR) return 0;
    ungetch(znak);
    return 1;
}

int putch(int znak)
{
    wechochar(aktywneOkno,znak);
    return 0; // $ Patrick line included
}

void textbackground(short kolor)
{
    if(!zainicjowane) inicjuj();
    kolorTla = kolor%8;
    short k=1;
    for(short i=0; i<8; i++) //wyszukajmy numer pary dla kolorow
    {
        for(short j=0; j<8; j++, k++)
        {
            if(kolorTekstu == i && kolorTla == j)
            {
                biezacaPara = k;
                wbkgd(aktywneOkno, COLOR_PAIR(k));
            }
        }
    }
    
    wrefresh(aktywneOkno);
}

void textcolor(short kolor)
{
    if(!zainicjowane) inicjuj();
    kolorTekstu = kolor%8;
    
    short k=1;
    for(short i=0; i<8; i++) //wyszukajmy numer pary dla kolorow
    {
        for(short j=0; j<8; j++, k++)
        {
            if(kolorTekstu == i && kolorTla == j)
            {
                biezacaPara = k;
                wcolor_set(aktywneOkno,k, NULL);
            }
        }
    }
    
    wrefresh(aktywneOkno);
}

int wherex(void)
{
    if(!zainicjowane) inicjuj();
    int x, y;
    getyx(aktywneOkno, y, x);
    return x + 1;
}

int wherey(void)
{
    if(!zainicjowane) inicjuj();
    int x, y;
    getyx(aktywneOkno, y, x);
    return y + 1;
}

void window(int xup, int yup, int xdown, int ydown)
{
    if( xup<1 || yup<1 || xdown>COLS || ydown>LINES)
    { //jesli zle dane podano...
        xdown = COLS - xup;
        ydown = LINES - yup;
        //return;
    }
    
    bool istnieje = FALSE;
    
    if(!zainicjowane) inicjuj();
    
    /*
     Istnieje alternatywne rozwiazanie tworzenia nowych okien,
     w momencie tworzenia nowego okna, usuwa sie okno poprzednie,
     tzn zwalnia pamiec tego okna, komenda delwin(nzw_okna) i tworzy
     sie nowe okno, ustawiajac jego jako domyslne-biezace. Jednak
     poniewaz moze to zabierac za duzo czasu i niepotrzebnie spowolniac,
     majac na uwadze rozmiar dzisiejszych pamieci, postanowilem, uzyc
     tablicy, ktora przechowywuje wsk. na adresy okien i wykorzystuje
     zaalokowana juz przestrzen. Aczkolwiek mozna to w kazdej chwili zmienic.
     */
    
    /*
     There is an alternative solution for creating new windows,
     when the new window is created, the previous window is removed,
     ie it frees the memory of this window, delwin (nzw_okna) command and creates
     new window, setting it as default-current. But
     because it can take too much time and unnecessarily slow down,
     bearing in mind the size of present memories, I decided to use
     an array that stores wsk. to window addresses and uses
     space already allocated. However, you can change it at any time.
     */
    
    for(int i=0; i<n && !istnieje; i++) //sprawdzimy czy podane okno juz nie
        // zostalo wczesniej stworzone
    {
        if( okienka[i].xup == xup && okienka[i].yup == yup
           && okienka[i].xdown == xdown && okienka[i].ydown == ydown)
        {
            aktywneOkno = okienka[i].okno;
            istnieje = TRUE;
            clrscr();
        }
    }
    
    if(!istnieje && n < MAX_OKIEN) //jesli nie ma takiego okna to tworzymy je
    {
        aktywneOkno = newwin(ydown - yup + 1, xdown - xup + 1, yup - 1, xup - 1);
        //nie dam glowy czy dokladnie tak wyswietla conio.h
        
        //do tablicy zapisac...
        okienka[n].okno = aktywneOkno;
        okienka[n].xup = xup;
        okienka[n].yup = yup;
        okienka[n].xdown = xdown;
        okienka[n].ydown = ydown;
        
        wcolor_set(aktywneOkno,biezacaPara, NULL);
        wbkgd(aktywneOkno, COLOR_PAIR(biezacaPara));
        
        //przywrocenie ustawien klawiszy
        cbreak(); //wylaczmy buforowanie wejscia
        noecho(); //bez wyswietlania na ekran
        keypad(aktywneOkno, TRUE); //pelne kody klawiszy
        scrollok(aktywneOkno, TRUE);
        
        n++;
    }
    
    wrefresh(aktywneOkno);
    
    return;
}



