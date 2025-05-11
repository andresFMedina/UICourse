// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "UVMMoney.generated.h"

/**
 * 
 */
UCLASS()
class UICOURSE_API UUVMMoney : public UMVVMViewModelBase
{
	GENERATED_BODY()


	UPROPERTY(BlueprintReadOnly, FieldNotify, Setter, Getter, meta = (AllowPrivateAccess))
	int32 CurrentMoney;
	UPROPERTY(BlueprintReadOnly, FieldNotify, Setter, Getter, meta = (AllowPrivateAccess))
	int32 MoneyChanged;

	UFUNCTION(BlueprintCallable)
	void Init();

	UFUNCTION()
	void OnMoneyChanged(int32 NewAmount);
	
public:
	UFUNCTION(BlueprintPure, FieldNotify)
	int32 GetCurrentMoney() const;
	UFUNCTION(BlueprintCallable)
	void SetCurrentMoney(const int32 NewAmount);

	UFUNCTION(BlueprintPure, FieldNotify)
	int32 GetMoneyChanged() const;
	UFUNCTION(BlueprintCallable)
	void SetMoneyChanged(const int32 NewAmount);
};
