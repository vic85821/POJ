#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;


typedef struct{
    char c[5];
}answer;

bool cmp(answer a,answer b)
{
    if(strlen(a.c)!=strlen(b.c))
        return strlen(a.c)<strlen(b.c);
    else
        return strcmp(a.c,b.c)<0;
}

int main()
{
    int num_ans,num_que;
    scanf("%d",&num_ans);
    getchar();

    answer a[100000];
    char useless[5];
    for(int i=0;i<num_ans;++i)
        memset(a[i].c,0,sizeof(a[i].c));

    for(int i=0;i<num_ans;++i)
    {
        gets(a[i].c);
    }
    sort(a,a+num_ans,cmp);
    gets(useless);

    scanf("%d",&num_que);
    int temp=0;
    for(int i=0;i<num_que;++i)
    {
        scanf("%d",&temp);
        printf("%s\n",a[temp-1].c);
    }

    return 0;
}
