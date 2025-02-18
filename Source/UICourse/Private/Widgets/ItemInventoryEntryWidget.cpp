// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ItemInventoryEntryWidget.h"
#include "Model/ItemInventoryModel.h"
#include "Data/ItemInventory.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Kismet/KismetTextLibrary.h"

void UItemInventoryEntryWidget::NativeOnListItemObjectSet(UObject* ItemInventoryModel)
{
	InventoryItem = Cast<UItemInventoryModel>(ItemInventoryModel);
	check(InventoryItem);

	if (InventoryItem->GetItemInfo())
	{
		auto Item = InventoryItem->GetItemInfo()->ItemRow.GetRow<FInventoryItemRow>("Get Row Inv");
		ItemIcon->SetBrushFromSoftTexture(Item->Thumbnail);
		TextItemStack->SetText(UKismetTextLibrary::Conv_IntToText(InventoryItem->GetItemInfo()->ItemQuantity));
	}

}
