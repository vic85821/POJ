#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
    char s1[120],s2[120];
    int i1[26],i2[26];

    gets(s1);
    gets(s2);

        char temp;
        memset(i1,0,sizeof(i1));
        memset(i2,0,sizeof(i2));

        for(int i=0;i<26;++i)
        {
            for(int j=0;j<strlen(s1);++j)
            {
                if(s1[j] == 'A'+i)
                {
                    i1[i]++;
                }
            }
            for(int j=0;j<strlen(s2);++j)
            {
                if(s2[j] == 'A'+i)
                {
                    i2[i]++;
                }
            }
        }

        sort(i1,i1+26);
        sort(i2,i2+26);

        int k=0;
        for(k=0;k<26;++k)
        {
            if(i1[k]!=i2[k])
            {
                printf("NO");
                return 0;
            }
        }
        if(k==26)
            printf("YES");

        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));


    return 0;
}
