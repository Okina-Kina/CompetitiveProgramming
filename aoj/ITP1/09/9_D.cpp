#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

class Command{
    private:
        string m_str;

    public:
        Command(string str){
            m_str = str;
        }

        void print(int left, int right){
            cout << m_str.substr(left, right - left + 1) << endl;
        }

        void replace(int left, int right, string p){
            m_str.replace(left, right - left + 1, p);
        }

        void reverse(int left, int right){
            ::reverse(m_str.begin() + left, m_str.begin() + right + 1);
        }
};

int main(){
    string str;
    int n;
    cin >> str >> n;
    cin.ignore();

    Command command(str);

    for(int i = 0; i < n; i++){
        string cmd;
        cin >> cmd;

        int left, right;
        string p;

        if(cmd == "print"){
            cin >> left >> right;
            command.print(left,right);
        }
        if(cmd == "reverse"){
            cin >> left >> right;
            command.reverse(left, right);
        }
        if(cmd == "replace"){
            cin >> left >> right >> p;
             command.replace(left, right, p);
        }

    }

    return 0;
}