#include<cstdio>
#include<cstdlib>
#include<cstdint>

int32_t main(int32_t argc,char* argv[])
{
	//argv�̐������J��Ԃ�
	for (int32_t i = 0; i < argc; i++)
	{
		//������argv��i�Ԃ�\��
		printf(argv[i]);
		//���s
		printf("\n");
	}

	system("pause");
	return 0;
}