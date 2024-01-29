#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

Player::Player(GameObject* parent)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Player.fbx");
	assert(hModel_ >= 0);
	transform_.position_.x = 0.5;
	transform_.position_.z = 1.5;
}

void Player::Update()
{
	XMVECTOR vFront = { 0,0,1,0 };
	XMVECTOR move{ 0,0,1,0 };
	float speed = 0.01f;

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
	pos = pos + speed * move;
	XMStoreFloat3(&(transform_.position_), pos);

	XMVECTOR vdot = XMVector3Dot(vFront, move);
	float angle = acos(XMVectorGetX(vdot));
	transform_.rotate_.y = XMConvertToDegrees(angle);
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
