/***
Read data : std::cin>>variable;
Submit answer : std::cout<<awnser;
***/
#include <iostream>
#include <sstream>
using namespace std;

int main(){
    std::string line;
    int n;
    std::cin >> n;

    int m[n];
    std::getline(std::cin, line);
    for(int i = 0; i < n; i++){
        std::cin >> m[i];
    }

    int nbCovid = 0;
    for(int i = 0; i < n; i++){
        float vaccin = 0;
        for(int j=0; j<m[i]; j++){
            int eleve;
            cin >> eleve;
            if(eleve == 1){
                vaccin++;
            }
        }
        if(vaccin*10/m[i]< 9){
            nbCovid++;
        }
    }
    
    cout<<nbCovid;
    return 0;

}