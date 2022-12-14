vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        pascal.push_back({1});
        if(numRows==1){
            return pascal;
        }
        pascal.push_back({1,1});
        if(numRows==2){
            return pascal;
        }
        for(int i=2; i<numRows; i++){
            vector<int> row;
            row.push_back(1);
            for(int j=1; j<=i-1; j++){
                row.push_back(pascal[i-1][j-1]+pascal[i-1][j]);
            }
            row.push_back(1);
            pascal.push_back(row);
        }
        return pascal;
}
