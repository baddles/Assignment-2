// HELP I DONT EVEN KNOW WHAT THE HECK DID I WROTE IN THIS PROGRAM BY THIS POINT ANYMORE.
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cstdlib>
#define DEBUG 0 // Debug mode, 0 = off, 1 = on, other value would just be equal to 0.
#define GRID_WIDTH 10 // Define grid width (horizontal). This program uses j as width. Max is 10.
#define GRID_LENGTH 10 // Define grid length (vertical). This program uses i as length. Max is 10.
#define REQUIREMENT 10 // Value should be in percentage, e.g. 10% 20% 30%.
struct matrix { // This matrix struct is just used for get_ij function.
    int length; // i
    int width; // j
}; // get_ij function is to get number of widths and lengths from a given number.
// More explanation is in the function itself.

namespace Color { // This is here for output format, so toggled pixels can be viewed more clearly.
// SOURCE: https://stackoverflow.com/a/17469726 & https://misc.flogisoft.com/bash/tip_colors_and_formatting#colors
    enum Code {
        FG_DEFAULT          = 39,
        FG_BLACK            = 30,
        FG_RED              = 31,
        FG_GREEN            = 32,
        FG_YELLOW           = 33,
        FG_BLUE             = 34,
        FG_MAGENTA          = 35,
        FG_CYAN             = 36,
        FG_LIGHTGRAY        = 37,
        FG_DARKGRAY         = 90,
        FG_LIGHTRED         = 91,
        FG_LIGHTGREEN       = 92,
        FG_LIGHTYELLOW      = 93,
        FG_LIGHTBLUE        = 94,
        FG_LIGHTMAGENTA     = 95,
        FG_LIGHTCYAN        = 96,
        FG_WHITE            = 97,
        BG_DEFAULT          = 49,
        BG_BLACK            = 40,
        BG_RED              = 41,
        BG_GREEN            = 42,
        BG_YELLOW           = 43,
        BG_BLUE             = 44,
        BG_MAGENTA          = 45,
        BG_CYAN             = 46,
        BG_LIGHTGRAY        = 47,
        BG_DARKGRAY         = 100,
        BG_LIGHTRED         = 101,
        BG_LIGHTGREEN       = 102,
        BG_LIGHTYELLOW      = 103,
        BG_LIGHTBLUE        = 104,
        BG_LIGHTMAGENTA     = 105,
        BG_LIGHTCYAN        = 106,
        BG_WHITE            = 107,
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
} // The use of this namespace is in grid().

void grid(int[GRID_LENGTH][GRID_WIDTH]);


int main(int argc, const char* argv[])
{
    int a[GRID_LENGTH][GRID_WIDTH];
    for (int i = 0; i < GRID_LENGTH; i++)
        for (int j = 0; j < GRID_WIDTH; j++)
            a[i][j] = 0; // Init.
        std::string intepret = argv[1];
            int i = 0, j = 0;
            for (int si = 0; si < intepret.size(); si++) {
                if (intepret[si] == ',') {
                    j++;
                    if (j == GRID_WIDTH) {
                        i++;
                        j = 0;
                    }
                }
                else if (intepret[si] != ' ')
                    a[i][j] = intepret[si] - '0';
            }
            std::cout<<"Intepretation complete."<<std::endl;
            std::string bitflip = argv[2];
            if (bitflip[bitflip.size() - 1] != ' ')
                bitflip += " ";
            std::string px = "";
            std::set<int> s;
            for (int l = 0; l < bitflip.size(); l++) {
                if (bitflip[l] == ' ') {
                    s.insert(std::stoi(px));
                    px = "";
                }
                else px += bitflip[l];
            }
            if (s.size() != REQUIREMENT) {
                std::cout<<"Warning: not enough bits to flip to fit requirement!";
            }
            else {
                for (std::set<int>::iterator tmp = s.begin(); tmp != s.end(); tmp++) {
                int i = 0; j = *tmp % 10;
                    if (*tmp / 10 % 10 != 0)
                        i = *tmp / 10 % 10;
                    (a[i][j] == 0) ? a[i][j] = 1 : a[i][j] = 0;
            }
                    grid(a);
                for (int i = 0; i < GRID_LENGTH; i++)
        for (int j = 0; j < GRID_WIDTH; j++)
            std::cout<<a[i][j]<<", ";
            }
            return 0;
        }

        void grid(int a[GRID_LENGTH][GRID_WIDTH]) {
    Color::Modifier red(Color::FG_LIGHTCYAN);
    Color::Modifier def(Color::FG_DEFAULT);
    std::cout<<def<<"  ";
    for (int j = 0; j < GRID_WIDTH; j++) {
        std::cout<<j<<" ";
    }
    std::cout<<std::endl;
    for (int i = 0; i < GRID_LENGTH; i++) {
        std::cout<<i<<" ";
        for (int j = 0; j < GRID_WIDTH; j++) {
            if (a[i][j] == 0)
                std::cout<<def<<"- ";
            else std::cout<<red<<"* ";
        }
        std::cout<<def<<std::endl;
    }
}