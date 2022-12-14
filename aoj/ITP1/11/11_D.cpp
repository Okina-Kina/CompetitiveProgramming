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
    int n;
    cin >> n;

    vector<Dice> dices;

    for(int i = 0; i < n; i++){
        dices.push_back(Dice());
        for(int j = 0; j < 6; j++){
            int tmp;
            cin >> tmp;
            dices.at(i).setLabel(j, tmp);
        }
    }

    bool isNotSame = true;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = 0; k < 4; k++){
                dices.at(j).rotate('N');              
                for(int l = 0; l < 4; l++) {
                    dices.at(j).rotate('E');              
                    for(int l = 0; l < 4; l++){
                        dices.at(j).rotate('N');               
                        if(dices.at(i).isSame(dices.at(i), dices.at(j))){
                            isNotSame = false;
                            break;
                        }
                    }
                }
            }
        }
    }

    if(isNotSame) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}