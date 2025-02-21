// Fill out your copyright notice in the Description page of Project Settings.


#include "Model/ItemInventoryModel.h"

FInventoryItemRow& UItemInventoryModel::GetItemRefInfo()
{
    return *ItemInfo.ItemRow.GetRow<FInventoryItemRow>("Item from model");
}
