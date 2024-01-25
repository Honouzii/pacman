#include "PlayScene.h"
#include "stage.h"
#include "Player.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void PlayScene::Initialize()
{
    Instantiate<stage>(this);
	Instantiate<Player>(this);
}

//�X�V
void PlayScene::Update()
{

}

//�`��
void PlayScene::Draw()
{
}

//�J��
void PlayScene::Release()
{
}
