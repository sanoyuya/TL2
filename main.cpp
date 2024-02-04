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
	//テクスチャコンバーター
	std::unique_ptr<TextureConverter>converter = std::make_unique<TextureConverter>();

	//コマンドライン引数指定なし
	if (argc < NumArgument)
	{
		//使い方を表示する
		converter->OutPutUsage();
		return 0;
	}

	//COMライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//オプションの数
	int numOptions = argc - NumArgument;
	//オプション配列
	char** options = argv + NumArgument;

	//テクスチャの変換
	converter->ConvertTextureWICToDDS(argv[Argument::FilePath], numOptions, options);

	//COMライブラリの終了
	CoUninitialize();
	return 0;
}