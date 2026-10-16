#include <iostream>
#include <vector>

using namespace std;

int main() {
    int width, height;
    if (!(cin >> width >> height)) return 0;

    int appleX, appleY;
    cin >> appleX >> appleY;

    int headX, headY, bodyX, bodyY, tailX, tailY;
    cin >> headX >> headY >> bodyX >> bodyY >> tailX >> tailY;

    vector<vector<int>> grid(height, vector<int>(width, 0));

    grid[appleY][appleX] = 5;

    grid[headY][headX] = 1;
    grid[bodyY][bodyX] = 1;
    grid[tailY][tailX] = 1;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << grid[i][j];
            if (j < width - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
