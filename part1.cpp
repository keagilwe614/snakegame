#include <iostream>
#include <vector>

using namespace std;

int main(){
  int width; 
  int height;
  cin >> width >> height;
  vector<vector<int>> grid(height,vector<int>(width,0));
  
  for (int i=0;i<height;++i){
    for (int j=0;j<width;++j){
        cout<<grid[i][j];
        if (j < width-1){
          cout <<" ";
        }
    }
    cout <<"\n";
  }
  return 0;
}
  
