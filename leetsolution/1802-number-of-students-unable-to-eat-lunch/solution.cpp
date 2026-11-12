class Solution {
public:
    int countStudents(vector<int>& stu, vector<int>& sndw) {
        stack<int>sandwiches;
        queue<int>students;
        int m=stu.size(),c=0;
        for(int i=0;i<m;i++){
            students.push(stu[i]);
            sandwiches.push(sndw[m-1-i]);
        }
        while(sandwiches.size() && c!=students.size()){
            if(students.front()==sandwiches.top()){
                students.pop();
                sandwiches.pop();
                c=0;
            }
            else{
                int x=students.front();
                students.pop();
                students.push(x);
                c++;
            }
        }
        return students.size();
    }
};
