#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"

namespace {
	const float PLAYER_MOVE_SPEED{ 1.0f };
}

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
	XMVECTOR move{ 0,0,0,0 };

	if (Input::IsKeyDown(DIK_UP)) {
		move = XMVECTOR{ 0,0,1,0 };
	}
	if (Input::IsKeyDown(DIK_DOWN)) {
		move = XMVECTOR{ 0,0,-1,0 };
	}
	if (Input::IsKeyDown(DIK_LEFT)) {
		move = XMVECTOR{ -1,0,0,0 };
	}
	if (Input::IsKeyDown(DIK_RIGHT)) {
		move = XMVECTOR{ 1,0,0,0 };
	}
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	pos = pos + PLAYER_MOVE_SPEED * move;
	Debug::Log("(x,y=");
	Debug::Log(XMVectorGetX(pos));
	Debug::Log(",");
	Debug::Log(XMVectorGetX(pos), true);
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
