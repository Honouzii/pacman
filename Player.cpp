#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"
#include "stage.h"
#include "Gauge.h"
#include "Engine/SceneManager.h"
namespace {
	const float PLAYER_MOVE_SPEED{ 5.0f/60.0f };
}

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),
	hModel_(-1),speed_(PLAYER_MOVE_SPEED),pStage_(nullptr),hpCrr_(100),hpMax_(100)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Player.fbx");
	assert(hModel_ >= 0);
	transform_.position_.x = 0.5;
	transform_.position_.z = 1.5;
	pStage_ = (stage*)FindObject("stage");
}

void Player::Update()
{
	XMVECTOR vFront = { 0,0,1,0 };
	XMVECTOR move{ 0,0,0,0 };

	if (Input::IsKey(DIK_UP)) {
		move = XMVECTOR{ 0,0,1,0 };
	}
	if (Input::IsKey(DIK_DOWN)) {
		move = XMVECTOR{ 0,0,-1,0 };
	}
	if (Input::IsKey(DIK_LEFT)) {
		move = XMVECTOR{ -1,0,0,0 };
	}
	if (Input::IsKey(DIK_RIGHT)) {
		move = XMVECTOR{ 1,0,0,0 };
	}
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	XMVECTOR posTmp = XMVectorZero();
	posTmp = pos + speed_ * move;
	/*Debug::Log("(x,y=");
	Debug::Log(XMVectorGetX(pos));
	Debug::Log(",");
	Debug::Log(XMVectorGetZ(pos), true);*/

	int tx, ty;
	tx = (int)(XMVectorGetX(posTmp) + 1.0f);
	ty = pStage_->GetStageWidth() - (int)(XMVectorGetZ(posTmp) + 1.0f);
	if (!(pStage_->IsWall(tx, ty)))
	{
		pos = posTmp;
	}
	else {
		hpCrr_ = hpCrr_ - 2;
		if (hpCrr_ < 0) {
			SceneManager* pSM = (SceneManager*)FindObject("SceneManager");
			pSM->ChangeScene(SCENE_ID_GAMEOVER);
		}
	}

	if (!XMVector3Equal(move, XMVectorZero())) {
		XMStoreFloat3(&(transform_.position_), pos);
	    //XMVECTOR vdot = XMVector3Dot(vFront, move);
		float angle = atan2(XMVectorGetX(move), XMVectorGetZ(move));
		transform_.rotate_.y = XMConvertToDegrees(angle);
	}
	Gauge* pGauge = (Gauge*)FindObject("Gauge");
	pGauge->SetGaugeVal(hpCrr_, hpMax_);
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
