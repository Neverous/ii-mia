/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <iostream>
#include <string>

int tests,
    result,
    size = 39,
    act,
    position[256];
const char *buff;
std::string buffer;

int main(void)
{
    int p = 1;
    for(int a = 'A'; a <= 'Z'; ++ a, ++ p)
        position[a] = p;

    for(int a = '0'; a <= '9'; ++ a, ++ p)
        position[a] = p;

    position[(int) ':'] = p ++;
    position[(int) '.'] = p ++;

    buffer.reserve(1024);
    std::cin >> tests;
    std::getline(std::cin, buffer);
    for(int t = 0; t < tests; ++ t)
    {
        std::getline(std::cin, buffer);
        buff = buffer.c_str();
        result = 0;
        act = ' ';
        for(; *buff; ++ buff)
        {
            result += (size - position[act] + position[(int) *buff]) % size;
            act = *buff;
        }

        std::cout << result << std::endl;
    }

    return 0;
}
