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
        
        int k;
        cin >> k;
        
        int current_x, current_y;
        cin >> current_x >> current_y;
        grid[current_y][current_x] = snake_id;
        
        for (int j = 1; j < k; j++) {
            int next_x, next_y;
            cin >> next_x >> next_y;
            
            if (current_x == next_x) {
                if (current_y < next_y) {
                    for (int y = current_y; y <= next_y; y++) {
                        grid[y][current_x] = snake_id;
                    }
                } else {
                    for (int y = current_y; y >= next_y; y--) {
                        grid[y][current_x] = snake_id;
                    }
                }
            } else if (current_y == next_y) {
                if (current_x < next_x) {
                    for (int x = current_x; x <= next_x; x++) {
                        grid[current_y][x] = snake_id;
                    }
                } else {
                    for (int x = current_x; x >= next_x; x--) {
                        grid[current_y][x] = snake_id;
                    }
                }
            }
            
            current_x = next_x;
            current_y = next_y;
        }
    }
    
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            cout << grid[r][c];
            if (c < width - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}
