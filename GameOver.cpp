#include "GameOver.h"
#include "Engine/Image.h"


GameOver::GameOver(GameObject* parent)
	:GameObject(parent,"GameOver"),hPct_(-1)
{
}

void GameOver::Initialize()
{
	hPct_ = Image::Load("GameOver.jpg");
	assert(hPct_ >= 0);
}

void GameOver::Update()
{
}

void GameOver::Draw()
{
	Image::SetTransform(hPct_, transform_);
	Image::Draw(hPct_);
}

void GameOver::Release()
{
}
