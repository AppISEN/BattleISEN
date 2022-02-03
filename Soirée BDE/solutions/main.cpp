/*****************************************************
*                                                    *
*             Solution par Aubin Saunier             *
*                                                    *
*****************************************************/

/***
Read data : std::cin>>variable;
Submit answer : std::cout<<awnser;
***/
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    std::string line;
	int myNotes[5] = {0, 0, 0, 0, 0};
	int N;
	int K;

	std::getline(std::cin, line);
	int ind = 0;
	for (int i = 0; i < 5; i++){
		if(line[i] - '0' >= 0 && line[i] - '0' < 10){
			myNotes[ind] *= 10;
			myNotes[ind] += (line[i] - '0');
		}
		else{
			ind++;
		}
	}

	std::getline(std::cin, line);
	N = stoi(line);

	std::getline(std::cin, line);
	K = stoi(line);

	int** ecart = new int*[N];
	int* notesLastEvent = new int[N];
	for (int i = 0; i < N; i++){
		ecart[i] = new int[2];
		ecart[i][0] = 0;
		ecart[i][1] = i;
	}

	ind = 0;
	while (std::getline(std::cin, line))
	{
		int n = line.length();
		int temp = 0;
		int ind2 = 0;
		for (int i = 0; i < n; i++){
			if(line[i] - '0' >= 0 && line[i] - '0' < 10){
				temp *= 10;
				temp += (line[i] - '0');
			}
			else{
				ecart[ind][0] += abs(temp-myNotes[ind2]);
				temp = 0;
				ind2++;
			}
		}
		notesLastEvent[ind] = temp;
		ind++;
	}

	for (int i = 0; i < N; i++){
        int min = ecart[i][0];
        int indMin = i;
        for (int j = i; j < N; j++){
            if (ecart[j][0] < min){
                min = ecart[j][0];
                indMin = j;
            }
        }
		int a = ecart[i][0];
		int b = ecart[i][1];
		ecart[i][0] = ecart[indMin][0];
		ecart[i][1] = ecart[indMin][1];
		ecart[indMin][0] = a;
		ecart[indMin][1] = b;
    }

	int sum = 0;
	for (int i = 0; i < K; i++){
		sum += notesLastEvent[ecart[i][1]];
	}
	int answer = sum/K;

	cout << answer;
}