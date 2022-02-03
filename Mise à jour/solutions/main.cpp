//Code issue d'une épreuve de BattleDev

/****************************************************************/
/***/
/***/
/** SOLUTION BY ISOGRAD*/
/***/
/***/
/********************************************************************/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main(){
    std::size_t n;
    std::cin >> n;
    std::vector<std::string> map;
    map.reserve(n);
    copy(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>(), back_inserter(map));
    int count = 0;
    for(int y=0; y<n; ++y)
        for(int x=0; x<n; ++x){
            if(map[y][x]=='X') continue;
            for(int dy=-1, sc=count; dy<=1 && count==sc; ++dy)
                for(int dx=-1; dx<=1; ++dx)
                    if((dy || dx) && y+dy>=0 && x+dx>=0 && y+dy<n && x+dx<n && map[y+dy][x+dx]=='X'){
                        ++count;
                        break;
                    }
        }
    std::cout << count << "\n";
}