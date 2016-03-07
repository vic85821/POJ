#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

typedef struct{
    char c[51];
    int number;
}RAN;

bool cmp(RAN a,RAN b)
{
    return a.number < b.number;
}

int main()
{
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    RAN r[num2];
    memset(r,0,sizeof(r));
    getchar();
    for(int i=0;i<num2;++i)
    {
        memset(r[i].c,0,sizeof(r[i].c));
        gets(r[i].c);
    }

    for(int i=0;i<num2;++i)
    {
        for(int j=num1-1;j>=0;--j)
        {
            for(int k=0;k<j;++k)
            {
                if(r[i].c[k]>r[i].c[j])
                    r[i].number++;
            }
        }
    }
    sort(r,r+num2,cmp);

    for(int i=0;i<num2;++i)
    {
        printf("%s\n",r[i].c);
    }

    return 0;
}
