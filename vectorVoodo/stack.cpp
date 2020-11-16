#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <vector>

using namespace std;

ofstream outData;


int main()
{
	long double seconds;
	outData.open("out4.txt", ofstream::app);
	clock_t t;
	t = clock();
	int x = 0;
	int N = 100;

	for (int j = 1; j <= 100; j++)
	{
        vector<int> mine;
        for (int i = 1; i <=N; i++) 
        {
            mine.push_back(i);
        } 
        N = N + 100;   
        t = clock() - t;
        
    
        outData << "N is " << N << ',';
        outData << "time in ms " << t << ", ";
        
        seconds = static_cast<long double>(t*0.001);
        cout << "N is " << N << ',' << "time in ms " << t << ',' << "seconds are " << seconds << endl;
        outData << "N, " << N << ',' << "time in ms, " << t << ',' << "seconds are, " << seconds << endl;
    
    }
	outData.close();
	//cout << "vector int " << mine.begin() << endl;
	return 0;


}