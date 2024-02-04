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
	//argv�̐������J��Ԃ�
	for (int32_t i = 0; i < argc; i++)
	{
		//������argv��i�Ԃ�\��
		printf(argv[i]);
		//���s
		printf("\n");
	}

	//assert(argc >= Argument::NumArgument);

	//COM���C�u�����̏�����
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//�e�N�X�`���R���o�[�^�[
	std::unique_ptr<TextureConverter>converter = std::make_unique<TextureConverter>();

	//�e�N�X�`���̕ϊ�
	converter->ConvertTextureWICToDDS(argv[Argument::FilePath]);

	//COM���C�u�����̏I��
	CoUninitialize();
	return 0;
}