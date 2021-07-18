#include <bits/stdc++.h>
using namespace std;

struct Status 
{
	int a, b;
	bool operator<(const Status &s) const 
	{
		return a!=s.a ? a<s.a : b<s.b;
	}
};
queue<Status> Q;
map<Status, Status> from;

/* 递归输出方案 */
void print(Status &p) 
{
    if ( from.find(p) == from.end() || (p.a == 0&&p.b==0) )
    {
    	printf("<%d,%d>",  p.a, p.b);
        return;
    }
    print(from[p]); // 递归
    printf("-><%d,%d>",  p.a, p.b);
}

void refresh(Status &s, Status &t) 
{
    if ( from.find(t) == from.end() ) 
    { // 特判合法，加入队列
        from[t] = s;
        Q.push(t);
    }
}

void bfs(int A, int B, int C) 
{
	// 起点, 两杯水都空
	Status s,t; s.a=0; s.b=0; 
	Q.push(s);

    while (!Q.empty()) 
    {
    	// 取队首
        s = Q.front(); Q.pop();
        // 特判到达终点
        if (s.a == C || s.b == C) {
            print(s); // 输出方案
            return;
        }

        // 倒空 a 杯的水
        if (s.a > 0) {
            t.a = 0;  // 倒空
            t.b = s.b;// b 杯不变
            refresh(s, t);
        }

        // 同理，倒空 b 杯的水
        if (s.b > 0) {
            t.b = 0;  // 倒空
            t.a = s.a;// a 杯不变
            refresh(s, t);
        }

        // a 杯未满，续满 a 杯
        if (s.a < A) 
        {
        	// 续满 a 杯
        	t.a = A;  
        	t.b = s.b;
            refresh(s, t);

            // 考虑倒入
            if (s.b != 0) 
            {
                if (s.a + s.b <= A) 
                {
                    t.a = s.a + s.b;
                    t.b = 0;
           			refresh(s, t);
                } else 
                {
                    t.a = A;
                    t.b = s.a + s.b - A;
            		refresh(s, t);
                }
            }
        }

        // 同理，b 杯未满，续满 b 杯
        if (s.b < B) 
        {
            t.a = s.a;
            t.b = B;
            refresh(s, t);
            if (s.a != 0) 
            {
                if (s.a + s.b <= B) 
                {
                    t.a = 0;
                    t.b = s.a + s.b;
                    refresh(s, t);
                } else 
                {
                    t.a = s.a + s.b - B;
                    t.b = B;
                    refresh(s, t);
                }
            }
        }
    }
    printf("-1\n");
}
int main() 
{
    int a, b, c; 
    scanf("%d%d%d", &a, &b, &c);
    bfs(a, b, c);
    return 0;
}/* 26 29 11 */