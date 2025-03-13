// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/ItemInventory.h"
#include "INotifyFieldValueChanged.h"
#include "ItemInventoryModel.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class UICOURSE_API UItemInventoryModel : public UObject
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FItemSlot ItemInfo;

public:	
	
	FORCEINLINE const FItemSlot* GetItemInfo()const { return &ItemInfo; }
	FORCEINLINE void SetItemInfo(const FItemSlot& Item) { ItemInfo = Item; }
	FORCEINLINE void AddStackToItem(const int32 StackToAdd) { ItemInfo.ItemQuantity += StackToAdd; }
	UFUNCTION(BlueprintCallable)
	int32 RemoveStackToItem(const int32 StackToRemove);
	UFUNCTION(BlueprintPure)
	FInventoryItemRow& GetItemRefInfo();	

	
};
