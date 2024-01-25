#include "stage.h"
#include "Engine/Model.h"



//コンストラクタ
stage::stage(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

void stage::Initialize()
{
	hFloor_ = Model::Load("floor.fbx");
	assert(hFloor_ >= 0);
}

void stage::Update()
{
}

void stage::Draw()
{
	Transform stagefloor;
	for (float i = 0; i < 15; i++) {
		for (float j = 0; j < 15; j++) {
			Model::SetTransform(hFloor_, transform_);
			Model::Draw(hFloor_);
			stagefloor.position_ = { i,0,j };
		}
		Model::Draw(hFloor_);
	}
}


void stage::Release()
{
}
