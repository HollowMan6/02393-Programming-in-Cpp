#include <iostream>
using namespace std;

typedef enum { wood, stone } material;

struct tile {
    int x, y;
    bool isWall;
    material type;
};

void displayPlayground(tile** playground, int n, int m, int x, int y) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
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
    int n, m;
    cin >> n >> m;

    tile** playground = new tile*[n];
    for (int i = 0; i < n; i++) {
        playground[i] = new tile[m];
    }

    int x = m / 2;
    int y = n / 2;  // Initial player position

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            playground[i][j].x = j;
            playground[i][j].y = i;
            playground[i][j].isWall = (j == 0 || i == (n - 1) ||
                                       (i == 0 && j != m / 3) || j == (m - 1));
            if (playground[i][j].isWall) {
                playground[i][j].type = stone;
            } else {
                playground[i][j].type = wood;
            }
        }
    }

    char command;
    displayPlayground(playground, n, m, x, y);
    while (cin >> command && command != 'q') {
        int newX = x, newY = y;
        if (command == 'l' && x > 0 && !playground[y][x - 1].isWall) {
            newX--;
        } else if (command == 'r' && x < m - 1 &&
                   !playground[y][x + 1].isWall) {
            newX++;
        } else if (command == 'u' && y > 0 && !playground[y - 1][x].isWall) {
            newY--;
        } else if (command == 'd' && y < n - 1 &&
                   !playground[y + 1][x].isWall) {
            newY++;
        }

        displayPlayground(playground, n, m, newX, newY);
        x = newX;
        y = newY;
    }

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        delete[] playground[i];
    }
    delete[] playground;

    return 0;
}
