#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

class Card{
    private:
        string m_cardTaro, m_cardHanako;
        int m_pointTaro, m_pointHanako;

    public:
        Card(){
            m_pointTaro = 0;
            m_pointHanako = 0;
        }
        
        void updatePoint(string taro, string hanako){
            m_cardTaro = taro;
            m_cardHanako = hanako;

            if(m_cardTaro < m_cardHanako) m_pointHanako += 3;
            else if(m_cardTaro == m_cardHanako){
                m_pointTaro++;
                m_pointHanako++;
            }
            else m_pointTaro += 3;
        }

        void showPoints(){
            cout << m_pointTaro << " " << m_pointHanako << endl;
        }
};

int main(){
    int n;
    cin >> n;

    Card card = Card();
    int loopCnt = 0;

    while(loopCnt < n){
        string taro, hanako;
        cin >> taro >> hanako;

        card.updatePoint(taro, hanako);

        loopCnt++;
    }

    card.showPoints();

    return 0;
}