// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

class UTileView;
class UItemMenuWidget;
/**
 * 
 */
UCLASS()
class UICOURSE_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true"))
	UTileView* InventoryTileView;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess ="true"))
	UItemMenuWidget* ItemMenuWidget;

	UFUNCTION(BlueprintCallable)
	void CloseItemMenuWidget();

	

protected:
	virtual void NativeConstruct() override;

};
