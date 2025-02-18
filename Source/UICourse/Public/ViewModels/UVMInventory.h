// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "Data/ItemInventory.h"
#include "UVMInventory.generated.h"


USTRUCT(BlueprintType)
struct FInventoryByCategory
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	TArray<UItemInventoryModel*> InventoryItems;

};

class UItemInventoryModel;
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
	UFUNCTION(BlueprintCallable)
	void Init();

	UFUNCTION(BlueprintPure, FieldNotify)
	const TArray<UItemInventoryModel*> GetListByItemType() const;

	UFUNCTION()
	const EItemType GetSelectedItemType()const;
	UFUNCTION()
	void SetSelectedItemType(const EItemType ItemType);
	
};
