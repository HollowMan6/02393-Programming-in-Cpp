#include <iostream>
using namespace std;

typedef enum { wood, stone } material;

struct tile {
    int x, y;
    bool isWall;
    material type;
};

#define NROWS 12
#define NCOLS 16

void displayPlayground(tile playground[NROWS][NCOLS], int x, int y) {
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            if (i == y && j == x) {
                cout << "O";
            } else if (playground[i][j].isWall) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    tile playground[NROWS][NCOLS];
    int x = 5, y = 5;  // Initial player position

    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            playground[i][j].x = j;
            playground[i][j].y = i;
            playground[i][j].isWall = (j == 0 || i == (NROWS - 1) ||
                                       (i == 0 && j != 3) || j == (NCOLS - 1));
            if (playground[i][j].isWall) {
                playground[i][j].type = stone;
            } else {
                playground[i][j].type = wood;
            }
        }
    }

    char command;
    while (cin >> command && command != 'q') {
        int newX = x, newY = y;
        if (command == 'l' && x > 0 && !playground[y][x - 1].isWall) {
            newX--;
        } else if (command == 'r' && x < NCOLS - 1 &&
                   !playground[y][x + 1].isWall) {
            newX++;
        } else if (command == 'u' && y > 0 && !playground[y - 1][x].isWall) {
            newY--;
        } else if (command == 'd' && y < NROWS - 1 &&
                   !playground[y + 1][x].isWall) {
            newY++;
        }

        displayPlayground(playground, newX, newY);
        x = newX;
        y = newY;
    }

    return 0;
}
