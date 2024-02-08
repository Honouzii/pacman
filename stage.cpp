#include "stage.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/CsvReader.h"



//コンストラクタ
stage::stage(GameObject* parent)
	: GameObject(parent, "stage")
{
	CsvReader csv;
	csv.Load("map.csv");
	stageWidth_ = csv.GetWidth();
	stageHeight_ = csv.GetHeight();


	for (int i = 0; i < stageHeight_; i++) {
		vector<int>sdata(stageWidth_, 0);
		stageData_.push_back(sdata);
	}

	for (int j = 0; j < stageHeight_; j++) {
		for (int i = 0; i < stageWidth_; i++) {
			stageData_[j][i] = csv.GetValue(i, j);
		}
	}
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

	for (int z = 0; z < 15; z++) {
		for (int x = 0; x < 15; x++) {
			stagefloor.position_ = { (float)x,0, (float)(14 - z) };
			if (stageData_[z][x] == 1) {
				Model::SetTransform(hBlock_, stagefloor);
				Model::Draw(hBlock_);
			}
			else {
				Model::SetTransform(hFloor_, stagefloor);
				Model::Draw(hFloor_);
			}
		}
	}
}


void stage::Release()
{
	for (int i = 0; i < stageHeight_; i++)
	{
		stageData_[i].clear();
	}
	stageData_.clear();

}
