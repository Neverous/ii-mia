/* 2011
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>

int tests;
inline static const bool brainfuckVM(void);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
        if(brainfuckVM())
            puts("Terminates");
    
    return 0;
}

inline static const bool brainfuckVM(void)
{
    char memory[131072] = {},
         code[4096] = {},
         input[4096] = {};
    int jump[4096] = {},
        stack[4096] = {},
        last[2] = {};
    int memsize = 0, codesize = 0, inputsize = 0;
    int m = 0, s = 0, i = 0;
    scanf("%d %d %d %s %s", &memsize, &codesize, &inputsize, code, input);
    for(int c = 0; c < codesize; ++ c)
        switch(code[c])
        {
            case '[':
                stack[s ++] = c;
                break;
                
            case ']':
                jump[c] = stack[s - 1];
                jump[stack[-- s]] = c;
                break;
                
            default:
                jump[c] = c;
                break;
        }
    
    s = 0;
    for(int c = 0; c < codesize && s < 55000000; ++ c, ++ s)
    {
        switch(code[c])
        {
            case '-':
                -- memory[m];
                break;
                
            case '+':
                ++ memory[m];
                break;
                
            case '<':
                m = (memsize + m - 1) % memsize;
                break;
                
            case '>':
                m = (m + 1) % memsize;
                break;
                
            case '.':
                //putchar(memory[m]);
                break;
                
            case ',':
                if(i >= inputsize)
                    memory[m] = 255;
                
                else
                    memory[m] = input[i ++];
                
                break;
                
            case '[':
                if(!memory[m])
                    c = jump[c];
                
                break;
                
            case ']':
                if(memory[m])
                {
                    if(last[1] < c)
                    {
                        last[1] = c;
                        last[0] = jump[c];
                    }
                    
                    c = jump[c];
                }
                
                break;
        }
    }
    
    //puts("");
    if(s > 50000000)
    {
        printf("Loops %d %d\n", last[0], last[1]);
        return false;
    }
    
    return true;
}
