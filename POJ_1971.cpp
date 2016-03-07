#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

typedef struct{
    int x,y;
}dot;

typedef struct{
    int dis_x,dis_y;
}vec;

bool cmp(dot a,dot b)
{
    if(a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}

bool cmp1(vec a,vec b)
{
    if(a.dis_x != b.dis_x)
        return a.dis_x < b.dis_x;
    else
        return a.dis_y < b.dis_y;
}

int main()
{
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;++i)
    {
        int number,ans=0;
        scanf("%d",&number);
        dot d[number+1];
        for(int j=0;j<number;++j)
            scanf("%d %d",&d[j].x,&d[j].y);

        int Case = number*(number-1)/2;

        vec v[Case+1];

        int pos=0;
        for(int j=0;j<number-1;++j)
        {
            for(int k=j+1;k<number;++k)
            {
                v[pos].dis_x = (d[k].x + d[j].x);
                v[pos].dis_y = (d[k].y + d[j].y);
                pos++;
            }
        }

        sort(v,v+pos,cmp1);
        int same = 1;
        for(int j=0;j<pos-1;++j)
        {
            if(v[j].dis_x == v[j+1].dis_x && v[j].dis_y == v[j+1].dis_y)
                same++;
            else
                if(same>1){
                    ans += same * (same-1)/2;
                    same = 1;
                }
                else
                    same = 1;

        }
        printf("%d\n",ans);
        ans = 0;
    }

    return 0;
}
