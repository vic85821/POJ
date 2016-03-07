#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

typedef struct{
    char origin[7];
    char After_sort[7];
}word;

bool cmp(word a,word b)
{
    return strcmp(a.origin,b.origin) < 0;
}

int main()
{
    word c[101];
    int i;
    for(i=0;i<101;++i)
    {
        memset(c[i].origin,0,sizeof(c[i].origin));
        memset(c[i].After_sort,0,sizeof(c[i].After_sort));
    }

    for(i=0;i<101;++i)
    {
        gets(c[i].origin);
        if(strcmp(c[i].origin,"XXXXXX")==0)
            break;
        else
        {
            strcpy(c[i].After_sort,c[i].origin);
            sort(c[i].After_sort,c[i].After_sort+strlen(c[i].After_sort));
        }
    }
    sort(c,c+i,cmp);
    int number = i,Count = 0;

    char temp[8];
    for(;;)
    {

        memset(temp,0,sizeof(temp));
        gets(temp);
        if(strcmp(temp,"XXXXXX")==0)
            break;
        else
        {
            sort(temp,temp+strlen(temp));
            for(int j=0;j<number;++j)
            {
                if(strcmp(temp,c[j].After_sort) == 0)
                {
                    printf("%s\n",c[j].origin);
                    Count++;
                }
            }
            if(Count==0)
                printf("NOT A VALID WORD\n******\n");
            else
                printf("******\n");

            Count = 0;
        }
    }


}
