// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/InventoryWidget.h"
#include "Components/TileView.h"
#include "Widgets/ItemMenuWidget.h"
#include "Model/ItemInventoryModel.h"

void UInventoryWidget::CloseItemMenuWidget()
{
	if (ItemMenuWidget) 
	{
		ItemMenuWidget->RemoveFromParent();
		ItemMenuWidget = nullptr;
	}
}

void UInventoryWidget::OnRemoveItem(UItemInventoryModel* ItemToRemove)
{
	InventoryTileView->RemoveItem(ItemToRemove);
}

void UInventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();
}
