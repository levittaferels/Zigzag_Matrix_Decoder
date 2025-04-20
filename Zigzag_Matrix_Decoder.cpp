#include <iostream>
#include <vector>
#include <string>
using namespace std;

// matrix size rows*cols zig-zag diag order from a str
vector<vector<char>> decodeZigZagToMatrix(const string& input, int rows, int cols) {
    vector<vector<char>> mat(rows, vector<char>(cols, ' '));
    int idx = 0;
    int total = rows + cols - 1;

    for (int d = 0; d < total; ++d) {
        int r, c;
        if (d % 2 == 0) {
            r = (d < rows) ? d : rows - 1;
            c = d - r;
            while (r >= 0 && c < cols && idx < input.size()) {
                mat[r][c] = input[idx++];
                --r;
                ++c;
            }
        } else {
            c = (d < cols) ? d : cols - 1;
            r = d - c;
            while (c >= 0 && r < rows && idx < input.size()) {
                mat[r][c] = input[idx++];
                ++r;
                --c;
            }
        }
    }

    return mat;
}

string readMatrixColumnWise(const vector<vector<char>>& mat) {
    string result;
    int rows = mat.size();
    int cols = mat[0].size();
    for (int col = 0; col < cols; ++col) {
        for (int row = 0; row < rows; ++row) {
            char ch = mat[row][col];
            if (ch != '*') result += ch;
        }
    }
    return result;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    cin.ignore();

    string data;
    getline(cin, data); 

    if (data.length() != rows * cols) {
        cout << "[encrypted length error]" << endl;
        return 0;
    }

    vector<vector<char>> mat = decodeZigZagToMatrix(data, rows, cols);

    /*Print matrix row by row
    for (const auto& row : mat) {
        for (char ch : row) {
            cout << ch;
        }
        cout << endl;
    } */
   
    string sentence = readMatrixColumnWise(mat);
    cout << sentence << endl;

    return 0;
}
