// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Data/ItemInventory.h"
#include "ItemDescriptionWidget.generated.h"

class UTextBlock;
class UImage;
/**
 * 
 */
UCLASS()
class UICOURSE_API UItemDescriptionWidget : public UUserWidget
{
	GENERATED_BODY()


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess="true"))
	FInventoryItemRow CurrentItem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true"))
	UTextBlock* ItemNameText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true"))
	UTextBlock* ItemDescriptionText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true"))
	UTextBlock* ItemPowerText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true"))
	UImage* ItemTypeImage;

public:
	UFUNCTION(BlueprintCallable)
	FORCEINLINE FInventoryItemRow& GetItem() { return CurrentItem; }

	UFUNCTION(BlueprintCallable)
	void SetItem(const FInventoryItemRow& NewItem);
};
