#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdbool.h>

using namespace std;

int main()
{
    char s[220],temp1[220],temp2[220],temp3[220];

    char EndFile[] = "ENDOFINPUT";

    while(gets(temp1))
    {
        if(strcmp(temp1,EndFile)==0)
            break;
        else
        {
            gets(temp2);
            gets(temp3);
            for(int i=0;i<strlen(temp2);++i)
            {
                if('A'<=temp2[i] && temp2[i]<='Z')
                    s[i] = (temp2[i]-5 < 'A')?(temp2[i]-5+26):(temp2[i]-5);
                else
                    s[i] = temp2[i];
            }
            printf("%s\n",s);
            memset(temp1,0,sizeof(temp1));
            memset(temp2,0,sizeof(temp2));
            memset(s,0,sizeof(s));
        }
    }
    return 0;
}
