// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Data/ItemInventory.h"
#include "ItemInventoryEntryWidget.generated.h"

class UImage;
class UTextBlock;
class UButton;
class UItemInventoryModel;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventoryItemClick, UItemInventoryModel*, ItemClicked);

/**
 * 
 */
UCLASS()
class UICOURSE_API UItemInventoryEntryWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true"))
	UButton* ItemButton;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	UImage* ItemIcon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true"))
	UTextBlock* TextItemStack;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess="true"))
	UItemInventoryModel* InventoryItem;

	UFUNCTION()
	void OnButtonClicked();


protected:
	UFUNCTION(BlueprintCallable, Category = ObjectListEntry)
	virtual void NativeOnListItemObjectSet(UObject* ItemInventoryModel) override;

public:
	UPROPERTY(BlueprintAssignable)
	FOnInventoryItemClick OnInventoryItemClickDelegate;
};
