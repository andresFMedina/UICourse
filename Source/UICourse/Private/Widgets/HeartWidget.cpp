// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/HeartWidget.h"
#include "Components/Image.h"

void UHeartWidget::SetIconByPercent()
{
	
	if (FullHeartIcon && HalfHeartIcon && EmptyHeartIcon && HeartIcon) {
		if (Percent >= 1.f) HeartIcon->SetBrushFromTexture(FullHeartIcon, true);
		else if (Percent >= 0.5f) HeartIcon->SetBrushFromTexture(HalfHeartIcon, true);
		else HeartIcon->SetBrushFromTexture(EmptyHeartIcon, true);
	}
}

void UHeartWidget::NativePreConstruct()
{	
	Super::NativePreConstruct();
	SetIconByPercent();
}

void UHeartWidget::NativeConstruct()
{
	Super::NativeConstruct();
	SetIconByPercent();
}

void UHeartWidget::SetPercent(const float NewPercent)
{
	Percent = NewPercent;
}


