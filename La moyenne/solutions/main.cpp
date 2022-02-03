#include<iostream>

int main(){
    float n=0;
    float m=0;
    std::cin>>n;
    for(int i=0;i<n;i++){
        float x=0;
        std::cin>>x;
        m+=x;
    }
    m=m/n;
    std::cout<<m;
}