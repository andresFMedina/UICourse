// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ItemPickupWidget.h"
#include "Components/TextBlock.h"

void UItemPickupWidget::SetText(const FText& Text)
{
	if (this && InteractText) 
	{
		InteractText->SetText(Text);
	}
}
