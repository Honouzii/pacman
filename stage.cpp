#include "stage.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"



//コンストラクタ
stage::stage(GameObject* parent)
	: GameObject(parent, "stage")
{
}

void stage::Initialize()
{
	hFloor_ = Model::Load("floor.fbx");
	assert(hFloor_ >= 0);
	hBlock_ = Model::Load("wall.fbx");
	assert(hBlock_ >= 0);
	Camera::SetPosition({ 6.5,10,-5 });
	Camera::SetTarget({ 6.5,0,5.5 });
}

void stage::Update()
{
}

void stage::Draw()
{
	Transform stagefloor;
	stagefloor.position_ = { 0,0,0 };
	for (float i = 0; i < 15; i++) {
		for (float j = 0; j < 15; j++) {
			stagefloor.position_ = { (float)i,0,(float)j };
			if (i == 0 || j == 0 || i == 14 || j == 14) {
				Model::SetTransform(hBlock_, stagefloor);
				Model::Draw(hBlock_);
			}
			Model::SetTransform(hFloor_, stagefloor);
			Model::Draw(hFloor_);
		}
		Model::SetTransform(hFloor_, stagefloor);
		Model::Draw(hFloor_);
	}
}


void stage::Release()
{
}
