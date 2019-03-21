#include <iostream>
#include <iterator>
#include <chrono>

int main()
{
    
    int n,result,current,first,temp,pos;

    auto start = std::chrono::high_resolution_clock::now();

    std::cin >> n;
    /*  save the amount of first rest hours to sum with last rest hours
        for example:
            stdin:
                5
                1 0 1 0 1
            stdout:
                2
        coz 1 rest hour at the end of first day and second rest hour at the begining of the second day
    */
    first = 0;
    do{
        std::cin >> temp;
        first += temp;
    } while (temp);

    pos = (first + 1); // pos = 1 if there wasn't rest hours at the begining of the day
    
    current = 0;
    result =0;
    while(pos < n)
    {
        std::cin >> temp;
        if (temp == 1)
            current++;
        else
        {
            if (current > result)
                result = current;
            current = 0;
        }
        pos++;
    }
    if ((current + first) > result) // current == last rest hours
        std::cout << current + first << std::endl;
    else
        std::cout << result << std::endl;
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> dur = std::chrono::duration_cast<std::chrono::microseconds>(end - start);;
    std::cout << "SLOW " <<dur.count();
}