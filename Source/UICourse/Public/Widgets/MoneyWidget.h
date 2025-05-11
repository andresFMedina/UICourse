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
	
	UPROPERTY(BlueprintReadWrite, meta = ( AllowPrivateAccess = "true"))
	int32 TotalMoneyChanged;

	UPROPERTY(BlueprintReadWrite, Setter, meta = (AllowPrivateAccess = "true"))
	int32 MoneyChanged;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	int32 CurrentMoney;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true"))
	UTextBlock* CurrentMoneyText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true"))
	UTextBlock* TotalMoneyChangedText;

public:	
	UFUNCTION(BlueprintPure)
	FORCEINLINE int32 GetCurrentMoney() const { return CurrentMoney; }
	UFUNCTION(BlueprintCallable)
	void SetCurrentMoney(const int32 NewAmount);
	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32 GetMoneyChanged() const { return MoneyChanged; }
	UFUNCTION(BlueprintCallable)
	void SetMoneyChanged(const int32 NewAmount);
	UFUNCTION(BlueprintImplementableEvent)
	void StartMoneyChangedTimer();
	//void StartMoneyChangedTimer();
};
