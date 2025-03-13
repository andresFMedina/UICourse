// Fill out your copyright notice in the Description page of Project Settings.


#include "ViewModels/UVMInventoryEntryItem.h"

void UUVMInventoryEntryItem::SetItemQuantity(int32 NewQuantity)
{
	UE_MVVM_SET_PROPERTY_VALUE(ItemQuantity, NewQuantity);
}

int32 UUVMInventoryEntryItem::GetItemQuantity() const
{
	return ItemQuantity;
}

bool UUVMInventoryEntryItem::GetIsEquipped() const
{
	return bIsEquipped;
}

void UUVMInventoryEntryItem::SetIsEquipped(bool bNewValue)
{
	UE_MVVM_SET_PROPERTY_VALUE(bIsEquipped, bNewValue);
}
