#include<iostream>
using namespace std;

int** multiply(int** m,int N)
{
	int **ans = new int*[N];
	for (int i = 0; i < N; i++)
		ans[i] = new int[N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			ans[i][j] = 0;
			for (int k = 0; k < N; k++)
			{
				ans[i][j] += m[i][k] * m[k][j];
			}
		}
	return ans;
}


int main()
{
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
	//多组输入数据，以0结束
	//先根据up和down来初始化连通矩阵graph[N][N]
	//连通矩阵自乘
	//直到graph[A][B]！=0
	//输出graph[A][B]
	//即为按下up或down的次数
	int count = 0;
	int N, A, B;

	while (cin >> N)
	{
		int num[N];//num存了对应楼层的Ki，下标+1即楼层
		int i = 0;
		cin >> A >> B;
		while (i <= N)
			cin >> num[i++];

		int **ans;
		int **graph;	//0表示未到达，1已经到达
		graph = new int *[N];
		for (int i = 0; i < N; i++)
			graph[i] = new int[N];

		//先初始化连通矩阵
		for (int i = 0; i < N; i++)
		{
			if (i + num[i] < N)
				graph[i][i + num[i]] = 1;
			if (i - num[i] > 0)
				graph[i][i - num[i]] = 1;
		}

		while (ans[A - 1][B - 1] == 0)
			ans = multiply(graph, N);

		cout << graph[A - 1][B - 1] << endl;

	}

}