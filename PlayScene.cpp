#include "PlayScene.h"
#include "stage.h"
#include "Player.h"
#include "Gauge.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
    Instantiate<stage>(this);
	Instantiate<Player>(this);
	Instantiate<Gauge>(this);
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
