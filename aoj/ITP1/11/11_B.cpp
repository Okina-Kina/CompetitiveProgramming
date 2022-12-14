#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

class Dice{
    private:
        const int m_LABEL_SIZE = 6;
        vector<int> m_labels;

    public:
        Dice(){
            m_labels = vector<int>(m_LABEL_SIZE);
        }

        void setLabel(int labelPos, int label){
            if(m_LABEL_SIZE <= labelPos) return;

            m_labels.at(labelPos) = label;
        }
        
        void rotate(char direction){
            int tmp = 0;

            switch(direction){
                case 'E':
                    tmp = m_labels.at(0);
                    m_labels.at(0) = m_labels.at(3);
                    m_labels.at(3) = m_labels.at(5);
                    m_labels.at(5) = m_labels.at(2);
                    m_labels.at(2) = tmp;   
                    break;

                case 'N':
                    tmp = m_labels.at(0);
                    m_labels.at(0) = m_labels.at(1);
                    m_labels.at(1) = m_labels.at(5);
                    m_labels.at(5) = m_labels.at(4);
                    m_labels.at(4) = tmp;

                    break;

                case 'S':
                    tmp = m_labels.at(0);
                    m_labels.at(0) = m_labels.at(4);
                    m_labels.at(4) = m_labels.at(5);
                    m_labels.at(5) = m_labels.at(1);
                    m_labels.at(1) = tmp;
                    break;

                case 'W':
                    tmp = m_labels.at(0);
                    m_labels.at(0) = m_labels.at(2);
                    m_labels.at(2) = m_labels.at(5);
                    m_labels.at(5) = m_labels.at(3);
                    m_labels.at(3) = tmp;   

                    break;
            }
        }

        int findRightSurfaceLabel(int top, int forward){
            if(top == m_labels.at(3) && forward == m_labels.at(1)
            || top == m_labels.at(1) && forward == m_labels.at(2)
            || top == m_labels.at(2) && forward == m_labels.at(4)
            || top == m_labels.at(4) && forward == m_labels.at(3)) return m_labels.at(0);

            if(top == m_labels.at(0) && forward == m_labels.at(3)
            || top == m_labels.at(3) && forward == m_labels.at(5)
            || top == m_labels.at(5) && forward == m_labels.at(2)
            || top == m_labels.at(2) && forward == m_labels.at(0)) return m_labels.at(1);

            if(top == m_labels.at(5) && forward == m_labels.at(4)
            || top == m_labels.at(4) && forward == m_labels.at(0)
            || top == m_labels.at(1) && forward == m_labels.at(5)
            || top == m_labels.at(0) && forward == m_labels.at(1)) return m_labels.at(2);

            if(top == m_labels.at(1) && forward == m_labels.at(0)
            || top == m_labels.at(0) && forward == m_labels.at(4)
            || top == m_labels.at(4) && forward == m_labels.at(5)
            || top == m_labels.at(5) && forward == m_labels.at(1)) return m_labels.at(3);

            if(top == m_labels.at(3) && forward == m_labels.at(0)
            || top == m_labels.at(0) && forward == m_labels.at(2)
            || top == m_labels.at(2) && forward == m_labels.at(5)
            || top == m_labels.at(5) && forward == m_labels.at(3)) return m_labels.at(4);

            if(top == m_labels.at(2) && forward == m_labels.at(1)
            || top == m_labels.at(1) && forward == m_labels.at(3)
            || top == m_labels.at(3) && forward == m_labels.at(4)
            || top == m_labels.at(4) && forward == m_labels.at(2)) return m_labels.at(5);

            else return -1;
        }
};

int main(){
    Dice dice = Dice();

    for(int i = 0; i < 6; i++){
        int n;
        cin >> n;
        dice.setLabel(i, n);
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++){
        int top, forward;
        cin >> top >> forward;

        cout << dice.findRightSurfaceLabel(top, forward) << endl;
    }
    return 0;
}