// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "Data/ItemInventory.h"
#include "UVMItemSelected.generated.h"


/**
 * 
 */
UCLASS()
class UICOURSE_API UUVMItemSelected : public UMVVMViewModelBase
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, FieldNotify, Setter, Getter, meta = (AllowPrivateAccess))
	FInventoryItemRow ItemInfo;

public:
	UFUNCTION(BlueprintPure)
	const FInventoryItemRow& GetItemInfo() const;
	UFUNCTION(BlueprintCallable)
	void SetItemInfo(FInventoryItemRow& ItemSelectedInfo);

};
