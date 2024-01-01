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

        void showTop(){
            cout << m_labels.at(0) << endl;
        }

};

int main(){
    Dice dice = Dice();

    for(int i = 0; i < 6; i++){
        int n;
        cin >> n;
        dice.setLabel(i, n);
    }

    string directions;
    cin >> directions;

    for(int i = 0; i < directions.size(); i++){
        dice.rotate(directions.at(i));
    }

    dice.showTop();

    return 0;
}