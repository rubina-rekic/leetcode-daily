using namespace std;
#include <vector>

class Solution {
public:
    bool findRotation(vector<vector<int> >& mat, vector<vector<int> >& target) {

        int n = mat.size();

        bool identical = true;

        for(int i=0; i<n; i++){
            for(int j=0;j<n; j++){
                if(mat[i][j]!= target[i][j])
                {identical = false; break;}

            }
        }

        bool clockwise90 = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[j][n - i - 1]){
                    clockwise90 = false;
                break;}
                if (!clockwise90) break;
            }
        }

        bool anticlockwise90 = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[n - j - 1][i]){
                    anticlockwise90 = false;
                break;}
                if (!anticlockwise90) break;
            }
        }

        bool anticlockwise180 = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[n - i - 1][n - j - 1]){
                    anticlockwise180 = false;
                break;}
                if (!anticlockwise180) break;
            }
        }

        return identical || clockwise90 || anticlockwise90 || anticlockwise180;
    }
};