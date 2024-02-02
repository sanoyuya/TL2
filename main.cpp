#include<cstdio>
#include<cstdlib>
#include<cstdint>
#include<memory>
#include"TextureConverter.h"
#include <cassert>
#include<DirectXTex.h>

enum Argument
{
	ApplicationPath,//アプリケーションのパス
	FilePath,//渡されたファイルのパス

	NumArgument
};

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

	//assert(argc >= Argument::NumArgument);

	//COMライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//テクスチャコンバーター
	std::unique_ptr<TextureConverter>converter = std::make_unique<TextureConverter>();

	//テクスチャの変換
	converter->ConvertTextureWICToDDS(argv[Argument::FilePath]);

	//COMライブラリの終了
	CoUninitialize();

	system("pause");
	return 0;
}