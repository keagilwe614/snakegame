#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int width, height;
    cin >> width >> height;
    
    vector<vector<int>> grid(height, vector<int>(width, 0));
    
    int fruitX, fruitY;
    cin >> fruitX >> fruitY;
    grid[fruitY][fruitX] = 5;
    
    int nSnakes;
    cin >> nSnakes;
    
    int x = 0, y = 0;
    
    for (int i = 0; i < nSnakes; i++) {
        int snake_id = i + 1;
        int hx, hy, bx, by, tx, ty;
        cin >> hx >> hy >> bx >> by >> tx >> ty;
        
        grid[hy][hx] = snake_id;
        grid[by][bx] = snake_id;
        grid[ty][tx] = snake_id;
        
        if (i == 0) {
            x = hx;
            y = hy;
        }
    }
    
    string moves[] = {"DOWN", "LEFT", "RIGHT", "UP"};
    vector<string> best_moves;
    double min_distance = 1e9;
    
    for (int i = 0; i < 4; i++) {
        int nextX = x;
        int nextY = y;
        string dir = moves[i];
        
        if (dir == "LEFT") nextX--;
        else if (dir == "RIGHT") nextX++;
        else if (dir == "UP") nextY--;
        else if (dir == "DOWN") nextY++;
        
        if (nextX >= width || nextX < 0 || nextY >= height || nextY < 0) {
            continue;
        }
        
        if (grid[nextY][nextX] != 0 && grid[nextY][nextX] != 5) {
            continue;
        }
        
        double distance = sqrt(pow(nextX - fruitX, 2) + pow(nextY - fruitY, 2));
        
        if (distance < min_distance) {
            min_distance = distance;
            best_moves.clear();
            best_moves.push_back(dir);
        } else if (abs(distance - min_distance) < 1e-9) {
            best_moves.push_back(dir);
        }
    }
    
    for (int i = 0; i < best_moves.size(); i++) {
        cout << best_moves[i] << "\n";
    }
    
    return 0;
}
