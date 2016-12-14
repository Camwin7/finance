#pragma comment(lib, "C:/Users/Cameron/Documents/Programming/C++/Finance/Finance")
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "curses.h"

const int WIDTH = 80;
const int HEIGHT = 25;
const int PROMPT_WIDTH = WIDTH;
const int PROMPT_HEIGHT = 4;
const int INPUT_HEIGHT = 3;
const int INPUT_WIDTH = WIDTH;
const int LIST_HEIGHT = HEIGHT - PROMPT_HEIGHT - INPUT_HEIGHT;
const int LIST_WIDTH = WIDTH;

std::string getInput(WINDOW* win, int y, int x) {
    char str[20] = "";
    echo();
    curs_set(1);
    wmove(win, y, x);
    wgetstr(win, str);
    noecho();
    curs_set(0);
    return str;
}

int main() {
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    
    WINDOW* win_prompt = newwin(0, 0, PROMPT_HEIGHT, PROMPT_WIDTH);
    WINDOW* win_list = newwin(0, 0, LIST_HEIGHT, LIST_WIDTH);
    WINDOW* win_input = newwin(0, 0, INPUT_HEIGHT, INPUT_WIDTH);

    box(win_prompt, 0, 0);
    box(win_list, 0, 0);
    box(win_input, 0, 0);

    wrefresh(win_prompt);
    wrefresh(win_list);
    wrefresh(win_input);

    wgetch(win_input);

    return 0;
}

// IMPORTANT: Read is pronounced like lead, but read is pronounced like lead.