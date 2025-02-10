// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "ItemInventoryEntryWidget.generated.h"

class UImage;
class UTextBlock;
class UItemInventoryModel;
/**
 * 
 */
UCLASS()
class UICOURSE_API UItemInventoryEntryWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	UImage* ItemIcon;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	UTextBlock* TextItemStack;
	
	UItemInventoryModel* InventoryItem;


protected:
	virtual void NativeOnListItemObjectSet(UObject* ItemInventoryModel) override;
	
};
