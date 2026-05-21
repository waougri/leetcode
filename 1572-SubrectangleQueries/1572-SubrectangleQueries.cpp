// Last updated: 5/20/2026, 11:36:17 PM
#include <vector>
using std::vector;


class SubrectangleQueries {
    vector<vector<int>> rec;
public:

    SubrectangleQueries(vector<vector<int>>& rectangle) {
        this->rec = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
       for(int i = row1; i < row2 + 1; i++) {
        for(int j = col1; j < col2 + 1; j++){
            this->rec[i][j] = newValue;
        }
       } 
    }
    
    int getValue(int row, int col) {
       return this->rec[row][col];
    }
};
