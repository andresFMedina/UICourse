// Fill out your copyright notice in the Description page of Project Settings.


#include "ViewModels/UVMItemSelected.h"

const FInventoryItemRow& UUVMItemSelected::GetItemInfo() const
{
	return ItemInfo;
}

void UUVMItemSelected::SetItemInfo(FInventoryItemRow& ItemSelectedInfo)
{
	ItemInfo = ItemSelectedInfo;
	UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(ItemInfo);
}
