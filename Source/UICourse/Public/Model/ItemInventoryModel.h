// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/ItemInventory.h"
#include "ItemInventoryModel.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class UICOURSE_API UItemInventoryModel : public UObject
{
	GENERATED_BODY()

	FItemSlot ItemInfo;

public:	
	FORCEINLINE const FItemSlot* GetItemInfo()const { return &ItemInfo; }
	FORCEINLINE void SetItemInfo(const FItemSlot& Item) { ItemInfo = Item; }
	FORCEINLINE void AddStackToItem(const int32 StackToAdd) { ItemInfo.ItemQuantity += StackToAdd; }
	FORCEINLINE void RemoveStackToItem(const int32 StackToRemove) { ItemInfo.ItemQuantity -= StackToRemove; }
	UFUNCTION(BlueprintPure)
	FInventoryItemRow& GetItemRefInfo();
	
};
