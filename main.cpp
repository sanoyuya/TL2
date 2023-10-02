#include<cstdio>
#include<cstdlib>
#include<cstdint>

int32_t main(int32_t argc,char* argv[])
{
	//argv‚Ì”‚¾‚¯ŒJ‚è•Ô‚·
	for (int32_t i = 0; i < argc; i++)
	{
		//•¶š—ñargv‚Ìi”Ô‚ğ•\¦
		printf(argv[i]);
		//‰üs
		printf("\n");
	}

	system("pause");
	return 0;
}