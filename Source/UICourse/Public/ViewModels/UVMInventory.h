// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "Data/ItemInventory.h"
#include "UVMInventory.generated.h"


class UItemInventoryModel;
USTRUCT(BlueprintType)
struct FInventoryByCategory
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	TArray<UItemInventoryModel*> InventoryItems;

};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemUse, UItemInventoryModel*, ItemToUse);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDropItem, UItemInventoryModel*, ItemToDrop);

/**
 * 
 */

UCLASS(BlueprintType)
class UICOURSE_API UUVMInventory : public UMVVMViewModelBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, FieldNotify, Setter, Getter, meta = (AllowPrivateAccess))
	EItemType SelectedItemType;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess="true"))
	TMap<EItemType, FInventoryByCategory> InventoryItemsByType;

public:

	FOnItemUse OnItemUseDelegate;

	FOnDropItem OnDropItemDelegate;

	UFUNCTION(BlueprintCallable)
	void Init();

	UFUNCTION(BlueprintPure, FieldNotify)
	const TArray<UItemInventoryModel*> GetListByItemType() const;

	UFUNCTION()
	const EItemType GetSelectedItemType()const;
	UFUNCTION()
	void SetSelectedItemType(const EItemType ItemType);

	UFUNCTION(BlueprintCallable)
	void UseItem(UItemInventoryModel* ItemToUse);

	UFUNCTION(BlueprintCallable)
	void DropItem(UItemInventoryModel* ItemToDrop);
	
};
