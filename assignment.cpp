#include <bits/stdc++.h>
using namespace std;

void rowoperation(vector<vector<int>>& cost, int n) {
    for (int i = 0; i < n; i++) {
        int mini = INT_MAX;
        for (int j = 0; j < n; j++)
            mini = min(mini, cost[i][j]);

        for (int j = 0; j < n; j++)
            cost[i][j] -= mini;
    }
}

void columnoperation(vector<vector<int>>& cost, int n) {
    for (int j = 0; j < n; j++) {
        int mini = INT_MAX;

        for (int i = 0; i < n; i++)
            mini = min(mini, cost[i][j]);

        for (int i = 0; i < n; i++)
            cost[i][j] -= mini;
    }
}

void checkrowassignment(vector<vector<int>>& cost, vector<int>& assignment, vector<bool>& jobTaken, int n) {
    for (int i = 0; i < n; i++) {
        if (assignment[i] != -1) continue;

        int count = 0;
        int index = -1;

        for (int j = 0; j < n; j++) {
            if (cost[i][j] == 0 && !jobTaken[j]) {
                count++;
                index = j;
            }
        }

        if (count == 1) {
            assignment[i] = index;
            jobTaken[index] = true;
        }
    }
}

void checkcolumnassignment(vector<vector<int>>& cost, vector<int>& assignment, vector<bool>& jobTaken, int n) {
    for (int j = 0; j < n; j++) {
        if (jobTaken[j]) continue;

        int count = 0;
        int index = -1;

        for (int i = 0; i < n; i++) {
            if (cost[i][j] == 0 && assignment[i] == -1) {
                count++;
                index = i;
            }
        }

        if (count == 1) {
            assignment[index] = j;
            jobTaken[j] = true;
        }
    }
}

bool checkfullassignment(vector<vector<int>>& cost, vector<int>& assignment, int n) {

    assignment.assign(n, -1);
    vector<bool> jobTaken(n, false);

    bool changed = true;

    while (changed) {
        changed = false;

        checkrowassignment(cost, assignment, jobTaken, n);
        checkcolumnassignment(cost, assignment, jobTaken, n);

        for (int i = 0; i < n; i++)
            if (assignment[i] != -1)
                changed = true;
    }

    int assigned = 0;
    for (int i = 0; i < n; i++)
        if (assignment[i] != -1)
            assigned++;

    return assigned == n;
}

void adjustmatrix(vector<vector<int>>& cost, vector<int>& assignment, int n) {

    vector<bool> markedRow(n,false), markedCol(n,false);

    for(int i=0;i<n;i++)
        if(assignment[i]==-1)
            markedRow[i]=true;

    bool change=true;

    while(change){
        change=false;

        for(int i=0;i<n;i++){
            if(!markedRow[i]) continue;

            for(int j=0;j<n;j++){
                if(cost[i][j]==0 && !markedCol[j]){
                    markedCol[j]=true;
                    change=true;
                }
            }
        }

        for(int j=0;j<n;j++){
            if(!markedCol[j]) continue;

            for(int i=0;i<n;i++){
                if(assignment[i]==j && !markedRow[i]){
                    markedRow[i]=true;
                    change=true;
                }
            }
        }
    }

    int mini=INT_MAX;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(markedRow[i] && !markedCol[j])
                mini=min(mini,cost[i][j]);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(markedRow[i] && !markedCol[j])
                cost[i][j]-=mini;
            else if(!markedRow[i] && markedCol[j])
                cost[i][j]+=mini;
        }
}

int main() {

    int n;

    cout<<"Enter number of jobs: ";
    cin>>n;

    vector<vector<int>> cost(n,vector<int>(n));
    vector<vector<int>> original(n,vector<int>(n));

    cout<<"Enter cost matrix:\n";

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
            original[i][j]=cost[i][j];
        }

    rowoperation(cost,n);
    columnoperation(cost,n);

    vector<int> assignment;

    while(!checkfullassignment(cost,assignment,n)){
        adjustmatrix(cost,assignment,n);
    }

    cout<<"\nAssignments (Worker -> Job):\n";

    int total=0;

    for(int i=0;i<n;i++){
        cout<<i+1<<" -> "<<assignment[i]+1<<endl;
        total+=original[i][assignment[i]];
    }

    cout<<"Total Cost: "<<total;

}