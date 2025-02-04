// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MoneyWidget.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class UICOURSE_API UMoneyWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true"))
	UTextBlock* MoneyText;
};
