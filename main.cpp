#include<cstdio>
#include<cstdlib>
#include<cstdint>
#include<memory>
#include"TextureConverter.h"
#include <cassert>
#include<DirectXTex.h>

enum Argument
{
	ApplicationPath,//�A�v���P�[�V�����̃p�X
	FilePath,//�n���ꂽ�t�@�C���̃p�X

	NumArgument
};

int32_t main(int32_t argc,char* argv[])
{
	//�e�N�X�`���R���o�[�^�[
	std::unique_ptr<TextureConverter>converter = std::make_unique<TextureConverter>();

	//�R�}���h���C�������w��Ȃ�
	if (argc < NumArgument)
	{
		//�g������\������
		converter->OutPutUsage();
		return 0;
	}

	//COM���C�u�����̏�����
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//�I�v�V�����̐�
	int numOptions = argc - NumArgument;
	//�I�v�V�����z��
	char** options = argv + NumArgument;

	//�e�N�X�`���̕ϊ�
	converter->ConvertTextureWICToDDS(argv[Argument::FilePath], numOptions, options);

	//COM���C�u�����̏I��
	CoUninitialize();
	return 0;
}