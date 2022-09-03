//using dummy arrays for rows and columns
void setZeroes(vector<vector<int>> &matrix){
  int rows = matrix.size(), 
  int cols = matrix[0].size();
  vector <int> dummy1(rows,-1), dummy2(cols,-1);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == 0) {
        dummy1[i] = 0;
        dummy2[j] = 0;
      }
    }
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (dummy1[i] == 0 || dummy2[j]==0) {
        matrix[i][j] = 0;
      }
    }
  }
}

//Optimizing the dummy array approach
void setZeroes(vector<vector<int>> &matrix) {
  int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
  for (int i = 0; i < rows; i++) {
    //checking if 0 is present in the 0th column or not
    if (matrix[i][0] == 0) col0 = 0;
    for (int j = 1; j < cols; j++) {
      if (matrix[i][j] == 0) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }
  //traversing in the reverse direction and
  //checking if the row or col has 0 or not
  //and setting values of matrix accordingly.
  for (int i = rows - 1; i >= 0; i--) {
    for (int j = cols - 1; j >= 1; j--) {
      if (matrix[i][0] == 0 || matrix[0][j] == 0) {
        matrix[i][j] = 0;
      }
    }
    if (col0 == 0) {
      matrix[i][0] = 0;
    }
  }
}


//Using Sets
void setZeroes(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix[0].size();
        set<int> rows;
        set<int> cols;
        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                if(rows.count(i) || cols.count(j)){
                    matrix[i][j]=0;
                }
            }
        }
    }
