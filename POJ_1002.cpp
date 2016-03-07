#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>

using namespace std;

typedef struct{
    char c[8];
}node;

bool cmp(node a,node b)
{
    for(int i=0;i<7;++i)
    {
        if(a.c[i] != b.c[i])
            return a.c[i] < b.c[i];
    }
    return 0;
}

int main()
{
    int num;
    scanf("%d",&num);
    getchar();
    node number[100000];
    bool check[100000],flag = false;
    char temp[20];
    char MAP[26] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','0','7','7','8','8','8','9','9','9','0'};

    for(int i=0;i<num;++i)
        memset(number[i].c,0,sizeof(number[i].c));

    for(int i=0;i<num;++i)
    {
        int position = 0;
        memset(temp,0,sizeof(temp));
        gets(temp);
        for(int j=0;j<strlen(temp);++j)
        {
            if(temp[j] == '-' || temp[j] == 'Q' || temp[j]=='Z')
                continue;
            else if('0' <= temp[j] && temp[j] <= '9')
                number[i].c[position++] = temp[j];
            else if('A'<=temp[j] && temp[j]<='Y')
                number[i].c[position++] = MAP[temp[j]-'A'];
        }
    }
    sort(number,number+num,cmp);

    int total=1;
    for(int i=0;i<num;++i)
    {
        if(i!=num-1 && strcmp(number[i].c,number[i+1].c) == 0 )
            total++;
        else
        {
            if(total>1)
            {
                printf("%c%c%c-%c%c%c%c %d\n",number[i].c[0],number[i].c[1],number[i].c[2],number[i].c[3],number[i].c[4],number[i].c[5],number[i].c[6],total);
                flag = true;
            }
            total = 1;
        }
    }
    if(flag == false)
        printf("No duplicates.\n");

    return 0;
}
