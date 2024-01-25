#include "PlayScene.h"
#include "stage.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
    Instantiate<stage>(this);
}

//更新
void PlayScene::Update()
{

}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}
