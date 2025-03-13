// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "UVMInventoryEntryItem.generated.h"

class UItemInventoryModel;
/**
 * 
 */
UCLASS()
class UICOURSE_API UUVMInventoryEntryItem : public UMVVMViewModelBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, FieldNotify, Getter, Setter, meta = (AllowPrivateAccess = "true"))
	int32 ItemQuantity;

	UPROPERTY(BlueprintReadWrite, FieldNotify, Getter = "GetIsEquipped", Setter = "SetIsEquipped", meta = (AllowPrivateAccess = "true"))
	bool bIsEquipped;

public:	
	
	void SetItemQuantity(int32 NewQuantity);
	
	int32 GetItemQuantity() const;

	bool GetIsEquipped() const;
	void SetIsEquipped(bool bNewValue);

	
	

	
};
