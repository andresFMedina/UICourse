// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/InventoryWidget.h"
#include "Widgets/ItemMenuWidget.h"

void UInventoryWidget::CloseItemMenuWidget()
{
	if (ItemMenuWidget) 
	{
		ItemMenuWidget->RemoveFromParent();
		ItemMenuWidget = nullptr;
	}
}

void UInventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();
}
