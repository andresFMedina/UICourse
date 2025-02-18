// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "UVMMAinHUD.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class UICOURSE_API UUVMMAinHUD : public UMVVMViewModelBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, FieldNotify, Setter = "SetShowWidget", Getter = "GetShowWidget", meta = (AllowPrivateAccess))
	bool bShowWidget;

public:
	UFUNCTION(BlueprintPure)
	const bool GetShowWidget() const;
	
	UFUNCTION(BlueprintCallable)
	void SetShowWidget(const bool ShowWidget);

	UFUNCTION(BlueprintCallable)
	void Init();
	
};
