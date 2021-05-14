#pragma once
class HorizontalAxis
{
public:
	HorizontalAxis(float baseOffset = 0, float targetOffset = 0) {
		this->baseOffset = baseOffset;
		this->targetOffset = targetOffset;
	}
	float baseOffset;
	float targetOffset;

	static HorizontalAxis CenterToCenter() {
		return HorizontalAxis(0, 0);
	}
};


