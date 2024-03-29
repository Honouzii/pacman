#pragma once
#include "Engine/GameObject.h"


class stage;

class Player :
    public GameObject
{
	int hModel_;
	float speed_;
	stage* pStage_;
	int hpMax_;
	int hpCrr_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Player(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

