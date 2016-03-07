#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

int main()
{
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;++i)
    {
        int number,pos;
        scanf("%d %d",&number,&pos);
        priority_queue<int> pq;
        int temp,step = 1;
        int List[number];
        for(int j=0;j<number;++j)
        {
            scanf("%d",&temp);
            List[j] = temp;
            pq.push(temp);
        }
        for(int j=0;j<number;)
        {
            if(List[j] == pq.top())
            {
                if(j == pos)
                {
                    printf("%d\n",step);
                    break;
                }
                else
                {
                    step++;
                    j = (j+1<number)? j+1 : 0;
                    pq.pop();
                }
            }
            else
            {
                j = (j+1<number)? j+1 : 0;
            }
        }
    }

    return 0;
}
