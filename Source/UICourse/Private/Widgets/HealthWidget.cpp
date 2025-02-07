// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/HealthWidget.h"
#include "Components/WrapBox.h"
#include "Widgets/HeartWidget.h"
#include "MathUtil.h"

void UHealthWidget::SetHealthBox()
{
	if (HeartsBox && MaxHealth > 0.f && CurrentHealth > 0.f) 
	{
		HeartsBox->ClearChildren();
		for (auto i = 0; i < FMath::CeilToInt(MaxHealth); i++)
		{
			auto Widget = CreateWidget(this, HeartWidgetSubclass);
			auto HeartWidget = Cast<UHeartWidget>(Widget);
			if (HeartWidget) 
			{
				HeartWidget->SetPercent(CurrentHealth - i);
				HeartsBox->AddChild(HeartWidget);
			}
		}
	}
}

void UHealthWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	SetHealthBox();
}

void UHealthWidget::NativeConstruct()
{
	Super::NativeConstruct();
	SetHealthBox();
}

void UHealthWidget::SetMaxHealth(const float NewMaxHealth)
{
	MaxHealth = NewMaxHealth;
	SetHealthBox();
}

void UHealthWidget::SetCurrentHealth(const float NewCurrentHealth)
{
	CurrentHealth = NewCurrentHealth;
	SetHealthBox();
}
