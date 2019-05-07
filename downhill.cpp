#include <iostream>
using namespace std;

int dy[4] = {0, 0, -1, +1};
int dx[4] = {-1, +1, 0, 0};

int height, width;
int numOfPath = 0;

bool visited[500][500] = {false,};
int map[500][500];

bool isInMap(int y, int x) {
    if ((y >= 0) && (y < height) && (x >= 0) && (x < width)) return true;
    else return false;
}

void move(int y, int x) {
    if ((y == height - 1) && (x == width - 1)) {
        numOfPath++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int neighborY = y + dy[i];
        int neighborX = x + dx[i];

        if (isInMap(neighborY, neighborX)) {
            if (!visited[neighborY][neighborX] && (map[y][x] > map[neighborY][neighborX])) {
                visited[neighborY][neighborX] = true;
                move(neighborY, neighborX);
                visited[neighborY][neighborX] = false;
            }
        }
    }
}

int main() {
    cin >> height >> width;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) cin >> map[i][j];
    }

    visited[0][0] = true;
    move(0, 0);

    cout << numOfPath;
}
