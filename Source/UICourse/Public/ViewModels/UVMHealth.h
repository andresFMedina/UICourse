// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "UVMHealth.generated.h"

/**
 * 
 */
UCLASS()
class UICOURSE_API UUVMHealth : public UMVVMViewModelBase
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly, FieldNotify, Setter, Getter, meta = (AllowPrivateAccess))
	float MaxHealth;

	UPROPERTY(BlueprintReadOnly, FieldNotify, Setter, Getter, meta = (AllowPrivateAccess))
	float CurrentHealth;

	void Init();

public:
	float GetMaxHealth() const;
	float GetCurrentHealth() const;
	void SetMaxHealth(const float NewMaxHealth);
	void SetCurrentHealth(const float NewCurrentHealth);
};
