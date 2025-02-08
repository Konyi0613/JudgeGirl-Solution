#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
 
int main()
{
    int n;
    scanf("%d",&n);
    char input[5010];
    char now[5010];
    char processing[5010];
    char tmp[5010];
    char operator;
    int pre_plus_or_sub = 0; // 0 for plus, 1 for subtract
    bool mul_or_div = false;
    bool input_first_str = true;
    while(n >= 0)
    {
        scanf("%s",input);
        if (input_first_str)
        {
            n--;
            strcpy(processing,input);
            input_first_str = false;
            continue;
        }
        if (strcmp(input,"+") == 0 || strcmp(input,"-") == 0 || strcmp(input,"*") == 0 || strcmp(input,"/") == 0 || n == 0)
        {
            if (strcmp(input,"+") == 0 || strcmp(input,"-") == 0 || n == 0)
            {
                input_first_str = true;
                if (pre_plus_or_sub == 0)
                    strcat(now,processing);
                else
                {
                    int now_len = strlen(now);
                    int sub_len = strlen(processing);
                    char *ptr = &(now[now_len-sub_len]);
                    if(strcmp(ptr,processing) == 0)
                        now[now_len - sub_len] = '\0';
                }
                if (input[0] == '+')
                    pre_plus_or_sub = 0;
                else
                    pre_plus_or_sub = 1;
                if(n == 0)
                    n--;
            }
            operator = input[0];
            continue;
        }
        int num = 0;
        int input_len = strlen(input);
        for (int i = 0; i < input_len; i++)
            num = num*10 + (input[i]-'0');
        // printf("%d\n",num);
        if (operator == '*')
        {
            n--;
            strcpy(tmp,processing);
            int len = strlen(tmp);
            int flag = 0;
            for(int i = 0; i < len; i++)
                for(int j = 0; j < num; j++)
                {
                    processing[flag] = tmp[i];
                    flag++;
                }
            processing[flag] = '\0';
        }
        if (operator == '/')
        {
            n--;
            strcpy(tmp,processing);
            int len = strlen(tmp);
            int flag = 0;
            int char_num = 0;
            while(flag < len)
            {
                processing[char_num] = tmp[flag];
                char_num++;
                flag += num;
            }
            processing[char_num] = '\0';
        }
    }
    printf("%s",now);
}