// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ItemDescriptionWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

void UItemDescriptionWidget::SetItem(const FInventoryItemRow& NewItem)
{
	ItemNameText->SetText(NewItem.ItemName);
	ItemDescriptionText->SetText(NewItem.Description);
	ItemPowerText->SetText(FText::FromString(FString::SanitizeFloat(NewItem.Power)));
	CurrentItem = NewItem;
	if (GetVisibility() == ESlateVisibility::Collapsed)
	{
		SetVisibility(ESlateVisibility::Visible);
	}
}
