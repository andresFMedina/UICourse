// Fill out your copyright notice in the Description page of Project Settings.


#include "Model/ItemInventoryModel.h"

int32 UItemInventoryModel::RemoveStackToItem(const int32 StackToRemove)
{
   ItemInfo.ItemQuantity -= StackToRemove;
   return ItemInfo.ItemQuantity;
}

FInventoryItemRow& UItemInventoryModel::GetItemRefInfo()
{
    return *ItemInfo.ItemRow.GetRow<FInventoryItemRow>("Item from model");
}
