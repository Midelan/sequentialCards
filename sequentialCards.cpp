#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<vector<int>, double> savedValues;

double subsequentDraw(int spadesLeft, int clubsLeft, int heartsLeft, int diamondsLeft) 
{
    vector<int> cards = {spadesLeft, clubsLeft, heartsLeft, diamondsLeft};
    if(spadesLeft+clubsLeft+heartsLeft+diamondsLeft == 0) {
        return 1;
    } else if (savedValues.find(cards)!=savedValues.end()) {
        return savedValues[cards];
    } else {
        double prob = (clubsLeft*subsequentDraw(clubsLeft-1, spadesLeft, heartsLeft, diamondsLeft) +
                heartsLeft*subsequentDraw(heartsLeft-1, spadesLeft, clubsLeft, diamondsLeft) +
                diamondsLeft*subsequentDraw(diamondsLeft-1, spadesLeft, clubsLeft, heartsLeft)) /
                (clubsLeft + heartsLeft + diamondsLeft + spadesLeft);
        savedValues.insert({cards, prob});
    }
};

int main()
{
    int initialSpades = 12;
    int initialClubs = 13;
    int initialHearts = 13;
    int initialDiamonds = 13;

    cout << subsequentDraw(initialSpades, initialClubs, initialDiamonds, initialHearts);
}