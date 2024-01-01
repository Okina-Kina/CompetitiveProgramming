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

        int getLabelByIndex(int index){
            return m_labels.at(index);
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

        bool isSame(Dice d1, Dice d2){
            for(int i = 0; i < m_LABEL_SIZE; i++){               
                if(d1.getLabelByIndex(i) != d2.getLabelByIndex(i))
                    return false;
            }
            return true;
        }

        void showDice(){
            for(int i = 0; i < m_LABEL_SIZE; i++){
                cout << "i: " << i << " - " << m_labels.at(i) << endl;
            }
            cout << endl;
        }
};

int main(){
    Dice d1 = Dice();
    Dice d2 = Dice();

    string direction = "ENSW";

    for(int i = 0; i < 6; i++){
        int n;
        cin >> n;
        d1.setLabel(i, n);
    }

    for(int i = 0; i < 6; i++){
        int n;
        cin >> n;
        d2.setLabel(i, n);
    }

    bool isSame = false;
    for(int i = 0; i < 4; i++){
        d2.rotate('N');              
        for(int j = 0; j < 4; j++) {
            d2.rotate('E');              
            for(int k = 0; k < 4; k++){
                d2.rotate('N');               
                if(d1.isSame(d1, d2)){
                    isSame = true;
                    break;
                }
            }
        }
    }

    if(isSame) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}