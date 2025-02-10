// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/ItemInventory.h"
#include "ItemInventoryModel.generated.h"

/**
 * 
 */
UCLASS()
class UICOURSE_API UItemInventoryModel : public UObject
{
	GENERATED_BODY()

	FInventoryItemRow ItemInfo;

public:
	FORCEINLINE const FInventoryItemRow& GetItemInfo()const { return ItemInfo; }
	
};
