#include<cstdio>
#include<cstdlib>
#include<cstdint>

int32_t main(int32_t argc,char* argv[])
{
	//argvの数だけ繰り返す
	for (int32_t i = 0; i < argc; i++)
	{
		//文字列argvのi番を表示
		printf(argv[i]);
		//改行
		printf("\n");
	}

	system("pause");
	return 0;
}