//Code issue d'une épreuve de BattleDev

/****************************************************************/
/***/
/***/
/** SOLUTION BY AdrienVannson*/
/***/
/***/
/********************************************************************/

#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
using namespace std;
using ll = long long;

#define for_n(i,n) for (int i=0;i<n;i++)
inline int readInt () { int v; cin >> v; return v; }
const int oo = 1000*1000*1000;


int n1, n2, c;
vector< pair<int, int> > especes; // {valeur, poids}


int dyn[101][10001];

int getGainMax (int quantiteRestante, int espece)
{
    if (espece == (int)especes.size()) {
        return 0;
    }

    int &res = dyn[quantiteRestante][espece];
    if (res != -1) return res;

    if (especes[espece].second <= quantiteRestante) {
        res = max(getGainMax(quantiteRestante - especes[espece].second, espece+1), res) + especes[espece].first;
    }
    res = max(getGainMax(quantiteRestante, espece+1), res);

    return res;
}


int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    fill(*dyn, *dyn+101*10001, -1);

    cin >> n1 >> n2 >> c;

    for_n (i, n1) {
        int a, b;
        cin >> a >> b;

        especes.push_back(make_pair(a, b));
    }
    for_n (i, n2) {
        int a, b;
        cin >> a >> b;

        for_n (j, b) especes.push_back(make_pair(a, 1));
    }

    cout << getGainMax(c, 0) << endl;
}


