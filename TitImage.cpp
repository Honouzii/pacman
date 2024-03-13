#include "TitImage.h"
#include "Engine/Image.h"

TitImage::TitImage(GameObject* parent)
	:GameObject(parent, "TitImage"), hPict_(-1)
{
}

TitImage::~TitImage()
{
}

void TitImage::Initialize()
{
	hPict_ = Image::Load("pactit.jpg");
	assert(hPict_ >= 0);
}

void TitImage::Update()
{
}

void TitImage::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

void TitImage::Release()
{
}
