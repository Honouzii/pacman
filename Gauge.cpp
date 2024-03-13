#include "Gauge.h"
#include "Engine/Image.h"

Gauge::Gauge(GameObject* parent)
	:GameObject(parent,"Gauge"),hPct_(-1),hGaugeFrame_(-1),gaugeMaxVal_(100),gaugeCrrVal_(0)
{
}

void Gauge::Initialize()
{
	hPct_ = Image::Load("HP.png");
	assert(hPct_ >= 0);
	hGaugeFrame_ = Image::Load("HPber.png");
	assert(hGaugeFrame_ >= 0);

	transform_.position_.x = 0.0f;
	transform_.position_.y = 0.9f;
}

void Gauge::Update()
{
}

void Gauge::Draw()
{
	Transform trn = transform_;
	trn.scale_.x = (float)gaugeCrrVal_ / (float)gaugeMaxVal_;

	Image::SetTransform(hPct_, trn);
	Image::Draw(hPct_);

	Image::SetTransform(hGaugeFrame_, transform_);
	Image::Draw(hGaugeFrame_);
}

void Gauge::Release()
{
}
