#include <cstdio>
#include <iostream>
#include <utility>

using namespace std;


long indexOfLeastTime;
double tempTimeLeft;
double timeLeft;
double timeRate = 0.0005;



int main ()
{
    
    
    long cases;
    scanf (" %ld", &cases);
    
    double time;
    long long C;
    long N;
    
    
    for (long cs = 0; cs < cases; cs++)
    {
        bool phonesAlive = true;
        
        
        scanf (" %ld %lld", &N, &C);
        
        float phoneRate[N] = {0.0};
        float phonePower[N] = {0.0};
        
        for (long i = 0; i < N; i++)
        {
            int a, b;
            scanf (" %d %d", &a, &b);
            
            phoneRate[i] = (float) a;
            phonePower[i] = (float) b;
        }
        
        time = 0;
        
        while (phonesAlive)
        {
            time += timeRate;
            
            
            for (long b = 0; b < N; b++)
            {
                if (phonePower[b] <= 0)
                {
                    phonesAlive = false;
                }
                
                tempTimeLeft = phonePower[b] * (1 / phoneRate[b]);
                if (b == 0)
                {
                    indexOfLeastTime = b;
                    timeLeft = tempTimeLeft;
                }
                else
                {
                    if (tempTimeLeft < timeLeft)
                    {
                        indexOfLeastTime = b;
                        timeLeft = tempTimeLeft;
                    }
                }
                
                phonePower[b] -= phoneRate[b] * timeRate;
                
                
                if (b == N - 1)
                {
                    
                    phonePower[indexOfLeastTime] += (float) C * timeRate;
                    
                }
                
                
            }
            
            
            
        }
        
        printf("%f\n", time-timeRate);
        
        
    }
    
    return 0;
}
