#include <iostream>
#include <vector>

using namespace std;

int main() {
    int width, height;
    cin >> width >> height;
    
    vector<vector<int>> grid(height, vector<int>(width, 0));
    
    int apple_x, apple_y;
    cin >> apple_x >> apple_y;
    grid[apple_y][apple_x] = 5;
    
    int num_snakes;
    cin >> num_snakes;
    
    for (int i = 0; i < num_snakes; i++) {
        int snake_id = i + 1;
        int hx, hy, bx, by, tx, ty;
        cin >> hx >> hy >> bx >> by >> tx >> ty;
        
        grid[hy][hx] = snake_id;
        grid[by][bx] = snake_id;
        grid[ty][tx] = snake_id;
    }
    
    for (int k = 0; k < height; k++) {
        for (int c = 0; c < width; c++) {
            cout << grid[k][c];
            if (c < (width - 1)) {
                cout << " ";
            }
        }
       
    }
    
    return 0;
}
